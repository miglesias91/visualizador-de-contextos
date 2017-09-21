#pragma once

// modelo
#include <modelo/include/IEntidad.h>
#include <modelo/include/Fecha.h>

namespace visualizador
{
namespace modelo
{

class Periodo : public IEntidad
{
public:

	// CONSTRUCTORES

	Periodo();
	Periodo(Fecha* desde, Fecha* hasta, std::string etiqueta = "");
	virtual ~Periodo();

	// METODOS

	virtual void crearContenido();
	
	virtual void parsearValorAlmacenable(std::string valor_almacenable);

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
