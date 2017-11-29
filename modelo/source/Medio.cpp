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

// GETTERS

relaciones::RelacionesMedio * Medio::getRelacionesMedio()
{
    return this->relacion_medio;;
}

// SETTERS

void Medio::setRelacionesMedio(relaciones::RelacionesMedio * relaciones_medio)
{
    this->relacion_medio = relaciones_medio;
}

// METODOS

// metodos de IContieneJson

void Medio::crearJson()
{
}

bool Medio::parsearJson(IJson* json)
{
    return true;
}

// metodos de IAlmacenable

std::string Medio::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoMedio();
}

unsigned Medio::hashcode()
{
	return 0;
}

// metodos de IEntidad

IEntidad * Medio::clonar()
{
    Medio * clon = new Medio(this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setJson(this->getJson()->clonar());
    return clon;
}

// metodos de IRelacionable

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
