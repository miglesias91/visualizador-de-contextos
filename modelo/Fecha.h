#pragma once

// stl
#include <string>

// modelo
#include <modelo/IEntidad.h>

namespace visualizador
{
namespace modelo
{

class Fecha : public IEntidad
{
public:

	// CONSTRUCTORES

	Fecha();

	Fecha(std::string etiqueta, unsigned int dia, unsigned int mes, unsigned int anio);

	virtual ~Fecha();

	// METODOS

	virtual void crearContenido();

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

