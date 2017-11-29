#include <modelo/include/Seccion.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

Seccion::Seccion(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoSeccion(), NULL), relaciones_seccion(NULL)
{
    this->relaciones_seccion = new relaciones::RelacionesSeccion();
    this->setRelaciones(this->relaciones_seccion);
}

Seccion::~Seccion()
{
}

void Seccion::crearContenido()
{
}

bool Seccion::parsearContenido(IJson* contenido)
{
    return true;
}

std::string Seccion::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoSeccion();
}

unsigned int Seccion::hashcode()
{
	return 0;
}

IEntidad * Seccion::clonar()
{
    Seccion * clon = new Seccion(this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setContenido(this->getContenido()->clonar());
    return clon;
}

void Seccion::vincular()
{
}

void Seccion::desvincular()
{
}