#pragma once

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

// modelo
#include <modelo/include/RelacionConGrupo.h>


namespace visualizador
{
namespace modelo
{
namespace relaciones
{

class IRelacionConSecciones
{
public:
    IRelacionConSecciones(RelacionConGrupo * relacion_con_secciones = NULL);
    virtual ~IRelacionConSecciones();

    // GETTERS

    RelacionConGrupo * getRelacionConSecciones();

    // SETTERS

    void setRelacionConSecciones(RelacionConGrupo * relacion_con_secciones);

    // METODOS

    virtual void agregarRelacionConSeccion(visualizador::aplicacion::ID * id_seccion);

    virtual void eliminarRelacionConSeccion(visualizador::aplicacion::ID * id_seccion);

private:

    RelacionConGrupo * relacion_con_secciones;
};

};
};
};


