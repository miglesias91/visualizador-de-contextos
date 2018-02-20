#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_visualizadordecontexto.h"

// interfaz
#include <visualizador-de-contexto/DialogoTerminos.h>
#include <visualizador-de-contexto/DialogoConceptos.h>
#include <visualizador-de-contexto/DialogoFechas.h>
#include <visualizador-de-contexto/DialogoPeriodos.h>
#include <visualizador-de-contexto/DialogoConsultas.h>
#include <visualizador-de-contexto/DialogoMediosTwitter.h>

class visualizadordecontexto : public QMainWindow
{
	Q_OBJECT

public:
	visualizadordecontexto(QWidget *parent = Q_NULLPTR);

private slots:
    void on_action_abrir_terminos_triggered();

    void on_action_abrir_conceptos_triggered();

    void on_action_abrir_fechas_triggered();

    void on_action_abrir_periodos_triggered();

    void on_action_abrir_consulta_triggered();

    void on_action_abrir_medios_twitter_triggered();

private:
	Ui::visualizadordecontextoClass ui;

	// DIALOGOS

    DialogoTerminos * dialogo_terminos;
    DialogoConceptos * dialogo_conceptos;
    DialogoFechas * dialogo_fechas;
    DialogoPeriodos * dialogo_periodos;
    DialogoConsultas * dialogo_consultas;
    DialogoMediosTwitter * dialogo_medios_twitter;
};
