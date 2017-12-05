#pragma once

#include <QWidget>

// qt
#include <qmessagebox.h>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

// modelo
#include <modelo/include/Concepto.h>
#include <modelo/include/Termino.h>

// visualizador
#include <declaraciones_metatipos.h>

namespace Ui { class DialogoConceptos; };

class DialogoConceptos : public QWidget
{
    Q_OBJECT

public:
    DialogoConceptos(QWidget *parent = Q_NULLPTR);
    ~DialogoConceptos();

private slots:
    void on_action_actualizar_y_cerrar_triggered();

    void on_action_resetear_concepto_triggered();

    void on_action_eliminar_concepto_triggered();

    void on_action_guardar_concepto_triggered();

    void on_action_estado_btn_eliminar_triggered();

    void on_action_estado_btn_agregar_triggered();

private:
    Ui::DialogoConceptos *ui;

    // agregar un concepto a la lista de terminos de la ui.
    void agregarConceptoALista(visualizador::modelo::Concepto* concepto);

    void cargarListaConceptos();

    void descargarListaConceptos();

    std::vector<visualizador::modelo::Termino*> terminosSeleccionados();

    void cargarListaTerminos();

    void descargarListaTerminos();

    // mensajes

    QMessageBox * crearInformacionConceptoExistente();

    // ATRIBUTOS
    visualizador::aplicacion::GestorEntidades gestor_conceptos;
};

