#include <modelo/include/MedioPortalNoticias.h>

using namespace visualizador::modelo;

// scraping
#include <scraping/include/GestorMedios.h>
#include <extraccion/include/MedioPortalNoticias.h>

// aplicacion
#include <aplicacion/include/GestorResultadosDiarios.h>
#include <aplicacion/include/GestorRelaciones.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

MedioPortalNoticias::MedioPortalNoticias() :
    Medio(visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioPortalNoticias(), ""), web_portal("") {
}

MedioPortalNoticias::MedioPortalNoticias(const std::string & web_portal, const std::string & etiqueta) :
    Medio(visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioPortalNoticias(), etiqueta), web_portal(web_portal) {
}

MedioPortalNoticias::~MedioPortalNoticias() {}

std::string MedioPortalNoticias::web() const {
    return std::string();
}

void MedioPortalNoticias::web(const std::string & web_portal) {
    this->web_portal = web_portal;
}

std::vector<std::string> MedioPortalNoticias::secciones() const {
    return this->secciones_portal;
}

void MedioPortalNoticias::secciones(const std::vector<std::string> & secciones_portal) {
    this->secciones_portal = secciones_portal;
}

// metodos de IContieneJson

bool MedioPortalNoticias::armarJson()
{
    this->getJson()->reset();

    this->getJson()->agregarAtributoValor("web_portal", this->web_portal);
    this->getJson()->agregarAtributoArray("secciones", this->secciones);

    return true;
}

bool MedioPortalNoticias::parsearJson()
{
    this->web(this->getJson()->getAtributoValorString("web_portal"));
    this->secciones(this->getJson()->getAtributoArrayString("secciones"));

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

    //if (NULL != this->pagina_a_scrapear)
    //{// si hay una cuenta a scrapear, la clono.
    //    scraping::aplicacion::GestorMedios gestor_medios;
    //    clon->setPaginaAScrapear(gestor_medios.clonar<scraping::facebook::modelo::Pagina>(this->pagina_a_scrapear));
    //}
    clon->web(this->web_portal);
    clon->fecha_contenido_mas_antiguo(this->fecha_contenido_analizado_mas_antiguo);
    clon->fecha_contenido_mas_reciente(this->fecha_contenido_analizado_mas_reciente);
    clon->contenidos_analizados(this->cantidad_contenidos_analizados);

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
        this->web(portal.etiqueta());
        this->fecha_contenido_analizado_mas_antiguo = portal.getFechaContenidoHistoricoMasAntiguo();
        this->fecha_contenido_analizado_mas_reciente = portal.getFechaContenidoHistoricoMasReciente();
        this->cantidad_contenidos_analizados = portal.getCantidadDeContenidosHistoricos();
    }

    return existe_medio;
}

void MedioPortalNoticias::vincular() {
    //if (NULL != this->getPaginaAScrapear())
    //{
    //    visualizador::aplicacion::GestorDatosScraping gestor_datos_scraping;
    //    gestor_datos_scraping.almacenarMedio(this->getPaginaAScrapear());
    //    gestor_datos_scraping.almacenarIDActualMedio();
    //}

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    gestor_relaciones.vincularMedioPortalNoticias(this->getRelacionesMedio(), this->getId());
}

void MedioPortalNoticias::desvincular() {
    //if (NULL != this->getPaginaAScrapear())
    //{
    //    visualizador::aplicacion::GestorDatosScraping gestor_datos_scraping;
    //    gestor_datos_scraping.eliminarMedio(this->getPaginaAScrapear());
    //}

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    gestor_relaciones.desvincularMedioPortalNoticias(this->getRelacionesMedio(), this->getId());
}
