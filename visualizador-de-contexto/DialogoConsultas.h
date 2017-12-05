#pragma once

#include <QWidget>

// qt
#include <qlistwidget.h>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

// modelo
#include <modelo/include/Consulta.h>

// visualizador
#include <declaraciones_metatipos.h>

namespace Ui { class DialogoConsultas; };

class DialogoConsultas : public QWidget
{
    Q_OBJECT

public:
    DialogoConsultas(QWidget *parent = Q_NULLPTR);
    ~DialogoConsultas();

private slots:
    void on_action_agregar_conceptos_triggered();

    void on_action_sacar_conceptos_triggered();

    void on_action_setear_periodo_triggered();

    void on_action_agregar_medios_triggered();

    void on_action_agregar_secciones_triggered();

    void on_action_sacar_medios_triggered();

    void on_action_sacar_secciones_triggered();

    void on_action_agregar_reportes_triggered();

    void on_action_sacar_reportes_triggered();

    void on_action_realizar_consulta_y_cerrar_triggered();

private:
    Ui::DialogoConsultas *ui;

    // carga listas

    void cargarListaConceptos();
    void agregarConceptoALista(visualizador::modelo::Concepto* concepto, QListWidget * lista);

    void cargarListaPeriodos();
    void agregarPeriodoALista(visualizador::modelo::Periodo* periodo, QListWidget * lista);

    void cargarListaMedios();
    void agregarMedioALista(visualizador::modelo::Medio* periodo, QListWidget * lista);

    void cargarListaSecciones();
    void agregarSeccionALista(visualizador::modelo::Seccion* periodo, QListWidget * lista);

    void cargarListaReportes();
    void agregarReporteALista(visualizador::modelo::Reporte* periodo, QListWidget * lista);

    // obtener seleccionados de listas

    template <class ENTIDAD>
    std::vector<ENTIDAD*> itemsSeleccionados(QListWidget * lista);

    void sacarItemsSeleccionados(QListWidget * lista);

    std::vector<modelo::Concepto*> conceptosSeleccionados();

    std::vector<modelo::Periodo*> periodosSeleccionados();

    std::vector<modelo::Medio*> mediosSeleccionados();

    std::vector<modelo::Seccion*> seccionesSeleccionados();

    std::vector<modelo::Reporte*> reportesSeleccionados();

    // descargar listas

    template <class ENTIDAD>
    void descargarLista(QListWidget * lista);

    void descargarListaConceptos();

    void descargarListaPeriodos();

    void descargarListaMedios();

    void descargarListaSecciones();

    void descargarListaReportes();
};

template <class ENTIDAD>
std::vector<ENTIDAD*> DialogoConsultas::itemsSeleccionados(QListWidget * lista)
{
    std::vector<ENTIDAD*> items_seleccionados;
    QList<QListWidgetItem*> items = lista->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QVariant data = item->data(Qt::UserRole);
        ENTIDAD* termino = data.value<ENTIDAD*>();

        items_seleccionados.push_back(termino);
    }

    return items_seleccionados;
}

template <class ENTIDAD>
void DialogoConsultas::descargarLista(QListWidget * lista)
{
    QListWidgetItem* item = nullptr;

    // elimino las entidades de la lista
    ENTIDAD* entidad_lista = nullptr;
    unsigned int count = lista->count();
    while (0 != lista->count())
    {
        count = lista->count();

        entidad_lista = lista->item(0)->data(Qt::UserRole).value<ENTIDAD*>();

        if (0 == entidad_lista->restarReferencia())
        {
            delete entidad_lista;
        }

        item = lista->takeItem(0);
        delete item;
    }
}
