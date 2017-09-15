#include <modelo/Reporte.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/ConfiguracionAplicacion.h>

Reporte::Reporte() : IEntidad()
{
}

Reporte::Reporte(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoReporte())
{
}

Reporte::~Reporte()
{
}
