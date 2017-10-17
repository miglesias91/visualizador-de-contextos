#pragma once

#include <QWidget>

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

    void on_action_resetear_triggered();

    void on_action_guardar_triggered();

    void on_action_eliminar_triggered();

private:

	Ui::DialogoTerminos *ui;

	// METODOS
	void actualizarTerminos();

	void agregarTerminoALista(visualizador::modelo::Termino* termino);

	// ATRIBUTOS

	std::vector<visualizador::modelo::Termino*> terminos_actuales;
	std::vector<visualizador::modelo::Termino*> terminos_a_agregar;
	std::vector<visualizador::modelo::Termino*> terminos_a_eliminar;

};
