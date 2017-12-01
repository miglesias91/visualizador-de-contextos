#pragma once

// stl
#include <functional>
#include <string>

// aplicacion
#include <aplicacion/include/GestorRelaciones.h>

// modelo
#include <modelo/include/IEntidad.h>
#include <modelo/include/RelacionesTermino.h>

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

    relaciones::RelacionesTermino * getRelacionesTermino();

	// SETTERS
	
	void setValor(std::string valor);

    void setRelacionesTermino(relaciones::RelacionesTermino * relaciones_termino);

	// METODOS

    // metodos de IContieneJson

	virtual void crearJson();

	virtual bool parsearJson(IJson* json);
	
    // metodos de IAlmacenable

	virtual std::string prefijoGrupo();

	virtual unsigned int hashcode();

    // metodos de IEntidad

    virtual IEntidad * clonar();

    // metodos de IRelacionable

    virtual bool recuperarContenidoDeRelaciones();

    virtual void actualizarRelaciones(visualizador::aplicacion::ID * id_nuevo, visualizador::aplicacion::ID * id_viejo = NULL);

    virtual void vincular();

    virtual void desvincular();

private:

	std::string valor;

    relaciones::RelacionesTermino * relaciones_termino;
};

};
};

