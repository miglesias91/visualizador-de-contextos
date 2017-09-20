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

	Concepto();
	
	Concepto(std::string etiqueta, std::vector<Termino*> terminos, ContenidoEntidad* contenido);

	Concepto(std::string etiqueta, std::vector<Termino*> terminos);

	virtual ~Concepto();

	// GETTERS

	std::vector<Termino*> getTerminos();

	// SETTERS

	void agregarTermino(Termino* termino_nuevo);

	// METODOS

	virtual void crearContenido();


private:

	std::vector<Termino*> terminos;
};

};
};

