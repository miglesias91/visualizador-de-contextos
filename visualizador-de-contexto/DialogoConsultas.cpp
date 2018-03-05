#include "DialogoConsultas.h"
#include "ui_DialogoConsultas.h"

// scraping
#include <scraping/include/GestorMedios.h>
#include <aplicacion/include/Logger.h>

// aplicacion
#include <aplicacion/include/GestorDatosScraping.h>

using namespace visualizador;

DialogoConsultas::DialogoConsultas(QWidget *parent)
    : QWidget(parent), grafico_fuerza_en_noticia(NULL)
{
    ui = new Ui::DialogoConsultas();
    ui->setupUi(this);
 
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

    this->descargarLista<modelo::MedioTwitter>(this->ui->lista_medios);
    this->descargarLista<modelo::MedioTwitter>(this->ui->lista_medios_en_consulta);
    aplicacion::Logger::info("Medios twitter descargados.");

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

void DialogoConsultas::on_action_agregar_conceptos_triggered()
{
    std::vector<modelo::Concepto*> conceptos_seleccionados = this->itemsSeleccionados<modelo::Concepto>(this->ui->lista_conceptos);

    for (std::vector<modelo::Concepto*>::iterator it = conceptos_seleccionados.begin(); it != conceptos_seleccionados.end(); it++)
    {
        this->agregarConceptoALista(*it, this->ui->lista_conceptos_en_consulta);
    }

    aplicacion::Logger::info(std::to_string(conceptos_seleccionados.size()) + " conceptos agregados a la consulta.");

    this->sacarItemsSeleccionados(this->ui->lista_conceptos);
}

void DialogoConsultas::on_action_sacar_conceptos_triggered()
{
    std::vector<modelo::Concepto*> conceptos_seleccionados = this->itemsSeleccionados<modelo::Concepto>(this->ui->lista_conceptos_en_consulta);

    for (std::vector<modelo::Concepto*>::iterator it = conceptos_seleccionados.begin(); it != conceptos_seleccionados.end(); it++)
    {
        this->agregarConceptoALista(*it, this->ui->lista_conceptos);
    }

    aplicacion::Logger::info(std::to_string(conceptos_seleccionados.size()) + " conceptos sacados de la consulta.");

    this->sacarItemsSeleccionados(this->ui->lista_conceptos_en_consulta);
}

void DialogoConsultas::on_action_setear_periodo_triggered()
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

void DialogoConsultas::on_action_resetear_periodo_triggered()
{
    this->ui->lineedit_etiqueta_periodo->clear();
    this->ui->dateedit_desde->setDate(QDate::currentDate());
    this->ui->dateedit_hasta->setDate(QDate::currentDate());
    
    aplicacion::Logger::info("Periodo reseteado.");
}

void DialogoConsultas::on_action_agregar_medios_triggered()
{
    std::vector<modelo::MedioTwitter*> medios_seleccionados = this->itemsSeleccionados<modelo::MedioTwitter>(this->ui->lista_medios);

    for (std::vector<modelo::MedioTwitter*>::iterator it = medios_seleccionados.begin(); it != medios_seleccionados.end(); it++)
    {
        this->agregarMedioALista(*it, this->ui->lista_medios_en_consulta);
    }

    aplicacion::Logger::info(std::to_string(medios_seleccionados.size()) + " medios twitter agregados a la consulta.");

    this->sacarItemsSeleccionados(this->ui->lista_medios);
}

void DialogoConsultas::on_action_sacar_medios_triggered()
{
    std::vector<modelo::MedioTwitter*> medios_seleccionados = this->itemsSeleccionados<modelo::MedioTwitter>(this->ui->lista_medios_en_consulta);

    for (std::vector<modelo::MedioTwitter*>::iterator it = medios_seleccionados.begin(); it != medios_seleccionados.end(); it++)
    {
        this->agregarMedioALista(*it, this->ui->lista_medios);
    }

    aplicacion::Logger::info(std::to_string(medios_seleccionados.size()) + " medios twitter sacados de la consulta.");

    this->sacarItemsSeleccionados(this->ui->lista_medios_en_consulta);
}

void DialogoConsultas::on_action_agregar_secciones_triggered()
{
    std::vector<modelo::Seccion*> secciones_seleccionados = this->itemsSeleccionados<modelo::Seccion>(this->ui->lista_secciones);

    for (std::vector<modelo::Seccion*>::iterator it = secciones_seleccionados.begin(); it != secciones_seleccionados.end(); it++)
    {
        this->agregarSeccionALista(*it, this->ui->lista_secciones_en_consulta);
    }
    
    aplicacion::Logger::info(std::to_string(secciones_seleccionados.size()) + " secciones agregadas a la consulta.");

    this->sacarItemsSeleccionados(this->ui->lista_secciones);
}

void DialogoConsultas::on_action_sacar_secciones_triggered()
{
    std::vector<modelo::Seccion*> secciones_seleccionados = this->itemsSeleccionados<modelo::Seccion>(this->ui->lista_secciones_en_consulta);

    for (std::vector<modelo::Seccion*>::iterator it = secciones_seleccionados.begin(); it != secciones_seleccionados.end(); it++)
    {
        this->agregarSeccionALista(*it, this->ui->lista_secciones);
    }

    aplicacion::Logger::info(std::to_string(secciones_seleccionados.size()) + " secciones sacadas de la consulta.");

    this->sacarItemsSeleccionados(this->ui->lista_secciones_en_consulta);
}

void DialogoConsultas::on_action_agregar_reportes_triggered()
{
    std::vector<modelo::Reporte*> reportes_seleccionados = this->itemsSeleccionados<modelo::Reporte>(this->ui->lista_reportes);

    for (std::vector<modelo::Reporte*>::iterator it = reportes_seleccionados.begin(); it != reportes_seleccionados.end(); it++)
    {
        this->agregarReporteALista(*it, this->ui->lista_reportes_en_consulta);
    }

    aplicacion::Logger::info(std::to_string(reportes_seleccionados.size()) + " reportes agregados a la consulta.");

    this->sacarItemsSeleccionados(this->ui->lista_reportes);
}

void DialogoConsultas::on_action_sacar_reportes_triggered()
{
    std::vector<modelo::Reporte*> reportes_seleccionados = this->itemsSeleccionados<modelo::Reporte>(this->ui->lista_reportes_en_consulta);

    for (std::vector<modelo::Reporte*>::iterator it = reportes_seleccionados.begin(); it != reportes_seleccionados.end(); it++)
    {
        this->agregarReporteALista(*it, this->ui->lista_reportes);
    }

    aplicacion::Logger::info(std::to_string(reportes_seleccionados.size()) + " reportes sacados de la consulta.");

    this->sacarItemsSeleccionados(this->ui->lista_reportes_en_consulta);
}

void DialogoConsultas::on_action_realizar_consulta_y_cerrar_triggered()
{
    aplicacion::GestorDatosScraping gestor_datos;

    herramientas::utiles::Fecha desde(this->ui->dateedit_desde->date().day(), this->ui->dateedit_desde->date().month(), this->ui->dateedit_desde->date().year());
    herramientas::utiles::Fecha hasta(this->ui->dateedit_hasta->date().day(), this->ui->dateedit_hasta->date().month(), this->ui->dateedit_hasta->date().year());
    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados = gestor_datos.recuperarResultadosEntreRangoDeFechas(desde, hasta);

    aplicacion::Logger::info("Realizando consulta: " + std::to_string(resultados.size()) + " resultados recuperados para el rango [ " + desde.getStringDDmesAAAA() + " - " + hasta.getStringDDmesAAAA() + " ].");

    std::vector<modelo::MedioTwitter*> medios_seleccionados = this->mediosSeleccionados();
    std::vector<modelo::Concepto*> conceptos_seleccionados = this->conceptosSeleccionados();

    std::vector<graficos::modelo::Individuo*> individuos;

    for (std::vector<modelo::Concepto*>::iterator it_conceptos = conceptos_seleccionados.begin(); it_conceptos != conceptos_seleccionados.end(); it_conceptos++)
    {
        std::vector<double> datos_individuo;
        for (std::vector<modelo::MedioTwitter*>::iterator it_medios = medios_seleccionados.begin(); it_medios != medios_seleccionados.end(); it_medios++)
        {
            float fuerza_concepto_en_medio = 0.0f;
            for (std::vector<scraping::preparacion::ResultadoAnalisisDiario*>::iterator it_resultados = resultados.begin(); it_resultados != resultados.end(); it_resultados++)
            {
                scraping::preparacion::ResultadoAnalisisMedio* resultado_medio = (*it_resultados)->getResultadoMedio((*it_medios)->getCuentaAScrapear()->getId()->numero());

                if (NULL == resultado_medio)
                {
                    continue;
                }

                std::vector<modelo::Termino*> terminos_a_analizar = (*it_conceptos)->getTerminos();
                for (std::vector<modelo::Termino*>::iterator it_terminos = terminos_a_analizar.begin(); it_terminos != terminos_a_analizar.end(); it_terminos++)
                {
                    float fuerza_termino = resultado_medio->getResultadoFuerzaEnNoticia()->getFuerza((*it_terminos)->getValor());
                    fuerza_concepto_en_medio += fuerza_termino;
                }
            }
            datos_individuo.push_back(fuerza_concepto_en_medio);
        }
        graficos::modelo::Individuo * nuevo_individuo = new graficos::modelo::Individuo((*it_conceptos)->getEtiqueta(), datos_individuo);
        individuos.push_back(nuevo_individuo);
    }

    std::vector<std::string> categorias;
    for (std::vector<modelo::MedioTwitter*>::iterator it_medios = medios_seleccionados.begin(); it_medios != medios_seleccionados.end(); it_medios++)
    {
        categorias.push_back((*it_medios)->getEtiqueta());
    }

    if (NULL != this->grafico_fuerza_en_noticia)
    {
        delete this->grafico_fuerza_en_noticia;
    }

    this->grafico_fuerza_en_noticia = new graficos::GraficoDeBarras(individuos, categorias, 0.0f, 200.0f, u8"Aparición de conceptos en medios, desde " + desde.getStringDDMMAAAA("/") + " hasta " + hasta.getStringDDMMAAAA("/"));
    this->grafico_fuerza_en_noticia->mostrar();

    for (std::vector<scraping::preparacion::ResultadoAnalisisDiario*>::iterator it = resultados.begin(); it != resultados.end(); it++)
    {
        delete *it;
    }
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
    std::vector<modelo::MedioTwitter*> medios_actuales = gestor_entidades.recuperar<modelo::MedioTwitter>();

    for (std::vector<modelo::MedioTwitter*>::iterator it = medios_actuales.begin(); it != medios_actuales.end(); it++)
    {
        (*it)->sumarReferencia();
        this->agregarMedioALista(*it, this->ui->lista_medios);
    }

    aplicacion::Logger::info(std::to_string(medios_actuales.size()) + " medios twitter cargados.");

    this->ui->lista_medios->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoConsultas::agregarMedioALista(visualizador::modelo::MedioTwitter * medio_twitter, QListWidget * lista)
{
    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(medio_twitter);
    item->setData(Qt::UserRole, data);

    std::string texto_item = aplicacion::Logger::infoLog(medio_twitter);

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

std::vector<modelo::MedioTwitter*> DialogoConsultas::mediosSeleccionados()
{
    std::vector<modelo::MedioTwitter*> medios_seleccionados;

    // recupero los medios de la lista
    modelo::MedioTwitter* medio_lista = nullptr;
    for (unsigned int i = 0; i < ui->lista_medios_en_consulta->count(); i++)
    {
        medio_lista = this->ui->lista_medios_en_consulta->item(i)->data(Qt::UserRole).value<modelo::MedioTwitter*>();

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

// descargar listas
//
//void DialogoConsultas::descargarListaConceptos()
//{
//    QListWidgetItem* item = nullptr;
//
//    // elimino los conceptos de la lista
//    modelo::Concepto* concepto_lista = nullptr;
//    unsigned int count = ui->lista_conceptos->count();
//    while (0 != ui->lista_conceptos->count())
//    {
//        count = ui->lista_conceptos->count();
//
//        concepto_lista = this->ui->lista_conceptos->item(0)->data(Qt::UserRole).value<modelo::Concepto*>();
//
//        if (0 == concepto_lista->restarReferencia())
//        {
//            delete concepto_lista;
//        }
//
//        item = this->ui->lista_conceptos->takeItem(0);
//        delete item;
//    }
//
//    aplicacion::Logger::info("Conceptos descargados.");
//}
//
//void DialogoConsultas::descargarListaPeriodos()
//{
//    QListWidgetItem* item = nullptr;
//
//    // elimino los periodos de la lista
//    modelo::Periodo* periodo_lista = nullptr;
//    unsigned int count = ui->lista_periodos->count();
//    while (0 != ui->lista_periodos->count())
//    {
//        count = ui->lista_periodos->count();
//
//        periodo_lista = this->ui->lista_periodos->item(0)->data(Qt::UserRole).value<modelo::Periodo*>();
//
//        if (0 == periodo_lista->restarReferencia())
//        {
//            delete periodo_lista;
//        }
//
//        item = this->ui->lista_periodos->takeItem(0);
//        delete item;
//    }
//
//    aplicacion::Logger::info("Periodos descargados.");
//}
//
//void DialogoConsultas::descargarListaMedios()
//{
//    QListWidgetItem* item = nullptr;
//
//    // elimino los medios de la lista
//    modelo::MedioTwitter* medio_lista = nullptr;
//    unsigned int count = ui->lista_medios->count();
//    while (0 != ui->lista_medios->count())
//    {
//        count = ui->lista_medios->count();
//
//        medio_lista = this->ui->lista_medios->item(0)->data(Qt::UserRole).value<modelo::MedioTwitter*>();
//
//        if (0 == medio_lista->restarReferencia())
//        {
//            delete medio_lista;
//        }
//
//        item = this->ui->lista_medios->takeItem(0);
//        delete item;
//    }
//
//    aplicacion::Logger::info("Medios descargados.");
//}
//
//void DialogoConsultas::descargarListaSecciones()
//{
//    QListWidgetItem* item = nullptr;
//
//    // elimino las secciones de la lista
//    modelo::Seccion* seccion_lista = nullptr;
//    unsigned int count = ui->lista_secciones->count();
//    while (0 != ui->lista_secciones->count())
//    {
//        count = ui->lista_secciones->count();
//
//        seccion_lista = this->ui->lista_secciones->item(0)->data(Qt::UserRole).value<modelo::Seccion*>();
//
//        if (0 == seccion_lista->restarReferencia())
//        {
//            delete seccion_lista;
//        }
//
//        item = this->ui->lista_secciones->takeItem(0);
//        delete item;
//    }
//
//    aplicacion::Logger::info("Secciones descargadas.");
//}
//
//void DialogoConsultas::descargarListaReportes()
//{
//    QListWidgetItem* item = nullptr;
//
//    // elimino los reportes de la lista
//    modelo::Reporte* reporte_lista = nullptr;
//    unsigned int count = ui->lista_reportes->count();
//    while (0 != ui->lista_reportes->count())
//    {
//        count = ui->lista_reportes->count();
//
//        reporte_lista = this->ui->lista_reportes->item(0)->data(Qt::UserRole).value<modelo::Reporte*>();
//
//        if (0 == reporte_lista->restarReferencia())
//        {
//            delete reporte_lista;
//        }
//
//        item = this->ui->lista_reportes->takeItem(0);
//        delete item;
//    }
//
//    aplicacion::Logger::info("Reportes descargados.");
//}
