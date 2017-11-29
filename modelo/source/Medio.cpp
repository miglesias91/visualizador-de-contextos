#include <modelo/include/Medio.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

Medio::Medio(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedio(), NULL)
{
}

Medio::~Medio()
{
}

void Medio::crearJson()
{
}

bool Medio::parsearJson(IJson* json)
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

IEntidad * Medio::clonar()
{
    Medio * clon = new Medio(this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setJson(this->getJson()->clonar());
    return clon;
}

bool Medio::recuperarContenidoDeRelaciones()
{
    return true;
}

void Medio::actualizarRelaciones()
{
}

void Medio::vincular()
{
}

void Medio::desvincular()
{
}
