#include "DialogoMediosFacebook.h"
#include "ui_DialogoMediosFacebook.h"

// utiles
#include <utiles/include/FuncionesSistemaArchivos.h>

// visualizador-de-contexto
#include <visualizador-de-contexto/include/FabricaMensajes.h>

// aplicacion
#include <aplicacion/include/Logger.h>

// modelo
#include <modelo/include/MedioFacebook.h>

// scraping
#include <scraping/include/ConfiguracionScraping.h>

DialogoMediosFacebook::DialogoMediosFacebook(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoMediosFacebook();
    ui->setupUi(this);

    this->conectar_componentes();

    aplicacion::Logger::info("Iniciando dialogo Medios Facebook.");

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->cargarListaMediosFacebook();

    this->resetear();
}

DialogoMediosFacebook::~DialogoMediosFacebook()
{
    this->descargarListaMediosFacebook();

    aplicacion::Logger::info("Cerrando dialogo Medios Facebook.");

    delete ui;
}

void DialogoMediosFacebook::hideEvent(QHideEvent *) {
    emit se_cerro();
}

void DialogoMediosFacebook::showEvent(QShowEvent *) {
    emit se_abrio();
}

// SLOTS

void DialogoMediosFacebook::actualizar_y_cerrar()
{
    this->registrar_abm();
    this->gestor_medios.guardarCambios();

    aplicacion::Logger::info("Dialogo Medios Facebook guardado.");

    this->close();
}

void DialogoMediosFacebook::resetear()
{
    this->ui->lista_medios_facebook->clearSelection();

    this->estado_btn_eliminar();

    aplicacion::Logger::info("Dialogo Medios Facebook reseteado.");
}

void DialogoMediosFacebook::eliminar()
{
    QList<QListWidgetItem*> items = ui->lista_medios_facebook->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QVariant data = item->data(Qt::UserRole);
        modelo::MedioFacebook* medio = data.value<modelo::MedioFacebook*>();

        this->gestor_medios.eliminar(medio);

        aplicacion::Logger::info("Medio Facebook eliminado: '" + aplicacion::Logger::infoLog(medio) + "'.");

        delete medio;

        delete this->ui->lista_medios_facebook->takeItem(ui->lista_medios_facebook->row(item));
    }
}

void DialogoMediosFacebook::estado_btn_eliminar()
{
    int items_seleccionados = this->ui->lista_medios_facebook->selectedItems().size();
    if (0 >= items_seleccionados)
    {
        this->ui->btn_eliminar->setDisabled(true);
    }
    else
    {
        this->ui->btn_eliminar->setEnabled(true);
    }
}

void DialogoMediosFacebook::guardar() {

    this->actualizar_y_cerrar();

}

void DialogoMediosFacebook::cerrar() {

    this->close();
}

// METODOS PRIVADOS

