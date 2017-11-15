#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/ID.h>

// modelo
#include <modelo/include/IAlmacenable.h>
#include <modelo/include/IContieneJson.h>
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
    IEntidad(std::string etiqueta, std::string grupo, IJson * contenido = new IJson());

	virtual ~IEntidad();

	// GETTERS
	
	virtual std::string getEtiqueta();

	virtual std::string getValorAlmacenable();

	// SETTERS

	virtual void setEtiqueta(std::string etiqueta);

	// METODOS

	virtual void parsearValorAlmacenable(std::string valor_almacenable);

    // CONSULTAS

    virtual bool estaSucia();

    virtual bool estaLimpia();

private:

//	visualizador::aplicacion::ID* id;
	std::string etiqueta;
//	ContenidoEntidad* contenido;
//	std::string grupo;

    // true = el contenido que hay en la bd es el correcto | false = el contenido que hay en la bd no esta correcto, hay referencias 'sucias'.
    bool esta_limpia;
};

};
};

