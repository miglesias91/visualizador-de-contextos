#pragma once

#include <QWidget>

// qt
#include <qmessagebox.h>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

// modelo
#include <modelo/include/Fecha.h>

// visualizador
#include <declaraciones_metatipos.h>

namespace Ui { class DialogoFechas; };

class DialogoFechas : public QWidget
{
    Q_OBJECT

public:
    DialogoFechas(QWidget *parent = Q_NULLPTR);
    ~DialogoFechas();
    
    virtual void hideEvent(QHideEvent * evento);
    virtual void showEvent(QShowEvent * evento);

signals:

    void se_cerro();
    void se_abrio();

private slots:
    void guardar_fecha();

    void limpiar_fecha();

    void eliminar_fecha();

    void actualizar_y_cerrar();

    void estado_btn_eliminar();

    void guardar();

    void cerrar();

private:
    Ui::DialogoFechas *ui;

    // agregar una fecha a la lista de fechas de la ui.
    void agregarFechaALista(visualizador::modelo::Fecha* fecha);

    // descargo la lista de fechas
    void cargarListaFechas();

    // descargo la lista de fechas
    void descargarListaFechas();

    // mensajes

    QMessageBox * crearAdvertenciaFechaConRelacionesDependientes();
    QMessageBox * crearInformacionFechaExistente();

    // ATRIBUTOS

    visualizador::aplicacion::GestorEntidades gestor_fechas;
};
