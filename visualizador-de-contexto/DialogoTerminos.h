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

	// agregar un termino a la lista de terminos de la ui.
	void agregarTerminoALista(visualizador::modelo::Termino* termino);

	// chequea que existe el termino en la lista de terminos de la ui.
	bool existeTermino(visualizador::modelo::Termino* termino);

	// almacena logicamente el termino.
	void almacenarTermino(visualizador::modelo::Termino* termino);

	// elimina logicamente el termino.
	void eliminarTermino(visualizador::modelo::Termino* termino);

	// ATRIBUTOS

	// lista de terminos que NO ESTAN en la bd y se quieren agregar. se usa para operar logicamente.
	std::vector<visualizador::modelo::Termino*> terminos_a_almacenar;
	
	// lista de terminos que SI ESTAN en la bd y se quieren eliminar. se usa para operar logicamente.
	std::vector<visualizador::modelo::Termino*> terminos_a_eliminar;

	std::vector<visualizador::modelo::Termino*>::iterator terminos_it;

};

Q_DECLARE_METATYPE(visualizador::modelo::Termino*)
