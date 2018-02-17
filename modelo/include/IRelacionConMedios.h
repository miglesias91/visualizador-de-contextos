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

    RelacionConGrupo * getRelacionConMedios();

    // SETTERS

    void setRelacionConMedios(RelacionConGrupo * relacion_con_medios);

    // METODOS

    virtual void agregarRelacionConMedio(herramientas::utiles::ID * id_medio);

    virtual void eliminarRelacionConMedio(herramientas::utiles::ID * id_medio);

    virtual void actualizarRelacionConMedio(herramientas::utiles::ID * id_medio_nuevo, herramientas::utiles::ID * id_medio_viejo);

private:

    RelacionConGrupo * relacion_con_medios;
};

};
};
};


