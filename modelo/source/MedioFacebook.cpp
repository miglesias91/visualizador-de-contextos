#include <modelo/include/MedioFacebook.h>

using namespace visualizador::modelo;

// scraping
#include <scraping/include/GestorMedios.h>

// aplicacion
#include <aplicacion/include/GestorDatosScraping.h>
#include <aplicacion/include/GestorRelaciones.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

MedioFacebook::MedioFacebook() :
    Medio(visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioFacebook(), ""), nombre_pagina(""), pagina_a_scrapear(NULL)
{
}

MedioFacebook::MedioFacebook(std::string nombre_pagina, std::string etiqueta) :
    Medio(visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioFacebook(), etiqueta), nombre_pagina(nombre_pagina), pagina_a_scrapear(NULL)
{
}

MedioFacebook::~MedioFacebook()
{
    if (NULL != this->pagina_a_scrapear)
    {
        delete this->pagina_a_scrapear;
        this->pagina_a_scrapear = NULL;
    }
}

// GETTERS

std::string MedioFacebook::getNombrePagina()
{
    return this->nombre_pagina;
}

scraping::facebook::modelo::Pagina * MedioFacebook::getPaginaAScrapear()
{
    return this->pagina_a_scrapear;
}

// SETTERS

void MedioFacebook::setPaginaAScrapear(scraping::facebook::modelo::Pagina * pagina_a_scrapear)
{
    if (NULL != this->pagina_a_scrapear)
    {
        delete this->pagina_a_scrapear;
    }

    this->pagina_a_scrapear = pagina_a_scrapear;

    this->nombre_pagina = this->pagina_a_scrapear->getNombre();
    this->fecha_publicacion_mas_antigua = this->pagina_a_scrapear->getFechaContenidoHistoricoMasAntiguo();
    this->fecha_publicacion_mas_reciente = this->pagina_a_scrapear->getFechaContenidoHistoricoMasReciente();
    this->cantidad_publicaciones_analizadas = this->pagina_a_scrapear->getCantidadDeContenidosHistoricos();

    this->getRelacionesMedio()->setIDMedioAScrapear(this->pagina_a_scrapear->getId()->numero());
}

// METODOS

// metodos de IContieneJson

bool MedioFacebook::armarJson()
{
    this->getJson()->reset();

    this->getJson()->agregarAtributoValor("nombre_pagina", this->nombre_pagina);

    return true;
}

bool MedioFacebook::parsearJson()
{
    this->nombre_pagina = this->getJson()->getAtributoValorString("nombre_pagina");

    return true;
}

// metodos de IAlmacenable

std::string MedioFacebook::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoMedioFacebook();
}

unsigned long long int MedioFacebook::hashcode()
{
    return herramientas::utiles::IHashable::hashear(this->getNombrePagina());
}

// metodos de IEntidad

IEntidad * MedioFacebook::clonar()
{
    MedioFacebook * clon = new MedioFacebook(this->getNombrePagina(), this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setJson(this->getJson()->clonar());

    if (NULL != this->pagina_a_scrapear)
    {// si hay una cuenta a scrapear, la clono.
        scraping::aplicacion::GestorMedios gestor_medios;
        clon->setPaginaAScrapear(gestor_medios.clonar<scraping::facebook::modelo::Pagina>(this->pagina_a_scrapear));
    }

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    relaciones::RelacionesMedio * relaciones_clon = gestor_relaciones.clonar<relaciones::RelacionesMedio>(this->getRelacionesMedio());

    clon->setRelacionesMedio(relaciones_clon);

    return clon;
}

// metodos de IRelacionable

bool MedioFacebook::recuperarContenidoDeRelaciones()
{
    if (0 == this->getRelacionesMedio()->getIDMedioAScrapear())
    {// si no tiene cuenta a scrapear asociada, entonces no recupero nada y devuelve q la operacion salio bien.
        return true;
    }

    scraping::facebook::modelo::Pagina * pagina_a_scrapear = new scraping::facebook::modelo::Pagina();
    pagina_a_scrapear->setId(new herramientas::utiles::ID(this->getRelacionesMedio()->getIDMedioAScrapear()));

    visualizador::aplicacion::GestorDatosScraping gestor_datos_scraping;
    bool existe_datos_scraping = gestor_datos_scraping.recuperarMedio(pagina_a_scrapear);
    if (existe_datos_scraping)
    {
        this->setPaginaAScrapear(pagina_a_scrapear);
    }

    return existe_datos_scraping;
}

void MedioFacebook::vincular()
{
    if (NULL != this->getPaginaAScrapear())
    {
        visualizador::aplicacion::GestorDatosScraping gestor_datos_scraping;
        gestor_datos_scraping.almacenarMedio(this->getPaginaAScrapear());
        gestor_datos_scraping.almacenarIDActualMedio();
    }

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    gestor_relaciones.vincularMedioFacebook(this->getRelacionesMedio(), this->getId());
}

void MedioFacebook::desvincular()
{
    if (NULL != this->getPaginaAScrapear())
    {
        visualizador::aplicacion::GestorDatosScraping gestor_datos_scraping;
        gestor_datos_scraping.eliminarMedio(this->getPaginaAScrapear());
    }

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    gestor_relaciones.desvincularMedioFacebook(this->getRelacionesMedio(), this->getId());
}
