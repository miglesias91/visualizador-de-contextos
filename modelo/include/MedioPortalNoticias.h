#pragma once

// aplicacion
#include <aplicacion/include/GestorRelaciones.h>

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
        this->setNombre(web_portal + "/" + seccion_portal);
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
    virtual IEntidad * clonar() {
        subseccion * clon = new subseccion(this->getEtiqueta(), this->seccion());
        clon->setId(this->getId()->copia());
        clon->setJson(this->getJson()->clonar());
        clon->fecha_contenido_mas_antiguo(this->fecha_contenido_analizado_mas_antiguo);
        clon->fecha_contenido_mas_reciente(this->fecha_contenido_analizado_mas_reciente);
        clon->contenidos_analizados(this->cantidad_contenidos_analizados);
        clon->tamanio(this->tamanio_total);

        visualizador::aplicacion::GestorRelaciones gestor_relaciones;
        relaciones::RelacionesMedio * relaciones_clon = gestor_relaciones.clonar<relaciones::RelacionesMedio>(this->getRelacionesMedio());

        clon->setRelacionesMedio(relaciones_clon);

        return clon;
    }

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

    virtual std::unordered_map<std::string, subseccion*> subsecciones() const;

    virtual void subsecciones(const std::unordered_map<std::string, subseccion*> & subsecciones_portal);
    
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
    std::unordered_map<std::string, subseccion*> subsecciones_portal;
};

};
};
