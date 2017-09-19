#include <modelo/include/Medio.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

Medio::Medio() : IEntidad()
{
}

Medio::Medio(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedio())
{
}

Medio::~Medio()
{
}

void Medio::crearContenido()
{
}
