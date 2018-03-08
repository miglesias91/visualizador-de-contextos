#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_visualizadordecontexto.h"

// qt
#include <qfuturewatcher.h>

// interfaz
#include <visualizador-de-contexto/DialogoTerminos.h>
#include <visualizador-de-contexto/DialogoConceptos.h>
#include <visualizador-de-contexto/DialogoFechas.h>
#include <visualizador-de-contexto/DialogoPeriodos.h>
#include <visualizador-de-contexto/DialogoConsultas.h>
#include <visualizador-de-contexto/DialogoMediosTwitter.h>
#include <visualizador-de-contexto/DialogoMediosFacebook.h>

class visualizadordecontexto : public QMainWindow
{
	Q_OBJECT

public:
	visualizadordecontexto(QWidget *parent = Q_NULLPTR);
    ~visualizadordecontexto();

    void emitirProgreso(int progreso) { emit senialProgresoAnalisisCTX(progreso); }

signals:

    void senialProgresoAnalisisCTX(int);

private slots:
    void on_action_abrir_terminos_triggered();

    void on_action_abrir_conceptos_triggered();

    void on_action_abrir_fechas_triggered();

    void on_action_abrir_periodos_triggered();

    void on_action_abrir_consulta_triggered();

    void on_action_abrir_medios_twitter_triggered();

    void on_action_analizar_ctx_triggered();

    void on_action_deshabilitar_menu_triggered();

    void on_action_habilitar_menu_triggered();


private:
	Ui::visualizadordecontextoClass ui;

    // METODOS PRIVADOS

    void analizarCTX();

    // ATRIBUTOS

    QFutureWatcher<void> observador;

	// DIALOGOS

    DialogoTerminos * dialogo_terminos;
    DialogoConceptos * dialogo_conceptos;
    DialogoFechas * dialogo_fechas;
    DialogoPeriodos * dialogo_periodos;
    DialogoConsultas * dialogo_consultas;
    DialogoMediosTwitter * dialogo_medios_twitter;
    DialogoMediosFacebook * dialogo_medios_facebook;
};
