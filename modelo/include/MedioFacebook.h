#pragma once

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

    //virtual scraping::facebook::modelo::Pagina * getPaginaAScrapear();

    // metodos de Medio

    //virtual scraping::extraccion::Medio * getMedioAScrapear();

	// SETTERS

    virtual void setNombrePagina(std::string nombre_pagina);

    //virtual void setPaginaAScrapear(scraping::facebook::modelo::Pagina * pagina_a_scrapear);
    
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
};

};
};
