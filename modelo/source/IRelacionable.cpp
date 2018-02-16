#include <modelo/include/IRelacionable.h>

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador;

IRelacionable::IRelacionable(IRelaciones * relaciones) : relaciones(relaciones)
{
}

IRelacionable::~IRelacionable()
{
    if (NULL != this->relaciones)
    {
        delete this->relaciones;
        this->relaciones = NULL;
    }
}

// GETTERS

IRelaciones * IRelacionable::getRelaciones()
{
    return this->relaciones;
}

// SETTERS

void IRelacionable::setRelaciones(IRelaciones * relaciones)
{
    this->relaciones = relaciones;
}

// METODOS

bool IRelacionable::recuperarRelaciones()
{
    bool existe_relacion = aplicacion::IAdministradorAplicacion::getInstanciaAdminEntidades()->recuperar(this->relaciones);

    if (existe_relacion)
    {
        this->recuperarContenidoDeRelaciones();
    }

    return existe_relacion;
}

// CONSULTAS