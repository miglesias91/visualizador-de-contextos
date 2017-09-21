#include <modelo/include/IEntidad.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorIDs.h>

IEntidad::IEntidad()
{
}

IEntidad::IEntidad(std::string etiqueta, std::string grupo, ContenidoEntidad* contenido) : etiqueta(etiqueta), grupo(grupo), contenido(contenido)
{
}

IEntidad::~IEntidad()
{
}

visualizador::aplicacion::ID* IEntidad::getId()
{
	return this->id;
}

std::string IEntidad::getEtiqueta()
{
	return this->etiqueta;
}

ContenidoEntidad* IEntidad::getContenido()
{
	return this->contenido;
}

std::string IEntidad::getGrupo()
{
	return this->grupo;
}

std::string IEntidad::getValorAlmacenable()
{
	IJson* json_contenido = this->getContenido();
	IJson* json_almacenable = new IJson();

	json_almacenable->agregarAtributoValor("etiqueta", this->getEtiqueta());
	json_almacenable->agregarAtributoJson("contenido", json_contenido);

	std::string string_almacenable = json_almacenable->jsonString();

	delete json_almacenable;

	return string_almacenable;
}

void IEntidad::setId(visualizador::aplicacion::ID* id)
{
	this->id = id;
}

void IEntidad::setEtiqueta(std::string etiqueta)
{
	this->etiqueta = etiqueta;
}

void IEntidad::setContenido(ContenidoEntidad* contenido)
{
	this->contenido = contenido;
}

void IEntidad::setGrupo(std::string grupo)
{
	this->grupo = grupo;
}

void IEntidad::asignarNuevoId()
{
	this->id = visualizador::aplicacion::GestorIDs::nuevoID();
}
