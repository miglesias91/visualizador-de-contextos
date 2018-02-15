#include "DialogoConsultas.h"
#include "ui_DialogoConsultas.h"

using namespace visualizador;

DialogoConsultas::DialogoConsultas(QWidget *parent)
    : QWidget(parent), chart_view(NULL)
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

    this->descargarLista<modelo::Medio>(this->ui->lista_medios);
    this->descargarLista<modelo::Medio>(this->ui->lista_medios_en_consulta);

    this->descargarLista<modelo::Periodo>(this->ui->lista_periodos);

    this->descargarLista<modelo::Reporte>(this->ui->lista_reportes);
    // COMENTADA ESTA LINEA XQ HAY CARGADO POR DEFECTO 1 ITEM QUE NO SE PUEDE BORRAR. CUANDO SE SAQUE ESE ITEM SE TIENE Q VOLVER A USAR ESTA LINEA.
    // this->descargarLista<modelo::Reporte>(this->ui->lista_reportes_en_consulta);

    this->descargarLista<modelo::Seccion>(this->ui->lista_secciones);
    // COMENTADA ESTA LINEA XQ HAY CARGADO POR DEFECTO 1 ITEM QUE NO SE PUEDE BORRAR. CUANDO SE SAQUE ESE ITEM SE TIENE Q VOLVER A USAR ESTA LINEA.
    // this->descargarLista<modelo::Seccion>(this->ui->lista_secciones_en_consulta);

    delete this->chart_view;

    delete ui;
}

void DialogoConsultas::on_action_agregar_conceptos_triggered()
{
    std::vector<modelo::Concepto*> conceptos_seleccionados = this->itemsSeleccionados<modelo::Concepto>(this->ui->lista_conceptos);

    for (std::vector<modelo::Concepto*>::iterator it = conceptos_seleccionados.begin(); it != conceptos_seleccionados.end(); it++)
    {
        this->agregarConceptoALista(*it, this->ui->lista_conceptos_en_consulta);
    }

    this->sacarItemsSeleccionados(this->ui->lista_conceptos);
}

void DialogoConsultas::on_action_sacar_conceptos_triggered()
{
    std::vector<modelo::Concepto*> conceptos_seleccionados = this->itemsSeleccionados<modelo::Concepto>(this->ui->lista_conceptos_en_consulta);

    for (std::vector<modelo::Concepto*>::iterator it = conceptos_seleccionados.begin(); it != conceptos_seleccionados.end(); it++)
    {
        this->agregarConceptoALista(*it, this->ui->lista_conceptos);
    }

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

    this->ui->lineedit_etiqueta_periodo->setText(periodo_seleccionado->getEtiqueta().c_str());
    this->ui->dateedit_desde->setDate(fecha_desde);
    this->ui->dateedit_hasta->setDate(fecha_hasta);
}

void DialogoConsultas::on_action_resetear_periodo_triggered()
{
    this->ui->lineedit_etiqueta_periodo->clear();
    this->ui->dateedit_desde->setDate(QDate::currentDate());
    this->ui->dateedit_hasta->setDate(QDate::currentDate());
}

void DialogoConsultas::on_action_agregar_medios_triggered()
{
    std::vector<modelo::Medio*> medios_seleccionados = this->itemsSeleccionados<modelo::Medio>(this->ui->lista_medios);

    for (std::vector<modelo::Medio*>::iterator it = medios_seleccionados.begin(); it != medios_seleccionados.end(); it++)
    {
        this->agregarMedioALista(*it, this->ui->lista_medios_en_consulta);
    }

    this->sacarItemsSeleccionados(this->ui->lista_medios);
}

void DialogoConsultas::on_action_sacar_medios_triggered()
{
    std::vector<modelo::Medio*> medios_seleccionados = this->itemsSeleccionados<modelo::Medio>(this->ui->lista_medios_en_consulta);

    for (std::vector<modelo::Medio*>::iterator it = medios_seleccionados.begin(); it != medios_seleccionados.end(); it++)
    {
        this->agregarMedioALista(*it, this->ui->lista_medios);
    }

    this->sacarItemsSeleccionados(this->ui->lista_medios_en_consulta);
}

void DialogoConsultas::on_action_agregar_secciones_triggered()
{
    std::vector<modelo::Seccion*> secciones_seleccionados = this->itemsSeleccionados<modelo::Seccion>(this->ui->lista_secciones);

    for (std::vector<modelo::Seccion*>::iterator it = secciones_seleccionados.begin(); it != secciones_seleccionados.end(); it++)
    {
        this->agregarSeccionALista(*it, this->ui->lista_secciones_en_consulta);
    }
    
    this->sacarItemsSeleccionados(this->ui->lista_secciones);
}

