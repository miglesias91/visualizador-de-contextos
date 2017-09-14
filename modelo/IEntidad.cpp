#include <modelo/IEntidad.h>

using namespace visualizador::modelo;

IEntidad::IEntidad()
{
}

IEntidad::IEntidad(std::string id, std::string etiqueta, std::string contenido, std::string grupo) : id(id), etiqueta(etiqueta), contenido(contenido), grupo(grupo)
{
}

IEntidad::~IEntidad()
{
}

std::string IEntidad::getId()
{
	return this->id;
}

std::string IEntidad::getEtiqueta()
{
	return this->etiqueta;
}

std::string IEntidad::getContenido()
{
	return this->contenido;
}

std::string IEntidad::getGrupo()
{
	return this->grupo;
}

void IEntidad::setId(std::string id)
{
	this->id = id;
}

void IEntidad::setEtiqueta(std::string etiqueta)
{
	this->etiqueta = etiqueta;
}

void IEntidad::setContenido(std::string contenido)
{
	this->contenido = contenido;
}

void IEntidad::setGrupo(std::string grupo)
{
	this->grupo = grupo;
}
