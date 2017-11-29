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
    visualizador::aplicacion::ID * id_seccion_copia = id_seccion->copia();
    if (false == this->relacion_con_secciones->agregarRelacion(id_seccion_copia))
    {// si no lo agrego, entonces destruyo la copia.
        delete id_seccion_copia;
    }
}

void IRelacionConSecciones::eliminarRelacionConSeccion(visualizador::aplicacion::ID * id_seccion)
{
    this->relacion_con_secciones->eliminarRelacion(id_seccion);
}