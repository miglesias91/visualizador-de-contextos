#include <modelo/include/Grafico.h>

using namespace visualizador::modelo;

Grafico::Grafico(std::string etiqueta) : Reporte(etiqueta)
{
}

Grafico::~Grafico()
{
}

void Grafico::crearContenido()
{
}

bool Grafico::parsearContenido(IJson* contenido)
{
    return true;
}
