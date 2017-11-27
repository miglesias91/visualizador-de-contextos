#include <modelo/include/IRelaciones.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;

IRelaciones::IRelaciones(visualizador::aplicacion::ID* id_entidad, std::string grupo) : IAlmacenable(grupo), IContieneJson()
{
    this->setId(id_entidad);
}

IRelaciones::IRelaciones(IJson * contenido, visualizador::aplicacion::ID* id_entidad, std::string grupo) : IAlmacenable(grupo), IContieneJson(contenido)
{
    this->setId(id_entidad);
}

IRelaciones::~IRelaciones()
{
}
