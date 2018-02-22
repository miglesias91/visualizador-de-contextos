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

class IRelacionConMedios
{
public:
    IRelacionConMedios(RelacionConGrupo * relacion_con_medios = NULL);
    virtual ~IRelacionConMedios();

    // GETTERS

    RelacionConGrupo * getRelacionConMediosTwitter();

    // SETTERS

    void setRelacionConMediosTwitter(RelacionConGrupo * relacion_con_medios);

    // METODOS

    virtual void agregarRelacionConMedioTwitter(herramientas::utiles::ID * id_medio);

    virtual void eliminarRelacionConMedioTwitter(herramientas::utiles::ID * id_medio);

    virtual void actualizarRelacionConMedioTwitter(herramientas::utiles::ID * id_medio_nuevo, herramientas::utiles::ID * id_medio_viejo);

private:

    RelacionConGrupo * relacion_con_medios_twitter;
};

};
};
};


