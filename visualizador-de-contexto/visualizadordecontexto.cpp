#include "visualizadordecontexto.h"

// stl
#include <iostream>

visualizadordecontexto::visualizadordecontexto(QWidget *parent)
	: QMainWindow(parent), dialogo_terminos(NULL)
{
	ui.setupUi(this);
}

void visualizadordecontexto::on_action_abrir_terminos_triggered()
{
	this->dialogo_terminos = new DialogoTerminos();
	dialogo_terminos->show();
}

void visualizadordecontexto::on_action_abrir_conceptos_triggered()
{
    this->dialogo_conceptos = new DialogoConceptos();
    dialogo_conceptos->show();
}
