#include <modelo/include/IContieneJson.h>

using namespace visualizador::modelo;

IContieneJson::IContieneJson(IJson * contenido) : contenido(contenido)
{
}

IContieneJson::~IContieneJson()
{
    delete this->contenido;
    this->contenido = NULL;
}

IJson * IContieneJson::getContenido()
{
    return this->contenido;
}

void IContieneJson::setContenido(IJson * contenido)
{
    this->contenido = contenido;
}
