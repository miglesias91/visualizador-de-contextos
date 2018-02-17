#include <modelo/include/IRelacionConConsultas.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

IRelacionConConsultas::IRelacionConConsultas(RelacionConGrupo * relacion_con_consulta) : relacion_con_consulta(relacion_con_consulta)
{
}

IRelacionConConsultas::~IRelacionConConsultas()
{
    if (NULL != this->relacion_con_consulta)
    {
        delete this->relacion_con_consulta;
        this->relacion_con_consulta = NULL;
    }
}

// GETTERS

RelacionConGrupo * IRelacionConConsultas::getRelacionConConsultas()
{
    return this->relacion_con_consulta;
}

// SETTERS

void IRelacionConConsultas::setRelacionConConsultas(RelacionConGrupo * relacion_con_consulta)
{
    this->relacion_con_consulta = relacion_con_consulta;
}

// METODOS

void IRelacionConConsultas::agregarRelacionConConsulta(herramientas::utiles::ID * id_consulta)
{
    this->relacion_con_consulta->agregarRelacion(id_consulta);
}

void IRelacionConConsultas::eliminarRelacionConConsulta(herramientas::utiles::ID * id_consulta)
{
    this->relacion_con_consulta->eliminarRelacion(id_consulta);
}

void IRelacionConConsultas::actualizarRelacionConConsulta(herramientas::utiles::ID * id_consulta_nuevo, herramientas::utiles::ID * id_consulta_viejo)
{
    this->relacion_con_consulta->actualizarRelacion(id_consulta_nuevo, id_consulta_viejo);
}
