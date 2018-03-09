#pragma once

#include <QWidget>

// visualizador-de-contexto
#include <visualizador-de-contexto/include/FabricaMensajes.h>

// aplicacion
#include <aplicacion/include/Logger.h>
#include <aplicacion/include/GestorEntidades.h>

// modelo
#include <modelo/include/Concepto.h>

// visualizador
#include <declaraciones_metatipos.h>

namespace Ui { class DialogoEditarConcepto; };

class DialogoEditarConcepto : public QWidget
{
    Q_OBJECT

public:
    DialogoEditarConcepto(visualizador::modelo::Concepto * concepto_a_editar, QWidget *parent = Q_NULLPTR);
    ~DialogoEditarConcepto();

private slots:
    void on_action_eliminar_triggered();

    void on_action_nuevo_triggered();

    void on_action_ok_triggered();

    void on_action_editar_triggered();

private:
    Ui::DialogoEditarConcepto *ui;

    // METODOS INTERNOS

    void cargarListaTerminos(visualizador::modelo::Concepto * concepto_a_editar);

    void descargarListaTerminos();

    // ATRIBUTOS

    visualizador::aplicacion::GestorEntidades gestor_terminos_totales;
    visualizador::aplicacion::GestorEntidades gestor_terminos_de_concepto;
};
