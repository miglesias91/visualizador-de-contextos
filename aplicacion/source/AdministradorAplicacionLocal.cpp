#include <aplicacion/include/AdministradorAplicacionLocal.h>

using namespace visualizador::aplicacion;

// almacenamiento
#include <almacenamiento/include/IAdministradorAlmacenamiento.h>

AdministradorAplicacionLocal::AdministradorAplicacionLocal()
{
}

AdministradorAplicacionLocal::~AdministradorAplicacionLocal()
{
}

bool AdministradorAplicacionLocal::almacenar(visualizador::modelo::IEntidad * entidad)
{
	std::string clave = entidad->getId()->string();
	std::string grupo = entidad->getGrupo();
	std::string valor = entidad->getValorAlmacenable();

	almacenamiento::IAlmacenableClaveValor* entidad_a_almacenar = new almacenamiento::IAlmacenableClaveValor(clave, valor, grupo);

	bool retorno = almacenamiento::IAdministradorAlmacenamiento::getInstancia()->almacenar(entidad_a_almacenar);

	delete entidad_a_almacenar;

	return retorno;
}

bool AdministradorAplicacionLocal::recuperar(visualizador::modelo::IEntidad * entidad)
{
	std::string clave = entidad->getId()->string();
	std::string grupo = entidad->getGrupo();

	almacenamiento::IAlmacenableClaveValor* entidad_a_recuperar = new almacenamiento::IAlmacenableClaveValor(clave, grupo);

	bool retorno = almacenamiento::IAdministradorAlmacenamiento::getInstancia()->recuperar(entidad_a_recuperar);

	entidad->parsearValorAlmacenable(entidad_a_recuperar->getValor());

	delete entidad_a_recuperar;

	return retorno;
}

std::vector<visualizador::modelo::IEntidad*> AdministradorAplicacionLocal::recuperarGrupo(std::string prefijo_grupo)
{
	std::vector<almacenamiento::IAlmacenableClaveValor*> grupo;

	almacenamiento::IAdministradorAlmacenamiento::getInstancia()->recuperarGrupo(prefijo_grupo, grupo);

	return grupo;
}
