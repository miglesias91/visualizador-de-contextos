#include <modelo/include/Medio.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorDatosScraping.h>
#include <aplicacion/include/GestorRelaciones.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

Medio::Medio(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedio(), NULL), medio_a_scrapear(NULL)
{
    this->relaciones_medio= new relaciones::RelacionesMedio();
    this->setRelaciones(this->relaciones_medio);
}

Medio::~Medio()
{
    if (NULL != this->medio_a_scrapear)
    {
        delete this->medio_a_scrapear;
        this->medio_a_scrapear = NULL;
    }
}

// GETTERS

std::string Medio::getPrefijoGrupoMedio()
{
    return this->prefijo_grupo_medio;
}

scraping::extraccion::Medio * Medio::getMedioAScrapear()
{
    return this->medio_a_scrapear;
}

relaciones::RelacionesMedio * Medio::getRelacionesMedio()
{
    return this->relaciones_medio;
}

// SETTERS

void Medio::setPrefijoGrupoMedio(std::string prefijo_grupo_medio)
{
    this->prefijo_grupo_medio = prefijo_grupo_medio;
}

void Medio::setMedioAScrapear(scraping::extraccion::Medio * medio_a_scrapear)
{
    if (NULL != this->medio_a_scrapear)
    {
        delete this->medio_a_scrapear;
    }

    this->medio_a_scrapear = medio_a_scrapear;

    this->relaciones_medio->setIDMedioAScrapear(this->medio_a_scrapear->getId()->numero());
}

void Medio::setRelacionesMedio(relaciones::RelacionesMedio * relaciones_medio)
{
    if (NULL != this->relaciones_medio)
    {
        delete this->relaciones_medio;
    }

    this->relaciones_medio = relaciones_medio;
    this->setRelaciones(this->relaciones_medio);
}

// METODOS

// metodos de IContieneJson

void Medio::crearJson()
{
    this->getJson()->reset();

    this->getJson()->agregarAtributoValor("prefijo_grupo_medio", this->getPrefijoGrupoMedio());
}

bool Medio::parsearJson(IJson* json)
{
    std::string prefijo_grupo_medio = this->getJson()->getAtributoValorString("prefijo_grupo_medio");

    this->setPrefijoGrupoMedio(prefijo_grupo_medio);

    return true;
}

// metodos de IAlmacenable

std::string Medio::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoMedio();
}

unsigned Medio::hashcode()
{
    return IHashable::hashear(this->getGrupo() + this->getEtiqueta());
}

// metodos de IEntidad

IEntidad * Medio::clonar()
{
    Medio * clon = new Medio(this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setJson(this->getJson()->clonar());

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    relaciones::RelacionesMedio * relaciones_clon = gestor_relaciones.clonar<relaciones::RelacionesMedio>(this->getRelacionesMedio());

    clon->setRelacionesMedio(relaciones_clon);

    return clon;
}

// metodos de IRelacionable

bool Medio::recuperarContenidoDeRelaciones()
{
    scraping::extraccion::Medio * medio_a_scrapear = new scraping::extraccion::Medio(this->get);

    return true;
}

void Medio::actualizarRelaciones(herramientas::utiles::ID * id_nuevo, herramientas::utiles::ID * id_viejo)
{
}

void Medio::vincular()
{
    visualizador::aplicacion::GestorDatosScraping gestor_datos_scraping;
    gestor_datos_scraping.almacenarMedio(this->getMedioAScrapear());

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    gestor_relaciones.vincular(this->relaciones_medio, this->getId());
}

void Medio::desvincular()
{
    visualizador::aplicacion::GestorDatosScraping gestor_datos_scraping;
    gestor_datos_scraping.eliminarMedio(this->getMedioAScrapear());

    visualizador::aplicacion::GestorRelaciones gestor;
    gestor.desvincular(this->relaciones_medio, this->getId());
}

bool Medio::tieneRelacionesDependientes()
{
    return 0 != this->relaciones_medio->getRelacionConConsultas()->getIdsGrupo().size();
}
