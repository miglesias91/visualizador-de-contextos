#pragma once

// stl
#include <vector>

// modelo
#include <modelo/IEntidad.h>
#include <modelo/Termino.h>

namespace visualizador
{
namespace modelo
{

class Concepto : public IEntidad
{
public:
	Concepto();
	virtual ~Concepto();

private:

	std::vector<Termino> terminos;
};

};
};

