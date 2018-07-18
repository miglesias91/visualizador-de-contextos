#include <modelo/include/MedioFacebook.h>

using namespace visualizador::modelo;

// scraping
#include <scraping/include/GestorMedios.h>
#include <extraccion/include/MedioFacebook.h>

// aplicacion
#include <aplicacion/include/GestorResultadosDiarios.h>
#include <aplicacion/include/GestorRelaciones.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

MedioFacebook::MedioFacebook() :
    Medio(visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioFacebook(), ""), nombre_pagina("") {}

MedioFacebook::MedioFacebook(std::string nombre_pagina, std::string etiqueta) :
    Medio(visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedioFacebook(), etiqueta), nombre_pagina(nombre_pagina) {}

MedioFacebook::~MedioFacebook() {}

// GETTERS

std::string MedioFacebook::getNombrePagina() {
    return this->nombre_pagina;
}

// SETTERS

void MedioFacebook::setNombrePagina(std::string nombre_pagina)
{
    this->nombre_pagina = nombre_pagina;

    this->setNombre(this->nombre_pagina);
}

//void MedioFacebook::setPaginaAScrapear(scraping::facebook::modelo::Pagina * pagina_a_scrapear)
//{
//    if (NULL != this->pagina_a_scrapear)
//    {
//        delete this->pagina_a_scrapear;
//    }
//
//    this->pagina_a_scrapear = pagina_a_scrapear;
//
//    this->setNombrePagina(this->pagina_a_scrapear->getNombre());
//    this->fecha_publicacion_mas_antigua = this->pagina_a_scrapear->getFechaContenidoHistoricoMasAntiguo();
//    this->fecha_publicacion_mas_reciente = this->pagina_a_scrapear->getFechaContenidoHistoricoMasReciente();
//    this->cantidad_publicaciones_analizadas = this->pagina_a_scrapear->getCantidadDeContenidosHistoricos();
//
//    this->getRelacionesMedio()->setIDMedioAScrapear(this->pagina_a_scrapear->getId()->numero());
//
//    this->setMedioAScrapear(this->pagina_a_scrapear);
//}

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
    this->setNombrePagina(this->getJson()->getAtributoValorString("nombre_pagina"));

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

    //if (NULL != this->pagina_a_scrapear)
    //{// si hay una cuenta a scrapear, la clono.
    //    scraping::aplicacion::GestorMedios gestor_medios;
    //    clon->setPaginaAScrapear(gestor_medios.clonar<scraping::facebook::modelo::Pagina>(this->pagina_a_scrapear));
    //}
    clon->setNombrePagina(this->nombre_pagina);
    clon->fecha_contenido_mas_antiguo(this->fecha_contenido_analizado_mas_antiguo);
    clon->fecha_contenido_mas_reciente(this->fecha_contenido_analizado_mas_reciente);
    clon->contenidos_analizados(this->cantidad_contenidos_analizados);

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    relaciones::RelacionesMedio * relaciones_clon = gestor_relaciones.clonar<relaciones::RelacionesMedio>(this->getRelacionesMedio());

    clon->setRelacionesMedio(relaciones_clon);

    return clon;
}

// metodos de IRelacionable

bool MedioFacebook::recuperarContenidoDeRelaciones() {
    scraping::extraccion::interfaceo::MedioFacebook pagina;
    pagina.setId(this->getId()->copia());

    aplicacion::GestorResultadosDiarios gestor_resultados;
    bool existe_medio = gestor_resultados.recuperar(&pagina);
    if (existe_medio) {
        this->setNombrePagina(pagina.etiqueta());
        this->fecha_contenido_analizado_mas_antiguo = pagina.getFechaContenidoHistoricoMasAntiguo();
        this->fecha_contenido_analizado_mas_reciente = pagina.getFechaContenidoHistoricoMasReciente();
        this->cantidad_contenidos_analizados = pagina.getCantidadDeContenidosHistoricos();
    }

    return existe_medio;
}

void MedioFacebook::vincular()
{
    //if (NULL != this->getPaginaAScrapear())
    //{
    //    visualizador::aplicacion::GestorResultadosDiarios gestor_datos_scraping;
    //    gestor_datos_scraping.almacenarMedio(this->getPaginaAScrapear());
    //    gestor_datos_scraping.almacenarIDActualMedio();
    //}

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    gestor_relaciones.vincularMedioFacebook(this->getRelacionesMedio(), this->getId());
}

void MedioFacebook::desvincular()
{
    //if (NULL != this->getPaginaAScrapear())
    //{
    //    visualizador::aplicacion::GestorResultadosDiarios gestor_datos_scraping;
    //    gestor_datos_scraping.eliminarMedio(this->getPaginaAScrapear());
    //}

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    gestor_relaciones.desvincularMedioFacebook(this->getRelacionesMedio(), this->getId());
}
