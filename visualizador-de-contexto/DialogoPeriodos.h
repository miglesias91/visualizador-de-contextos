#pragma once

#include <QWidget>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

// modelo
#include <modelo/include/Periodo.h>

// visualizador
#include <declaraciones_metatipos.h>

namespace Ui { class DialogoPeriodos; };

class DialogoPeriodos : public QWidget
{
    Q_OBJECT

public:
    DialogoPeriodos(QWidget *parent = Q_NULLPTR);
    ~DialogoPeriodos();

    private slots:
    void on_action_guardar_periodo_triggered();

    void on_action_limpiar_periodo_triggered();

    void on_action_eliminar_periodo_triggered();

    void on_action_actualizar_y_cerrar_triggered();

    void on_action_estado_btn_eliminar_triggered();

private:
    Ui::DialogoPeriodos *ui;

    // METODOS INTERNOS

    void agregarPeriodoALista(visualizador::modelo::Periodo* periodo);

    void cargarListaPeriodos();

    void descargarListaPeriodos();
    
    void cargarComboboxesDesdeYHasta();

    void descargarComboboxesDesdeYHasta();

    visualizador::modelo::Fecha * fechaDesdeSeleccionada();
    
    visualizador::modelo::Fecha * fechaHastaSeleccionada();

    // ATRIBUTOS

    visualizador::aplicacion::GestorEntidades gestor_periodos;
};
