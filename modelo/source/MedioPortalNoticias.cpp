#include <modelo/include/MedioPortalNoticias.h>

using namespace visualizador::modelo;

// scraping
#include <scraping/include/GestorMedios.h>
#include <extraccion/include/MedioPortalNoticias.h>

// aplicacion
#include <aplicacion/include/GestorResultadosDiarios.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

MedioPortalNoticias::MedioPortalNoticias() :
    Medio(visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioPortalNoticias(), ""), web_portal("") {
}

MedioPortalNoticias::MedioPortalNoticias(const std::string & web_portal, const std::string & etiqueta) :
    Medio(visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioPortalNoticias(), etiqueta), web_portal(web_portal) {
}

MedioPortalNoticias::~MedioPortalNoticias() {
    std::for_each(begin(this->subsecciones_portal), end(this->subsecciones_portal), [=](std::pair<std::string,subseccion*> subseccion_portal) { delete subseccion_portal.second; });
}

std::string MedioPortalNoticias::web() const {
    return this->web_portal;
}

void MedioPortalNoticias::web(const std::string & web_portal) {
    this->web_portal = web_portal;
    this->setNombre(this->web_portal);
}

std::unordered_map<std::string, subseccion*> MedioPortalNoticias::subsecciones() const {
    return this->subsecciones_portal;
}

void MedioPortalNoticias::subsecciones(const std::unordered_map<std::string, subseccion*> & secciones_portal) {
    std::for_each(begin(this->subsecciones_portal), end(this->subsecciones_portal), [=](std::pair<std::string,subseccion*> subseccion_portal) { delete subseccion_portal.second; });
    this->subsecciones_portal = secciones_portal;
}

// metodos de IContieneJson

bool MedioPortalNoticias::armarJson()
{
    this->getJson()->reset();

    this->getJson()->agregarAtributoValor("web_portal", this->web_portal);

    return true;
}

bool MedioPortalNoticias::parsearJson()
{
    this->web(this->getJson()->getAtributoValorString("web_portal"));

    return true;
}

// metodos de IAlmacenable

std::string MedioPortalNoticias::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoMedioPortalNoticias();
}

unsigned long long int MedioPortalNoticias::hashcode()
{
    return herramientas::utiles::IHashable::hashear(this->web());
}

// metodos de IEntidad

IEntidad * MedioPortalNoticias::clonar()
{
    MedioPortalNoticias * clon = new MedioPortalNoticias(this->web(), this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setJson(this->getJson()->clonar());

    clon->web(this->web_portal);
    clon->fecha_contenido_mas_antiguo(this->fecha_contenido_analizado_mas_antiguo);
    clon->fecha_contenido_mas_reciente(this->fecha_contenido_analizado_mas_reciente);
    clon->contenidos_analizados(this->cantidad_contenidos_analizados);
    clon->seccion(this->seccion());

    std::unordered_map<std::string, subseccion*> subsecciones_clon;
    std::for_each(this->subsecciones_portal.begin(), this->subsecciones_portal.end(), [=, &subsecciones_clon](std::pair<std::string, subseccion*> subseccion_portal) {
        subsecciones_clon[subseccion_portal.second->seccion()] = new subseccion(this->web(), subseccion_portal.second->seccion());
    });

    clon->subsecciones(subsecciones_clon);

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    relaciones::RelacionesMedio * relaciones_clon = gestor_relaciones.clonar<relaciones::RelacionesMedio>(this->getRelacionesMedio());

    clon->setRelacionesMedio(relaciones_clon);

    return clon;
}

// metodos de IRelacionable

bool MedioPortalNoticias::recuperarContenidoDeRelaciones() {
    scraping::extraccion::interfaceo::MedioPortalNoticias portal;
    portal.setId(this->getId()->copia());

    aplicacion::GestorResultadosDiarios gestor_resultados;
    bool existe_medio = gestor_resultados.recuperar(&portal);
    if (existe_medio) {
        std::unordered_map<std::string, scraping::extraccion::interfaceo::seccion> info_secciones = portal.secciones();

        std::for_each(info_secciones.begin(), info_secciones.end(), [=](std::pair<std::string, scraping::extraccion::interfaceo::seccion> seccion_info) {
            if (this->subsecciones_portal.count(seccion_info.first) == 0) {
                this->subsecciones_portal[seccion_info.first] = new subseccion(this->web(), seccion_info.first);
            }

            this->subsecciones_portal[seccion_info.first]->setId(this->getId()->copia());
            this->subsecciones_portal[seccion_info.first]->fecha_contenido_mas_antiguo(seccion_info.second.mas_antiguo);
            this->subsecciones_portal[seccion_info.first]->fecha_contenido_mas_reciente(seccion_info.second.mas_reciente);
            this->subsecciones_portal[seccion_info.first]->contenidos_analizados(seccion_info.second.cantidad_total);
            this->subsecciones_portal[seccion_info.first]->tamanio(seccion_info.second.tamanio_total);
        });
    }

    return existe_medio;
}

void MedioPortalNoticias::vincular() {
    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    gestor_relaciones.vincularMedioPortalNoticias(this->getRelacionesMedio(), this->getId());
}

void MedioPortalNoticias::desvincular() {
    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    gestor_relaciones.desvincularMedioPortalNoticias(this->getRelacionesMedio(), this->getId());
}
