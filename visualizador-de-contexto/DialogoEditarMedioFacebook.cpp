#include "DialogoEditarMedioFacebook.h"
#include "ui_DialogoEditarMedioFacebook.h"

DialogoEditarMedioFacebook::DialogoEditarMedioFacebook(modelo::MedioFacebook * medio_facebook_nuevo, visualizador::aplicacion::GestorEntidades * gestor_medios, QWidget *parent)
    : medio_facebook(medio_facebook_nuevo), QDialog(parent)
{
    ui = new Ui::DialogoEditarMedioFacebook();
    ui->setupUi(this);

    this->conectar_componentes();

    aplicacion::Logger::info("Iniciando dialogo Editar Medios Facebook.");

    this->setAttribute(Qt::WA_DeleteOnClose);
}

DialogoEditarMedioFacebook::~DialogoEditarMedioFacebook()
{
    aplicacion::Logger::info("Cerrando dialogo Editar Medios Facebook.");

    delete ui;
}

// SLOTS
void DialogoEditarMedioFacebook::guardar()
{
    if (this->ui->lineedit_etiqueta->text().isEmpty())
    {
        QMessageBox * informacion_etiqueta_vacia = this->crearInformacionEtiquetaVacia();
        informacion_etiqueta_vacia->exec();

        delete informacion_etiqueta_vacia;

        return;
    }

    if (this->ui->lineedit_nombre_pagina->text().isEmpty())
    {
        QMessageBox * informacion_nombre_vacio = this->crearInformacionNombreVacio();
        informacion_nombre_vacio->exec();

        delete informacion_nombre_vacio;

        return;
    }

    std::string etiqueta = this->ui->lineedit_etiqueta->text().toStdString();
    std::string nombre_pagina = this->ui->lineedit_nombre_pagina->text().toStdString();

    this->medio_facebook->setEtiqueta(etiqueta);
    this->medio_facebook->setNombrePagina(nombre_pagina);

    this->accept();
}

void DialogoEditarMedioFacebook::cancelar()
{
    this->close();
}

// MENSAJES

QMessageBox * DialogoEditarMedioFacebook::crearInformacionEtiquetaVacia()
{
    std::string texto = u8"No se asigno la etiqueta. La etiqueta sirve para describir e identificar al medio en las consultas.";
    visualizador::aplicacion::comunicacion::Informacion informacion_etiqueta_vacia(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_etiqueta_vacia);
}

QMessageBox * DialogoEditarMedioFacebook::crearInformacionNombreVacio()
{
    std::string texto = u8"No se asigno un nombre de página.";
    visualizador::aplicacion::comunicacion::Informacion informacion_etiqueta_vacia(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_etiqueta_vacia);
}

void DialogoEditarMedioFacebook::conectar_componentes() {

    QObject::connect(this->ui->btn_guardar, &QPushButton::released, this, &DialogoEditarMedioFacebook::guardar);
    QObject::connect(this->ui->btn_cancelar, &QPushButton::released, this, &DialogoEditarMedioFacebook::cancelar);
}