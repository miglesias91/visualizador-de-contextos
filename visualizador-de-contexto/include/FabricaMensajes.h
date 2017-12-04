#pragma once

// qt
#include <qmessagebox.h>

// aplicacion
#include <aplicacion/include/Advertencia.h>
#include <aplicacion/include/Informacion.h>
#include <aplicacion/include/Error.h>
#include <aplicacion/include/Pregunta.h>

namespace comunicacion
{

class FabricaMensajes
{
public:
    FabricaMensajes();
    virtual ~FabricaMensajes();

    // METODOS PREDEFINIDOS

    // METODOS

    static QMessageBox * fabricar(visualizador::aplicacion::comunicacion::Informacion * mensaje_informacion);
    static QMessageBox * fabricar(visualizador::aplicacion::comunicacion::Error * mensaje_error);
    static QMessageBox * fabricar(visualizador::aplicacion::comunicacion::Advertencia * mensaje_advertencia);
    static QMessageBox * fabricar(visualizador::aplicacion::comunicacion::Pregunta * mensaje_pregunta);
};

};

