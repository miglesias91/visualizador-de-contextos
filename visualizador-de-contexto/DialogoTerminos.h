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

private:

	Ui::DialogoTerminos *ui;
    
    void conectar_componentes();

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
