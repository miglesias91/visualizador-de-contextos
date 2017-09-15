#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/ID.h>

namespace visualizador
{
namespace modelo
{

class IEntidad
{
public:

	// CONSTRUCTORES
	IEntidad();
	IEntidad(std::string etiqueta, std::string grupo, std::string contenido = "" );

	virtual ~IEntidad();

	// GETTERS

	virtual visualizador::aplicacion::ID* getId();
	
	virtual std::string getEtiqueta();

	virtual std::string getContenido();

	virtual std::string getGrupo();

	// SETTERS

	virtual void setId(visualizador::aplicacion::ID* id);

	virtual void setEtiqueta(std::string etiqueta);

	virtual void setContenido(std::string contenido);

	virtual void setGrupo(std::string grupo);

	// METODOS

	virtual void crearContenido() = 0;

private:

	visualizador::aplicacion::ID* id;
	std::string etiqueta;
	std::string contenido;
	std::string grupo;
};

};
};

