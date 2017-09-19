#include <modelo/include/Consulta.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

Consulta::Consulta() : IEntidad()
{
}

Consulta::Consulta(std::string etiqueta, Periodo * periodo, Reporte * reporte, std::vector<Concepto*> conceptos, std::vector<Medio*> medios, std::vector<Seccion*> secciones)
	: IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoConsulta()), periodo(periodo), reporte(reporte), conceptos(conceptos), medios(medios), secciones(secciones)
{
}

Consulta::~Consulta()
{
}

Periodo * Consulta::getPeriodo()
{
	return this->periodo;
}

Reporte * Consulta::getReporte()
{
	return this->reporte;
}

std::vector<Concepto*> Consulta::getConceptos()
{
	return this->conceptos;
}

std::vector<Medio*> Consulta::getMedios()
{
	return this->medios;
}

std::vector<Seccion*> Consulta::getSecciones()
{
	return this->secciones;
}

void Consulta::setPeriodo(Periodo * periodo)
{
	this->periodo = periodo;
}

void Consulta::setReporte(Reporte * reporte)
{
	this->reporte = reporte;
}

void Consulta::agregarConcepto(Concepto * concepto)
{
	this->conceptos.push_back(concepto);
}

void Consulta::agregarMedio(Medio * medio)
{
	this->medios.push_back(medio);
}

void Consulta::agregarSeccion(Seccion * seccion)
{
	this->secciones.push_back(seccion);
}

void Consulta::crearContenido()
{
}
