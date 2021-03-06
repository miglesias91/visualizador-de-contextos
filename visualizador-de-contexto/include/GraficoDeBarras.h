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
#include <visualizador-de-contexto/include/Categoria.h>

namespace graficos
{

class GraficoDeBarras
{
public:
    GraficoDeBarras(std::vector<modelo::Individuo*> individuos, std::vector<modelo::Categoria*> categorias, double rango_eje_y_min, double rango_eje_y_max, std::string etiqueta, std::string titulo_ventana = u8"Gr�fico de barras");
    virtual ~GraficoDeBarras();

    // GETTERS

    virtual std::vector<modelo::Individuo*> getIndividuos();
    virtual std::vector<modelo::Categoria*> getCategorias();
    virtual double getRangoEjeYMin();
    virtual double getRangoEjeYMax();

    // SETTERS

    virtual void setIndividuos(std::vector<modelo::Individuo*> individuos);
    virtual void setCategorias(std::vector<modelo::Categoria*> categorias);
    virtual void setRangoEjeYMin(double rango_eje_y_min);
    virtual void setRangoEjeYMax(double rango_eje_y_max);

    QtCharts::QChartView * getChartView();

    // METODOS

    virtual void mostrar();

    // CONSULTAS

private:

    // ATRIBUTOS

    std::string etiqueta;
    std::string titulo_ventana;
    std::vector<modelo::Individuo*> individuos;
    std::vector<modelo::Categoria*> categorias;
    int rango_eje_y_min;
    int rango_eje_y_max;

    QtCharts::QChartView * chart_view;

};

};

