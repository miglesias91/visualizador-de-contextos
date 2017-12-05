#pragma once

#include <QWidget>

// qt
#include <qmessagebox.h>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

// modelo
#include <modelo/include/Fecha.h>

// visualizador
#include <declaraciones_metatipos.h>

namespace Ui { class DialogoFechas; };

class DialogoFechas : public QWidget
{
    Q_OBJECT

public:
    DialogoFechas(QWidget *parent = Q_NULLPTR);
    ~DialogoFechas();

private slots:
    void on_action_guardar_fecha_triggered();

    void on_action_limpiar_fecha_triggered();

    void on_action_eliminar_fecha_triggered();

    void on_action_actualizar_y_cerrar_triggered();

    void on_action_estado_btn_eliminar_triggered();

private:
    Ui::DialogoFechas *ui;

    QMessageBox * crearAdvertenciaFechaConRelacionesDependientes();

    // agregar una fecha a la lista de fechas de la ui.
    void agregarFechaALista(visualizador::modelo::Fecha* fecha);

    // descargo la lista de fechas
    void cargarListaFechas();

    // descargo la lista de fechas
    void descargarListaFechas();

    // ATRIBUTOS

    visualizador::aplicacion::GestorEntidades gestor_fechas;
};
