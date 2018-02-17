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

// GETTERS

RelacionConGrupo * IRelacionConConceptos::getRelacionConConceptos()
{
    return this->relacion_con_conceptos;
}

// SETTERS

void IRelacionConConceptos::setRelacionConConceptos(RelacionConGrupo * relacion_con_conceptos)
{
    this->relacion_con_conceptos = relacion_con_conceptos;
}

// METODOS


void IRelacionConConceptos::agregarRelacionConConcepto(herramientas::utiles::ID * id_concepto)
{
    this->relacion_con_conceptos->agregarRelacion(id_concepto);
}

void IRelacionConConceptos::eliminarRelacionConConcepto(herramientas::utiles::ID * id_concepto)
{
    this->relacion_con_conceptos->eliminarRelacion(id_concepto);
}

void IRelacionConConceptos::actualizarRelacionConConcepto(herramientas::utiles::ID * id_concepto_nuevo, herramientas::utiles::ID * id_concepto_viejo)
{
    this->relacion_con_conceptos->actualizarRelacion(id_concepto_nuevo, id_concepto_viejo);
}
