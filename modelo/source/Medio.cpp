#include <modelo/include/Medio.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorRelaciones.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

Medio::Medio(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoMedio(), NULL)
{
    this->relaciones_medio= new relaciones::RelacionesMedio();
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

// METODOS

// metodos de IContieneJson

void Medio::crearJson()
{
}

bool Medio::parsearJson(IJson* json)
{
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
    return true;
}

void Medio::actualizarRelaciones(visualizador::aplicacion::ID * id_nuevo, visualizador::aplicacion::ID * id_viejo)
{
}

void Medio::vincular()
{
    visualizador::aplicacion::GestorRelaciones gestor;
    gestor.vincular(this->relaciones_medio, this->getId());
}

void Medio::desvincular()
{
    visualizador::aplicacion::GestorRelaciones gestor;
    gestor.desvincular(this->relaciones_medio, this->getId());
}
