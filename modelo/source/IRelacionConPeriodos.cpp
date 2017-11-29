#include <modelo/include/IRelacionConPeriodos.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

IRelacionConPeriodos::IRelacionConPeriodos(RelacionConGrupo * relacion_con_periodos) : relacion_con_periodos(relacion_con_periodos)
{
}

IRelacionConPeriodos::~IRelacionConPeriodos()
{
    if (NULL != this->relacion_con_periodos)
    {
        delete this->relacion_con_periodos;
        this->relacion_con_periodos = NULL;
    }
}

// GETTERS

RelacionConGrupo * IRelacionConPeriodos::getRelacionConPeriodos()
{
    return this->relacion_con_periodos;
}

// SETTERS

void IRelacionConPeriodos::setRelacionConPeriodos(RelacionConGrupo * relacion_con_periodos)
{
    this->relacion_con_periodos = relacion_con_periodos;
}

// METODOS


void IRelacionConPeriodos::agregarRelacionConPeriodo(visualizador::aplicacion::ID * id_periodo)
{
    visualizador::aplicacion::ID * id_periodo_copia = id_periodo->copia();
    if (false == this->relacion_con_periodos->agregarRelacion(id_periodo_copia))
    {// si no lo agrego, entonces destruyo la copia.
        delete id_periodo_copia;
    }
}

void IRelacionConPeriodos::eliminarRelacionConPeriodo(visualizador::aplicacion::ID * id_periodo)
{
    this->relacion_con_periodos->eliminarRelacion(id_periodo);
}