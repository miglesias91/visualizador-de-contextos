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

    RelacionConGrupo * getRelacionConConceptos();

    // SETTERS

    void setRelacionConConceptos(RelacionConGrupo * relacion_con_conceptos);

    // METODOS

    virtual void agregarRelacionConConcepto(herramientas::utiles::ID * id_concepto);

    virtual void eliminarRelacionConConcepto(herramientas::utiles::ID * id_concepto);

    virtual void actualizarRelacionConConcepto(herramientas::utiles::ID * id_concepto_nuevo, herramientas::utiles::ID * id_concepto_viejo);

private:

    RelacionConGrupo * relacion_con_conceptos;
};

};
};
};


