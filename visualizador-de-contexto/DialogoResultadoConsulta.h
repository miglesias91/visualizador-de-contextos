#pragma once

// qt
#include <QWidget>
#include <qtreewidget.h>
#include <qtablewidget.h>
#include <qdatetime.h>
#include <qsizepolicy.h>
#include <qfuturewatcher.h>
#include <QtConcurrent/qtconcurrentrun.h>

// herramientas
#include <utiles/include/Fecha.h>
#include <utiles/include/Json.h>
#include <utiles/include/FuncionesSistemaArchivos.h>
#include <utiles/include/csv.h>

// aplicacion
#include <aplicacion/include/GestorResultadosDiarios.h>

// visu
#include <visualizador-de-contexto/include/waitingspinnerwidget.h>

namespace Ui { class DialogoResultadoConsulta; };

struct info_consulta {
    enum ordenar_por {
        APARICIONES = 0, FUERZA = 1
    };

    bool conceptos = false;
    bool tendencias = false;
    uint32_t top_tendencias = 0;
    ordenar_por orden = APARICIONES;
};

class DialogoResultadoConsulta : public QWidget
{
    Q_OBJECT

public:
    DialogoResultadoConsulta(QWidget *parent = Q_NULLPTR);

    DialogoResultadoConsulta(
        std::vector<modelo::Medio*> medios,
        std::vector<modelo::Concepto*> conceptos,
        std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados,
        const info_consulta& info,
        QWidget *parent = Q_NULLPTR);
    ~DialogoResultadoConsulta();

    void volcar_datos(const std::vector<modelo::Medio*>& medios,
        const std::vector<modelo::Concepto*>& conceptos,
        const std::vector<scraping::preparacion::ResultadoAnalisisDiario*>& resultados);

private:
    Ui::DialogoResultadoConsulta *ui;

    // metodos privados

    void conectar_componentes();

    void completar_resultados_por_concepto(const std::vector<modelo::Concepto*> & conceptos, const std::vector<modelo::Medio*> & medios, const std::vector<scraping::preparacion::ResultadoAnalisisDiario*> & resultados);
    void completar_tendencias(const std::vector<modelo::Medio*> & medios, const std::vector<scraping::preparacion::ResultadoAnalisisDiario*> & resultados);
    //void completar_arboles(const std::vector<modelo::Medio*> & medios, const std::vector<modelo::Concepto*> & conceptos, const std::vector<scraping::preparacion::ResultadoAnalisisDiario*> & resultados);
    
    void nuevo_arbol_medio(const std::vector<modelo::Concepto*> &conceptos, modelo::Medio* medio, scraping::preparacion::ResultadoAnalisisDiario* resultado);
    void nueva_tendencia(modelo::Medio* medio, scraping::preparacion::ResultadoAnalisisDiario* resultado);
	//QTreeWidget * nuevo_arbol_sentimiento(const unsigned long long int & fecha, const std::vector<modelo::Medio*> & medios);
 //   QTreeWidget * nuevo_arbol_fuerza_en_noticia(const unsigned long long int & fecha, const std::vector<modelo::Medio*> & medios);

 //   QTreeWidgetItem * completar_sentimiento(modelo::Concepto * concepto, std::vector<modelo::Medio*> medios, scraping::preparacion::ResultadoAnalisisDiario * resultado);
 //   QTreeWidgetItem * completar_fuerza_en_noticia(modelo::Concepto * concepto, std::vector<modelo::Medio*> medios, scraping::preparacion::ResultadoAnalisisDiario * resultado);

 //   QTreeWidgetItem * completar_sentimiento(modelo::Termino * termino, std::vector<modelo::Medio*> medios, scraping::preparacion::ResultadoAnalisisDiario * resultado);
 //   QTreeWidgetItem * completar_fuerza_en_noticia(modelo::Termino * termino, std::vector<modelo::Medio*> medios, scraping::preparacion::ResultadoAnalisisDiario * resultado);

    QTreeWidgetItem * completar_fila_arbol(modelo::Concepto * concepto, modelo::Medio* medio, scraping::preparacion::ResultadoAnalisisDiario * resultado);
    QTreeWidgetItem * completar_fila_arbol(modelo::Termino * termino, modelo::Medio* medio, scraping::preparacion::ResultadoAnalisisDiario * resultado);

    void mostrar_resultado(int fecha);
    void ocultar_resultado(int fecha);

    void mostrar_resultado_dia(int dia);

    void colapsar_sentimiento(QTreeWidgetItem *item);
    void expandir_sentimiento(QTreeWidgetItem *item);

    void colapsar_fuerza_en_noticia(QTreeWidgetItem *item);
    void expandir_fuerza_en_noticia(QTreeWidgetItem *item);
    void exportar_actual();
    void exportar_todo();
    void exportar_rango();

    void habilitar_exportar_botones();
    void deshabilitar_exportar_botones();

    //bool fecha_fuerza_sentimiento_a_csv(int fecha, herramientas::utiles::csv * doc);
    bool fecha_tendencia_a_csv(int fecha, herramientas::utiles::csv * doc);
    bool fecha_conceptos_a_csv(int fecha, herramientas::utiles::csv * doc);

    herramientas::utiles::Json * fecha_a_json(int fecha);
    herramientas::utiles::Json * concepto_a_json(QTreeWidget * fuerza_en_noticia, QTreeWidget * sentimiento, int idx_concepto, int idx_medio);
    herramientas::utiles::Json * termino_a_json(QTreeWidget * fuerza_en_noticia, QTreeWidget * sentimiento, int idx_concepto, int idx_termino, int idx_medio);

    std::string path_icono(modelo::Medio* medio);
    std::string tipo_medio(modelo::Medio* medio);

    // atributos
    std::vector<modelo::Medio*> medios;
    std::vector<modelo::Concepto*> conceptos;
    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados;

    std::unordered_map<unsigned long long int, QTreeWidget*> sentimientos;
	std::unordered_map<unsigned long long int, QTreeWidget*> fuerzas_en_noticia;
    std::unordered_map<unsigned long long int, std::vector<QWidget*>> tendencias;
    std::unordered_map<unsigned long long int, std::vector<std::pair<std::string, QTableWidget*>>> tablas_tendencias;


    std::unordered_map<unsigned long long int, std::vector<QWidget*>> resultados_por_conceptos;
    std::unordered_map<unsigned long long int, std::vector<std::pair<std::string, QTreeWidget*>>> arboles_resultados_por_conceptos;

    herramientas::utiles::Fecha fecha_actual;

    std::vector<unsigned int> meses_con_treinta_dias;

    WaitingSpinnerWidget spinner;
    QFutureWatcher<void> observador_exportacion;
    
    std::vector<std::string> nombres_columnas_csv;
    info_consulta info;
};
