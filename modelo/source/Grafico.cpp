#include <modelo/include/Grafico.h>

using namespace visualizador::modelo;

Grafico::Grafico(std::string etiqueta) : Reporte(etiqueta)
{
}

Grafico::~Grafico()
{
}

bool Grafico::armarJson()
{
    return true;
}

bool Grafico::parsearJson()
{
    return true;
}
