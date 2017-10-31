#pragma once

// modelo
#include <modelo/include/IEntidad.h>

namespace visualizador
{
namespace modelo
{

class Reporte : public IEntidad
{
public:

	Reporte(std::string etiqueta = "");

	virtual ~Reporte();

	// METODOS

	virtual void crearContenido();

	virtual void parsearContenido(IJson* contenido);

	virtual std::string prefijoGrupo();

	virtual unsigned int hashcode();
   
    Reporte* clonar();

};

};
};
