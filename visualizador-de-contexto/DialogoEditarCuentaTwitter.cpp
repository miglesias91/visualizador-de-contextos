#include "DialogoEditarCuentaTwitter.h"
#include "ui_DialogoEditarCuentaTwitter.h"

DialogoEditarCuentaTwitter::DialogoEditarCuentaTwitter(visualizador::modelo::MedioTwitter * medio_twitter_nuevo, visualizador::aplicacion::GestorEntidades * gestor_medios, QWidget *parent)
    : QDialog(parent)
{
    ui = new Ui::DialogoEditarCuentaTwitter();
    ui->setupUi(this);

    aplicacion::Logger::info("Iniciando dialogo Editar Medios Twitter.");

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->ui->lineedit_etiqueta->setText(concepto_a_editar->getEtiqueta().c_str());
    this->etiqueta_original = concepto_a_editar->getEtiqueta();

    this->cargarListaTerminos(concepto_a_editar);
}

DialogoEditarCuentaTwitter::~DialogoEditarCuentaTwitter()
{
    this->descargarListaTerminos();

    aplicacion::Logger::info("Cerrando dialogo Editar Medios Twitter.");

    delete ui;
}
