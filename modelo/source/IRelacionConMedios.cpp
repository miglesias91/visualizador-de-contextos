#include <modelo/include/IRelacionConMedios.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

IRelacionConMedios::IRelacionConMedios(RelacionConGrupo * relacion_con_medios) : relacion_con_medios(relacion_con_medios)
{
}

IRelacionConMedios::~IRelacionConMedios()
{
    if (NULL != this->relacion_con_medios)
    {
        delete this->relacion_con_medios;
        this->relacion_con_medios = NULL;
    }
}

// GETTERS

RelacionConGrupo * IRelacionConMedios::getRelacionConMedios()
{
    return this->relacion_con_medios;
}

// SETTERS

void IRelacionConMedios::setRelacionConMedios(RelacionConGrupo * relacion_con_medios)
{
    this->relacion_con_medios = relacion_con_medios;
}

// METODOS


void IRelacionConMedios::agregarRelacionConMedio(visualizador::aplicacion::ID * id_medio)
{
    visualizador::aplicacion::ID * id_medio_copia = id_medio->copia();
    if (false == this->relacion_con_medios->agregarRelacion(id_medio_copia))
    {// si no lo agrego, entonces destruyo la copia.
        delete id_medio_copia;
    }
}

void IRelacionConMedios::eliminarRelacionConMedio(visualizador::aplicacion::ID * id_medio)
{
    this->relacion_con_medios->eliminarRelacion(id_medio);
}