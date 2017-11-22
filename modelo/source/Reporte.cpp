#include <modelo/include/Reporte.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

Reporte::Reporte(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoReporte())
{
}

Reporte::~Reporte()
{
}

void Reporte::crearContenido()
{
}

bool Reporte::parsearContenido(IJson* contenido)
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
    clon->setContenido(this->getContenido()->clonar());
    return clon;
}
