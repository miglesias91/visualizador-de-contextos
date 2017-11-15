#pragma once

// modelo
#include <modelo/include/IJson.h>

namespace visualizador
{
namespace modelo
{

class IContieneJson
{
public:
    // CONSTRUCTORES

    IContieneJson(IJson * contenido = NULL);
    ~IContieneJson();

    // GETTERS

    virtual IJson * getContenido();

    // SETTERS

    virtual void setContenido(IJson * contenido);

    // METODOS
    
    virtual void crearContenido() = 0;

    // parsea el contenido JSON, y devuelve 'true' si el contenido es correcto, devuelve 'false' si el contenido parseado no esta correcto.
    virtual bool parsearContenido(IJson * contenido) = 0;

private:

    IJson * contenido;
};

};
};

