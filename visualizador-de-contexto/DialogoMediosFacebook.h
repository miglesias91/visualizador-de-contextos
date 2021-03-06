#pragma once

#include <QWidget>

// qt
#include <qmessagebox.h>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

// scraping::extraccion
#include <extraccion/include/Medio.h>

// visualizador
#include <visualizador-de-contexto/DialogoEditarMedioFacebook.h>
#include <declaraciones_metatipos.h>

namespace Ui { class DialogoMediosFacebook; };

class DialogoMediosFacebook : public QWidget
{
    Q_OBJECT

public:
    DialogoMediosFacebook(QWidget *parent = Q_NULLPTR);
    ~DialogoMediosFacebook();
    
    virtual void hideEvent(QHideEvent * evento);
    virtual void showEvent(QShowEvent * evento);

signals:

    void se_cerro();
    void se_abrio();

private slots:
    void actualizar_y_cerrar();

    void resetear();

    void eliminar();

    void estado_btn_eliminar();

    void nueva_pagina();

    void guardar();
    void cerrar();

private:
    Ui::DialogoMediosFacebook *ui;

    void conectar_componentes();

    // METODOS PRIVADOS

    void cargarListaMediosFacebook();

    void descargarListaMediosFacebook();

    // agregar un termino a la lista de terminos de la ui.
    void agregarMedioFacebookALista(modelo::MedioFacebook * medio_facebook);

    void registrar_abm();

    // mensajes

    QMessageBox * crearInformacionMedioFacebookExistente();

    // ATRIBUTOS
    visualizador::aplicacion::GestorEntidades gestor_medios;

    DialogoEditarMedioFacebook * dialogo_editar_medio_facebook;
};
