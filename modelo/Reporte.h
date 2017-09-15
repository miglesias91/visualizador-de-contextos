#pragma once

// modelo
#include <modelo/IEntidad.h>

namespace visualizador
{
namespace modelo
{

class Reporte : public IEntidad
{
public:
	Reporte();

	Reporte(std::string etiqueta);

	virtual ~Reporte();
};

};
};
