#pragma once

#include <QWidget>

// qt
#include <qmessagebox.h>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

// scraping::extraccion
#include <extraccion/include/Medio.h>

// scraping::facebook
#include <facebook/include/Pagina.h>

// visualizador
#include <declaraciones_metatipos.h>

namespace Ui { class DialogoMediosFacebook; };

class DialogoMediosFacebook : public QWidget
{
    Q_OBJECT

public:
    DialogoMediosFacebook(QWidget *parent = Q_NULLPTR);
    ~DialogoMediosFacebook();

private slots:
    void on_action_actualizar_y_cerrar_triggered();

    void on_action_resetear_triggered();

    void on_action_guardar_triggered();

    void on_action_eliminar_triggered();

    void on_action_estado_btn_eliminar_triggered();

    void on_action_estado_btn_agregar_triggered();

private:
    Ui::DialogoMediosFacebook *ui;

    // METODOS PRIVADOS

    void cargarListaMediosFacebook();

    void descargarListaMediosFacebook();

    // agregar un termino a la lista de terminos de la ui.
    void agregarMedioFacebookALista(modelo::MedioFacebook * medio_facebook);

    // mensajes

    QMessageBox * crearInformacionMedioFacebookExistente();

    // ATRIBUTOS
    visualizador::aplicacion::GestorEntidades gestor_medios;
};
