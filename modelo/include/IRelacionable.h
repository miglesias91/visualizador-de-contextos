#pragma once

// modelo
#include <modelo/include/IRelaciones.h>

namespace visualizador
{
namespace modelo
{
namespace relaciones
{

class IRelacionable
{
public:
    IRelacionable(IRelaciones * relaciones = NULL);
    virtual ~IRelacionable();

    // GETTERS

    virtual IRelaciones * getRelaciones();

    // SETTERS

    virtual void setRelaciones(IRelaciones * relaciones);

    // METODOS

    virtual void vincular() = 0;

    virtual void desvincular() = 0;

private:

    IRelaciones * relaciones;
};

};
};
};


