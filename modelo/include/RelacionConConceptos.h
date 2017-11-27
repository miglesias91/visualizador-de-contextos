#pragma once

// modelo
#include <modelo/include/IRelacionConGrupo.h>

namespace visualizador
{
namespace modelo
{
namespace relaciones
{

class RelacionConConceptos : public IRelacionConGrupo
{
public:

    // CONSTRUCTORES

    RelacionConConceptos();
    virtual ~RelacionConConceptos();

    // GETTERS

    // SETTTERS

    // METODOS

    // metodos de IContienJson

    virtual void crearContenido();

    virtual bool parsearContenido(IJson * contenido);
};

};
};
};

