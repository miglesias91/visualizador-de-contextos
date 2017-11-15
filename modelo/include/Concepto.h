#pragma once

// stl
#include <vector>

// modelo
#include <modelo/include/IEntidad.h>
#include <modelo/include/Termino.h>

namespace visualizador
{
namespace modelo
{

class Concepto : public IEntidad
{
public:

	// CONSTRUCTORES

	Concepto(std::string etiqueta = "");
	
	Concepto(std::vector<Termino*> terminos, IJson* contenido, std::string etiqueta = "");

	Concepto(std::vector<Termino*> terminos, std::string etiqueta = "");

	virtual ~Concepto();

	// GETTERS

	std::vector<Termino*> getTerminos();

	// SETTERS

	void agregarTermino(Termino* termino_nuevo);

	// METODOS

	virtual void crearContenido();

	virtual bool parsearContenido(IJson* contenido);
	
	virtual std::string prefijoGrupo();
	
	virtual unsigned int hashcode();

    Concepto* clonar();

private:

	std::vector<Termino*> terminos;
};

};
};

