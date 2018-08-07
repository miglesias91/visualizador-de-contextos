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
#include <utiles/include/FuncionesString.h>

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

void DialogoMediosPortales::cargarListaMediosPortales() {
    std::vector<modelo::MedioPortalNoticias*> portales_actuales = this->gestor_medios.recuperar<modelo::MedioPortalNoticias>();

    if (portales_actuales.size() == 0) {  // si no hay portales agregados, entonces:
        this->registrar_abm();  // registor el abm de los portales preexistentes + almaceno las entidades,
        portales_actuales = this->gestor_medios.recuperar<modelo::MedioPortalNoticias>();  // y ahora recupero las entidades recien almacenadas.
    }

    std::for_each(portales_actuales.begin(), portales_actuales.end(), [=](modelo::MedioPortalNoticias * portal){
        this->agregarPortalALista(portal);
    });

    aplicacion::Logger::info(std::to_string(portales_actuales.size()) + " portales cargados.");

    std::for_each(portales_actuales.begin(), portales_actuales.end(), [=](modelo::MedioPortalNoticias * medio_portal) { delete medio_portal; });

    this->ui->arbol_medios_portales->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoMediosPortales::agregarPortalALista(modelo::MedioPortalNoticias * medio_portal_noticias) {

    uint32_t cantidad_total = 0;
    uint32_t tamanio_total = 0;
    QList<QTreeWidgetItem*> items_subsecciones;
    std::unordered_map<std::string, modelo::subseccion*> subsecciones_portal = medio_portal_noticias->subsecciones();

    std::for_each(subsecciones_portal.begin(), subsecciones_portal.end(), [=, &items_subsecciones, &cantidad_total, &tamanio_total](std::pair<std::string, modelo::subseccion*> nombre_subseccion) {
        std::string texto_item = nombre_subseccion.first + " | " +
            nombre_subseccion.second->fecha_contenido_mas_antiguo().getStringDDMMAAAA("/") + " - " + nombre_subseccion.second->fecha_contenido_mas_reciente().getStringDDMMAAAA("/") + " | " +
            std::to_string(nombre_subseccion.second->contenidos_analizados()) + " | " + herramientas::utiles::FuncionesString::toString(nombre_subseccion.second->tamanio()/1000,0) + "k";
        QTreeWidgetItem* item_subseccion = new QTreeWidgetItem(QStringList(texto_item.c_str()));
        items_subsecciones.push_back(item_subseccion);
        cantidad_total += nombre_subseccion.second->contenidos_analizados();
        tamanio_total += nombre_subseccion.second->tamanio();
    });

    std::string texto_item = (medio_portal_noticias->getEtiqueta() + " | " + std::to_string(cantidad_total));
    QTreeWidgetItem * item_portal = new QTreeWidgetItem(QStringList((medio_portal_noticias->getEtiqueta() + " | " + std::to_string(cantidad_total) + " noticias analizadas | " + herramientas::utiles::FuncionesString::toString(tamanio_total / 1000, 0) + "k caracteres procesados.").c_str()));
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
