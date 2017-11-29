#pragma once

// modelo
#include <modelo/include/IEntidad.h>

#include <modelo/include/RelacionesSeccion.h>

namespace visualizador
{
namespace modelo
{

class Seccion : public IEntidad
{
public:

	Seccion(std::string etiqueta = "");

	virtual ~Seccion();

    // GETTERS

    // SETTERS

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

    relaciones::RelacionesSeccion * relaciones_seccion;

};

};
};
