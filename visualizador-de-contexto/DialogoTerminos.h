#pragma once

#include <QWidget>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

// modelo
#include <modelo/include/Termino.h>

namespace Ui { class DialogoTerminos; };

class DialogoTerminos : public QWidget
{
	Q_OBJECT

public:
	DialogoTerminos(QWidget *parent = Q_NULLPTR);
	~DialogoTerminos();

private slots:
    void on_action_actualizarYCerrar_triggered();

    void on_action_resetear_termino_triggered();

    void on_action_guardar_termino_triggered();

    void on_action_eliminar_termino_triggered();

private:

	Ui::DialogoTerminos *ui;

	// agregar un termino a la lista de terminos de la ui.
	void agregarTerminoALista(visualizador::modelo::Termino* termino);

	// ATRIBUTOS
    visualizador::aplicacion::GestorEntidades gestor_terminos;

};

Q_DECLARE_METATYPE(visualizador::modelo::Termino*)
