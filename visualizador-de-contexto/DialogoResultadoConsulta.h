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

// aplicacion
#include <aplicacion/include/GestorResultadosDiarios.h>

namespace Ui { class DialogoResultadoConsulta; };

class DialogoResultadoConsulta : public QWidget
{
    Q_OBJECT

public:
    DialogoResultadoConsulta(QWidget *parent = Q_NULLPTR);

    DialogoResultadoConsulta(
        std::vector<modelo::Medio*> medios,
        std::vector<modelo::Concepto*> conceptos,
        std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados,
        QWidget *parent = Q_NULLPTR);
    ~DialogoResultadoConsulta();

    void volcar_datos(const std::vector<modelo::Medio*>& medios,
        const std::vector<modelo::Concepto*>& conceptos,
        const std::vector<scraping::preparacion::ResultadoAnalisisDiario*>& resultados);

private:
    Ui::DialogoResultadoConsulta *ui;

    // metodos privados

    void conectar_componentes();

	void completar_tendencias(const std::vector<modelo::Medio*> & medios, const std::vector<scraping::preparacion::ResultadoAnalisisDiario*> & resultados);
    void completar_arboles(const std::vector<modelo::Medio*> & medios, const std::vector<modelo::Concepto*> & conceptos, const std::vector<scraping::preparacion::ResultadoAnalisisDiario*> & resultados);
    
	void nueva_tendencia(modelo::Medio* medio, scraping::preparacion::ResultadoAnalisisDiario* resultado);
	QTreeWidget * nuevo_arbol_sentimiento(const unsigned long long int & fecha, const std::vector<modelo::Medio*> & medios);
    QTreeWidget * nuevo_arbol_fuerza_en_noticia(const unsigned long long int & fecha, const std::vector<modelo::Medio*> & medios);

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
    void exportar_actual();
    void exportar_todo();
    void exportar_rango();

    void habilitar_exportar_botones();
    void deshabilitar_exportar_botones();

    herramientas::utiles::Json * fecha_a_json(int fecha);
    herramientas::utiles::Json * concepto_a_json(QTreeWidget * fuerza_en_noticia, QTreeWidget * sentimiento, int idx_concepto, int idx_medio);
    herramientas::utiles::Json * termino_a_json(QTreeWidget * fuerza_en_noticia, QTreeWidget * sentimiento, int idx_concepto, int idx_termino, int idx_medio);

    std::string path_icono(modelo::Medio* medio);

    // atributos
    std::vector<modelo::Medio*> medios;
    std::vector<modelo::Concepto*> conceptos;
    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados;

    std::unordered_map<unsigned long long int, QTreeWidget*> sentimientos;
	std::unordered_map<unsigned long long int, QTreeWidget*> fuerzas_en_noticia;
	std::unordered_map<unsigned long long int, std::vector<QWidget*>> tendencias;

    herramientas::utiles::Fecha fecha_actual;

    std::vector<unsigned int> meses_con_treinta_dias;

    QFutureWatcher<void> observador_exportacion;
};
