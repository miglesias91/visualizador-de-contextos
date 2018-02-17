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

    virtual void agregarRelacionConSeccion(herramientas::utiles::ID * id_seccion);

    virtual void eliminarRelacionConSeccion(herramientas::utiles::ID * id_seccion);

    virtual void actualizarRelacionConSeccion(herramientas::utiles::ID * id_seccion_nuevo, herramientas::utiles::ID * id_seccion_viejo);

private:

    RelacionConGrupo * relacion_con_secciones;
};

};
};
};


