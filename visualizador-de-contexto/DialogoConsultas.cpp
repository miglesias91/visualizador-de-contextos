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
    : QWidget(parent), grafico_fuerza_en_noticia(NULL), dialogo_resultados(nullptr)
{
    ui = new Ui::DialogoConsultas();
    ui->setupUi(this);

    this->ui->lbl_etiqueta->setVisible(false);
    this->ui->lineedit_etiqueta_periodo->setVisible(false);
    this->ui->progressbar_realizar_consulta->setVisible(false);

    this->conectar_componentes();

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->cargarListaConceptos();
    this->cargarListaMedios();
    this->cargarListaPeriodos();
    this->cargarListaReportes();
    this->cargarListaSecciones();
}

DialogoConsultas::~DialogoConsultas()
{
    this->descargarLista<modelo::Concepto>(this->ui->lista_conceptos);
    this->descargarLista<modelo::Concepto>(this->ui->lista_conceptos_en_consulta);
    aplicacion::Logger::info("Conceptos descargados.");

    this->descargarLista<modelo::Medio>(this->ui->lista_medios);
    this->descargarLista<modelo::Medio>(this->ui->lista_medios_en_consulta);
    aplicacion::Logger::info("Medios descargados.");

    this->descargarLista<modelo::Periodo>(this->ui->lista_periodos);
    aplicacion::Logger::info("Periodos descargados.");

    this->descargarLista<modelo::Reporte>(this->ui->lista_reportes);
    // COMENTADA ESTA LINEA XQ HAY CARGADO POR DEFECTO 1 ITEM QUE NO SE PUEDE BORRAR. CUANDO SE SAQUE ESE ITEM SE TIENE Q VOLVER A USAR ESTA LINEA.
    // this->descargarLista<modelo::Reporte>(this->ui->lista_reportes_en_consulta);
    aplicacion::Logger::info("Reportes descargados.");

    this->descargarLista<modelo::Seccion>(this->ui->lista_secciones);
    // COMENTADA ESTA LINEA XQ HAY CARGADO POR DEFECTO 1 ITEM QUE NO SE PUEDE BORRAR. CUANDO SE SAQUE ESE ITEM SE TIENE Q VOLVER A USAR ESTA LINEA.
    // this->descargarLista<modelo::Seccion>(this->ui->lista_secciones_en_consulta);
    aplicacion::Logger::info("Secciones descargados.");

    if (NULL != this->grafico_fuerza_en_noticia)
    {
        delete this->grafico_fuerza_en_noticia;
    }

    delete ui;
}

void DialogoConsultas::hideEvent(QHideEvent *) {
    emit se_cerro();
}

void DialogoConsultas::showEvent(QShowEvent *) {
    emit se_abrio();
}

void DialogoConsultas::guardar() {

    this->close();
}

