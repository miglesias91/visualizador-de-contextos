#include <modelo/include/IRelacionable.h>

using namespace visualizador::modelo::relaciones;

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

