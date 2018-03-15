#pragma once

#include <QDialog>

// visualizador-de-contexto
#include <visualizador-de-contexto/include/FabricaMensajes.h>

// aplicacion
#include <aplicacion/include/Logger.h>
#include <aplicacion/include/GestorEntidades.h>

// modelo
#include <modelo/include/MedioFacebook.h>

// visualizador
#include <declaraciones_metatipos.h>

namespace Ui { class DialogoEditarMedioFacebook; };

class DialogoEditarMedioFacebook : public QDialog
{
    Q_OBJECT

public:
    DialogoEditarMedioFacebook(visualizador::modelo::MedioFacebook * medio_facebook_nuevo, visualizador::aplicacion::GestorEntidades * gestor_medios, QWidget *parent = Q_NULLPTR);
    ~DialogoEditarMedioFacebook();

public slots:

    void ok();
    void cancelar();

private:
    Ui::DialogoEditarMedioFacebook *ui;

    // MENSAJES

    QMessageBox * crearInformacionEtiquetaVacia();
    QMessageBox * crearInformacionNombreVacio();

    // ATRIBUTOS
    visualizador::modelo::MedioFacebook * medio_facebook;
};
