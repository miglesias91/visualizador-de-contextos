#include <modelo/include/IRelaciones.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;

IRelaciones::IRelaciones(herramientas::utiles::ID* id_entidad, std::string grupo, herramientas::utiles::Json * json) : IAlmacenable(grupo), herramientas::utiles::IContieneJson(json)
{
    this->setId(id_entidad);
}

IRelaciones::~IRelaciones()
{
}
