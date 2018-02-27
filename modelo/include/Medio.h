#pragma once

// scraping::extraccion
#include <extraccion/include/Medio.h>

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

    Medio(std::string tipo_medio, std::string etiqueta = "");

    virtual ~Medio();

    // GETTERS

    relaciones::RelacionesMedio * getRelacionesMedio();

	// SETTERS

    void setRelacionesMedio(relaciones::RelacionesMedio * relaciones_medio);

    // METODOS

    // metodos de IRelacionable

    virtual bool recuperarContenidoDeRelaciones();

    virtual void actualizarRelaciones(herramientas::utiles::ID * id_nuevo, herramientas::utiles::ID * id_viejo = NULL);

    // CONSULTAS

    // consultas de IRelacionable

    virtual bool tieneRelacionesDependientes();

private:

    // ATRIBUTOS

    relaciones::RelacionesMedio * relaciones_medio;
};

};
};
