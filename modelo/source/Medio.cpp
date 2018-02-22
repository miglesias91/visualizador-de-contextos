#include <modelo/include/Medio.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorDatosScraping.h>
#include <aplicacion/include/GestorRelaciones.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

Medio::Medio(std::string tipo_medio, std::string etiqueta) : IEntidad(etiqueta, tipo_medio, NULL)
{
    this->relaciones_medio= new relaciones::RelacionesMedio();
    this->setRelaciones(this->relaciones_medio);
}

Medio::~Medio()
{
    //if (NULL != this->medio_a_scrapear)
    //{
    //    delete this->medio_a_scrapear;
    //    this->medio_a_scrapear = NULL;
    //}
}

// GETTERS

//scraping::extraccion::Medio * Medio::getMedioAScrapear()
//{
//    return this->medio_a_scrapear;
//}

relaciones::RelacionesMedio * Medio::getRelacionesMedio()
{
    return this->relaciones_medio;
}

// SETTERS

//void Medio::setMedioAScrapear(scraping::extraccion::Medio * medio_a_scrapear)
//{
//    if (NULL != this->medio_a_scrapear)
//    {
//        delete this->medio_a_scrapear;
//    }
//
//    this->medio_a_scrapear = medio_a_scrapear;
//
//    this->relaciones_medio->setIDMedioAScrapear(this->medio_a_scrapear->getId()->numero());
//}

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

//void Medio::crearJson()
//{
//}
//
//bool Medio::parsearJson(IJson* json)
//{
//    return true;
//}

// metodos de IAlmacenable

//std::string Medio::prefijoGrupo()
//{
//	return aplicacion::ConfiguracionAplicacion::prefijoMedio();
//}
//
//unsigned Medio::hashcode()
//{
//    return IHashable::hashear(this->getGrupo() + this->getEtiqueta());
//}

// metodos de IEntidad

//IEntidad * Medio::clonar()
//{
//    Medio * clon = new Medio(this->getEtiqueta());
//    clon->setId(this->getId()->copia());
//    clon->setJson(this->getJson()->clonar());
//
//    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
//    relaciones::RelacionesMedio * relaciones_clon = gestor_relaciones.clonar<relaciones::RelacionesMedio>(this->getRelacionesMedio());
//
//    clon->setRelacionesMedio(relaciones_clon);
//
//    return clon;
//}

// metodos de IRelacionable

bool Medio::recuperarContenidoDeRelaciones()
{
    return true;
}

void Medio::actualizarRelaciones(herramientas::utiles::ID * id_nuevo, herramientas::utiles::ID * id_viejo)
{
}

void Medio::vincular()
{
    //visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    //gestor_relaciones.vincular(this->relaciones_medio, this->getId());
}

void Medio::desvincular()
{
    //visualizador::aplicacion::GestorRelaciones gestor;
    //gestor.desvincular(this->relaciones_medio, this->getId());
}

bool Medio::tieneRelacionesDependientes()
{
    return 0 != this->relaciones_medio->getRelacionConConsultas()->getIdsGrupo().size();
}
