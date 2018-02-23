#include "visualizadordecontexto.h"

// stl
#include <iostream>
#include <chrono>
#include <thread>

// scraping
#include <scraping/include/GestorTareas.h>

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

void dormir(unsigned long long int mili)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(mili));
}

void visualizadordecontexto::on_action_analizar_ctx_triggered()
{    
    std::thread deshabilitar_botones(dormir, 3000);

    std::thread deshabilitar_botones(desactivar);


    this->ui.btn_terminos->setEnabled(false);
    this->ui.btn_conceptos->setEnabled(false);
    this->ui.btn_fechas->setEnabled(false);
    this->ui.btn_periodos->setEnabled(false);
    this->ui.btn_medios_twitter->setEnabled(false);
    this->ui.btn_consulta->setEnabled(false);

    deshabilitar_botones.join();

    this->ui.btn_terminos->setEnabled(true);
    this->ui.btn_conceptos->setEnabled(true);
    this->ui.btn_fechas->setEnabled(true);
    this->ui.btn_periodos->setEnabled(true);
    this->ui.btn_medios_twitter->setEnabled(true);
    this->ui.btn_consulta->setEnabled(true);

}
