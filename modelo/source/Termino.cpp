#include <modelo/include/Termino.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorIDs.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

std::hash<std::string> Termino::hasher;

Termino::Termino() : IEntidad("", visualizador::aplicacion::ConfiguracionAplicacion::prefijoTermino()), valor(""), relaciones(NULL)
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
	IJson* contenido = this->getContenido();
	contenido->reset();

	contenido->agregarAtributoValor("valor", this->getValor());
}

bool Termino::parsearContenido(IJson* contenido)
{
	std::string valor = contenido->getAtributoValorString("valor");

	this->setValor(valor);

    return true;
}

std::string Termino::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoTermino();
}

unsigned int Termino::hashcode()
{
	return hasher(this->getValor());
}

IEntidad * Termino::clonar()
{
    Termino * clon = new Termino(this->valor, this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setContenido(this->getContenido()->clonar());
    return clon;
}
