#pragma once

// qt
#include <QWidget>
#include <qtreewidget.h>

// aplicacion
#include <aplicacion/include/GestorDatosScraping.h>

namespace Ui { class DialogoResultadoConsulta; };

class DialogoResultadoConsulta : public QWidget
{
    Q_OBJECT

public:
    DialogoResultadoConsulta(
        std::vector<modelo::Medio*> medios,
        std::vector<modelo::Concepto*> conceptos,
        std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados,
        QWidget *parent = Q_NULLPTR);
    ~DialogoResultadoConsulta();

private:
    Ui::DialogoResultadoConsulta *ui;

    // metodos privados
    QTreeWidget * nuevo_arbol_sentimiento(const unsigned long long int & fecha);
    QTreeWidget * nuevo_arbol_fuerza_en_noticia(const unsigned long long int & fecha);

    void mostrar_resultado(int fecha);

    // atributos
    std::vector<modelo::Medio*> medios;
    std::vector<modelo::Concepto*> conceptos;
    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados;

    std::unordered_map<unsigned long long int, QTreeWidget*> sentimientos;
    std::unordered_map<unsigned long long int, QTreeWidget*> fuerzas_en_noticia;
};
