#include <visualizador-de-contexto/include/GraficoDeBarras.h>

// qt
#include <qfont.h>

using namespace graficos;

GraficoDeBarras::GraficoDeBarras(std::vector<modelo::Individuo*> individuos, std::vector<std::string> categorias, double rango_eje_y_min, double rango_eje_y_max, std::string etiqueta, std::string titulo_ventana) :
    individuos(individuos), categorias(categorias), rango_eje_y_min(rango_eje_y_min), rango_eje_y_max(rango_eje_y_max), etiqueta(etiqueta), titulo_ventana(titulo_ventana), chart_view(NULL)
{
    QtCharts::QBarSeries * series = new QtCharts::QBarSeries();

    for (std::vector<modelo::Individuo*>::iterator it_individuo = this->individuos.begin(); it_individuo != this->individuos.end(); it_individuo++)
    {
        QtCharts::QBarSet * set = new QtCharts::QBarSet((*it_individuo)->getNombre().c_str());

        std::vector<double> datos_individuo = (*it_individuo)->getDatos();

        for (std::vector<double>::iterator it_datos = datos_individuo.begin(); it_datos != datos_individuo.end(); it_datos++)
        {
            *set << *it_datos;
        }

        series->append(set);
    }

    QFont fuente_grafico;
    fuente_grafico.setPixelSize(25);
    fuente_grafico.setBold(true);

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitleFont(fuente_grafico);
    chart->setTitle(this->etiqueta.c_str());

    QStringList categories;
    for (std::vector<std::string>::iterator it = this->categorias.begin(); it != this->categorias.end(); it++)
    {
        categories << (*it).c_str();
    }

    QFont fuente_ejes;
    fuente_ejes.setPixelSize(15);

    QtCharts::QBarCategoryAxis *axis_x = new QtCharts::QBarCategoryAxis();
    
    axis_x->append(categories);
    chart->setAxisX(axis_x, series);

    std::string primera_categoria = *this->categorias.begin();
    std::string ultima_categoria = *(this->categorias.end() - 1);
    axis_x->setRange(QString(primera_categoria.c_str()), QString(ultima_categoria.c_str()));

    QtCharts::QValueAxis *axis_y = new QtCharts::QValueAxis();
    chart->setAxisY(axis_y, series);
    axis_y->setRange(rango_eje_y_min, rango_eje_y_max);

    axis_y->setLabelsFont(fuente_ejes);
    axis_x->setLabelsFont(fuente_ejes);

    QFont fuente_leyenda;
    fuente_leyenda.setPixelSize(15);
    fuente_leyenda.setBold(true);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignmentFlag::AlignBottom);
    chart->legend()->setFont(fuente_leyenda);

    this->chart_view = new QtCharts::QChartView(chart);
    this->chart_view->setWindowTitle(QString(this->titulo_ventana.c_str()));
    this->chart_view->setRenderHint(QPainter::Antialiasing);

    this->chart_view->setMinimumWidth(850);
    this->chart_view->setMinimumHeight(1000);
}

GraficoDeBarras::~GraficoDeBarras()
{
    if (NULL != this->chart_view)
    {
        delete this->chart_view;
        this->chart_view = NULL;
    }

    for (std::vector<modelo::Individuo*>::iterator it_individuo = this->individuos.begin(); it_individuo != this->individuos.end(); it_individuo++)
    {
        delete *it_individuo;
    }
}

// GETTERS

std::vector<modelo::Individuo*> GraficoDeBarras::getIndividuos()
{
    return this->individuos;
}

std::vector<std::string> GraficoDeBarras::getCategorias()
{
    return this->categorias;
}

double GraficoDeBarras::getRangoEjeYMin()
{
    return this->rango_eje_y_min;
}

double GraficoDeBarras::getRangoEjeYMax()
{
    return this->rango_eje_y_max;
}

// SETTERS

void GraficoDeBarras::setIndividuos(std::vector<modelo::Individuo*> individuos)
{
    this->individuos = individuos;
}

void GraficoDeBarras::setCategorias(std::vector<std::string> categorias)
{
    this->categorias = categorias;
}

void GraficoDeBarras::setRangoEjeYMin(double rango_eje_y_min)
{
    this->rango_eje_y_min = rango_eje_y_min;
}

void GraficoDeBarras::setRangoEjeYMax(double rango_eje_y_max)
{
    this->rango_eje_y_max = rango_eje_y_max;
}

QtCharts::QChartView * GraficoDeBarras::getChartView()
{
    return this->chart_view;
}

// METODOS

void GraficoDeBarras::mostrar()
{
    this->chart_view->showMaximized();
}

// CONSULTAS