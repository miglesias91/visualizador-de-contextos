#pragma once

// modelo
#include <modelo/include/Reporte.h>

namespace visualizador
{
namespace modelo
{

class Grafico : public Reporte
{
public:

	// CONSTRUCTORES
	
	Grafico(std::string etiqueta = "");

	virtual ~Grafico();

	// METODOS

	virtual bool armarJson();

	virtual bool parsearJson();

	// GETTERS

	// SETTERS
};

};
};

