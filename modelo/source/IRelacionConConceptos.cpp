#include <modelo/include/IRelacionConConceptos.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

IRelacionConConceptos::IRelacionConConceptos(RelacionConGrupo * relacion_con_conceptos) : relacion_con_conceptos(relacion_con_conceptos)
{
}

IRelacionConConceptos::~IRelacionConConceptos()
{
    if (NULL != this->relacion_con_conceptos)
    {
        delete this->relacion_con_conceptos;
        this->relacion_con_conceptos = NULL;
    }
}

// GETTES

// SETTERS

// METODOS


void IRelacionConConceptos::agregarRelacionConConcepto(visualizador::aplicacion::ID * id_concepto)
{
    visualizador::aplicacion::ID * id_concepto_copia = id_concepto->copia();
    if (false == this->relacion_con_conceptos->agregarRelacion(id_concepto_copia))
    {// si no lo agrego, entonces destruyo la copia.
        delete id_concepto_copia;
    }
}

void IRelacionConConceptos::eliminarRelacionConConcepto(visualizador::aplicacion::ID * id_concepto)
{
    this->relacion_con_conceptos->eliminarRelacion(id_concepto);
}

RelacionConGrupo * IRelacionConConceptos::getRelacionConConceptos()
{
    return this->relacion_con_conceptos;
}

void IRelacionConConceptos::setRelacionConConceptos(RelacionConGrupo * relacion_con_conceptos)
{
    this->relacion_con_conceptos = relacion_con_conceptos;
}
