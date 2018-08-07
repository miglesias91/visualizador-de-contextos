#include "DialogoConsultas.h"
#include "ui_DialogoConsultas.h"

// scraping
#include <scraping/include/GestorMedios.h>

// aplicacion
#include <aplicacion/include/GestorResultadosDiarios.h>
#include <aplicacion/include/GestorConsultas.h>
#include <aplicacion/include/Logger.h>

// modelo
#include <modelo/include/MedioPortalNoticias.h>

using namespace visualizador;

DialogoConsultas::DialogoConsultas(QWidget *parent)
    : QWidget(parent), grafico_fuerza_en_noticia(NULL), dialogo_resultados(nullptr), spinner(this, false, false)
{
    ui = new Ui::DialogoConsultas();
    ui->setupUi(this);

    this->ui->lbl_etiqueta->setVisible(false);
    this->ui->lineedit_etiqueta_periodo->setVisible(false);

    herramientas::utiles::Fecha actual = herramientas::utiles::Fecha::getFechaActual();
    herramientas::utiles::Fecha desde = actual;
    desde -= std::chrono::hours(7 * 24);  // una semana para atras.
    this->ui->dateedit_desde->setDate(QDate(desde.getAnio(), desde.getMes(), desde.getDia()));
    this->ui->dateedit_hasta->setDate(QDate(actual.getAnio(), actual.getMes(), actual.getDia()));

    this->ui->layout_botones->addWidget(&this->spinner);
    this->spinner.setColor(QColor(61, 174, 233));
    this->spinner.setLineLength(3);
    this->spinner.setLineWidth(3);
    this->spinner.setInnerRadius(5);

    this->conectar_componentes();
    this->habilitar_consulta();
    this->habilitar_tendencias();
    this->habilitar_conceptos();

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->cargarListaConceptos();
    this->cargarListaMedios();
}

DialogoConsultas::~DialogoConsultas()
{
    this->descargarLista<modelo::Concepto>(this->ui->lista_conceptos);
    this->descargarLista<modelo::Concepto>(this->ui->lista_conceptos_en_consulta);
    aplicacion::Logger::info("Conceptos descargados.");

    this->descargarLista<modelo::Medio>(this->ui->lista_medios);
    this->descargarLista<modelo::Medio>(this->ui->lista_medios_en_consulta);
    aplicacion::Logger::info("Medios descargados.");

    delete ui;
}

void DialogoConsultas::closeEvent(QCloseEvent *) {
    emit se_cerro();
}

void DialogoConsultas::showEvent(QShowEvent *) {
    emit se_abrio();
}

void DialogoConsultas::guardar() {
    //this->close();
    this->setVisible(false);
}

void DialogoConsultas::cerrar() {
    this->close();
}

void DialogoConsultas::habilitar_consulta() {
    if (this->ui->checkbox_conceptos->isChecked() || this->ui->checkbox_tendencia->isChecked()) {
        this->ui->btn_realizar_consulta->setEnabled(true);
    } else {
        this->ui->btn_realizar_consulta->setEnabled(false);
    }
}

void DialogoConsultas::habilitar_conceptos() {
    if (this->ui->checkbox_conceptos->isChecked()) {
        this->ui->lista_conceptos_en_consulta->setEnabled(true);
        this->ui->btn_sacar_conceptos->setEnabled(true);
    }
    else {
        this->ui->lista_conceptos_en_consulta->setEnabled(false);
        this->ui->btn_sacar_conceptos->setEnabled(false);
    }
}

void DialogoConsultas::habilitar_tendencias() {
    if (this->ui->checkbox_tendencia->isChecked()) {
        this->ui->lbl_mostrar_primeros->setEnabled(true);
        this->ui->spinbox_tendencias->setEnabled(true);
        this->ui->lbl_ordenar_por->setEnabled(true);
        this->ui->combobox_tendencia->setEnabled(true);
    }
    else {
        this->ui->lbl_mostrar_primeros->setEnabled(false);
        this->ui->spinbox_tendencias->setEnabled(false);
        this->ui->lbl_ordenar_por->setEnabled(false);
        this->ui->combobox_tendencia->setEnabled(false);
    }
}

