#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/ID.h>

// modelo
#include <modelo/include/IAlmacenable.h>
#include <modelo/include/IContieneJson.h>
#include <modelo/include/IReferenciable.h>
#include <modelo/include/IRelaciones.h>

namespace visualizador
{
namespace modelo
{

class IEntidad : public IAlmacenable, public IContieneJson, public IReferenciable
{
public:

	// CONSTRUCTORES
	IEntidad();
    IEntidad(std::string etiqueta, std::string grupo, relaciones::IRelaciones * relaciones, IJson * contenido = new IJson());

	virtual ~IEntidad();

	// GETTERS
	
	virtual std::string getEtiqueta();

    virtual relaciones::IRelaciones * IEntidad::getRelaciones();
    
    // metodos IAlmacenable

    virtual std::string getValorAlmacenable();

	// SETTERS

	virtual void setEtiqueta(std::string etiqueta);

    virtual void setRelaciones(relaciones::IRelaciones * relaciones);

    // metodos de IAlmacenable

    virtual void setId(visualizador::aplicacion::ID* id_termino);

	// METODOS

	virtual void parsearValorAlmacenable(std::string valor_almacenable);

    virtual IEntidad * clonar() = 0;

    static std::vector<IAlmacenable*> comoAlmacenables(std::vector<IEntidad*> entidades);

    // CONSULTAS

    virtual bool estaSucia();

    virtual bool estaLimpia();

private:

	std::string etiqueta;

    relaciones::IRelaciones * relaciones;

    // true = el contenido que hay en la bd es el correcto | false = el contenido que hay en la bd no esta correcto, hay referencias 'sucias'.
    bool esta_limpia;
};

};
};

