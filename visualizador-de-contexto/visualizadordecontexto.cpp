#include "visualizadordecontexto.h"

// stl
#include <iostream>
#include <chrono>
#include <thread>

// qt
#include <QtConcurrent/qtconcurrentrun.h>
#include <qprogressdialog.h>

// scraping
#include <scraping/include/GestorTareas.h>

// aplicacion
#include <aplicacion/include/Logger.h>

visualizadordecontexto::visualizadordecontexto(QWidget *parent)
    : QMainWindow(parent), dialogo_terminos(NULL), dialogo_conceptos(NULL), dialogo_fechas(NULL), dialogo_periodos(NULL), dialogo_consultas(NULL)
{
	ui.setupUi(this);

    visualizador::aplicacion::Logger::marca("INICIO INTERFAZ QT");

    this->ui.btn_fechas->setEnabled(false);
    this->ui.btn_periodos->setEnabled(false);

    this->ui.bar_analizar_ctx->hide();
}

visualizadordecontexto::~visualizadordecontexto()
{
    visualizador::aplicacion::Logger::marca("FIN INTERFAZ QT");
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

void visualizadordecontexto::on_action_abrir_medios_facebook_triggered()
{
    this->dialogo_medios_facebook = new DialogoMediosFacebook();
    this->dialogo_medios_facebook->show();
}

void visualizadordecontexto::on_action_analizar_ctx_triggered()
{    
    QObject::connect(&(this->observador), &QFutureWatcher<void>::started, this, &visualizadordecontexto::on_action_deshabilitar_menu_triggered);
    QObject::connect(&(this->observador), &QFutureWatcher<void>::started, this->ui.bar_analizar_ctx, &QProgressBar::show);
    QObject::connect(&(this->observador), &QFutureWatcher<void>::finished, this, &visualizadordecontexto::on_action_habilitar_menu_triggered);
    QObject::connect(&(this->observador), &QFutureWatcher<void>::finished, this->ui.bar_analizar_ctx, &QProgressBar::hide);

    QObject::connect(this, &visualizadordecontexto::senialProgresoAnalisisCTX, this->ui.bar_analizar_ctx, &QProgressBar::setValue);

    QFuture<void> funcion = QtConcurrent::run(this, &visualizadordecontexto::analizarCTX);

    this->observador.setFuture(funcion);
}

void visualizadordecontexto::on_action_deshabilitar_menu_triggered()
{
    this->ui.btn_terminos->setEnabled(false);
    this->ui.btn_conceptos->setEnabled(false);
    //this->ui.btn_fechas->setEnabled(false);
    //this->ui.btn_periodos->setEnabled(false);
    this->ui.btn_medios_twitter->setEnabled(false);
    this->ui.btn_medios_facebook->setEnabled(false);
    this->ui.btn_consulta->setEnabled(false);
    this->ui.btn_analizar_ctx->setEnabled(false);
}

void visualizadordecontexto::on_action_habilitar_menu_triggered()
{
    this->ui.btn_terminos->setEnabled(true);
    this->ui.btn_conceptos->setEnabled(true);
    //this->ui.btn_fechas->setEnabled(true);
    //this->ui.btn_periodos->setEnabled(true);
    this->ui.btn_medios_twitter->setEnabled(true);
    this->ui.btn_medios_facebook->setEnabled(true);
    this->ui.btn_consulta->setEnabled(true);
    this->ui.btn_analizar_ctx->setEnabled(true);
}

// metodos privados

void visualizadordecontexto::analizarCTX()
{
    this->emitirProgreso(10);

    scraping::aplicacion::GestorTareas::scrapearTwitter();
    this->emitirProgreso(25);

    scraping::aplicacion::GestorTareas::depurarYAnalizarTwitter();
    this->emitirProgreso(40);
    
    scraping::aplicacion::GestorTareas::prepararYAlmacenarTwitter();
    this->emitirProgreso(55);

    scraping::aplicacion::GestorTareas::scrapearFacebook();
    this->emitirProgreso(70);

    scraping::aplicacion::GestorTareas::depurarYAnalizarFacebook();
    this->emitirProgreso(85);

    scraping::aplicacion::GestorTareas::prepararYAlmacenarFacebook();
    this->emitirProgreso(100);
}
