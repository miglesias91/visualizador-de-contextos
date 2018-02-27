#pragma once

// stl
#include <string>

// herramientas
#include <utiles/include/IContieneJson.h>
#include <utiles/include/IReferenciable.h>

// modelo
#include <modelo/include/IAlmacenable.h>
#include <modelo/include/IRelacionable.h>

namespace visualizador
{
namespace modelo
{

class IEntidad : public IAlmacenable, public herramientas::utiles::IContieneJson, public relaciones::IRelacionable, public herramientas::utiles::IReferenciable
{
public:

	// CONSTRUCTORES
	IEntidad();
    IEntidad(std::string etiqueta, std::string grupo, relaciones::IRelaciones * relaciones, herramientas::utiles::Json * json = new herramientas::utiles::Json());

	virtual ~IEntidad();

	// GETTERS
	
	virtual std::string getEtiqueta();
    
    // getters de IAlmacenable

    virtual std::string getValorAlmacenable();

	// SETTERS

	virtual void setEtiqueta(std::string etiqueta);

    // setters de IAlmacenable

    virtual void setId(herramientas::utiles::ID* id_termino);

	// METODOS

    virtual IEntidad * clonar() = 0;

    static std::vector<IAlmacenable*> comoAlmacenables(std::vector<IEntidad*> entidades);

    // metodos de IAlmacenable

	virtual void parsearValorAlmacenable(std::string valor_almacenable);

    // CONSULTAS

    virtual bool estaSucia();

    virtual bool estaLimpia();

private:

	std::string etiqueta;

    // true = el contenido que hay en la bd es el correcto | false = el contenido que hay en la bd no esta correcto, hay referencias 'sucias'.
    bool esta_limpia;
};

};
};

