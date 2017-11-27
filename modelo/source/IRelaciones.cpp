#include <modelo/include/IRelaciones.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;

IRelaciones::IRelaciones(std::string grupo) : IAlmacenable(grupo), IContieneJson()
{
}

IRelaciones::IRelaciones(IJson * contenido, std::string grupo) : IAlmacenable(grupo), IContieneJson(contenido)
{

}

IRelaciones::~IRelaciones()
{
}
