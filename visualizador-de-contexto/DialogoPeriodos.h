#pragma once

#include <QWidget>

// qt
#include <qmessagebox.h>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

// modelo
#include <modelo/include/Periodo.h>

// visualizador
#include <declaraciones_metatipos.h>

namespace Ui { class DialogoPeriodos; };

class DialogoPeriodos : public QWidget
{
    Q_OBJECT

public:
    DialogoPeriodos(QWidget *parent = Q_NULLPTR);
    ~DialogoPeriodos();

    virtual void hideEvent(QHideEvent * evento);
    virtual void showEvent(QShowEvent * evento);

signals:

    void se_cerro();
    void se_abrio();

private slots:
    void guardar_periodo();

    void limpiar_periodo();

    void eliminar_periodo();

    void actualizar_y_cerrar();

    void estado_btn_eliminar();

    void estado_btn_agregar();

    void guardar();

    void cerrar();

private:
    Ui::DialogoPeriodos *ui;

    // METODOS INTERNOS

    void agregarPeriodoALista(visualizador::modelo::Periodo* periodo);

    void cargarListaPeriodos();

    void descargarListaPeriodos();
    
    void cargarComboboxesDesdeYHasta();

    void descargarComboboxesDesdeYHasta();

    //visualizador::modelo::Fecha * fechaDesdeSeleccionada();
    //
    //visualizador::modelo::Fecha * fechaHastaSeleccionada();

    // MENSAJES

    QMessageBox * crearInformacionPeriodoExistente();
    QMessageBox * crearErrorFechaDesdeMayorAFechaHasta();

    // ATRIBUTOS

    visualizador::aplicacion::GestorEntidades gestor_periodos;
};
