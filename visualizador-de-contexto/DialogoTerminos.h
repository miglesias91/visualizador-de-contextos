#pragma once

#include <QWidget>

// qt
#include <qmessagebox.h>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

// modelo
#include <modelo/include/Termino.h>

// visualizador
#include <declaraciones_metatipos.h>

namespace Ui { class DialogoTerminos; };

class DialogoTerminos : public QWidget
{
	Q_OBJECT

public:
	DialogoTerminos(QWidget *parent = Q_NULLPTR);
	~DialogoTerminos();

private slots:
    void on_action_actualizar_y_cerrar_triggered();

    void on_action_resetear_termino_triggered();

    void on_action_guardar_termino_triggered();

    void on_action_eliminar_termino_triggered();

    void on_action_estado_btn_eliminar_triggered();

    void on_action_estado_btn_agregar_triggered();

private:

	Ui::DialogoTerminos *ui;

    void cargarListaTerminos();

    void descargarListaTerminos();

    // agregar un termino a la lista de terminos de la ui.
    void agregarTerminoALista(visualizador::modelo::Termino* termino);

    // mensajes

    QMessageBox * crearAdvertenciaTerminoConRelacionesDependientes();
    QMessageBox * crearInformacionTerminoExistente();

	// ATRIBUTOS
    visualizador::aplicacion::GestorEntidades gestor_terminos;

};
