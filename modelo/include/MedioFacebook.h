#pragma once

// scraping::extraccion
#include <facebook/include/Pagina.h>

// modelo
#include <modelo/include/Medio.h>

namespace visualizador
{
namespace modelo
{

class MedioFacebook : public Medio
{
public:

	// CONSTRUCTORES

    MedioFacebook();

    MedioFacebook(std::string nombre_pagina, std::string etiqueta = "");

	virtual ~MedioFacebook();

	// GETTERS

    virtual std::string getNombrePagina();

    virtual scraping::facebook::modelo::Pagina * getPaginaAScrapear();

	// SETTERS

    virtual void setPaginaAScrapear(scraping::facebook::modelo::Pagina * pagina_a_scrapear);
    // METODOS

    // metodos de IContieneJson

    virtual bool armarJson();

    virtual bool parsearJson();

    // metodos de IAlmacenable

    virtual std::string prefijoGrupo();

    virtual unsigned long long int hashcode();

    // metodos de IEntidad

    virtual IEntidad * clonar();

    // metodos de IRelacionable

    virtual bool recuperarContenidoDeRelaciones();

    virtual void vincular();

    virtual void desvincular();

    // CONSULTAS

private:

    // ATRIBUTOS

    std::string nombre_pagina;

    herramientas::utiles::Fecha fecha_publicacion_mas_reciente;
    herramientas::utiles::Fecha fecha_publicacion_mas_antigua;
    unsigned long long int cantidad_publicaciones_analizadas;

    scraping::facebook::modelo::Pagina * pagina_a_scrapear;
};

};
};
