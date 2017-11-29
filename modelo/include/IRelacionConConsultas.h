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

class IRelacionConConsultas
{
public:
    IRelacionConConsultas(RelacionConGrupo * relacion_con_conceptos = NULL);
    virtual ~IRelacionConConsultas();

    // GETTERS

    RelacionConGrupo * getRelacionConConsultas();

    // SETTERS

    void setRelacionConConsultas(RelacionConGrupo * relacion_con_consultas);

    // METODOS

    virtual void agregarRelacionConConsulta(visualizador::aplicacion::ID * id_consulta);

    virtual void eliminarRelacionConConsulta(visualizador::aplicacion::ID * id_consulta);

private:

    RelacionConGrupo * relacion_con_consulta;
};

};
};
};


