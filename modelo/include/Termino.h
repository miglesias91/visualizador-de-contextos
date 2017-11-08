#pragma once

// stl
#include <functional>
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

	virtual bool parsearContenido(IJson* contenido);
	
	virtual std::string prefijoGrupo();

	virtual unsigned int hashcode();

    Termino* clonar();

private:

	static std::hash<std::string> hasher;

	std::string valor;
};

};
};

