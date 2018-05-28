#pragma once

// qt
#include <QWidget>
#include <qtreewidget.h>
#include <qdatetime.h>
#include <qsizepolicy.h>

// herramientas
#include <utiles/include/Fecha.h>
#include <utiles/include/Json.h>
#include <utiles/include/FuncionesSistemaArchivos.h>

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

    void conectar_componentes();

    void completar_arboles(std::vector<modelo::Medio*> medios, std::vector<modelo::Concepto*> conceptos, std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados);
    
    QTreeWidget * nuevo_arbol_sentimiento(const unsigned long long int & fecha, const QStringList & etiquetas_medios);
    QTreeWidget * nuevo_arbol_fuerza_en_noticia(const unsigned long long int & fecha, const QStringList & etiquetas_medios);

    QTreeWidgetItem * completar_sentimiento(modelo::Concepto * concepto, std::vector<modelo::Medio*> medios, scraping::preparacion::ResultadoAnalisisDiario * resultado);
    QTreeWidgetItem * completar_fuerza_en_noticia(modelo::Concepto * concepto, std::vector<modelo::Medio*> medios, scraping::preparacion::ResultadoAnalisisDiario * resultado);

    QTreeWidgetItem * completar_sentimiento(modelo::Termino * termino, std::vector<modelo::Medio*> medios, scraping::preparacion::ResultadoAnalisisDiario * resultado);
    QTreeWidgetItem * completar_fuerza_en_noticia(modelo::Termino * termino, std::vector<modelo::Medio*> medios, scraping::preparacion::ResultadoAnalisisDiario * resultado);

    void mostrar_resultado(int fecha);
    void ocultar_resultado(int fecha);

    void mostrar_resultado_dia(int dia);

    void colapsar_sentimiento(QTreeWidgetItem *item);
    void expandir_sentimiento(QTreeWidgetItem *item);

    void colapsar_fuerza_en_noticia(QTreeWidgetItem *item);
    void expandir_fuerza_en_noticia(QTreeWidgetItem *item);

    void exportar(int fecha);
    void exportar_actual();
    void exportar_todo();
    void exportar_rango();

    // atributos
    std::vector<modelo::Medio*> medios;
    std::vector<modelo::Concepto*> conceptos;
    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados;

    std::unordered_map<unsigned long long int, QTreeWidget*> sentimientos;
    std::unordered_map<unsigned long long int, QTreeWidget*> fuerzas_en_noticia;

    herramientas::utiles::Fecha fecha_actual;

    std::vector<unsigned int> meses_con_treinta_dias;
    std::vector<unsigned long long int> fechas_exportadas;
};
