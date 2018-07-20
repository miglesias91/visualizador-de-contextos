#include <modelo/include/MedioTwitter.h>

using namespace visualizador::modelo;

// scraping
#include <scraping/include/GestorMedios.h>
#include <extraccion/include/MedioTwitter.h>

// aplicacion
#include <aplicacion/include/GestorResultadosDiarios.h>
#include <aplicacion/include/GestorRelaciones.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

MedioTwitter::MedioTwitter() :
    Medio(visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioTwitter(), ""), nombre_usuario("") {}

MedioTwitter::MedioTwitter(std::string nombre_usuario, std::string etiqueta) :
    Medio(visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioTwitter() ,etiqueta), nombre_usuario(nombre_usuario) {}

MedioTwitter::~MedioTwitter() {}

// GETTERS

std::string MedioTwitter::getNombreUsuario()
{
    return this->nombre_usuario;
}

// SETTERS

void MedioTwitter::setNombreUsuario(std::string nombre_usuario)
{
    this->nombre_usuario = nombre_usuario;

    this->setNombre(this->nombre_usuario);
}

//void MedioTwitter::setCuentaAScrapear(scraping::twitter::modelo::Cuenta * cuenta_a_scrapear)
//{
//    if (NULL != this->cuenta_a_scrapear)
//    {
//        delete this->cuenta_a_scrapear;
//    }
//
//    this->cuenta_a_scrapear = cuenta_a_scrapear;
//
//    this->setNombreUsuario(this->cuenta_a_scrapear->getNombre());
//    this->fecha_tweet_mas_antiguo = this->cuenta_a_scrapear->getFechaContenidoHistoricoMasAntiguo();
//    this->fecha_tweet_mas_antiguo = this->cuenta_a_scrapear->getFechaContenidoHistoricoMasReciente();
//    this->cantidad_tweets_analizados = this->cuenta_a_scrapear->getCantidadDeContenidosHistoricos();
//
//    this->getRelacionesMedio()->setIDMedioAScrapear(this->cuenta_a_scrapear->getId()->numero());
//
//    this->setMedioAScrapear(this->cuenta_a_scrapear);
//}

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
    this->setNombreUsuario(this->getJson()->getAtributoValorString("nombre_usuario"));

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

    clon->setNombreUsuario(this->nombre_usuario);
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

bool MedioTwitter::recuperarContenidoDeRelaciones() {
    scraping::extraccion::interfaceo::MedioTwitter cuenta;
    cuenta.setId(this->getId()->copia());

    aplicacion::GestorResultadosDiarios gestor_resultados;
    bool existe_medio = gestor_resultados.recuperar(&cuenta);
    if (existe_medio) {
        this->setNombreUsuario(cuenta.etiqueta());
        this->fecha_contenido_analizado_mas_antiguo = cuenta.getFechaContenidoHistoricoMasAntiguo();
        this->fecha_contenido_analizado_mas_reciente = cuenta.getFechaContenidoHistoricoMasReciente();
        this->cantidad_contenidos_analizados = cuenta.getCantidadDeContenidosHistoricos();
        this->tamanio_total = cuenta.tamanio();
    }

    return existe_medio;
}

void MedioTwitter::vincular() {
    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    gestor_relaciones.vincularMedioTwitter(this->getRelacionesMedio(), this->getId());
}

void MedioTwitter::desvincular() {
    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    gestor_relaciones.desvincularMedioTwitter(this->getRelacionesMedio(), this->getId());
}
