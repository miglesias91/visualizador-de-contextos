#include <modelo/Termino.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/ConfiguracionAplicacion.h>

Termino::Termino() : IEntidad()
{
}

Termino::Termino(std::string termino) : IEntidad(termino, termino, visualizador::aplicacion::ConfiguracionAplicacion::prefijoTermino()), valor(termino)
{
}

Termino::~Termino()
{
}

std::string Termino::getValor()
{
	return this->valor;
}

void Termino::setValor(std::string valor)
{
	this->valor = valor;
}
