#pragma once

#include <QWidget>

// qt
#include <qmessagebox.h>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

// scraping::extraccion
#include <extraccion/include/Medio.h>

// scraping::twitter
#include <twitter/include/Cuenta.h>

// visualizador
#include <declaraciones_metatipos.h>

namespace Ui { class DialogoMediosTwitter; };

class DialogoMediosTwitter : public QWidget
{
    Q_OBJECT

public:
    DialogoMediosTwitter(QWidget *parent = Q_NULLPTR);
    ~DialogoMediosTwitter();

private slots:
    void on_action_actualizar_y_cerrar_triggered();

    void on_action_resetear_cuenta_triggered();

    void on_action_guardar_cuenta_triggered();

    void on_action_eliminar_cuenta_triggered();

    void on_action_estado_btn_eliminar_triggered();

    void on_action_estado_btn_agregar_triggered();

private:
    Ui::DialogoMediosTwitter *ui;

    void cargarListaMediosTwitter();

    void descargarListaMediosTwitter();

    // agregar un termino a la lista de terminos de la ui.
    void agregarMedioTwitterALista(modelo::Medio * medio);

    // mensajes

    QMessageBox * crearInformacionMedioTwitterExistente();

    // ATRIBUTOS
    visualizador::aplicacion::GestorEntidades gestor_medios;
};
