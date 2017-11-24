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

	Periodo(std::string etiqueta = "");
	Periodo(Fecha* desde, Fecha* hasta, std::string etiqueta = "");
	virtual ~Periodo();

	// METODOS

	virtual void crearContenido();
	
	virtual bool parsearContenido(IJson* contenido);

	virtual std::string prefijoGrupo();

	virtual unsigned int hashcode();

    //Periodo* clonar();

    virtual IEntidad * clonar();

	// GETTERS

	Fecha* getDesde();
	Fecha* getHasta();

	// SETTERS

	void setDesde(Fecha* desde);
	void setHasta(Fecha* hasta);

private:
	
    Fecha* desde;
	Fecha* hasta;
  
    IRelacion * relacion_consultas;
};

};
};
