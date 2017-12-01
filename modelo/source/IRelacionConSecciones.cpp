#include <modelo/include/IRelacionConSecciones.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

IRelacionConSecciones::IRelacionConSecciones(RelacionConGrupo * relacion_con_secciones) : relacion_con_secciones(relacion_con_secciones)
{
}

IRelacionConSecciones::~IRelacionConSecciones()
{
    if (NULL != this->relacion_con_secciones)
    {
        delete this->relacion_con_secciones;
        this->relacion_con_secciones = NULL;
    }
}

// GETTERS

RelacionConGrupo * IRelacionConSecciones::getRelacionConSecciones()
{
    return this->relacion_con_secciones;
}

// SETTERS

void IRelacionConSecciones::setRelacionConSecciones(RelacionConGrupo * relacion_con_secciones)
{
    this->relacion_con_secciones = relacion_con_secciones;
}

// METODOS


void IRelacionConSecciones::agregarRelacionConSeccion(visualizador::aplicacion::ID * id_seccion)
{
    this->relacion_con_secciones->agregarRelacion(id_seccion);
}

void IRelacionConSecciones::eliminarRelacionConSeccion(visualizador::aplicacion::ID * id_seccion)
{
    this->relacion_con_secciones->eliminarRelacion(id_seccion);
}

void IRelacionConSecciones::actualizarRelacionConSeccion(visualizador::aplicacion::ID * id_seccion_nuevo, visualizador::aplicacion::ID * id_seccion_viejo)
{
    this->relacion_con_secciones->actualizarRelacion(id_seccion_nuevo, id_seccion_viejo);
}
