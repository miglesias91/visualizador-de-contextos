#pragma once

// modelo
#include <modelo/include/IEntidad.h>

namespace visualizador
{
namespace modelo
{

class Medio : public IEntidad
{
public:

	// CONSTRUCTORES

	Medio(std::string etiqueta = "");

	virtual ~Medio();

	// METODOS

	virtual void crearContenido();
	
	virtual void parsearContenido(IJson* contenido);
	
	// GETTERS

	// SETTERS


};

};
};
