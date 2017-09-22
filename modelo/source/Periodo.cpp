#include <modelo/include/Periodo.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

// CONSTRUCTORES

Periodo::Periodo(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoPeriodo()), desde(NULL), hasta(NULL)
{
}

Periodo::Periodo(Fecha * desde, Fecha * hasta, std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoPeriodo()),  desde(desde), hasta(hasta)
{
}

Periodo::~Periodo()
{
}

// METODOS

void Periodo::crearContenido()
{
	ContenidoEntidad* contenido = this->getContenido();
	contenido->reset();

	contenido->agregarAtributoValor("id_fecha_desde", this->getDesde()->getId()->numero());
	contenido->agregarAtributoValor("id_fecha_hasta", this->getHasta()->getId()->numero());
}

void Periodo::parsearContenido(IJson* contenido)
{
}

// GETTERS

Fecha * Periodo::getDesde()
{
	return this->desde;
}

Fecha * Periodo::getHasta()
{
	return this->hasta;
}

// SETTERS

void Periodo::setDesde(Fecha * desde)
{
	this->desde = desde;
}

void Periodo::setHasta(Fecha * hasta)
{
	this->hasta = hasta;
}
