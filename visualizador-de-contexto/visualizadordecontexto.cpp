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
    : QMainWindow(parent),
    dialogo_terminos(nullptr), dialogo_conceptos(nullptr), dialogo_fechas(nullptr), dialogo_periodos(nullptr), dialogo_consultas(nullptr), dialogo_activo(nullptr),
    hay_dialogo_abierto(false)
{
	ui.setupUi(this);

    this->conectar_componentes();

    visualizador::aplicacion::Logger::marca("INICIO INTERFAZ QT");

    this->ui.btn_fechas->setEnabled(false);
    this->ui.btn_fechas->setVisible(false);
    this->ui.btn_periodos->setEnabled(false);
    this->ui.btn_periodos->setVisible(false);

    this->ui.bar_analizar_ctx->hide();
}

visualizadordecontexto::~visualizadordecontexto()
{
    visualizador::aplicacion::Logger::marca("FIN INTERFAZ QT");
}

void visualizadordecontexto::abrir_terminos() {
    
    this->guardar_activo();

	this->dialogo_terminos = new DialogoTerminos(this->ui.widget_area_trabajo);
    this->dialogo_terminos->showMaximized();
    this->ui.layout_ventana_abierta->addWidget(this->dialogo_terminos);

    QObject::connect(this->dialogo_terminos, &DialogoTerminos::se_cerro, this, &visualizadordecontexto::sin_dialogo_activo);

    this->hay_dialogo_abierto = true;
    this->dialogo_activo = this->dialogo_terminos;
}

void visualizadordecontexto::abrir_conceptos() {

    this->guardar_activo();

    this->dialogo_conceptos = new DialogoConceptos(this->ui.widget_area_trabajo);
    dialogo_conceptos->showMaximized();
    this->ui.layout_ventana_abierta->addWidget(this->dialogo_conceptos);

    QObject::connect(this->dialogo_conceptos, &DialogoConceptos::se_cerro, this, &visualizadordecontexto::sin_dialogo_activo);

    this->hay_dialogo_abierto = true;
    this->dialogo_activo = this->dialogo_conceptos;
}

void visualizadordecontexto::abrir_fechas() {

    this->guardar_activo();

    this->dialogo_fechas = new DialogoFechas(this->ui.widget_area_trabajo);
    this->dialogo_fechas->showMaximized();
    this->ui.layout_ventana_abierta->addWidget(this->dialogo_fechas);

    QObject::connect(this->dialogo_fechas, &DialogoFechas::se_cerro, this, &visualizadordecontexto::sin_dialogo_activo);

    this->hay_dialogo_abierto = true;
    this->dialogo_activo = this->dialogo_fechas;
}

void visualizadordecontexto::abrir_periodos() {

    this->guardar_activo();

    this->dialogo_periodos = new DialogoPeriodos(this->ui.widget_area_trabajo);
    this->dialogo_periodos->showMaximized();
    this->ui.layout_ventana_abierta->addWidget(this->dialogo_periodos);

    QObject::connect(this->dialogo_periodos, &DialogoPeriodos::se_cerro, this, &visualizadordecontexto::sin_dialogo_activo);

    this->hay_dialogo_abierto = true;
    this->dialogo_activo = this->dialogo_periodos;
}

void visualizadordecontexto::abrir_consulta() {

    this->guardar_activo();

    this->dialogo_consultas = new DialogoConsultas(this->ui.widget_area_trabajo);
    this->dialogo_consultas->showMaximized();
    this->ui.layout_ventana_abierta->addWidget(this->dialogo_consultas);

    QObject::connect(this->dialogo_consultas, &DialogoConsultas::se_cerro, this, &visualizadordecontexto::sin_dialogo_activo);

    this->hay_dialogo_abierto = true;
    this->dialogo_activo = this->dialogo_consultas;
}

void visualizadordecontexto::abrir_medios_twitter() {

    this->guardar_activo();

    this->dialogo_medios_twitter = new DialogoMediosTwitter(this->ui.widget_area_trabajo);
    this->dialogo_medios_twitter->showMaximized();
    this->ui.layout_ventana_abierta->addWidget(this->dialogo_medios_twitter);

    QObject::connect(this->dialogo_medios_twitter, &DialogoMediosTwitter::se_cerro, this, &visualizadordecontexto::sin_dialogo_activo);

    this->hay_dialogo_abierto = true;
    this->dialogo_activo = this->dialogo_medios_twitter;
}

void visualizadordecontexto::abrir_medios_facebook() {

    this->guardar_activo();

    this->dialogo_medios_facebook = new DialogoMediosFacebook(this->ui.widget_area_trabajo);
    this->dialogo_medios_facebook->showMaximized();
    this->ui.layout_ventana_abierta->addWidget(this->dialogo_medios_facebook);

    QObject::connect(this->dialogo_medios_facebook, &DialogoMediosFacebook::se_cerro, this, &visualizadordecontexto::sin_dialogo_activo);

    this->hay_dialogo_abierto = true;
    this->dialogo_activo = this->dialogo_medios_facebook;
}

void visualizadordecontexto::abrir_medios_portales() {

    this->guardar_activo();

    this->dialogo_medios_portales = new DialogoMediosPortales(this->ui.widget_area_trabajo);
    this->dialogo_medios_portales->showMaximized();
    this->ui.layout_ventana_abierta->addWidget(this->dialogo_medios_portales);

    QObject::connect(this->dialogo_medios_portales, &DialogoMediosPortales::se_cerro, this, &visualizadordecontexto::sin_dialogo_activo);

    this->hay_dialogo_abierto = true;
    this->dialogo_activo = this->dialogo_medios_portales;
}

void visualizadordecontexto::guardar_activo() {

    if (this->hay_dialogo_abierto) {
        QMetaObject::invokeMethod(this->dialogo_activo, "guardar");
    }
}

void visualizadordecontexto::hay_dialogo_activo() {
    this->hay_dialogo_abierto = true;
}

void visualizadordecontexto::sin_dialogo_activo() {
    this->hay_dialogo_abierto = false;
    this->dialogo_activo = nullptr;
}

void visualizadordecontexto::analizar_ctx() {

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
    QObject::connect(this->ui.btn_medios_portales, &QPushButton::released, this, &visualizadordecontexto::abrir_medios_portales);

    QObject::connect(this->ui.btn_consulta, &QPushButton::released, this, &visualizadordecontexto::abrir_consulta);
    QObject::connect(this->ui.btn_analizar_ctx, &QPushButton::released, this, &visualizadordecontexto::analizar_ctx);
}

void visualizadordecontexto::tarea_analizar_ctx() 
{
    //this->emitirProgreso(10);
    //scraping::aplicacion::GestorTareas::scrapearTwitter();
    //this->emitirProgreso(25);
    //scraping::aplicacion::GestorTareas::scrapearFacebook();
    //this->emitirProgreso(40);
    //scraping::aplicacion::GestorTareas::depurarYAnalizarContenidos();
    //this->emitirProgreso(70);
    //scraping::aplicacion::GestorTareas::prepararYAlmacenarContenidos();
    //this->emitirProgreso(100);
}
