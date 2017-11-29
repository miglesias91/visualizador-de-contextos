#include <modelo/include/Reporte.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

Reporte::Reporte(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoReporte(), NULL), relaciones_reporte(NULL)
{
    this->relaciones_reporte = new relaciones::RelacionesReporte();
    this->setRelaciones(this->relaciones_reporte);
}

Reporte::~Reporte()
{
}

// GETTERS

relaciones::RelacionesReporte * Reporte::getRelacionesReporte()
{
    return this->relaciones_reporte;
}

// SETTERS

void Reporte::setRelacionesReporte(relaciones::RelacionesReporte * relaciones_reporte)
{
    this->relaciones_reporte = relaciones_reporte;
}

// METODOS

// metodos IContieneJson

void Reporte::crearJson()
{
}

bool Reporte::parsearJson(IJson* json)
{
    return true;
}

// metodos IAlmacenable

std::string Reporte::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoReporte();
}

unsigned int Reporte::hashcode()
{
	return 0;
}

// metodos IEntidad

IEntidad * Reporte::clonar()
{
    Reporte * clon = new Reporte(this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setJson(this->getJson()->clonar());
    return clon;
}

// metodos IRelacionable

bool Reporte::recuperarContenidoDeRelaciones()
{
    return true;
}

void Reporte::actualizarRelaciones()
{
}

void Reporte::vincular()
{
}

void Reporte::desvincular()
{
}