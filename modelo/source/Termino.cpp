#include <modelo/include/Termino.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorIDs.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

Termino::Termino() : IEntidad()
{
}

Termino::Termino(std::string termino) : IEntidad(termino, visualizador::aplicacion::ConfiguracionAplicacion::prefijoTermino()), valor(termino)
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

void Termino::crearContenido()
{
}
