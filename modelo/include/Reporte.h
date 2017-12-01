#pragma once

// modelo
#include <modelo/include/IEntidad.h>

#include <modelo/include/RelacionesReporte.h>

namespace visualizador
{
namespace modelo
{

class Reporte : public IEntidad
{
public:

	Reporte(std::string etiqueta = "");

	virtual ~Reporte();

    // GETTERS

    relaciones::RelacionesReporte * getRelacionesReporte();

    // SETTERS

    void setRelacionesReporte(relaciones::RelacionesReporte * relaciones_reporte);

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

    relaciones::RelacionesReporte * relaciones_reporte;

};

};
};
