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

class IRelacionConTerminos
{
public:
    IRelacionConTerminos(RelacionConGrupo * relacion_con_termino = NULL);
    virtual ~IRelacionConTerminos();

    // GETTERS

    RelacionConGrupo * getRelacionConTerminos();

    // SETTERS

    void setRelacionConTerminos(RelacionConGrupo * relacion_con_terminos);

    // METODOS

    virtual void agregarRelacionConTermino(herramientas::utiles::ID * id_termino);

    virtual void eliminarRelacionConTermino(herramientas::utiles::ID * id_termino);

    virtual void actualizarRelacionConTermino(herramientas::utiles::ID * id_termino_nuevo, herramientas::utiles::ID * id_termino_viejo);

private:

    RelacionConGrupo * relacion_con_terminos;
};

};
};
};