void DialogoConsultas::cerrar() {

    this->close();
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

void DialogoConsultas::setear_periodo()
{
    // selecciono el 1ero xq ya se que solo puedo haber elegido uno.
    std::vector<modelo::Periodo*> periodos_seleccionados = this->itemsSeleccionados<modelo::Periodo>(this->ui->lista_periodos);

    if (0 == periodos_seleccionados.size())
    {// si no se selecciono ninguno entonces salgo.
        return;
    }

    modelo::Periodo* periodo_seleccionado = periodos_seleccionados[0];

    std::string etiqueta_fecha = periodo_seleccionado->getEtiqueta();
    QDate fecha_desde(periodo_seleccionado->getDesde()->getAnio(), periodo_seleccionado->getDesde()->getMes(), periodo_seleccionado->getDesde()->getDia());
    QDate fecha_hasta(periodo_seleccionado->getHasta()->getAnio(), periodo_seleccionado->getHasta()->getMes(), periodo_seleccionado->getHasta()->getDia());

    aplicacion::Logger::info(periodo_seleccionado->getEtiqueta() + " periodo seteado para la consulta.");

    this->ui->lineedit_etiqueta_periodo->setText(periodo_seleccionado->getEtiqueta().c_str());
    this->ui->dateedit_desde->setDate(fecha_desde);
    this->ui->dateedit_hasta->setDate(fecha_hasta);
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

void DialogoConsultas::agregar_secciones()
{
    std::vector<modelo::Seccion*> secciones_seleccionados = this->itemsSeleccionados<modelo::Seccion>(this->ui->lista_secciones);

    for (std::vector<modelo::Seccion*>::iterator it = secciones_seleccionados.begin(); it != secciones_seleccionados.end(); it++)
    {
        this->agregarSeccionALista(*it, this->ui->lista_secciones_en_consulta);
    }
    
    aplicacion::Logger::info(std::to_string(secciones_seleccionados.size()) + " secciones agregadas a la consulta.");

    this->sacarItemsSeleccionados(this->ui->lista_secciones);
}

void DialogoConsultas::sacar_secciones()
{
    std::vector<modelo::Seccion*> secciones_seleccionados = this->itemsSeleccionados<modelo::Seccion>(this->ui->lista_secciones_en_consulta);

    for (std::vector<modelo::Seccion*>::iterator it = secciones_seleccionados.begin(); it != secciones_seleccionados.end(); it++)
    {
        this->agregarSeccionALista(*it, this->ui->lista_secciones);
    }

    aplicacion::Logger::info(std::to_string(secciones_seleccionados.size()) + " secciones sacadas de la consulta.");

    this->sacarItemsSeleccionados(this->ui->lista_secciones_en_consulta);
}

void DialogoConsultas::agregar_reportes()
{
    std::vector<modelo::Reporte*> reportes_seleccionados = this->itemsSeleccionados<modelo::Reporte>(this->ui->lista_reportes);

    for (std::vector<modelo::Reporte*>::iterator it = reportes_seleccionados.begin(); it != reportes_seleccionados.end(); it++)
    {
        this->agregarReporteALista(*it, this->ui->lista_reportes_en_consulta);
    }

    aplicacion::Logger::info(std::to_string(reportes_seleccionados.size()) + " reportes agregados a la consulta.");

    this->sacarItemsSeleccionados(this->ui->lista_reportes);
}

void DialogoConsultas::sacar_reportes()
{
    std::vector<modelo::Reporte*> reportes_seleccionados = this->itemsSeleccionados<modelo::Reporte>(this->ui->lista_reportes_en_consulta);

    for (std::vector<modelo::Reporte*>::iterator it = reportes_seleccionados.begin(); it != reportes_seleccionados.end(); it++)
    {
        this->agregarReporteALista(*it, this->ui->lista_reportes);
    }

    aplicacion::Logger::info(std::to_string(reportes_seleccionados.size()) + " reportes sacados de la consulta.");

    this->sacarItemsSeleccionados(this->ui->lista_reportes_en_consulta);
}

void DialogoConsultas::recuperar_resultados() {

    QFuture<void> tarea_exportacion = QtConcurrent::run([this]() {

        std::vector<modelo::Medio*> medios_seleccionados = this->mediosSeleccionados();
        std::vector<modelo::Concepto*> conceptos_seleccionados = this->conceptosSeleccionados();

        aplicacion::GestorResultadosDiarios gestor_datos;

        herramientas::utiles::Fecha desde(this->ui->dateedit_desde->date().day(), this->ui->dateedit_desde->date().month(), this->ui->dateedit_desde->date().year());
        herramientas::utiles::Fecha hasta(this->ui->dateedit_hasta->date().day(), this->ui->dateedit_hasta->date().month(), this->ui->dateedit_hasta->date().year());

        if (medios_seleccionados.empty()) {
            QMessageBox * informacion_no_hay_medios_seleccionados = this->crearInformacionNoHayMediosSeleccionados();
            informacion_no_hay_medios_seleccionados->exec();

            delete informacion_no_hay_medios_seleccionados;

            return;
        }

        if (conceptos_seleccionados.empty()) {
            QMessageBox * informacion_no_hay_conceptos_seleccionados = this->crearInformacionNoHayConceptosSeleccionados();
            informacion_no_hay_conceptos_seleccionados->exec();

            delete informacion_no_hay_conceptos_seleccionados;

            return;
        }

        gestor_datos.recuperarResultados(desde, hasta, medios_seleccionados, conceptos_seleccionados, &(this->resultados_filtrados));
    });

    this->observador_realizar_consulta.setFuture(tarea_exportacion);

    //aplicacion::GestorConsultas gestor_consultas;
    //gestor_consultas.setMedios(medios_seleccionados);
    //gestor_consultas.setConceptos(conceptos_seleccionados);
    //gestor_consultas.setData(resultados);

    //std::vector<graficos::modelo::Individuo*> individuos;
    //std::vector<graficos::modelo::Categoria*> categorias;
    //gestor_consultas.fuerzaDeConceptosEnMedios(individuos, categorias);

    //if (NULL != this->grafico_fuerza_en_noticia)
    //{
    //    delete this->grafico_fuerza_en_noticia;
    //}

    //this->grafico_fuerza_en_noticia = new graficos::GraficoDeBarras(individuos, categorias, 0.0f, 200.0f, u8"Aparición de conceptos en medios, desde " + desde.getStringDDMMAAAA("/") + " hasta " + hasta.getStringDDMMAAAA("/"));
    //this->grafico_fuerza_en_noticia->mostrar();

    //for (std::vector<scraping::preparacion::ResultadoAnalisisDiario*>::iterator it = resultados.begin(); it != resultados.end(); it++)
    //{
    //    delete *it;
    //}

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

    this->dialogo_resultados = new DialogoResultadoConsulta(medios_seleccionados, conceptos_seleccionados, this->resultados_filtrados);
    this->ui->opciones_consulta->addTab(dialogo_resultados, ("consulta_" + herramientas::utiles::Fecha::getFechaActual().getStringAAAAMMDDHHmmSS()).c_str());
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

void DialogoConsultas::cargarListaPeriodos()
{
    aplicacion::GestorEntidades gestor;
    std::vector<modelo::Periodo*> periodos_actuales = gestor.recuperar<modelo::Periodo>();
    for (std::vector<modelo::Periodo*>::iterator it = periodos_actuales.begin(); it != periodos_actuales.end(); it++)
    {
        (*it)->sumarReferencia();
        this->agregarPeriodoALista(*it, this->ui->lista_periodos);
    }

    aplicacion::Logger::info(std::to_string(periodos_actuales.size()) + " periodos cargados.");

    // this->ui->lista_periodos->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoConsultas::agregarPeriodoALista(visualizador::modelo::Periodo * periodo, QListWidget * lista)
{
    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(periodo);
    item->setData(Qt::UserRole, data);

    std::string texto_item = aplicacion::Logger::infoLog(periodo);

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
    std::for_each(medios_portales_actuales.begin(), medios_portales_actuales.end(), [=](modelo::MedioPortalNoticias * portal) {
        std::vector<modelo::subseccion*> secciones = portal->subsecciones();
        std::for_each(secciones.begin(), secciones.end(), [=](modelo::subseccion * subseccion_portal) {
            this->agregarMedioALista(subseccion_portal, this->ui->lista_medios);
        });
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

void DialogoConsultas::cargarListaSecciones()
{
    aplicacion::GestorEntidades gestor;
    std::vector<modelo::Seccion*> secciones_actuales = gestor.recuperar<modelo::Seccion>();
    for (std::vector<modelo::Seccion*>::iterator it = secciones_actuales.begin(); it != secciones_actuales.end(); it++)
    {
        (*it)->sumarReferencia();
        this->agregarSeccionALista(*it, this->ui->lista_secciones);
    }

    aplicacion::Logger::info(std::to_string(secciones_actuales.size()) + " secciones cargadas.");

    this->ui->lista_secciones->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoConsultas::agregarSeccionALista(visualizador::modelo::Seccion * seccion, QListWidget * lista)
{
    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(seccion);
    item->setData(Qt::UserRole, data);

    std::string texto_item = seccion->getEtiqueta();

    item->setText(texto_item.c_str());

    lista->insertItem(0, item);
}

void DialogoConsultas::cargarListaReportes()
{
    aplicacion::GestorEntidades gestor;
    std::vector<modelo::Reporte*> reportes_actuales = gestor.recuperar<modelo::Reporte>();
    for (std::vector<modelo::Reporte*>::iterator it = reportes_actuales.begin(); it != reportes_actuales.end(); it++)
    {
        (*it)->sumarReferencia();
        this->agregarReporteALista(*it, this->ui->lista_reportes);
    }

    aplicacion::Logger::info(std::to_string(reportes_actuales.size()) + " reportes cargados.");

    this->ui->lista_reportes->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoConsultas::agregarReporteALista(visualizador::modelo::Reporte * reporte, QListWidget * lista)
{
    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(reporte);
    item->setData(Qt::UserRole, data);

    std::string texto_item = reporte->getEtiqueta();

    item->setText(texto_item.c_str());

    lista->insertItem(0, item);
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

std::vector<modelo::Seccion*> DialogoConsultas::seccionesSeleccionados()
{
    return std::vector<modelo::Seccion*>();
}

std::vector<modelo::Reporte*> DialogoConsultas::reportesSeleccionados()
{
    return std::vector<modelo::Reporte*>();
}

void DialogoConsultas::conectar_componentes()
{
    QObject::connect(this->ui->btn_agregar_conceptos, &QPushButton::released, this, &DialogoConsultas::agregar_conceptos);
    QObject::connect(this->ui->btn_sacar_conceptos, &QPushButton::released, this, &DialogoConsultas::sacar_conceptos);

    QObject::connect(this->ui->btn_agregar_medios, &QPushButton::released, this, &DialogoConsultas::agregar_medios);
    QObject::connect(this->ui->btn_sacar_medios, &QPushButton::released, this, &DialogoConsultas::sacar_medios);

    QObject::connect(this->ui->btn_realizar_consulta, &QPushButton::released, this, &DialogoConsultas::recuperar_resultados);
    QObject::connect(this->ui->btn_cancelar, &QPushButton::released, this, &QWidget::close);

    QObject::connect(&(this->observador_realizar_consulta), &QFutureWatcher<void>::started, this, &DialogoConsultas::deshabilitar_opciones);
    QObject::connect(&(this->observador_realizar_consulta), &QFutureWatcher<void>::started, this->ui->progressbar_realizar_consulta, &QProgressBar::show);
    QObject::connect(&(this->observador_realizar_consulta), &QFutureWatcher<void>::finished, this, &DialogoConsultas::habilitar_opciones);
    QObject::connect(&(this->observador_realizar_consulta), &QFutureWatcher<void>::finished, this, &DialogoConsultas::mostrar_resultados);
    QObject::connect(&(this->observador_realizar_consulta), &QFutureWatcher<void>::finished, this->ui->progressbar_realizar_consulta, &QProgressBar::hide);
    QObject::connect(&(this->observador_realizar_consulta), &QFutureWatcher<void>::progressValueChanged, this->ui->progressbar_realizar_consulta, &QProgressBar::valueChanged);
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
    return comunicacion::FabricaMensajes::fabricar(&informacion_sin_resultados);
}

QMessageBox * DialogoConsultas::crearInformacionNoHayMediosSeleccionados()
{
    std::string texto = u8"No hay medios seleccionados.";
    visualizador::aplicacion::comunicacion::Informacion informacion_sin_resultados(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_sin_resultados);
}

QMessageBox * DialogoConsultas::crearInformacionNoHayConceptosSeleccionados()
{
    std::string texto = u8"No hay conceptos seleccionados.";
    visualizador::aplicacion::comunicacion::Informacion informacion_sin_resultados(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_sin_resultados);
}
