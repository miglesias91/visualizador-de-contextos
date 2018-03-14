#pragma once

#include <QDialog>

// qt
#include <qlistwidget.h>

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

class DialogoEditarConcepto : public QDialog
{
    Q_OBJECT

public:
    DialogoEditarConcepto(visualizador::modelo::Concepto * concepto_a_editar, visualizador::aplicacion::GestorEntidades * gestor_terminos, QWidget *parent = Q_NULLPTR);
    ~DialogoEditarConcepto();

private slots:
    void on_action_eliminar_triggered();

    void on_action_nuevo_triggered();

    void on_action_ok_triggered();

    void termino_actualizado(QListWidgetItem * item_actualizado);

    void guardar_termino_sin_editar(QListWidgetItem * item_actual, QListWidgetItem * item_previo);

private:
    Ui::DialogoEditarConcepto *ui;

    // METODOS INTERNOS

    bool etiquetaModificada();
    bool listaDeTerminosModificada();

    void cargarListaTerminos(visualizador::modelo::Concepto * concepto_a_editar);

    void descargarListaTerminos();

    QMessageBox * crearInformacionTerminoExistente();
    QMessageBox * crearInformacionEtiquetaVacia();
    QMessageBox * crearInformacionListaDeTerminosVacia();

    // ATRIBUTOS

    std::string etiqueta_original;

    std::string termino_sin_editar;

    visualizador::modelo::Concepto * concepto_a_editar;
    visualizador::aplicacion::GestorEntidades * gestor_terminos;
    visualizador::aplicacion::GestorEntidades gestor_terminos_de_concepto;
};
