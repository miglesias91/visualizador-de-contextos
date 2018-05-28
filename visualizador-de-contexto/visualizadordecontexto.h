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
    void abrir_terminos();

    void abrir_conceptos();

    void abrir_fechas();

    void abrir_periodos();

    void abrir_consulta();

    void abrir_medios_twitter();

    void analizar_ctx();

    void deshabilitar_menu();

    void habilitar_menu();

    void abrir_medios_facebook();

private:
	Ui::visualizadordecontextoClass ui;

    // METODOS PRIVADOS

    void conectar_componentes();

    void tarea_analizar_ctx();

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
