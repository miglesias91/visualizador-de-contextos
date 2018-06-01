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
#include <visualizador-de-contexto/DialogoEditarConcepto.h>
#include <declaraciones_metatipos.h>


namespace Ui { class DialogoConceptos; };

class DialogoConceptos : public QWidget
{
    Q_OBJECT

public:
    DialogoConceptos(QWidget *parent = Q_NULLPTR);
    ~DialogoConceptos();

    virtual void hideEvent(QHideEvent * evento);
    virtual void showEvent(QShowEvent * evento);

signals:

    void se_cerro();
    void se_abrio();

private slots:
    void actualizar_y_cerrar();

    void resetear_concepto();

    void eliminar_concepto();

    void estado_btn_eliminar();

    void concepto_dobleclikeado(QListWidgetItem * item_dobleclikeado);

    void nuevo_concepto();

    void guardar();

    void cerrar();

private:
    Ui::DialogoConceptos *ui;

    void conectar_componentes();

    // agregar un concepto a la lista de terminos de la ui.
    void agregarConceptoALista(visualizador::modelo::Concepto* concepto);

    void cargarListaConceptos();

    void descargarListaConceptos();

    std::vector<visualizador::modelo::Concepto*> conceptosSeleccionados();

    // mensajes

    QMessageBox * crearInformacionConceptoExistente();

    // ATRIBUTOS
    visualizador::aplicacion::GestorEntidades gestor_conceptos;
    visualizador::aplicacion::GestorEntidades gestor_terminos;

    DialogoEditarConcepto * dialogo_editar_concepto;
};

