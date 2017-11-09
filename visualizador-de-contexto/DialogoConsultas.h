#pragma once

#include <QWidget>

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
};
