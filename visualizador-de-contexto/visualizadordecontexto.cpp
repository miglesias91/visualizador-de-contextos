#include "visualizadordecontexto.h"

// stl
#include <iostream>

visualizadordecontexto::visualizadordecontexto(QWidget *parent)
	: QMainWindow(parent), dialogo_terminos(NULL)
{
	ui.setupUi(this);
}

void visualizadordecontexto::on_action_abrirTerminos_triggered()
{
	this->dialogo_terminos = new DialogoTerminos();
	dialogo_terminos->show();
}
