#include <modelo/include/Termino.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorIDs.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

std::hash<std::string> Termino::hasher;

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

std::string Termino::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoTermino();
}

unsigned int Termino::hashcode()
{
	return hasher(this->getValor());
}
