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


void IRelacionConTerminos::agregarRelacionConTermino(herramientas::utiles::ID * id_termino)
{
    this->relacion_con_terminos->agregarRelacion(id_termino);
}

void IRelacionConTerminos::eliminarRelacionConTermino(herramientas::utiles::ID * id_termino)
{
    this->relacion_con_terminos->eliminarRelacion(id_termino);
}

void IRelacionConTerminos::actualizarRelacionConTermino(herramientas::utiles::ID * id_termino_nuevo, herramientas::utiles::ID * id_termino_viejo)
{
    this->relacion_con_terminos->actualizarRelacion(id_termino_nuevo, id_termino_viejo);
}
