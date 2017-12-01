#pragma once

// modelo
#include <modelo/include/IEntidad.h>
#include <modelo/include/RelacionesMedio.h>

namespace visualizador
{
namespace modelo
{

class Medio : public IEntidad
{
public:

	// CONSTRUCTORES

	Medio(std::string etiqueta = "");

	virtual ~Medio();

	// GETTERS
    
    relaciones::RelacionesMedio * getRelacionesMedio();

	// SETTERS

    void setRelacionesMedio(relaciones::RelacionesMedio * relaciones_medio);

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

    relaciones::RelacionesMedio * relaciones_medio;


};

};
};
