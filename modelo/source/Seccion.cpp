#include <modelo/include/Seccion.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

Seccion::Seccion(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoSeccion())
{
}

Seccion::~Seccion()
{
}

void Seccion::crearContenido()
{
}

void Seccion::parsearContenido(IJson* contenido)
{
}

std::string Seccion::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoSeccion();
}

unsigned int Seccion::hashcode()
{
	return 0;
}
