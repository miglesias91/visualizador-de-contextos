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

    virtual bool recuperarRelaciones();

    virtual bool recuperarContenidoDeRelaciones() = 0;

    virtual void actualizarRelaciones(visualizador::aplicacion::ID * id_nuevo, visualizador::aplicacion::ID * id_viejo = NULL) = 0;

    virtual void vincular() = 0;

    virtual void desvincular() = 0;

private:

    IRelaciones * relaciones;
};

};
};
};


