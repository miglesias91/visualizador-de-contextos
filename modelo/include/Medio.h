#pragma once

// modelo
#include <modelo/include/IEntidad.h>

namespace visualizador
{
namespace modelo
{

class Medio : public IEntidad
{
public:

	// CONSTRUCTORES

	Medio(std::string etiqueta = "");

	virtual ~Medio();

	// METODOS

	virtual void crearContenido();
	
	virtual bool parsearContenido(IJson* contenido);
	
	virtual std::string prefijoGrupo();

	virtual unsigned int hashcode();

    //Medio* clonar();

    virtual IEntidad * clonar();

	// GETTERS

	// SETTERS

private:

    IRelacion * relacion_consultas;


};

};
};
