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

    virtual void agregarRelacionConConsulta(herramientas::utiles::ID * id_consulta);

    virtual void eliminarRelacionConConsulta(herramientas::utiles::ID * id_consulta);

    virtual void actualizarRelacionConConsulta(herramientas::utiles::ID * id_consulta_nuevo, herramientas::utiles::ID * id_consulta_viejo);

private:

    RelacionConGrupo * relacion_con_consulta;
};

};
};
};


