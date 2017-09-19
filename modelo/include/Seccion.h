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
	Seccion();

	Seccion(std::string etiqueta);

	virtual ~Seccion();

	// METODOS

	virtual void crearContenido();

};

};
};
