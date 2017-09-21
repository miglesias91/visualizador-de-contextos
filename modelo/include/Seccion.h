#pragma once

// modelo
#include <modelo/include/IEntidad.h>

namespace visualizador
{
namespace modelo
{

class Seccion : public IEntidad
{
public:

	Seccion(std::string etiqueta = "");

	virtual ~Seccion();

	// METODOS

	virtual void crearContenido();

	virtual void parsearValorAlmacenable(std::string valor_almacenable);

};

};
};
