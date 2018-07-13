#pragma once

#include <QWidget>

// qt
#include <qmessagebox.h>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

// scraping::extraccion
#include <extraccion/include/Medio.h>

// visualizador
#include <visualizador-de-contexto/DialogoEditarCuentaTwitter.h>
#include <declaraciones_metatipos.h>

namespace Ui { class DialogoMediosTwitter; };

class DialogoMediosTwitter : public QWidget
{
    Q_OBJECT

public:
    DialogoMediosTwitter(QWidget *parent = Q_NULLPTR);
    ~DialogoMediosTwitter();

    virtual void hideEvent(QHideEvent * evento);
    virtual void showEvent(QShowEvent * evento);

signals:

    void se_cerro();
    void se_abrio();

private slots:
    void actualizar_y_cerrar();

    void resetear_cuenta();

    void eliminar_cuenta();

    void estado_btn_eliminar();

    void nueva_cuenta();

    void guardar();

    void cerrar();

private:
    Ui::DialogoMediosTwitter *ui;

    void conectar_componentes();

    void cargarListaMediosTwitter();

    void descargarListaMediosTwitter();

    // agregar un termino a la lista de terminos de la ui.
    void agregarMedioTwitterALista(modelo::MedioTwitter * medio_twitter);

    // mensajes

    QMessageBox * crearInformacionMedioTwitterExistente();

    // ATRIBUTOS
    visualizador::aplicacion::GestorEntidades gestor_medios;

    DialogoEditarCuentaTwitter * dialogo_editar_medio_twitter;
};
