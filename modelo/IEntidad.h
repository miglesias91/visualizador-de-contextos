#pragma once

// stl
#include <string>

namespace visualizador
{
namespace modelo
{

class IEntidad
{
public:

	// CONSTRUCTORES
	IEntidad();
	virtual ~IEntidad();

	// GETTERS

	virtual std::string getId();
	
	virtual std::string getEtiqueta();

	virtual std::string getContenido();

	virtual std::string getGrupo();

	// SETTERS

	virtual void setId(std::string id);

	virtual void setEtiqueta(std::string etiqueta);

	virtual void setContenido(std::string contenido);

	virtual void setGrupo(std::string grupo);

	// METODOS

	virtual void crearContenido() = 0;

private:

	std::string id;
	std::string etiqueta;
	std::string contenido;
	std::string grupo;
};

};
};

