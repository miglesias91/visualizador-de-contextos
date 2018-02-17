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


void IRelacionConMedios::agregarRelacionConMedio(herramientas::utiles::ID * id_medio)
{
    this->relacion_con_medios->agregarRelacion(id_medio);
}

void IRelacionConMedios::eliminarRelacionConMedio(herramientas::utiles::ID * id_medio)
{
    this->relacion_con_medios->eliminarRelacion(id_medio);
}

void IRelacionConMedios::actualizarRelacionConMedio(herramientas::utiles::ID * id_medio_nuevo, herramientas::utiles::ID * id_medio_viejo)
{
    this->relacion_con_medios->actualizarRelacion(id_medio_nuevo, id_medio_viejo);
}
