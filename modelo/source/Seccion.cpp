#include <modelo/include/Seccion.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

Seccion::Seccion() : IEntidad()
{
}

Seccion::Seccion(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoSeccion())
{
}

Seccion::~Seccion()
{
}

void Seccion::crearContenido()
{
}
