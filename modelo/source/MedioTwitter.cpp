#include <modelo/include/MedioTwitter.h>

using namespace visualizador::modelo;

// scraping
#include <scraping/include/GestorMedios.h>

// aplicacion
#include <aplicacion/include/GestorDatosScraping.h>
#include <aplicacion/include/GestorRelaciones.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

MedioTwitter::MedioTwitter(std::string etiqueta) : Medio(visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioTwitter() ,etiqueta), cuenta_a_scrapear(NULL)
{
}

MedioTwitter::~MedioTwitter()
{
    if (NULL != this->cuenta_a_scrapear)
    {
        delete this->cuenta_a_scrapear;
        this->cuenta_a_scrapear = NULL;
    }
}

// GETTERS

scraping::twitter::modelo::Cuenta * MedioTwitter::getCuentaAScrapear()
{
    return this->cuenta_a_scrapear;
}

// SETTERS

void MedioTwitter::setCuentaAScrapear(scraping::twitter::modelo::Cuenta * cuenta_a_scrapear)
{
    if (NULL != this->cuenta_a_scrapear)
    {
        delete this->cuenta_a_scrapear;
    }

    this->cuenta_a_scrapear = cuenta_a_scrapear;

    this->nombre_usuario = this->cuenta_a_scrapear->getNombre();

    this->getRelacionesMedio()->setIDMedioAScrapear(this->cuenta_a_scrapear->getId()->numero());
}

// METODOS

// metodos de IContieneJson

void MedioTwitter::crearJson()
{
    this->getJson()->reset();

    this->getJson()->agregarAtributoValor("nombre_usuario", this->nombre_usuario);
}

bool MedioTwitter::parsearJson(IJson* json)
{
    this->nombre_usuario = json->getAtributoValorString("nombre_usuario");

    return true;
}

// metodos de IAlmacenable

std::string MedioTwitter::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoMedioTwitter();
}

unsigned MedioTwitter::hashcode()
{
    return IHashable::hashear(this->getGrupo() + this->getEtiqueta() + this->nombre_usuario);
}

// metodos de IEntidad

IEntidad * MedioTwitter::clonar()
{
    MedioTwitter * clon = new MedioTwitter(this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setJson(this->getJson()->clonar());

    if (NULL != this->cuenta_a_scrapear)
    {// si hay una cuenta a scrapear, la clono.
        scraping::aplicacion::GestorMedios gestor_medios;
        clon->setCuentaAScrapear(gestor_medios.clonar<scraping::twitter::modelo::Cuenta>(this->cuenta_a_scrapear));
    }

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    relaciones::RelacionesMedio * relaciones_clon = gestor_relaciones.clonar<relaciones::RelacionesMedio>(this->getRelacionesMedio());

    clon->setRelacionesMedio(relaciones_clon);

    return clon;
}

// metodos de IRelacionable

bool MedioTwitter::recuperarContenidoDeRelaciones()
{
    if (0 == this->getRelacionesMedio()->getIDMedioAScrapear())
    {// si no tiene cuenta a scrapear asociada, entonces no recupero nada y devuelve q la operacion salio bien.
        return true;
    }

    scraping::twitter::modelo::Cuenta * cuenta_a_scrapear = new scraping::twitter::modelo::Cuenta();
    cuenta_a_scrapear->setId(new herramientas::utiles::ID(this->getRelacionesMedio()->getIDMedioAScrapear()));

    this->setCuentaAScrapear(cuenta_a_scrapear);

    visualizador::aplicacion::GestorDatosScraping gestor_datos_scraping;
    return gestor_datos_scraping.recuperarMedio(cuenta_a_scrapear);
}

void MedioTwitter::vincular()
{
    if (NULL != this->getCuentaAScrapear())
    {
        visualizador::aplicacion::GestorDatosScraping gestor_datos_scraping;
        gestor_datos_scraping.almacenarMedio(this->getCuentaAScrapear());
        gestor_datos_scraping.almacenarIDActualMedio();
    }

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    gestor_relaciones.vincularMedioTwitter(this->getRelacionesMedio(), this->getId());

    //Medio::vincular();
}

void MedioTwitter::desvincular()
{
    if (NULL != this->getCuentaAScrapear())
    {
        visualizador::aplicacion::GestorDatosScraping gestor_datos_scraping;
        gestor_datos_scraping.eliminarMedio(this->getCuentaAScrapear());
    }

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    gestor_relaciones.desvincularMedioTwitter(this->getRelacionesMedio(), this->getId());
    //Medio::desvincular();
}
