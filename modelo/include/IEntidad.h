#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/ID.h>

// modelo
#include <modelo/include/IAlmacenable.h>
#include <modelo/include/ContenidoJson.h>
#include <modelo/include/IReferenciable.h>

namespace visualizador
{
namespace modelo
{

class IEntidad : public IAlmacenable, public IContieneJson, public IReferenciable
{
public:

	// CONSTRUCTORES
	IEntidad();
	IEntidad(std::string etiqueta, std::string grupo, ContenidoEntidad* contenido = new ContenidoEntidad());

	virtual ~IEntidad();

	// GETTERS
	
	virtual std::string getEtiqueta();

	virtual ContenidoEntidad* getContenido();

	virtual std::string getValorAlmacenable();

	// SETTERS

	virtual void setEtiqueta(std::string etiqueta);

	virtual void setContenido(ContenidoEntidad* contenido);

	// METODOS

	virtual void crearContenido() = 0;

	virtual void parsearValorAlmacenable(std::string valor_almacenable);

    // parte el contenido JSON, y devuelve 'true' si el contenido es correcto, devuelve 'false' si el contenido parseado no esta correcto.
	virtual bool parsearContenido(IJson* contenido) = 0;

    // CONSULTAS

    virtual bool estaSucia();

    virtual bool estaLimpia();

private:

//	visualizador::aplicacion::ID* id;
	std::string etiqueta;
	ContenidoEntidad* contenido;
//	std::string grupo;

    // true = el contenido que hay en la bd es el correcto | false = el contenido que hay en la bd no esta correcto, hay referencias 'sucias'.
    bool esta_limpia;
};

};
};

