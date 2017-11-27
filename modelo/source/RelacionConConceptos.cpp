#include <modelo/include/RelacionConConceptos.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;

RelacionConConceptos::RelacionConConceptos() : IRelacionConGrupo()
{
}

RelacionConConceptos::~RelacionConConceptos()
{
}

void RelacionConConceptos::crearContenido()
{
    IJson* contenido = this->getContenido();
    contenido->reset();

    contenido->agregarAtributoArray("ids_conceptos", this->getIdsGrupoComoUint());
}

bool RelacionConConceptos::parsearContenido(IJson * contenido)
{
    std::vector<unsigned long long int> ids_conceptos = contenido->getAtributoArrayUint("ids_conceptos");

    for (std::vector<unsigned long long int>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        this->agregarRelacion(*it);
    }
 
    return true;
}
