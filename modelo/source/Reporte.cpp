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

void Reporte::crearJson()
{
}

bool Reporte::parsearJson(IJson* json)
{
    return true;
}

std::string Reporte::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoReporte();
}

unsigned int Reporte::hashcode()
{
	return 0;
}

IEntidad * Reporte::clonar()
{
    Reporte * clon = new Reporte(this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setJson(this->getJson()->clonar());
    return clon;
}

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