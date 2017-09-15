#pragma once

// modelo
#include <modelo/IEntidad.h>
#include <modelo/Fecha.h>

namespace visualizador
{
namespace modelo
{

class Periodo : public IEntidad
{
public:

	// CONSTRUCTORES

	Periodo();
	Periodo(std::string etiqueta, Fecha* desde, Fecha* hasta);
	virtual ~Periodo();

	// METODOS

	virtual void crearContenido();

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
