#include <modelo/Concepto.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/ConfiguracionAplicacion.h>

Concepto::Concepto() : IEntidad()
{
}

Concepto::Concepto(std::string etiqueta, std::vector<Termino*> terminos) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoConcepto()), terminos(terminos)
{
}

Concepto::~Concepto()
{
}

std::vector<Termino*> Concepto::getTerminos()
{
	return this->terminos;
}

void Concepto::agregarTermino(Termino* termino_nuevo)
{
	this->terminos.push_back(termino_nuevo);
}

void Concepto::crearContenido()
{
}
