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

    virtual void agregarRelacionConPeriodo(visualizador::aplicacion::ID * id_periodo);

    virtual void eliminarRelacionConPeriodo(visualizador::aplicacion::ID * id_periodo);

    virtual void actualizarRelacionConPeriodo(visualizador::aplicacion::ID * id_periodo_nuevo, visualizador::aplicacion::ID * id_periodo_viejo);

private:

    RelacionConGrupo * relacion_con_periodos;
};

};
};
};


