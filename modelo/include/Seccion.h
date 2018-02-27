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

    relaciones::RelacionesSeccion * getRelacionesSeccion();

    // SETTERS

    void setRelacionesSeccion(relaciones::RelacionesSeccion * relaciones_seccion);

	// METODOS

    // metodos de IContieneJson

	virtual void crearJson();

	virtual bool parsearJson(IJson* json);

    // metodos de IAlmacenable

	virtual std::string prefijoGrupo();

	virtual unsigned long long int hashcode();

    // metodos de IEntidad

    virtual IEntidad * clonar();

    // metodos de IRelacionable

    virtual bool recuperarContenidoDeRelaciones();

    virtual void actualizarRelaciones(herramientas::utiles::ID * id_nuevo, herramientas::utiles::ID * id_viejo = NULL);

    virtual void vincular();

    virtual void desvincular();

    // CONSULTAS

    // consultas de IRelacionable

    virtual bool tieneRelacionesDependientes();

private:

    relaciones::RelacionesSeccion * relaciones_seccion;

};

};
};