void DialogoConsultas::on_action_sacar_secciones_triggered()
{
    std::vector<modelo::Seccion*> secciones_seleccionados = this->itemsSeleccionados<modelo::Seccion>(this->ui->lista_secciones_en_consulta);

    for (std::vector<modelo::Seccion*>::iterator it = secciones_seleccionados.begin(); it != secciones_seleccionados.end(); it++)
    {
        this->agregarSeccionALista(*it, this->ui->lista_secciones);
    }

    this->sacarItemsSeleccionados(this->ui->lista_secciones_en_consulta);
}

void DialogoConsultas::on_action_agregar_reportes_triggered()
{
    std::vector<modelo::Reporte*> reportes_seleccionados = this->itemsSeleccionados<modelo::Reporte>(this->ui->lista_reportes);

    for (std::vector<modelo::Reporte*>::iterator it = reportes_seleccionados.begin(); it != reportes_seleccionados.end(); it++)
    {
        this->agregarReporteALista(*it, this->ui->lista_reportes_en_consulta);
    }

    this->sacarItemsSeleccionados(this->ui->lista_reportes);
}

void DialogoConsultas::on_action_sacar_reportes_triggered()
{
    std::vector<modelo::Reporte*> reportes_seleccionados = this->itemsSeleccionados<modelo::Reporte>(this->ui->lista_reportes_en_consulta);

    for (std::vector<modelo::Reporte*>::iterator it = reportes_seleccionados.begin(); it != reportes_seleccionados.end(); it++)
    {
        this->agregarReporteALista(*it, this->ui->lista_reportes);
    }

    this->sacarItemsSeleccionados(this->ui->lista_reportes_en_consulta);
}

