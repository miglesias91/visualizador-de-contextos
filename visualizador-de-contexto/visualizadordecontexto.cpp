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

    this->conectar_componentes();

    visualizador::aplicacion::Logger::marca("INICIO INTERFAZ QT");

    this->ui.btn_fechas->setEnabled(false);
    this->ui.btn_periodos->setEnabled(false);

    this->ui.bar_analizar_ctx->hide();
}

visualizadordecontexto::~visualizadordecontexto()
{
    visualizador::aplicacion::Logger::marca("FIN INTERFAZ QT");
}

void visualizadordecontexto::abrir_terminos()
{
	this->dialogo_terminos = new DialogoTerminos();
	dialogo_terminos->show();
}

void visualizadordecontexto::abrir_conceptos()
{
    this->dialogo_conceptos = new DialogoConceptos();
    dialogo_conceptos->show();
}

void visualizadordecontexto::abrir_fechas()
{
    this->dialogo_fechas = new DialogoFechas();
    this->dialogo_fechas->show();
}

void visualizadordecontexto::abrir_periodos()
{
    this->dialogo_periodos = new DialogoPeriodos();
    this->dialogo_periodos->show();
}

void visualizadordecontexto::abrir_consulta()
{
    this->dialogo_consultas = new DialogoConsultas();
    this->dialogo_consultas->show();
}

void visualizadordecontexto::abrir_medios_twitter()
{
    this->dialogo_medios_twitter = new DialogoMediosTwitter();
    this->dialogo_medios_twitter->show();
}

void visualizadordecontexto::abrir_medios_facebook()
{
    this->dialogo_medios_facebook = new DialogoMediosFacebook();
    this->dialogo_medios_facebook->show();
}

void visualizadordecontexto::analizar_ctx()
{    
    QObject::connect(&(this->observador), &QFutureWatcher<void>::started, this, &visualizadordecontexto::deshabilitar_menu);
    QObject::connect(&(this->observador), &QFutureWatcher<void>::started, this->ui.bar_analizar_ctx, &QProgressBar::show);
    QObject::connect(&(this->observador), &QFutureWatcher<void>::finished, this, &visualizadordecontexto::habilitar_menu);
    QObject::connect(&(this->observador), &QFutureWatcher<void>::finished, this->ui.bar_analizar_ctx, &QProgressBar::hide);

    QObject::connect(this, &visualizadordecontexto::senialProgresoAnalisisCTX, this->ui.bar_analizar_ctx, &QProgressBar::setValue);

    QFuture<void> funcion = QtConcurrent::run(this, &visualizadordecontexto::tarea_analizar_ctx);

    this->observador.setFuture(funcion);
}

void visualizadordecontexto::deshabilitar_menu()
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

void visualizadordecontexto::habilitar_menu()
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

void visualizadordecontexto::conectar_componentes() {

    QObject::connect(this->ui.btn_terminos, &QPushButton::released, this, &visualizadordecontexto::abrir_terminos);
    QObject::connect(this->ui.btn_conceptos, &QPushButton::released, this, &visualizadordecontexto::abrir_conceptos);
    QObject::connect(this->ui.btn_fechas, &QPushButton::released, this, &visualizadordecontexto::abrir_fechas);
    QObject::connect(this->ui.btn_periodos, &QPushButton::released, this, &visualizadordecontexto::abrir_periodos);
    QObject::connect(this->ui.btn_medios_twitter, &QPushButton::released, this, &visualizadordecontexto::abrir_medios_twitter);
    QObject::connect(this->ui.btn_medios_facebook, &QPushButton::released, this, &visualizadordecontexto::abrir_medios_facebook);

    QObject::connect(this->ui.btn_consulta, &QPushButton::released, this, &visualizadordecontexto::abrir_consulta);
    QObject::connect(this->ui.btn_analizar_ctx, &QPushButton::released, this, &visualizadordecontexto::analizar_ctx);
}

void visualizadordecontexto::tarea_analizar_ctx() 
{
    this->emitirProgreso(10);
    scraping::aplicacion::GestorTareas::scrapearTwitter();
    this->emitirProgreso(25);
    scraping::aplicacion::GestorTareas::scrapearFacebook();
    this->emitirProgreso(40);
    scraping::aplicacion::GestorTareas::depurarYAnalizarContenidos();
    this->emitirProgreso(70);
    scraping::aplicacion::GestorTareas::prepararYAlmacenarContenidos();
    this->emitirProgreso(100);
}
