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
	
	virtual void parsearValorAlmacenable(std::string valor_almacenable);
	
	// GETTERS

	// SETTERS


};

};
};
