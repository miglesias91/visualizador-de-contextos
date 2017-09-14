#pragma once

// modelo
#include <modelo/Reporte.h>

namespace visualizador
{
namespace modelo
{

class Grafico : public Reporte
{
public:
	Grafico();
	virtual ~Grafico();

	virtual void crearContenido();

};

};
};

