#include <visualizador-de-contexto/include/GraficoDeBarras.h>

using namespace graficos;

GraficoDeBarras::GraficoDeBarras(std::vector<modelo::Individuo> individuos, std::vector<std::string> categorias, double rango_eje_y_min, double rango_eje_y_max, std::string etiqueta) :
    individuos(individuos), categorias(categorias), rango_eje_y_min(rango_eje_y_min), rango_eje_y_max(rango_eje_y_max), etiqueta(etiqueta), chart_view(NULL)
{
    QtCharts::QBarSeries * series = new QtCharts::QBarSeries();

    for (std::vector<modelo::Individuo>::iterator it_individuo = this->individuos.begin(); it_individuo != this->individuos.end(); it_individuo++)
    {
        QtCharts::QBarSet * set = new QtCharts::QBarSet(it_individuo->getNombre().c_str());

        std::vector<double> datos_individuo = it_individuo->getDatos();

        for (std::vector<double>::iterator it_datos = datos_individuo.begin(); it_datos != datos_individuo.end(); it_datos++)
        {
            *set << *it_datos;
        }

        series->append(set);
    }

    QtCharts::QChart *chart = new QtCharts::QChart();
    chart->addSeries(series);
    chart->setTitle(this->etiqueta.c_str());

    QStringList categories;
    for (std::vector<std::string>::iterator it = this->categorias.begin(); it != this->categorias.end(); it++)
    {
        categories << (*it).c_str();
    }

    QtCharts::QBarCategoryAxis *axisX = new QtCharts::QBarCategoryAxis();
    axisX->append(categories);
    chart->setAxisX(axisX, series);

    std::string primera_categoria = *this->categorias.begin();
    std::string ultima_categoria = *(this->categorias.end() - 1);
    axisX->setRange(QString(primera_categoria.c_str()), QString(ultima_categoria.c_str()));

    QtCharts::QValueAxis *axisY = new QtCharts::QValueAxis();
    chart->setAxisY(axisY, series);
    axisY->setRange(rango_eje_y_min, rango_eje_y_max);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    this->chart_view = new QtCharts::QChartView(chart);
    this->chart_view->setRenderHint(QPainter::Antialiasing);

    chart_view->show();
}

GraficoDeBarras::~GraficoDeBarras()
{
    if (NULL != this->chart_view)
    {
        delete this->chart_view;
        this->chart_view = NULL;
    }
}

// GETTERS

std::vector<modelo::Individuo> GraficoDeBarras::getIndividuos()
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

void GraficoDeBarras::setIndividuos(std::vector<modelo::Individuo> individuos)
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

// METODOS

// CONSULTAS