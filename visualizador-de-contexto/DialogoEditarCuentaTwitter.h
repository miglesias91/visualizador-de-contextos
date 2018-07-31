#pragma once

#include <QDialog>

// visualizador-de-contexto
#include <visualizador-de-contexto/include/FabricaMensajes.h>

// aplicacion
#include <aplicacion/include/Logger.h>
#include <aplicacion/include/GestorEntidades.h>

// modelo
#include <modelo/include/MedioTwitter.h>

// visualizador
#include <declaraciones_metatipos.h>

namespace Ui { class DialogoEditarCuentaTwitter; };

class DialogoEditarCuentaTwitter : public QDialog
{
    Q_OBJECT

public:
    DialogoEditarCuentaTwitter(visualizador::modelo::MedioTwitter * medio_twitter_nuevo, visualizador::aplicacion::GestorEntidades * gestor_medios, QWidget *parent = Q_NULLPTR);
    ~DialogoEditarCuentaTwitter();

public slots:

    void guardar();
    void cancelar();

private:
    Ui::DialogoEditarCuentaTwitter *ui;

    void conectar_componentes();

    // MENSAJES

    QMessageBox * crearInformacionEtiquetaVacia();
    QMessageBox * crearInformacionNombreVacio();
    QMessageBox * crearInformacionCuentaInexistente();

    // ATRIBUTOS
    visualizador::modelo::MedioTwitter * medio_twitter;
};
