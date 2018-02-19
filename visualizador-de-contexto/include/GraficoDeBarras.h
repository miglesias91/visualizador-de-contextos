#pragma once

// qt
#include <QtCharts/qchartview.h>
#include <QtCharts/qbarseries.h>
#include <QtCharts/qbarset.h>
#include <QtCharts/qlegend.h>
#include <QtCharts/qbarcategoryaxis.h>
#include <QtCharts/qvalueaxis.h>

// modelo
#include <visualizador-de-contexto/include/Individuo.h>

namespace graficos
{

class GraficoDeBarras
{
public:
    GraficoDeBarras(std::vector<modelo::Individuo*> individuos, std::vector<std::string> categorias, double rango_eje_y_min, double rango_eje_y_max, std::string etiqueta);
    virtual ~GraficoDeBarras();

    // GETTERS

    virtual std::vector<modelo::Individuo*> getIndividuos();
    virtual std::vector<std::string> getCategorias();
    virtual double getRangoEjeYMin();
    virtual double getRangoEjeYMax();

    // SETTERS

    virtual void setIndividuos(std::vector<modelo::Individuo*> individuos);
    virtual void setCategorias(std::vector<std::string> categorias);
    virtual void setRangoEjeYMin(double rango_eje_y_min);
    virtual void setRangoEjeYMax(double rango_eje_y_max);

    // METODOS

    virtual void mostrar();

    // CONSULTAS

private:

    // ATRIBUTOS

    std::string etiqueta;
    std::vector<modelo::Individuo*> individuos;
    std::vector<std::string> categorias;
    int rango_eje_y_min;
    int rango_eje_y_max;

    QtCharts::QChartView * chart_view;


};

};

