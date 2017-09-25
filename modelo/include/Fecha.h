#pragma once

// stl
#include <string>

// modelo
#include <modelo/include/IEntidad.h>

namespace visualizador
{
namespace modelo
{

class Fecha : public IEntidad
{
public:

	// CONSTRUCTORES

	Fecha(std::string etiqueta = "");

	Fecha(unsigned int dia, unsigned int mes, unsigned int anio, std::string etiqueta = "");

	virtual ~Fecha();

	// METODOS

	virtual void crearContenido();
	
	virtual void parsearContenido(IJson* contenido);

	// GETTERS

	unsigned int getDia();
	unsigned int getMes();
	unsigned int getAnio();

	std::string getStringDia();
	std::string getStringMes();
	std::string getStringAnio();

	// SETTERS

	void setDia(std::string dia);
	void setMes(std::string mes);
	void setAnio(std::string anio);

	void setDia(unsigned int dia);
	void setMes(unsigned int mes);
	void setAnio(unsigned int anio);

private:

	unsigned int dia;
	unsigned int mes;
	unsigned int anio;
};

};
};

