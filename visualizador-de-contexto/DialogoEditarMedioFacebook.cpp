#include "DialogoEditarMedioFacebook.h"
#include "ui_DialogoEditarMedioFacebook.h"

DialogoEditarMedioFacebook::DialogoEditarMedioFacebook(modelo::MedioFacebook * medio_facebook_nuevo, visualizador::aplicacion::GestorEntidades * gestor_medios, QWidget *parent)
    : QDialog(parent)
{
    ui = new Ui::DialogoEditarMedioFacebook();
    ui->setupUi(this);

    aplicacion::Logger::info("Iniciando dialogo Editar Medios Facebook.");

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->ui->lineedit_etiqueta->setText(concepto_a_editar->getEtiqueta().c_str());
    this->etiqueta_original = concepto_a_editar->getEtiqueta();

    this->cargarListaTerminos(concepto_a_editar);
}

DialogoEditarMedioFacebook::~DialogoEditarMedioFacebook()
{
    this->descargarListaTerminos();

    aplicacion::Logger::info("Cerrando dialogo Editar Medios Facebook.");

    delete ui;
}
