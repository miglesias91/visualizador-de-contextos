#include <modelo/include/ContenidoJson.h>

using namespace visualizador::modelo;

// stl
#include <sstream>

ContenidoJson::ContenidoJson() : IJson()
{
}

ContenidoJson::~ContenidoJson()
{
}

ContenidoJson * ContenidoJson::clonar()
{
    return static_cast<ContenidoJson*>(this->IJson::clonar());
}