void DialogoConsultas::agregar_conceptos()
{
    std::vector<modelo::Concepto*> conceptos_seleccionados = this->itemsSeleccionados<modelo::Concepto>(this->ui->lista_conceptos);

    for (std::vector<modelo::Concepto*>::iterator it = conceptos_seleccionados.begin(); it != conceptos_seleccionados.end(); it++)
    {
        this->agregarConceptoALista(*it, this->ui->lista_conceptos_en_consulta);
    }

    aplicacion::Logger::info(std::to_string(conceptos_seleccionados.size()) + " conceptos agregados a la consulta.");

    this->sacarItemsSeleccionados(this->ui->lista_conceptos);
}

void DialogoConsultas::sacar_conceptos()
{
    std::vector<modelo::Concepto*> conceptos_seleccionados = this->itemsSeleccionados<modelo::Concepto>(this->ui->lista_conceptos_en_consulta);

    for (std::vector<modelo::Concepto*>::iterator it = conceptos_seleccionados.begin(); it != conceptos_seleccionados.end(); it++)
    {
        this->agregarConceptoALista(*it, this->ui->lista_conceptos);
    }

    aplicacion::Logger::info(std::to_string(conceptos_seleccionados.size()) + " conceptos sacados de la consulta.");

    this->sacarItemsSeleccionados(this->ui->lista_conceptos_en_consulta);
}

void DialogoConsultas::resetear_periodo()
{
    this->ui->lineedit_etiqueta_periodo->clear();
    this->ui->dateedit_desde->setDate(QDate::currentDate());
    this->ui->dateedit_hasta->setDate(QDate::currentDate());
    
    aplicacion::Logger::info("Periodo reseteado.");
}

void DialogoConsultas::agregar_medios()
{
    std::vector<modelo::Medio*> medios_seleccionados = this->itemsSeleccionados<modelo::Medio>(this->ui->lista_medios);

    for (std::vector<modelo::Medio*>::iterator it = medios_seleccionados.begin(); it != medios_seleccionados.end(); it++)
    {
        this->agregarMedioALista(*it, this->ui->lista_medios_en_consulta);
    }

    aplicacion::Logger::info(std::to_string(medios_seleccionados.size()) + " medios agregados a la consulta.");

    this->sacarItemsSeleccionados(this->ui->lista_medios);
}

void DialogoConsultas::sacar_medios()
{
    std::vector<modelo::Medio*> medios_seleccionados = this->itemsSeleccionados<modelo::Medio>(this->ui->lista_medios_en_consulta);

    for (std::vector<modelo::Medio*>::iterator it = medios_seleccionados.begin(); it != medios_seleccionados.end(); it++)
    {
        this->agregarMedioALista(*it, this->ui->lista_medios);
    }

    aplicacion::Logger::info(std::to_string(medios_seleccionados.size()) + " medios sacados de la consulta.");

    this->sacarItemsSeleccionados(this->ui->lista_medios_en_consulta);
}

void DialogoConsultas::recuperar_resultados() {

    std::vector<modelo::Medio*> medios_seleccionados = this->mediosSeleccionados();
    std::vector<modelo::Concepto*> conceptos_seleccionados = this->conceptosSeleccionados();

    if (medios_seleccionados.empty()) {
        QMessageBox * informacion_no_hay_medios_seleccionados = this->crearInformacionNoHayMediosSeleccionados();
        informacion_no_hay_medios_seleccionados->exec();

        delete informacion_no_hay_medios_seleccionados;

        return;
    }

    //if (conceptos_seleccionados.empty() && (this->ui->checkbox_sentimiento->isChecked() || this->ui->checkbox_fuerza->isChecked())) {
    if (this->ui->checkbox_conceptos->isChecked() && conceptos_seleccionados.empty() ) {
        QMessageBox * informacion_no_hay_conceptos_seleccionados = this->crearInformacionNoHayConceptosSeleccionados();
        informacion_no_hay_conceptos_seleccionados->exec();

        delete informacion_no_hay_conceptos_seleccionados;

        return;
    }

    QFuture<void> tarea_exportacion = QtConcurrent::run([=]() {
        aplicacion::GestorResultadosDiarios gestor_datos;

        herramientas::utiles::Fecha desde(this->ui->dateedit_desde->date().day(), this->ui->dateedit_desde->date().month(), this->ui->dateedit_desde->date().year());
        herramientas::utiles::Fecha hasta(this->ui->dateedit_hasta->date().day(), this->ui->dateedit_hasta->date().month(), this->ui->dateedit_hasta->date().year());
        
        gestor_datos.recuperarResultados(desde, hasta, medios_seleccionados, conceptos_seleccionados, &(this->resultados_filtrados));
    });

    this->observador_realizar_consulta.setFuture(tarea_exportacion);
}

