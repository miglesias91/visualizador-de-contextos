#include <modelo/Periodo.h>

using namespace visualizador::modelo;

Periodo::Periodo()
{
}

visualizador::modelo::Periodo::Periodo(Fecha * desde, Fecha * hasta) : desde(desde), hasta(hasta)
{
}

Periodo::~Periodo()
{
}

Fecha * Periodo::getDesde()
{
	return this->desde;
}

Fecha * Periodo::getHasta()
{
	return this->hasta;
}

void Periodo::setDesde(Fecha * desde)
{
	this->desde = desde;
}

void Periodo::setHasta(Fecha * hasta)
{
	this->hasta = hasta;
}
