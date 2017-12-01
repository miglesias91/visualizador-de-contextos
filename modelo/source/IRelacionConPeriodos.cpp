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
    this->relacion_con_periodos->agregarRelacion(id_periodo);
}

void IRelacionConPeriodos::eliminarRelacionConPeriodo(visualizador::aplicacion::ID * id_periodo)
{
    this->relacion_con_periodos->eliminarRelacion(id_periodo);
}

void IRelacionConPeriodos::actualizarRelacionConPeriodo(visualizador::aplicacion::ID * id_periodo_nuevo, visualizador::aplicacion::ID * id_periodo_viejo)
{
    this->relacion_con_periodos->actualizarRelacion(id_periodo_nuevo, id_periodo_viejo);
}
