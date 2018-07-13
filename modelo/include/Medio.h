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

    virtual scraping::extraccion::Medio * getMedioAScrapear();

    virtual std::string getNombre();

    virtual std::string seccion() const;
    virtual void seccion(const std::string & seccion_medio);

	// SETTERS

    void setRelacionesMedio(relaciones::RelacionesMedio * relaciones_medio);

    virtual void setMedioAScrapear(scraping::extraccion::Medio * medio_a_scrapear);

    virtual void setNombre(std::string nombre);

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

    scraping::extraccion::Medio * medio_a_scrapear;

    std::string nombre, seccion_medio;
};

};
};
