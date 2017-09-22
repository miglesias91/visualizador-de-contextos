#include <aplicacion/include/AdministradorAplicacionLocal.h>

using namespace visualizador::aplicacion;

// almacenamiento
#include <almacenamiento/include/IAdministradorAlmacenamiento.h>

AdministradorAplicacionLocal::AdministradorAplicacionLocal()
{
	almacenamiento::IAdministradorAlmacenamiento::iniciar("configuracion_almacenamiento.json");
}

AdministradorAplicacionLocal::~AdministradorAplicacionLocal()
{
}

bool AdministradorAplicacionLocal::almacenar(visualizador::modelo::IEntidad * entidad)
{
	std::string clave = entidad->getId()->string();
	std::string grupo = entidad->getGrupo();
	std::string valor = entidad->getValorAlmacenable();

	almacenamiento::IAlmacenableClaveValor* entidad_a_almacenar = new almacenamiento::IAlmacenableClaveValor(clave, grupo, valor);

	bool retorno = almacenamiento::IAdministradorAlmacenamiento::getInstancia()->almacenar(entidad_a_almacenar);

	delete entidad_a_almacenar;

	return retorno;
}

bool AdministradorAplicacionLocal::recuperar(visualizador::modelo::IEntidad * entidad)
{
	std::string clave = entidad->getId()->string();
	std::string grupo = entidad->getGrupo();

	almacenamiento::IAlmacenableClaveValor* clave_valor_a_recuperar = new almacenamiento::IAlmacenableClaveValor(clave, grupo);

	bool retorno = almacenamiento::IAdministradorAlmacenamiento::getInstancia()->recuperar(clave_valor_a_recuperar);

	entidad->parsearValorAlmacenable(clave_valor_a_recuperar->getValor());

	delete clave_valor_a_recuperar;

	return retorno;
}

std::vector<visualizador::modelo::IEntidad*> AdministradorAplicacionLocal::recuperarGrupo(std::string prefijo_grupo)
{
	std::vector<almacenamiento::IAlmacenableClaveValor*> grupo;

	almacenamiento::IAdministradorAlmacenamiento::getInstancia()->recuperarGrupo(prefijo_grupo, grupo);

	return std::vector<visualizador::modelo::IEntidad*>();
}
