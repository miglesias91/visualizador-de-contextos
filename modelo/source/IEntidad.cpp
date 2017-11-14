#include <modelo/include/IEntidad.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorIDs.h>

IEntidad::IEntidad() : IReferenciable(), IAlmacenable(), contenido(NULL), esta_limpia(false)
{
}

IEntidad::IEntidad(std::string etiqueta, std::string grupo, ContenidoEntidad* contenido)
    : IReferenciable(), IAlmacenable(grupo), etiqueta(etiqueta), contenido(contenido), esta_limpia(false)
{
}

IEntidad::~IEntidad()
{
	delete this->contenido;
	this->contenido = NULL;
}

std::string IEntidad::getEtiqueta()
{
	return this->etiqueta;
}

ContenidoEntidad* IEntidad::getContenido()
{
	return this->contenido;
}

std::string IEntidad::getValorAlmacenable()
{
	this->crearContenido();

	IJson* json_contenido = this->getContenido();
	IJson* json_almacenable = new IJson();

	json_almacenable->agregarAtributoValor("etiqueta", this->getEtiqueta());
	json_almacenable->agregarAtributoJson("contenido", json_contenido);

	std::string string_almacenable = json_almacenable->jsonString();

	delete json_almacenable;

	return string_almacenable;
}

void IEntidad::setEtiqueta(std::string etiqueta)
{
	this->etiqueta = etiqueta;
}

void IEntidad::setContenido(ContenidoEntidad* contenido)
{
	this->contenido = contenido;
}

void IEntidad::parsearValorAlmacenable(std::string valor_almacenable)
{
	IJson json_almacenable(valor_almacenable);

	std::string etiqueta = json_almacenable.getAtributoValorString("etiqueta");
	this->setEtiqueta(etiqueta);

	IJson* json_contenido = json_almacenable.getAtributoValorJson("contenido");

	this->esta_limpia = this->parsearContenido(json_contenido);

	delete json_contenido;
}

bool IEntidad::estaSucia()
{
    return !this->estaLimpia();
}

bool IEntidad::estaLimpia()
{
    return this->esta_limpia;
}
