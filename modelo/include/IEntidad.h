#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/ID.h>

// modelo
#include <modelo/include/ContenidoEntidad.h>

namespace visualizador
{
namespace modelo
{

class IEntidad
{
public:

	// CONSTRUCTORES
	IEntidad();
	IEntidad(std::string etiqueta, std::string grupo, ContenidoEntidad* contenido = new ContenidoEntidad());

	virtual ~IEntidad();

	// GETTERS

	virtual visualizador::aplicacion::ID* getId();
	
	virtual std::string getEtiqueta();

	virtual ContenidoEntidad* getContenido();

	virtual std::string getGrupo();

	virtual std::string getValorAlmacenable();

	// SETTERS

	virtual void setId(visualizador::aplicacion::ID* id);

	virtual void setEtiqueta(std::string etiqueta);

	virtual void setContenido(ContenidoEntidad* contenido);

	virtual void setGrupo(std::string grupo);

	// METODOS

	virtual void asignarNuevoId();

	virtual void crearContenido() = 0;

	virtual void parsearValorAlmacenable(std::string valor_almacenable);

	virtual void parsearContenido(IJson* contenido) = 0;


private:

	visualizador::aplicacion::ID* id;
	std::string etiqueta;
	ContenidoEntidad* contenido;
	std::string grupo;
};

};
};

