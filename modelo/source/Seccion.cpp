#include <modelo/include/Seccion.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

Seccion::Seccion(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoSeccion(), NULL), relaciones_seccion(NULL)
{
    this->relaciones_seccion = new relaciones::RelacionesSeccion();
    this->setRelaciones(this->relaciones_seccion);
}

Seccion::~Seccion()
{
}

// GETTERS

relaciones::RelacionesSeccion * Seccion::getRelacionesSeccion()
{
    return this->relaciones_seccion;
}

// SETTERS

void Seccion::setRelacionesSeccion(relaciones::RelacionesSeccion * relaciones_seccion)
{
    this->relaciones_seccion = relaciones_seccion;
}

// METODOS

// metodos IContieneJson

void Seccion::crearJson()
{
}

bool Seccion::parsearJson(IJson* json)
{
    return true;
}

// metodos de IAlmacenable

std::string Seccion::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoSeccion();
}

unsigned int Seccion::hashcode()
{
	return 0;
}

// metodos de IEntidad

IEntidad * Seccion::clonar()
{
    Seccion * clon = new Seccion(this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setJson(this->getJson()->clonar());
    return clon;
}

bool Seccion::recuperarContenidoDeRelaciones()
{
    return true;
}

// metodos de IRelacionable

void Seccion::actualizarRelaciones()
{
}

void Seccion::vincular()
{
}

void Seccion::desvincular()
{
}