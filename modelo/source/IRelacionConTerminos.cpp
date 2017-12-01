#include <modelo/include/IRelacionConTerminos.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

IRelacionConTerminos::IRelacionConTerminos(RelacionConGrupo * relacion_con_terminos) : relacion_con_terminos(relacion_con_terminos)
{
}

IRelacionConTerminos::~IRelacionConTerminos()
{
    if (NULL != this->relacion_con_terminos)
    {
        delete this->relacion_con_terminos;
        this->relacion_con_terminos = NULL;
    }
}

// GETTERS

RelacionConGrupo * IRelacionConTerminos::getRelacionConTerminos()
{
    return this->relacion_con_terminos;
}

// SETTERS

void IRelacionConTerminos::setRelacionConTerminos(RelacionConGrupo * relacion_con_terminos)
{
    this->relacion_con_terminos = relacion_con_terminos;
}

// METODOS


void IRelacionConTerminos::agregarRelacionConTermino(visualizador::aplicacion::ID * id_termino)
{
    visualizador::aplicacion::ID * id_termino_copia = id_termino->copia();
    if (false == this->relacion_con_terminos->agregarRelacion(id_termino_copia))
    {// si no lo agrego, entonces destruyo la copia.
        delete id_termino_copia;
    }
}

void IRelacionConTerminos::eliminarRelacionConTermino(visualizador::aplicacion::ID * id_termino)
{
    this->relacion_con_terminos->eliminarRelacion(id_termino);
}