void DialogoConsultas::mostrar_resultados() {

    herramientas::utiles::Fecha desde(this->ui->dateedit_desde->date().day(), this->ui->dateedit_desde->date().month(), this->ui->dateedit_desde->date().year());
    herramientas::utiles::Fecha hasta(this->ui->dateedit_hasta->date().day(), this->ui->dateedit_hasta->date().month(), this->ui->dateedit_hasta->date().year());

    std::vector<modelo::Medio*> medios_seleccionados = this->mediosSeleccionados();
    std::vector<modelo::Concepto*> conceptos_seleccionados = this->conceptosSeleccionados();

    if (this->resultados_filtrados.empty()) {
        QMessageBox * informacion_etiqueta_vacia = this->crearInformacionSinResultados();
        informacion_etiqueta_vacia->exec();

        delete informacion_etiqueta_vacia;

        aplicacion::Logger::info("Realizando consulta: " + std::to_string(this->resultados_filtrados.size()) + " resultados recuperados para el rango [ " + desde.getStringDDmesAAAA() + " - " + hasta.getStringDDmesAAAA() + " ].");

        return;
    }

    aplicacion::Logger::info("Realizando consulta: " + std::to_string(this->resultados_filtrados.size()) + " resultados recuperados para el rango [ " + desde.getStringDDmesAAAA() + " - " + hasta.getStringDDmesAAAA() + " ].");

    info_consulta info{
        this->ui->checkbox_conceptos->isChecked(),
        this->ui->checkbox_tendencia->isChecked(),
        this->ui->spinbox_tendencias->value(),
        info_consulta::ordenar_por(this->ui->combobox_tendencia->currentIndex())
    };

    this->dialogo_resultados = new DialogoResultadoConsulta(medios_seleccionados, conceptos_seleccionados, this->resultados_filtrados, info);
    //this->ui->opciones_consulta->addTab(dialogo_resultados, ("consulta_" + herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS()).c_str());
    this->ui->opciones_consulta->addTab(dialogo_resultados, "consulta");
    this->ui->opciones_consulta->setCurrentWidget(this->dialogo_resultados);
    this->dialogo_resultados->show();

    std::for_each(this->resultados_filtrados.begin(), this->resultados_filtrados.end(),
        [](scraping::preparacion::ResultadoAnalisisDiario* resultado)
    { delete resultado; });

    this->resultados_filtrados.clear();
}

// carga listas

