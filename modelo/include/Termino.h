#pragma once

// stl
#include <string>

// modelo
#include <modelo/include/IEntidad.h>

namespace visualizador
{
namespace modelo
{

class Termino : public IEntidad
{
public:

	// CONSTRUCTORES
	Termino();

	Termino(std::string termino, std::string etiqueta = "");
	virtual ~Termino();

	// GETTERS
	std::string getValor();

	// SETTERS
	void setValor(std::string valor);

	// METODOS
	virtual void crearContenido();


private:

	std::string valor;
};

};
};

