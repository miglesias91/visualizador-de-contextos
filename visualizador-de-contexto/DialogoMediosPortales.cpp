#include "DialogoMediosPortales.h"
#include "ui_DialogoMediosPortales.h"

// qt
#include <qlistwidget.h>
#include <qtreewidget.h>

// medios
#include <noticias/include/config.h>

// utiles
#include <utiles/include/Fecha.h>
#include <utiles/include/FuncionesSistemaArchivos.h>

// visualizador-de-contexto
#include <visualizador-de-contexto/include/FabricaMensajes.h>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>
#include <aplicacion/include/Logger.h>

DialogoMediosPortales::DialogoMediosPortales(QWidget* parent)
    : QWidget(parent) {
    ui = new Ui::DialogoMediosPortales();
    ui->setupUi(this);

    this->conectar_componentes();

    aplicacion::Logger::info("Iniciando dialogo medios portales.");

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->cargarListaMediosPortales();
}

DialogoMediosPortales::~DialogoMediosPortales() {
    this->descargarListaMediosPortales();

    aplicacion::Logger::info("Cerrando dialogo medios portales.");

    delete ui;
}

void DialogoMediosPortales::hideEvent(QHideEvent*) {
    emit se_cerro();
}

void DialogoMediosPortales::showEvent(QShowEvent*) {
    emit se_abrio();
}

void DialogoMediosPortales::guardar() {
    this->close();
}

void DialogoMediosPortales::cerrar() {
    this->close();
}

// METODOS PRIVADOS

void DialogoMediosPortales::agregarSubseccionALista(modelo::subseccion* portal) {
    portal->sumarReferencia();

    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(portal);
    item->setData(Qt::UserRole, data);

    std::string texto_item = aplicacion::Logger::infoLog(portal);

    item->setText(texto_item.c_str());

    this->ui->lista_medios_portales->insertItem(0, item);
}

void DialogoMediosPortales::cargarListaMediosPortales() {
    std::vector<modelo::MedioPortalNoticias*> portales_actuales = this->gestor_medios.gestionar<modelo::MedioPortalNoticias>();

    if (portales_actuales.size() == 0) {  // si no hay portales agregados, entonces:
        this->registrar_abm();  // registor el abm de los portales preexistentes + almaceno las entidades,
        portales_actuales = this->gestor_medios.recuperar<modelo::MedioPortalNoticias>();  // y ahora recupero las entidades recien almacenadas.
    }

    std::for_each(portales_actuales.begin(), portales_actuales.end(), [=](modelo::MedioPortalNoticias * portal){
        //std::vector<modelo::subseccion*> subsecciones_portal = portal->subsecciones();
        //std::for_each(subsecciones_portal.begin(), subsecciones_portal.end(), [=](modelo::subseccion * subseccion){
        //    modelo::subseccion* clon = this->gestor_medios.clonar<modelo::subseccion>(subseccion);
        //    this->agregarSubseccionALista(clon);
        //});
        this->agregarPortalALista(portal);
    });

    aplicacion::Logger::info(std::to_string(portales_actuales.size()) + " portales cargados.");

    this->ui->lista_medios_portales->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoMediosPortales::descargarListaMediosPortales() {
    //QListWidgetItem* item = nullptr;

    //// elimino los periodos de la lista
    //modelo::subseccion* subseccion_lista = nullptr;
    //unsigned int count = ui->lista_medios_portales->count();

    //while (0 != ui->lista_medios_portales->count()) {
    //    count = ui->lista_medios_portales->count();

    //    subseccion_lista = this->ui->lista_medios_portales->item(0)->data(Qt::UserRole).value<modelo::subseccion*>();

    //    if (0 == subseccion_lista->restarReferencia()) {
    //        delete subseccion_lista;
    //    }

    //    item = this->ui->lista_medios_portales->takeItem(0);
    //    delete item;
    //}

    //aplicacion::Logger::info(std::to_string(count) + " portales descargados.");
}

void DialogoMediosPortales::agregarPortalALista(modelo::MedioPortalNoticias * medio_portal_noticias) {

    uint32_t cantidad_total = 0;
    QList<QTreeWidgetItem*> items_subsecciones;
    std::vector<modelo::subseccion*> subsecciones_portal = medio_portal_noticias->subsecciones();
    std::for_each(subsecciones_portal.begin(), subsecciones_portal.end(), [=, &items_subsecciones, &cantidad_total](modelo::subseccion * subseccion){
        QTreeWidgetItem* item_subseccion = new QTreeWidgetItem(QStringList((subseccion->seccion() + " | " + std::to_string(subseccion->contenidos_analizados())).c_str()));
        items_subsecciones.push_back(item_subseccion);
        cantidad_total += subseccion->contenidos_analizados();
    });

    QTreeWidgetItem * item_portal = new QTreeWidgetItem(QStringList((medio_portal_noticias->getEtiqueta() + " | " + std::to_string(cantidad_total)).c_str()));
    item_portal->addChildren(items_subsecciones);

    this->ui->arbol_medios_portales->addTopLevelItem(item_portal);
}

void DialogoMediosPortales::registrar_abm() {
    std::vector<herramientas::utiles::Json*> altas;
    std::for_each(medios::noticias::config::feeds.begin(), medios::noticias::config::feeds.end(), [=, &altas](std::pair<std::string, medios::noticias::config_feed> nombre_feed){
        modelo::MedioPortalNoticias * portal = new modelo::MedioPortalNoticias(nombre_feed.second.web, nombre_feed.first);
        this->gestor_medios.almacenar(portal);

        herramientas::utiles::Json * alta = new herramientas::utiles::Json();
        alta->agregarAtributoValor("id", portal->getId()->numero());
        alta->agregarAtributoValor("web", nombre_feed.second.web);
        altas.push_back(alta);
    });
    this->gestor_medios.guardarCambios();

    herramientas::utiles::Json registro;
    registro.agregarAtributoArray("altas", altas);

    herramientas::utiles::Json abm;
    abm.agregarAtributoJson("portales", &registro);

    //exporto 'registro' al path indicado.
    if(altas.size() > 0) { 
        herramientas::utiles::FuncionesSistemaArchivos::escribir(aplicacion::ConfiguracionAplicacion::dirABM() + "/" + herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS() + ".json", abm.jsonStringLindo());
    }

    std::for_each(altas.begin(), altas.end(), [=](herramientas::utiles::Json * json) { delete json; });
}

void DialogoMediosPortales::conectar_componentes() {
    QObject::connect(this->ui->btn_cerrar, &QPushButton::released, this, &DialogoMediosPortales::close);
}
