#include <modelo/include/IRelacionConMedios.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

IRelacionConMedios::IRelacionConMedios(RelacionConGrupo * relacion_con_medios) : relacion_con_medios_twitter(relacion_con_medios)
{
}

IRelacionConMedios::~IRelacionConMedios()
{
    if (NULL != this->relacion_con_medios_twitter)
    {
        delete this->relacion_con_medios_twitter;
        this->relacion_con_medios_twitter = NULL;
    }
}

// GETTERS

RelacionConGrupo * IRelacionConMedios::getRelacionConMediosTwitter()
{
    return this->relacion_con_medios_twitter;
}

// SETTERS

void IRelacionConMedios::setRelacionConMediosTwitter(RelacionConGrupo * relacion_con_medios_twitter)
{
    this->relacion_con_medios_twitter = relacion_con_medios_twitter;
}

// METODOS


void IRelacionConMedios::agregarRelacionConMedioTwitter(herramientas::utiles::ID * id_medio)
{
    this->relacion_con_medios_twitter->agregarRelacion(id_medio);
}

void IRelacionConMedios::eliminarRelacionConMedioTwitter(herramientas::utiles::ID * id_medio)
{
    this->relacion_con_medios_twitter->eliminarRelacion(id_medio);
}

void IRelacionConMedios::actualizarRelacionConMedioTwitter(herramientas::utiles::ID * id_medio_nuevo, herramientas::utiles::ID * id_medio_viejo)
{
    this->relacion_con_medios_twitter->actualizarRelacion(id_medio_nuevo, id_medio_viejo);
}
