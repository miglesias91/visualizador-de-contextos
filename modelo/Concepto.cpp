#include <modelo/Concepto.h>

using namespace visualizador::modelo;

Concepto::Concepto() : IEntidad()
{
}

Concepto::~Concepto()
{
}

std::vector<Termino> Concepto::getTerminos()
{
	return this->terminos;
}

void Concepto::agregarTermino(Termino termino_nuevo)
{
	this->terminos.push_back(termino_nuevo);
}
