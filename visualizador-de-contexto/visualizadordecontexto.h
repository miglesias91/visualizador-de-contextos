#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_visualizadordecontexto.h"

// qt
#include <qprocess.h>
#include <qfuturewatcher.h>

// interfaz
#include <visualizador-de-contexto/DialogoTerminos.h>
#include <visualizador-de-contexto/DialogoConceptos.h>
#include <visualizador-de-contexto/DialogoFechas.h>
#include <visualizador-de-contexto/DialogoPeriodos.h>
#include <visualizador-de-contexto/DialogoConsultas.h>
#include <visualizador-de-contexto/DialogoMediosTwitter.h>
#include <visualizador-de-contexto/DialogoMediosFacebook.h>
#include <visualizador-de-contexto/DialogoMediosPortales.h>
#include <visualizador-de-contexto/include/waitingspinnerwidget.h>

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
    void abrir_medios_facebook();
    void abrir_medios_portales();

    void analizar_ctx();
    void deshabilitar_menu();
    void habilitar_menu();
    void guardar_activo();
    void hay_dialogo_activo();
    void sin_dialogo_activo();
    void dialogo_consulta_cerrado();

private:
	Ui::visualizadordecontextoClass ui;

    // METODOS PRIVADOS
    void conectar_componentes();
    void tarea_analizar_ctx();

    // ATRIBUTOS
    QProcess scraping;
    QFutureWatcher<void> observador;
    WaitingSpinnerWidget spinner;


	// DIALOGOS
    DialogoTerminos * dialogo_terminos;
    DialogoConceptos * dialogo_conceptos;
    DialogoFechas * dialogo_fechas;
    DialogoPeriodos * dialogo_periodos;
    DialogoConsultas * dialogo_consultas;
    DialogoMediosTwitter * dialogo_medios_twitter;
    DialogoMediosFacebook * dialogo_medios_facebook;
    DialogoMediosPortales * dialogo_medios_portales;

    QWidget * dialogo_activo;
    bool hay_dialogo_abierto;
    bool dialogo_consulta_abierto;
};
