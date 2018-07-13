#include <modelo/include/Medio.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorDatosScraping.h>
#include <aplicacion/include/GestorRelaciones.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

Medio::Medio(std::string tipo_medio, std::string etiqueta) : IEntidad(etiqueta, tipo_medio, NULL), seccion_medio("")
{
    this->relaciones_medio = new relaciones::RelacionesMedio();
    this->setRelaciones(this->relaciones_medio);
}

Medio::~Medio()
{
}

// GETTERS

relaciones::RelacionesMedio * Medio::getRelacionesMedio()
{
    return this->relaciones_medio;
}

scraping::extraccion::Medio * Medio::getMedioAScrapear()
{
    return this->medio_a_scrapear;
}

std::string Medio::getNombre()
{
    return this->nombre;
}

std::string visualizador::modelo::Medio::seccion() const {
    return this->seccion_medio;
}

void Medio::seccion(const std::string & seccion_medio) {
    this->seccion_medio = seccion_medio;
}

// SETTERS

void Medio::setRelacionesMedio(relaciones::RelacionesMedio * relaciones_medio)
{
    if (NULL != this->relaciones_medio)
    {
        delete this->relaciones_medio;
    }

    this->relaciones_medio = relaciones_medio;
    this->setRelaciones(this->relaciones_medio);
}

void Medio::setMedioAScrapear(scraping::extraccion::Medio * medio_a_scrapear)
{
    this->medio_a_scrapear = medio_a_scrapear;
}

void Medio::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

// METODOS

// metodos de IRelacionable

bool Medio::recuperarContenidoDeRelaciones()
{
    return true;
}

void Medio::actualizarRelaciones(herramientas::utiles::ID * id_nuevo, herramientas::utiles::ID * id_viejo)
{
}

bool Medio::tieneRelacionesDependientes()
{
    return 0 != this->relaciones_medio->getRelacionConConsultas()->getIdsGrupo().size();
}