void DialogoConsultas::on_action_realizar_consulta_y_cerrar_triggered()
{
    QtCharts::QBarSeries *barseries = new QtCharts::QBarSeries();

    QtCharts::QBarSet * set0 = new QtCharts::QBarSet("Jane");
    *set0 << 1 << 2 << 3 << 4 << 5 << 6;
    barseries->append(set0);

    QtCharts::QBarSet * set1 = new QtCharts::QBarSet("John");
    *set1 << 5 << 0 << 0 << 4 << 0 << 7;
    barseries->append(set1);

    QtCharts::QBarSet * set2 = new QtCharts::QBarSet("Axel");
    *set2 << 3 << 5 << 8 << 13 << 8 << 5;
    barseries->append(set2);

    QtCharts::QBarSet * set3 = new QtCharts::QBarSet("Mary");
    *set3 << 5 << 6 << 7 << 3 << 4 << 5;
    barseries->append(set3);

    QtCharts::QBarSet * set4 = new QtCharts::QBarSet("Sam");
    *set4 << 9 << 7 << 5 << 3 << 1 << 2;
    barseries->append(set4);

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(barseries);
    chart->setTitle("Line and barchart example");

    QStringList categories;
    categories << "Jan" << "Feb" << "Mar" << "Apr" << "May" << "Jun";
    QtCharts::QBarCategoryAxis *axisX = new QtCharts::QBarCategoryAxis();
    axisX->append(categories);
    chart->setAxisX(axisX, barseries);
    axisX->setRange(QString("Jan"), QString("Jun"));

    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
    chart->setAxisY(axisY, barseries);
    axisY->setRange(0, 20);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    
    this->chart_view = new QtCharts::QChartView(chart);
    this->chart_view->setRenderHint(QPainter::Antialiasing);

    chart_view->show();

    // this->close();
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

    this->ui->lista_conceptos->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoConsultas::agregarConceptoALista(visualizador::modelo::Concepto * concepto, QListWidget * lista)
{
    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(concepto);
    item->setData(Qt::UserRole, data);

    std::vector<modelo::Termino*> terminos = concepto->getTerminos();

    std::string texto_item = concepto->getEtiqueta() + " - ";
    if (false == terminos.empty())
    {
        texto_item += (*terminos.begin())->getValor();
        for (std::vector<modelo::Termino*>::iterator it = terminos.begin() + 1; it != terminos.end(); it++)
        {
            texto_item += ", " + (*it)->getValor();
        }
    }

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

    // this->ui->lista_periodos->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoConsultas::agregarPeriodoALista(visualizador::modelo::Periodo * periodo, QListWidget * lista)
{
    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(periodo);
    item->setData(Qt::UserRole, data);

    std::string texto_item = periodo->getEtiqueta() + " - [ " + periodo->getDesde()->getStringDDmesAAAA(" ") + " , " + periodo->getHasta()->getStringDDmesAAAA(" ") + " ]";

    item->setText(texto_item.c_str());

    lista->insertItem(0, item);
}

void DialogoConsultas::cargarListaMedios()
{
    aplicacion::GestorEntidades gestor;
    std::vector<modelo::Medio*> medios_actuales = gestor.recuperar<modelo::Medio>();
    for (std::vector<modelo::Medio*>::iterator it = medios_actuales.begin(); it != medios_actuales.end(); it++)
    {
        (*it)->sumarReferencia();
        this->agregarMedioALista(*it, this->ui->lista_medios);
    }

    this->ui->lista_medios->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoConsultas::agregarMedioALista(visualizador::modelo::Medio * medio, QListWidget * lista)
{
    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(medio);
    item->setData(Qt::UserRole, data);

    std::string texto_item = medio->getEtiqueta();

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
    return std::vector<modelo::Concepto*>();
}

std::vector<modelo::Periodo*> DialogoConsultas::periodosSeleccionados()
{
    return std::vector<modelo::Periodo*>();
}

std::vector<modelo::Medio*> DialogoConsultas::mediosSeleccionados()
{
    return std::vector<modelo::Medio*>();
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

void DialogoConsultas::descargarListaConceptos()
{
    QListWidgetItem* item = nullptr;

    // elimino los conceptos de la lista
    modelo::Concepto* concepto_lista = nullptr;
    unsigned int count = ui->lista_conceptos->count();
    while (0 != ui->lista_conceptos->count())
    {
        count = ui->lista_conceptos->count();

        concepto_lista = this->ui->lista_conceptos->item(0)->data(Qt::UserRole).value<modelo::Concepto*>();

        if (0 == concepto_lista->restarReferencia())
        {
            delete concepto_lista;
        }

        item = this->ui->lista_conceptos->takeItem(0);
        delete item;
    }
}

void DialogoConsultas::descargarListaPeriodos()
{
    QListWidgetItem* item = nullptr;

    // elimino los periodos de la lista
    modelo::Periodo* periodo_lista = nullptr;
    unsigned int count = ui->lista_periodos->count();
    while (0 != ui->lista_periodos->count())
    {
        count = ui->lista_periodos->count();

        periodo_lista = this->ui->lista_periodos->item(0)->data(Qt::UserRole).value<modelo::Periodo*>();

        if (0 == periodo_lista->restarReferencia())
        {
            delete periodo_lista;
        }

        item = this->ui->lista_periodos->takeItem(0);
        delete item;
    }
}

void DialogoConsultas::descargarListaMedios()
{
    QListWidgetItem* item = nullptr;

    // elimino los medios de la lista
    modelo::Medio* medio_lista = nullptr;
    unsigned int count = ui->lista_medios->count();
    while (0 != ui->lista_medios->count())
    {
        count = ui->lista_medios->count();

        medio_lista = this->ui->lista_medios->item(0)->data(Qt::UserRole).value<modelo::Medio*>();

        if (0 == medio_lista->restarReferencia())
        {
            delete medio_lista;
        }

        item = this->ui->lista_medios->takeItem(0);
        delete item;
    }
}

void DialogoConsultas::descargarListaSecciones()
{
    QListWidgetItem* item = nullptr;

    // elimino las secciones de la lista
    modelo::Seccion* seccion_lista = nullptr;
    unsigned int count = ui->lista_secciones->count();
    while (0 != ui->lista_secciones->count())
    {
        count = ui->lista_secciones->count();

        seccion_lista = this->ui->lista_secciones->item(0)->data(Qt::UserRole).value<modelo::Seccion*>();

        if (0 == seccion_lista->restarReferencia())
        {
            delete seccion_lista;
        }

        item = this->ui->lista_secciones->takeItem(0);
        delete item;
    }
}

void DialogoConsultas::descargarListaReportes()
{
    QListWidgetItem* item = nullptr;

    // elimino los reportes de la lista
    modelo::Reporte* reporte_lista = nullptr;
    unsigned int count = ui->lista_reportes->count();
    while (0 != ui->lista_reportes->count())
    {
        count = ui->lista_reportes->count();

        reporte_lista = this->ui->lista_reportes->item(0)->data(Qt::UserRole).value<modelo::Reporte*>();

        if (0 == reporte_lista->restarReferencia())
        {
            delete reporte_lista;
        }

        item = this->ui->lista_reportes->takeItem(0);
        delete item;
    }
}
