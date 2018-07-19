#pragma once

// modelo
#include <modelo/include/Medio.h>

namespace visualizador
{
namespace modelo
{

struct subseccion : public Medio {
public:
    subseccion(const std::string & web_portal, const std::string & seccion_portal)
        : Medio(visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioPortalNoticias(), web_portal) {
        this->setNombre(seccion_portal);
        this->seccion(seccion_portal);
    }

    // metodos de IContieneJson
    virtual bool armarJson() { return true; }
    virtual bool parsearJson() { return true; }

    // metodos de IAlmacenable
    virtual std::string prefijoGrupo() {
        return aplicacion::ConfiguracionAplicacion::prefijoMedioPortalNoticias();
    }

    virtual unsigned long long int hashcode() {
        return herramientas::utiles::IHashable::hashear(this->getNombre() + this->seccion());
    }

    // metodos de IEntidad
    virtual IEntidad * clonar() { return nullptr; }

    // metodos de IRelacionable
    virtual bool recuperarContenidoDeRelaciones() { return true; }
    virtual void vincular() {}
    virtual void desvincular() {}
};

class MedioPortalNoticias : public Medio
{
public:
	// CONSTRUCTORES

    MedioPortalNoticias();

    MedioPortalNoticias(const std::string & web_portal, const std::string & etiqueta = "");

	virtual ~MedioPortalNoticias();

	// GETTERS

    virtual std::string web() const;
    virtual void web(const std::string & web_portal);

    virtual std::vector<subseccion*> subsecciones() const;
    virtual void subsecciones(const std::vector<subseccion*> & subsecciones_portal);
    
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
    std::string web_portal;
    std::vector<subseccion*> subsecciones_portal;
};

};
};
