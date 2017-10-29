#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_visualizadordecontexto.h"

// interfaz
#include <visualizador-de-contexto/DialogoTerminos.h>
#include <visualizador-de-contexto/DialogoConceptos.h>

class visualizadordecontexto : public QMainWindow
{
	Q_OBJECT

public:
	visualizadordecontexto(QWidget *parent = Q_NULLPTR);

private slots:
    void on_action_abrir_terminos_triggered();

    void on_action_abrir_conceptos_triggered();

private:
	Ui::visualizadordecontextoClass ui;

	// DIALOGOS

    DialogoTerminos* dialogo_terminos;
    DialogoConceptos* dialogo_conceptos;
};
