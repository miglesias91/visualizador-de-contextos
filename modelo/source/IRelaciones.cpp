#include <modelo/include/IRelaciones.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;

IRelaciones::IRelaciones(visualizador::aplicacion::ID* id_entidad, std::string grupo, IJson * json) : IAlmacenable(grupo), IContieneJson(json)
{
    this->setId(id_entidad);
}

IRelaciones::~IRelaciones()
{
}
