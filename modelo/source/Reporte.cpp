#include <modelo/include/Reporte.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorRelaciones.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

Reporte::Reporte(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoReporte(), NULL), relaciones_reporte(NULL)
{
    this->relaciones_reporte = new relaciones::RelacionesReporte();
    this->setRelaciones(this->relaciones_reporte);
}

Reporte::~Reporte()
{
}

// GETTERS

relaciones::RelacionesReporte * Reporte::getRelacionesReporte()
{
    return this->relaciones_reporte;
}

// SETTERS

void Reporte::setRelacionesReporte(relaciones::RelacionesReporte * relaciones_reporte)
{
    if (NULL != this->relaciones_reporte)
    {
        delete this->relaciones_reporte;
    }

    this->relaciones_reporte = relaciones_reporte;
    this->setRelaciones(this->relaciones_reporte);
}

// METODOS

// metodos IContieneJson

bool Reporte::armarJson()
{
}

bool Reporte::parsearJson()
{
    return true;
}

// metodos IAlmacenable

std::string Reporte::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoReporte();
}

unsigned long long int Reporte::hashcode()
{
    return IHashable::hashear(this->getGrupo() + this->getEtiqueta());
}

// metodos IEntidad

IEntidad * Reporte::clonar()
{
    Reporte * clon = new Reporte(this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setJson(this->getJson()->clonar());

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    relaciones::RelacionesReporte * relaciones_clon = gestor_relaciones.clonar<relaciones::RelacionesReporte>(this->getRelacionesReporte());

    clon->setRelacionesReporte(relaciones_clon);

    return clon;
}

// metodos IRelacionable

bool Reporte::recuperarContenidoDeRelaciones()
{
    return true;
}

void Reporte::actualizarRelaciones(herramientas::utiles::ID * id_nuevo, herramientas::utiles::ID * id_viejo)
{
}

void Reporte::vincular()
{
    visualizador::aplicacion::GestorRelaciones gestor;
    gestor.vincular(this->relaciones_reporte, this->getId());
}

void Reporte::desvincular()
{
    visualizador::aplicacion::GestorRelaciones gestor;
    gestor.desvincular(this->relaciones_reporte, this->getId());
}

bool Reporte::tieneRelacionesDependientes()
{
    return 0 != this->relaciones_reporte->getRelacionConConsultas()->getIdsGrupo().size();
}