void DialogoConsultas::cargarListaConceptos()
{
    aplicacion::GestorEntidades gestor;
    std::vector<modelo::Concepto*> conceptos_actuales = gestor.recuperar<modelo::Concepto>();
    for (std::vector<modelo::Concepto*>::iterator it = conceptos_actuales.begin(); it != conceptos_actuales.end(); it++)
    {
        (*it)->sumarReferencia();
        this->agregarConceptoALista(*it, this->ui->lista_conceptos);
    }

    aplicacion::Logger::info(std::to_string(conceptos_actuales.size()) + " conceptos cargados.");

    this->ui->lista_conceptos->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoConsultas::agregarConceptoALista(visualizador::modelo::Concepto * concepto, QListWidget * lista)
{
    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(concepto);
    item->setData(Qt::UserRole, data);

    std::string texto_item = aplicacion::Logger::infoLog(concepto);

    item->setText(texto_item.c_str());

    lista->insertItem(0, item);
}

void DialogoConsultas::cargarListaMedios()
{
    // recupero las cuentas de twitter
    visualizador::aplicacion::GestorEntidades gestor_entidades;

    std::vector<modelo::MedioTwitter*> medios_twitter_actuales = gestor_entidades.recuperar<modelo::MedioTwitter>();
    for (std::vector<modelo::MedioTwitter*>::iterator it = medios_twitter_actuales.begin(); it != medios_twitter_actuales.end(); it++)
    {
        (*it)->sumarReferencia();
        this->agregarMedioALista(*it, this->ui->lista_medios);
    }
    aplicacion::Logger::info(std::to_string(medios_twitter_actuales.size()) + " medios de twitter cargados.");

    // recupero las cuentas de facebook
    std::vector<modelo::MedioFacebook*> medios_facebook_actuales = gestor_entidades.recuperar<modelo::MedioFacebook>();
    for (std::vector<modelo::MedioFacebook*>::iterator it = medios_facebook_actuales.begin(); it != medios_facebook_actuales.end(); it++)
    {
        (*it)->sumarReferencia();
        this->agregarMedioALista(*it, this->ui->lista_medios);
    }
    aplicacion::Logger::info(std::to_string(medios_facebook_actuales.size()) + " medios de facebook cargados.");

    // recupero los portales de noticia
    std::vector<modelo::MedioPortalNoticias*> medios_portales_actuales = gestor_entidades.recuperar<modelo::MedioPortalNoticias>();
    std::for_each(medios_portales_actuales.begin(), medios_portales_actuales.end(), [=, &gestor_entidades](modelo::MedioPortalNoticias * portal) {
        std::unordered_map<std::string, modelo::subseccion*> subsecciones = portal->subsecciones();
        std::for_each(subsecciones.begin(), subsecciones.end(), [=, &gestor_entidades](std::pair<std::string, modelo::subseccion*> subseccion_portal) {
            modelo::subseccion* clon = gestor_entidades.clonar<modelo::subseccion>(subseccion_portal.second);
            clon->sumarReferencia();
            this->agregarMedioALista(clon, this->ui->lista_medios);
        });
        delete portal;
    });

    this->ui->lista_medios->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoConsultas::agregarMedioALista(visualizador::modelo::Medio * medio, QListWidget * lista)
{
    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(medio);
    item->setData(Qt::UserRole, data);

    std::string texto_item = aplicacion::Logger::infoLog(medio);

    item->setText(texto_item.c_str());

    lista->insertItem(0, item);
}

void DialogoConsultas::actualizar_listas() {
    aplicacion::GestorEntidades gestor;
    std::vector<modelo::Concepto*> conceptos_actuales = gestor.recuperar<modelo::Concepto>();

    std::for_each(conceptos_actuales.begin(), conceptos_actuales.end(), [=](modelo::Concepto* concepto) {
        // elimino las entidades de la lista
        modelo::Concepto* concepto_lista = nullptr;
        uint32_t i = 0;
        while (i != this->ui->lista_conceptos->count()) {

            concepto_lista = this->ui->lista_conceptos->item(i)->data(Qt::UserRole).value<modelo::Concepto*>();

            if (concepto->getId()->numero() == concepto_lista->getId()->numero()) {
                delete concepto;
                return;
            }
            i++;
        }

        i = 0;
        while (i != this->ui->lista_conceptos_en_consulta->count()) {

            concepto_lista = this->ui->lista_conceptos_en_consulta->item(i)->data(Qt::UserRole).value<modelo::Concepto*>();

            if (concepto->getId()->numero() == concepto_lista->getId()->numero()) {
                delete concepto;
                return;
            }
            i++;
        }

        // si no esta en ninguna de las listas de conceptos, entonces lo agrego.
        concepto->sumarReferencia();
        QListWidgetItem* item = new QListWidgetItem();

        QVariant data = QVariant::fromValue(concepto);
        item->setData(Qt::UserRole, data);

        std::string texto_item = aplicacion::Logger::infoLog(concepto);

        item->setText(texto_item.c_str());

        this->ui->lista_conceptos->insertItem(0, item);
    });

}

// obtener seleccionados de listas

void DialogoConsultas::sacarItemsSeleccionados(QListWidget * lista)
{
    QList<QListWidgetItem*> items = lista->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        delete lista->takeItem(lista->row(item));
    }
}

std::vector<modelo::Concepto*> DialogoConsultas::conceptosSeleccionados()
{
    std::vector<modelo::Concepto*> conceptos_seleccionados;

    // recupero los conceptos de la lista
    modelo::Concepto* concepto_lista = nullptr;
    for (unsigned int i = 0; i < ui->lista_conceptos_en_consulta->count(); i++)
    {
        concepto_lista = this->ui->lista_conceptos_en_consulta->item(i)->data(Qt::UserRole).value<modelo::Concepto*>();
        
        conceptos_seleccionados.push_back(concepto_lista);
    }

    return conceptos_seleccionados;
}

modelo::Periodo* DialogoConsultas::periodoSeleccionado()
{
    visualizador::modelo::Fecha * desde = new visualizador::modelo::Fecha(this->ui->dateedit_desde->date().day(), this->ui->dateedit_desde->date().month(), this->ui->dateedit_desde->date().year(), "desde_seleccionado");
    visualizador::modelo::Fecha * hasta = new visualizador::modelo::Fecha(this->ui->dateedit_hasta->date().day(), this->ui->dateedit_hasta->date().month(), this->ui->dateedit_hasta->date().year(), "hasta_seleccionado");

    return new modelo::Periodo(desde, hasta, "periodo_seleccionado");
}

std::vector<modelo::Medio*> DialogoConsultas::mediosSeleccionados()
{
    std::vector<modelo::Medio*> medios_seleccionados;

    // recupero los medios de la lista
    modelo::Medio* medio_lista = nullptr;
    for (unsigned int i = 0; i < ui->lista_medios_en_consulta->count(); i++)
    {
        medio_lista = this->ui->lista_medios_en_consulta->item(i)->data(Qt::UserRole).value<modelo::Medio*>();

        medios_seleccionados.push_back(medio_lista);
    }

    return medios_seleccionados;
}

void DialogoConsultas::conectar_componentes()
{
    QObject::connect(this->ui->btn_agregar_conceptos, &QPushButton::released, this, &DialogoConsultas::agregar_conceptos);
    QObject::connect(this->ui->btn_sacar_conceptos, &QPushButton::released, this, &DialogoConsultas::sacar_conceptos);

    QObject::connect(this->ui->btn_agregar_medios, &QPushButton::released, this, &DialogoConsultas::agregar_medios);
    QObject::connect(this->ui->btn_sacar_medios, &QPushButton::released, this, &DialogoConsultas::sacar_medios);

    QObject::connect(this->ui->btn_realizar_consulta, &QPushButton::released, this, &DialogoConsultas::recuperar_resultados);
    QObject::connect(this->ui->btn_cancelar, &QPushButton::released, this, &QWidget::close);

    QObject::connect(this->ui->checkbox_tendencia, &QCheckBox::stateChanged, this, &DialogoConsultas::habilitar_consulta);
    QObject::connect(this->ui->checkbox_tendencia, &QCheckBox::stateChanged, this, &DialogoConsultas::habilitar_tendencias);
    QObject::connect(this->ui->checkbox_conceptos, &QCheckBox::stateChanged, this, &DialogoConsultas::habilitar_conceptos);
    QObject::connect(this->ui->checkbox_conceptos, &QCheckBox::stateChanged, this, &DialogoConsultas::habilitar_consulta);

    QObject::connect(&(this->observador_realizar_consulta), &QFutureWatcher<void>::started, this, &DialogoConsultas::deshabilitar_opciones);
    QObject::connect(&(this->observador_realizar_consulta), &QFutureWatcher<void>::started, &(this->spinner), &WaitingSpinnerWidget::start);
    QObject::connect(&(this->observador_realizar_consulta), &QFutureWatcher<void>::finished, this, &DialogoConsultas::habilitar_opciones);
    QObject::connect(&(this->observador_realizar_consulta), &QFutureWatcher<void>::finished, this, &DialogoConsultas::mostrar_resultados);
    QObject::connect(&(this->observador_realizar_consulta), &QFutureWatcher<void>::finished, &(this->spinner), &WaitingSpinnerWidget::stop);
}

void DialogoConsultas::habilitar_opciones() {

    this->ui->opciones_consulta->setEnabled(true);
}

void DialogoConsultas::deshabilitar_opciones() {

    this->ui->opciones_consulta->setDisabled(true);
}

QMessageBox * DialogoConsultas::crearInformacionSinResultados()
{
    std::string texto = u8"No se encontró contenido para visualizar dentro del rango de fechas seleccionado.";
    visualizador::aplicacion::comunicacion::Informacion informacion_sin_resultados(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_sin_resultados, this);
}

QMessageBox * DialogoConsultas::crearInformacionNoHayMediosSeleccionados()
{
    std::string texto = u8"No hay medios seleccionados.";
    visualizador::aplicacion::comunicacion::Informacion informacion_sin_resultados(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_sin_resultados, this);
}

QMessageBox * DialogoConsultas::crearInformacionNoHayConceptosSeleccionados()
{
    std::string texto = u8"No hay conceptos seleccionados.";
    visualizador::aplicacion::comunicacion::Informacion informacion_sin_resultados(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_sin_resultados, this);
}
