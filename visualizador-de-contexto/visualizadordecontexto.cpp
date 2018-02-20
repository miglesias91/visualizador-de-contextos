#include "visualizadordecontexto.h"

// stl
#include <iostream>

visualizadordecontexto::visualizadordecontexto(QWidget *parent)
    : QMainWindow(parent), dialogo_terminos(NULL), dialogo_conceptos(NULL), dialogo_fechas(NULL), dialogo_periodos(NULL), dialogo_consultas(NULL)
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

void visualizadordecontexto::on_action_abrir_fechas_triggered()
{
    this->dialogo_fechas = new DialogoFechas();
    this->dialogo_fechas->show();
}

void visualizadordecontexto::on_action_abrir_periodos_triggered()
{
    this->dialogo_periodos = new DialogoPeriodos();
    this->dialogo_periodos->show();
}

void visualizadordecontexto::on_action_abrir_consulta_triggered()
{
    this->dialogo_consultas = new DialogoConsultas();
    this->dialogo_consultas->show();
}

void visualizadordecontexto::on_action_abrir_medios_twitter_triggered()
{
    this->dialogo_medios_twitter = new DialogoMediosTwitter();
    this->dialogo_medios_twitter->show();
}
