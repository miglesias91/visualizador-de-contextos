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

class IRelacionConPeriodos
{
public:
    IRelacionConPeriodos(RelacionConGrupo * relacion_con_periodos = NULL);
    virtual ~IRelacionConPeriodos();

    // GETTERS

    RelacionConGrupo * getRelacionConPeriodos();

    // SETTERS

    void setRelacionConPeriodos(RelacionConGrupo * relacion_con_periodos);

    // METODOS

    virtual void agregarRelacionConPeriodo(herramientas::utiles::ID * id_periodo);

    virtual void eliminarRelacionConPeriodo(herramientas::utiles::ID * id_periodo);

    virtual void actualizarRelacionConPeriodo(herramientas::utiles::ID * id_periodo_nuevo, herramientas::utiles::ID * id_periodo_viejo);

private:

    RelacionConGrupo * relacion_con_periodos;
};

};
};
};


