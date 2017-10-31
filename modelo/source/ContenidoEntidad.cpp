#include <modelo/include/ContenidoEntidad.h>

using namespace visualizador::modelo;

// stl
#include <sstream>

ContenidoEntidad::ContenidoEntidad() : IJson()
{
}

ContenidoEntidad::~ContenidoEntidad()
{
}

ContenidoEntidad * ContenidoEntidad::clonar()
{
    return static_cast<ContenidoEntidad*>(this->IJson::clonar());
}
