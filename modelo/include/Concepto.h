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
	
	Concepto(std::vector<Termino*> terminos, ContenidoEntidad* contenido, std::string etiqueta = "");

	Concepto(std::vector<Termino*> terminos, std::string etiqueta = "");

	virtual ~Concepto();

	// GETTERS

	std::vector<Termino*> getTerminos();

	// SETTERS

	void agregarTermino(Termino* termino_nuevo);

	// METODOS

	virtual void crearContenido();

	virtual void parsearValorAlmacenable(std::string valor_almacenable);

private:

	std::vector<Termino*> terminos;
};

};
};

