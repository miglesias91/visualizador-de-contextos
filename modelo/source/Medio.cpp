#include <modelo/include/Medio.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

Medio::Medio(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedio())
{
}

Medio::~Medio()
{
}

void Medio::crearContenido()
{
}

bool Medio::parsearContenido(IJson* contenido)
{
    return true;
}

std::string Medio::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoMedio();
}

unsigned Medio::hashcode()
{
	return 0;
}

Medio * Medio::clonar()
{
    Medio * clon = new Medio(this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setContenido(this->getContenido()->clonar());
    return clon;
}
