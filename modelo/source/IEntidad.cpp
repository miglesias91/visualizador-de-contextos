#include <modelo/include/IEntidad.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorIDs.h>

IEntidad::IEntidad()
{
}

IEntidad::IEntidad(std::string etiqueta, std::string grupo, std::string contenido) : etiqueta(etiqueta), grupo(grupo), contenido(contenido)
{
	this->id = visualizador::aplicacion::GestorIDs::nuevoID();
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

std::string IEntidad::getContenido()
{
	return this->contenido;
}

std::string IEntidad::getGrupo()
{
	return this->grupo;
}

void IEntidad::setId(visualizador::aplicacion::ID* id)
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
