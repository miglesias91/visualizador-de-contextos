#include <modelo/include/Termino.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorIDs.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

Termino::Termino() : IEntidad("", visualizador::aplicacion::ConfiguracionAplicacion::prefijoTermino()), valor("")
{
}

Termino::Termino(std::string termino, std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoTermino()), valor(termino)
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
	ContenidoEntidad* contenido = this->getContenido();
	contenido->reset();

	contenido->agregarAtributoValor("valor", this->getValor());
}

void Termino::parsearContenido(IJson* contenido)
{
	std::string valor = contenido->getAtributoValorString("valor");

	this->setValor(valor);
}
