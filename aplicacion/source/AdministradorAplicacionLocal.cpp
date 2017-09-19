#include <aplicacion/include/AdministradorAplicacionLocal.h>

using namespace visualizador::aplicacion;

AdministradorAplicacionLocal::AdministradorAplicacionLocal()
{
}

AdministradorAplicacionLocal::~AdministradorAplicacionLocal()
{
}

bool AdministradorAplicacionLocal::almacenar(visualizador::modelo::IEntidad * entidad)
{
	return false;
}

bool AdministradorAplicacionLocal::recuperar(visualizador::modelo::IEntidad * entidad)
{
	return false;
}

std::vector<visualizador::modelo::IEntidad*> AdministradorAplicacionLocal::recuperarGrupo(std::string prefijo_grupo)
{
	return std::vector<visualizador::modelo::IEntidad*>();
}
