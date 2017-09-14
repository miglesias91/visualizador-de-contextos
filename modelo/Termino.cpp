#include <modelo/Termino.h>

using namespace visualizador::modelo;

Termino::Termino() : IEntidad()
{
}

Termino::Termino(std::string termino) : valor(termino)
{
}

Termino::~Termino()
{
}

std::string Termino::getValor()
{
	return std::string();
}

void Termino::setValor(std::string valor)
{
	this->valor = valor;
}
