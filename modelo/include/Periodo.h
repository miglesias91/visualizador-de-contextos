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

	// GETTERS

	Fecha* getDesde();
	Fecha* getHasta();

	// SETTERS

	void setDesde(Fecha* desde);
	void setHasta(Fecha* hasta);

    // METODOS

    // metodos de IContieneJson

    virtual void crearContenido();

    virtual bool parsearContenido(IJson* contenido);

    // metodos de IAlmacenable

    virtual std::string prefijoGrupo();

    virtual unsigned int hashcode();

    // metodos de IEntidad

    virtual IEntidad * clonar();

    // metodos de IRelacionable

    virtual void vincular();

    virtual void desvincular();

private:
	
    Fecha* desde;
	Fecha* hasta;
  
    //IRelacionConGrupo * relacion_consultas;
};

};
};