void DialogoMediosFacebook::cargarListaMediosFacebook()
{
    std::vector<modelo::MedioFacebook*> medios_actuales = this->gestor_medios.gestionar<modelo::MedioFacebook>();

    for (std::vector<modelo::MedioFacebook*>::iterator it = medios_actuales.begin(); it != medios_actuales.end(); it++)
    {
        modelo::MedioFacebook * clon = this->gestor_medios.clonar<modelo::MedioFacebook>(*it);
        this->agregarMedioFacebookALista(clon);
    }

    aplicacion::Logger::info(std::to_string(medios_actuales.size()) + " medios facebook cargados.");

    this->ui->lista_medios_facebook->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoMediosFacebook::descargarListaMediosFacebook()
{
    QListWidgetItem* item = nullptr;

    // elimino los periodos de la lista
    modelo::MedioFacebook* medio_lista = nullptr;
    unsigned int count = ui->lista_medios_facebook->count();
    while (0 != ui->lista_medios_facebook->count())
    {
        count = ui->lista_medios_facebook->count();

        medio_lista = this->ui->lista_medios_facebook->item(0)->data(Qt::UserRole).value<modelo::MedioFacebook*>();

        if (0 == medio_lista->restarReferencia())
        {
            delete medio_lista;
        }

        item = this->ui->lista_medios_facebook->takeItem(0);
        delete item;
    }

    aplicacion::Logger::info(std::to_string(count) + " medios facebook descargados.");
}

void DialogoMediosFacebook::agregarMedioFacebookALista(modelo::MedioFacebook * medio_facebook)
{
    medio_facebook->sumarReferencia();

    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(medio_facebook);
    item->setData(Qt::UserRole, data);

    std::string texto_item = aplicacion::Logger::infoLog(medio_facebook);

    item->setText(texto_item.c_str());

    this->ui->lista_medios_facebook->insertItem(0, item);
}

void DialogoMediosFacebook::registrar_abm() {
    std::vector<modelo::IEntidad*> entidades_de_alta = gestor_medios.getEntidadesAAlmacenar();
    std::vector<modelo::IEntidad*> entidades_de_baja = gestor_medios.getEntidadesAEliminar();

    std::vector<herramientas::utiles::Json*> altas;
    std::for_each(entidades_de_alta.begin(), entidades_de_alta.end(), [=, &altas](modelo::IEntidad * entidad) {
        modelo::MedioFacebook * facebook = static_cast<modelo::MedioFacebook*>(entidad);
        herramientas::utiles::Json * alta = new herramientas::utiles::Json();
        alta->agregarAtributoValor("id", facebook->getId()->numero());
        alta->agregarAtributoValor("usuario", facebook->getNombrePagina());
        altas.push_back(alta);
    });

    std::vector<uint64_t> bajas;
    std::for_each(entidades_de_baja.begin(), entidades_de_baja.end(), [=, &bajas](modelo::IEntidad * entidad) {
        bajas.push_back(entidad->getId()->numero());
    });

    herramientas::utiles::Json registro;
    registro.agregarAtributoArray("altas", altas);
    registro.agregarAtributoArray("bajas", bajas);

    herramientas::utiles::Json abm;
    abm.agregarAtributoJson("facebook", &registro);

    //exporto 'registro' al path indicado.
    if(altas.size() > 0 || bajas.size() > 0) { 
        herramientas::utiles::FuncionesSistemaArchivos::escribir(aplicacion::ConfiguracionAplicacion::dirABM() + "/" + herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS() + ".json", abm.jsonStringLindo());
    }

    std::for_each(altas.begin(), altas.end(), [=](herramientas::utiles::Json * json) { delete json; });
}

void DialogoMediosFacebook::nueva_pagina()
{
    modelo::MedioFacebook * medio_facebook_nuevo = new modelo::MedioFacebook();
    this->dialogo_editar_medio_facebook = new DialogoEditarMedioFacebook(medio_facebook_nuevo, &this->gestor_medios, this);
    if (this->dialogo_editar_medio_facebook->exec())
    {
        if (false == this->gestor_medios.existe(medio_facebook_nuevo))
        {
            // y lo agrego en la lista visible.
            this->agregarMedioFacebookALista(medio_facebook_nuevo);

            // ahora si la almaceno.
            this->gestor_medios.almacenar(medio_facebook_nuevo);

            aplicacion::Logger::info("Medio Facebbok agregado: { " + aplicacion::Logger::infoLog(medio_facebook_nuevo) + " }.");
        }
        else
        {
            QMessageBox * informacion_termino_existente = this->crearInformacionMedioFacebookExistente();
            informacion_termino_existente->exec();

            delete informacion_termino_existente;

            delete medio_facebook_nuevo;
        }

        this->resetear();
    }
    else
    {
        delete medio_facebook_nuevo;
    }
}

QMessageBox * DialogoMediosFacebook::crearInformacionMedioFacebookExistente()
{
    std::string texto = u8"La cuenta de Facebook que se quiere agregar ya existe!";
    visualizador::aplicacion::comunicacion::Informacion informacion_termino_existente(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_termino_existente, this);
}

void DialogoMediosFacebook::conectar_componentes() {

    QObject::connect(this->ui->btn_nueva, &QPushButton::released, this, &DialogoMediosFacebook::nueva_pagina);
    QObject::connect(this->ui->btn_eliminar, &QPushButton::released, this, &DialogoMediosFacebook::eliminar);
	QObject::connect(this->ui->btn_guardar, &QPushButton::released, this, &DialogoMediosFacebook::actualizar_y_cerrar);
	QObject::connect(this->ui->lista_medios_facebook, &QListWidget::itemSelectionChanged, this, &DialogoMediosFacebook::estado_btn_eliminar);
    QObject::connect(this->ui->btn_cancelar, &QPushButton::released, this, &DialogoMediosFacebook::close);
}