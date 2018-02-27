#include <modelo/include/Seccion.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorRelaciones.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

Seccion::Seccion(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoSeccion(), NULL), relaciones_seccion(NULL)
{
    this->relaciones_seccion = new relaciones::RelacionesSeccion();
    this->setRelaciones(this->relaciones_seccion);
}

Seccion::~Seccion()
{
}

// GETTERS

relaciones::RelacionesSeccion * Seccion::getRelacionesSeccion()
{
    return this->relaciones_seccion;
}

// SETTERS

void Seccion::setRelacionesSeccion(relaciones::RelacionesSeccion * relaciones_seccion)
{
    if (NULL != this->relaciones_seccion)
    {
        delete this->relaciones_seccion;
    }

    this->relaciones_seccion = relaciones_seccion;
    this->setRelaciones(this->relaciones_seccion);
}

// METODOS

// metodos IContieneJson

bool Seccion::armarJson()
{
    return true;
}

bool Seccion::parsearJson()
{
    return true;
}

// metodos de IAlmacenable

std::string Seccion::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoSeccion();
}

unsigned long long int Seccion::hashcode()
{
	return IHashable::hashear(this->getGrupo() + this->getEtiqueta());
}

// metodos de IEntidad

IEntidad * Seccion::clonar()
{
    Seccion * clon = new Seccion(this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setJson(this->getJson()->clonar());

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    relaciones::RelacionesSeccion * relaciones_clon = gestor_relaciones.clonar<relaciones::RelacionesSeccion>(this->getRelacionesSeccion());

    clon->setRelacionesSeccion(relaciones_clon);

    return clon;
}

// metodos de IRelacionable

bool Seccion::recuperarContenidoDeRelaciones()
{
    return true;
}

void Seccion::actualizarRelaciones(herramientas::utiles::ID * id_nuevo, herramientas::utiles::ID * id_viejo)
{
}

void Seccion::vincular()
{
    visualizador::aplicacion::GestorRelaciones gestor;
    gestor.vincular(this->relaciones_seccion, this->getId());
}

void Seccion::desvincular()
{
    visualizador::aplicacion::GestorRelaciones gestor;
    gestor.desvincular(this->relaciones_seccion, this->getId());
}

bool Seccion::tieneRelacionesDependientes()
{
    return 0 != this->relaciones_seccion->getRelacionConConsultas()->getIdsGrupo().size();
}
