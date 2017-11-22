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

	virtual bool parsearContenido(IJson* contenido);

	virtual std::string prefijoGrupo();

	virtual unsigned int hashcode();

    //Seccion* clonar();

    virtual IEntidad * clonar();

};

};
};
