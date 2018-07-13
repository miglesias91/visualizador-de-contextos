#pragma once

// modelo
#include <modelo/include/Medio.h>

namespace visualizador
{
namespace modelo
{

class MedioPortalNoticias : public Medio
{
public:

	// CONSTRUCTORES

    MedioPortalNoticias();

    MedioPortalNoticias(const std::string & web_portal, const std::string & seccion_portal, const std::string & etiqueta = "");

	virtual ~MedioPortalNoticias();

	// GETTERS

    virtual std::string web() const;
    virtual void web(const std::string & web_portal);

    virtual std::string seccion() const;
    virtual void seccion(const std::string & seccion_portal);
    
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
};

};
};
