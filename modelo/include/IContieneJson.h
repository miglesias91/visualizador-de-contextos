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

    IContieneJson(IJson * json = NULL);
    virtual ~IContieneJson();

    // GETTERS

    virtual IJson * getJson();

    // SETTERS

    virtual void setJson(IJson * json);

    // METODOS
    
    virtual void crearJson() = 0;

    // parsea el contenido JSON, y devuelve 'true' si el contenido es correcto, devuelve 'false' si el contenido parseado no esta correcto.
    virtual bool parsearJson(IJson * json) = 0;

private:

    IJson * json;
};

};
};

