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

    relaciones::RelacionesReporte * relaciones_reporte;

};

};
};
