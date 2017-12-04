#include <visualizador-de-contexto/include/FabricaMensajes.h>

using namespace comunicacion;

FabricaMensajes::FabricaMensajes()
{
}

FabricaMensajes::~FabricaMensajes()
{
}

QMessageBox * FabricaMensajes::fabricar(visualizador::aplicacion::comunicacion::Informacion * mensaje_informacion)
{
    QString titulo = QString(mensaje_informacion->getTitulo().c_str());
    QString texto = QString(mensaje_informacion->getTexto().c_str());
    QFlags<QMessageBox::StandardButton> botones;
    botones.setFlag(QMessageBox::StandardButton::Ok);
    QMessageBox * mensaje = new QMessageBox(QMessageBox::Icon::Information, titulo, texto, botones);

    return mensaje;
}

QMessageBox * FabricaMensajes::fabricar(visualizador::aplicacion::comunicacion::Error * mensaje_error)
{
    QString titulo = QString(mensaje_error->getTitulo().c_str());
    QString texto = QString(mensaje_error->getTexto().c_str());
    QFlags<QMessageBox::StandardButton> botones;
    botones.setFlag(QMessageBox::StandardButton::Ok);
    QMessageBox * mensaje = new QMessageBox(QMessageBox::Icon::Critical, titulo, texto, botones);

    return mensaje;
}

QMessageBox * FabricaMensajes::fabricar(visualizador::aplicacion::comunicacion::Advertencia * mensaje_advertencia)
{
    QString titulo = QString(mensaje_advertencia->getTitulo().c_str());
    QString texto = QString(mensaje_advertencia->getTexto().c_str());
    QFlags<QMessageBox::StandardButton> botones;
    botones.setFlag(QMessageBox::StandardButton::Ok);
    QMessageBox * mensaje = new QMessageBox(QMessageBox::Icon::Warning, titulo, texto, botones);

    return mensaje;
}

QMessageBox * FabricaMensajes::fabricar(visualizador::aplicacion::comunicacion::Pregunta * mensaje_pregunta)
{
    QString titulo = QString(mensaje_pregunta->getTitulo().c_str());
    QString texto = QString(mensaje_pregunta->getTexto().c_str());
    QFlags<QMessageBox::StandardButton> botones;
    botones.setFlag(QMessageBox::StandardButton::Yes);
    botones.setFlag(QMessageBox::StandardButton::No);
    QMessageBox * mensaje = new QMessageBox(QMessageBox::Icon::Question, titulo, texto, botones);

    return mensaje;
}
