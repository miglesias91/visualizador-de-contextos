#include <modelo/include/Seccion.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

Seccion::Seccion(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoSeccion(), NULL)
{
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
