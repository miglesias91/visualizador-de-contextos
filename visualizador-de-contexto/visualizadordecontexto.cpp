#include "visualizadordecontexto.h"

// stl
#include <iostream>

// interfaz
#include <visualizador-de-contexto/DialogoTerminos.h>

visualizadordecontexto::visualizadordecontexto(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}

void visualizadordecontexto::on_action_abrirTerminos_triggered()
{
	DialogoTerminos* dialogo_terminos = new DialogoTerminos();
	dialogo_terminos->show();
}
