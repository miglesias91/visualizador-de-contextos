#include <modelo/Periodo.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/ConfiguracionAplicacion.h>

// CONSTRUCTORES

Periodo::Periodo()
{
}

Periodo::Periodo(std::string etiqueta, Fecha * desde, Fecha * hasta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoPeriodo()),  desde(desde), hasta(hasta)
{
}

Periodo::~Periodo()
{
}

// METODOS

void Periodo::crearContenido()
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
