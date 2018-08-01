#include "DialogoEditarCuentaTwitter.h"
#include "ui_DialogoEditarCuentaTwitter.h"

// medios
#include <twitter/include/Aplicacion.h>

DialogoEditarCuentaTwitter::DialogoEditarCuentaTwitter(visualizador::modelo::MedioTwitter * medio_twitter_nuevo, visualizador::aplicacion::GestorEntidades * gestor_medios, QWidget *parent)
    : medio_twitter(medio_twitter_nuevo), QDialog(parent)
{
    ui = new Ui::DialogoEditarCuentaTwitter();
    ui->setupUi(this);

    this->conectar_componentes();

    aplicacion::Logger::info("Iniciando dialogo Editar Medios Twitter.");

    this->setAttribute(Qt::WA_DeleteOnClose);
}

DialogoEditarCuentaTwitter::~DialogoEditarCuentaTwitter()
{
    aplicacion::Logger::info("Cerrando dialogo Editar Medios Twitter.");

    delete ui;
}

// SLOTS
void DialogoEditarCuentaTwitter::guardar()
{
    if (this->ui->lineedit_etiqueta->text().isEmpty())
    {
        QMessageBox * informacion_etiqueta_vacia = this->crearInformacionEtiquetaVacia();
        informacion_etiqueta_vacia->exec();

        delete informacion_etiqueta_vacia;

        return;
    }

    if (this->ui->lineedit_nombre_cuenta->text().isEmpty())
    {
        QMessageBox * informacion_nombre_vacio = this->crearInformacionNombreVacio();
        informacion_nombre_vacio->exec();

        delete informacion_nombre_vacio;

        return;
    }

    std::string etiqueta = this->ui->lineedit_etiqueta->text().toStdString();
    std::string nombre_cuenta = this->ui->lineedit_nombre_cuenta->text().toStdString();

    if (false == medios::twitter::Aplicacion::existe(nombre_cuenta)) {
        QMessageBox * informacion_cuenta_inexistente = this->crearInformacionCuentaInexistente();
        informacion_cuenta_inexistente->exec();

        delete informacion_cuenta_inexistente;

        return;
    }

    this->medio_twitter->setEtiqueta(etiqueta);
    this->medio_twitter->setNombreUsuario(nombre_cuenta);

    this->accept();
}

void DialogoEditarCuentaTwitter::cancelar()
{
    this->close();
}

// MENSAJES

QMessageBox * DialogoEditarCuentaTwitter::crearInformacionEtiquetaVacia()
{
    std::string texto = u8"No se asigno la etiqueta. La etiqueta sirve para describir e identificar al medio en las consultas.";
    visualizador::aplicacion::comunicacion::Informacion informacion_etiqueta_vacia(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_etiqueta_vacia, this);
}

QMessageBox * DialogoEditarCuentaTwitter::crearInformacionNombreVacio()
{
    std::string texto = u8"No se asigno un nombre de cuenta.";
    visualizador::aplicacion::comunicacion::Informacion informacion_etiqueta_vacia(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_etiqueta_vacia, this);
}

QMessageBox * DialogoEditarCuentaTwitter::crearInformacionCuentaInexistente() {
    std::string texto = u8"La cuenta \"" + this->ui->lineedit_nombre_cuenta->text().toStdString() + "\" no existe. ";
    visualizador::aplicacion::comunicacion::Informacion informacion_etiqueta_vacia(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_etiqueta_vacia, this);
}

void DialogoEditarCuentaTwitter::conectar_componentes() {

    QObject::connect(this->ui->btn_guardar, &QPushButton::released, this, &DialogoEditarCuentaTwitter::guardar);
    QObject::connect(this->ui->btn_cancelar, &QPushButton::released, this, &DialogoEditarCuentaTwitter::cancelar);
}