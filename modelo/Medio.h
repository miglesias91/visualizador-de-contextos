#pragma once

// modelo
#include <modelo/IEntidad.h>

namespace visualizador
{
namespace modelo
{

class Medio : public IEntidad
{
public:
	Medio();
	virtual ~Medio();

	virtual void crearContenido();

};

};
};
