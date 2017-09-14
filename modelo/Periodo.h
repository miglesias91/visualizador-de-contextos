#pragma once

// modelo
#include <modelo/Fecha.h>

namespace visualizador
{
namespace modelo
{

class Periodo
{
public:

	// CONSTRUCTORES

	Periodo();
	Periodo(Fecha* desde, Fecha* hasta);
	virtual ~Periodo();

	// GETTERS

	Fecha* getDesde();
	Fecha* getHasta();

	// SETTERS

	void setDesde(Fecha* desde);
	void setHasta(Fecha* hasta);

private:
	Fecha* desde;
	Fecha* hasta;
};

};
};
