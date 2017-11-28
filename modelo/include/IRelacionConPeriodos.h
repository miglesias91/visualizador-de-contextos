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

class IRelacionConConceptos
{
public:
    IRelacionConConceptos(RelacionConGrupo * relacion_con_conceptos = NULL);
    virtual ~IRelacionConConceptos();

    // GETTERS

    // SETTERS

    // METODOS

    virtual void agregarRelacionConConcepto(visualizador::aplicacion::ID * id_consulta);

    virtual void eliminarRelacionConConcepto(visualizador::aplicacion::ID * id_consulta);

private:

    RelacionConGrupo * relacion_con_conceptos;
};

};
};
};


