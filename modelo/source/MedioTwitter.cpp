#include <modelo/include/MedioTwitter.h>

using namespace visualizador::modelo;

// scraping
#include <scraping/include/GestorMedios.h>

// aplicacion
#include <aplicacion/include/GestorDatosScraping.h>
#include <aplicacion/include/GestorRelaciones.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

MedioTwitter::MedioTwitter() :
    Medio(visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioTwitter(), ""), nombre_usuario(""), cuenta_a_scrapear(NULL)
{
}

MedioTwitter::MedioTwitter(std::string nombre_usuario, std::string etiqueta) :
    Medio(visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioTwitter() ,etiqueta), nombre_usuario(nombre_usuario), cuenta_a_scrapear(NULL)
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

std::string MedioTwitter::getNombreUsuario()
{
    return this->nombre_usuario;
}

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
    this->fecha_tweet_mas_antiguo = this->cuenta_a_scrapear->getFechaContenidoHistoricoMasAntiguo();
    this->fecha_tweet_mas_antiguo = this->cuenta_a_scrapear->getFechaContenidoHistoricoMasReciente();
    this->cantidad_tweets_analizados = this->cuenta_a_scrapear->getCantidadDeContenidosHistoricos();

    this->getRelacionesMedio()->setIDMedioAScrapear(this->cuenta_a_scrapear->getId()->numero());
}

// METODOS

// metodos de IContieneJson

bool MedioTwitter::armarJson()
{
    this->getJson()->reset();

    this->getJson()->agregarAtributoValor("nombre_usuario", this->nombre_usuario);

    return true;
}

bool MedioTwitter::parsearJson()
{
    this->nombre_usuario = this->getJson()->getAtributoValorString("nombre_usuario");

    return true;
}

// metodos de IAlmacenable

std::string MedioTwitter::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoMedioTwitter();
}

unsigned long long int MedioTwitter::hashcode()
{
    return herramientas::utiles::IHashable::hashear(this->getNombreUsuario());
}

// metodos de IEntidad

IEntidad * MedioTwitter::clonar()
{
    MedioTwitter * clon = new MedioTwitter(this->getNombreUsuario(), this->getEtiqueta());
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

    visualizador::aplicacion::GestorDatosScraping gestor_datos_scraping;
    bool existe_datos_scraping = gestor_datos_scraping.recuperarMedio(cuenta_a_scrapear);
    if (existe_datos_scraping)
    {
        this->setCuentaAScrapear(cuenta_a_scrapear);
    }

    return existe_datos_scraping;
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
}
