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


void IRelacionConPeriodos::agregarRelacionConPeriodo(herramientas::utiles::ID * id_periodo)
{
    this->relacion_con_periodos->agregarRelacion(id_periodo);
}

void IRelacionConPeriodos::eliminarRelacionConPeriodo(herramientas::utiles::ID * id_periodo)
{
    this->relacion_con_periodos->eliminarRelacion(id_periodo);
}

void IRelacionConPeriodos::actualizarRelacionConPeriodo(herramientas::utiles::ID * id_periodo_nuevo, herramientas::utiles::ID * id_periodo_viejo)
{
    this->relacion_con_periodos->actualizarRelacion(id_periodo_nuevo, id_periodo_viejo);
}
