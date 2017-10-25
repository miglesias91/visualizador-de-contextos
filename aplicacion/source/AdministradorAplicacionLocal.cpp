#include <aplicacion/include/AdministradorAplicacionLocal.h>

using namespace visualizador::aplicacion;

// almacenamiento
#include <almacenamiento/include/IAdministradorAlmacenamiento.h>

AdministradorAplicacionLocal::AdministradorAplicacionLocal() : admin_almacenamiento(NULL)
{
	almacenamiento::IAdministradorAlmacenamiento::iniciar("configuracion_almacenamiento.json");

    this->admin_almacenamiento = almacenamiento::IAdministradorAlmacenamiento::getInstancia();
}

AdministradorAplicacionLocal::~AdministradorAplicacionLocal()
{
	almacenamiento::IAdministradorAlmacenamiento::liberar();
}

bool AdministradorAplicacionLocal::abrirBD()
{
	bool retorno = this->admin_almacenamiento->abrir();

	return retorno;
}

bool AdministradorAplicacionLocal::cerrarBD()
{
	this->almacenarIDActual();

	bool retorno = this->admin_almacenamiento->cerrar();

	return retorno;
}

bool AdministradorAplicacionLocal::almacenar(visualizador::modelo::IEntidad * entidad)
{
	std::string clave = entidad->getId()->string();
	std::string grupo = entidad->getGrupo();
	std::string valor = entidad->getValorAlmacenable();

	almacenamiento::IAlmacenableClaveValor* entidad_a_almacenar = new almacenamiento::IAlmacenableClaveValor(clave, grupo, valor);

	bool retorno = this->admin_almacenamiento->almacenar(entidad_a_almacenar);

	delete entidad_a_almacenar;

	return retorno;
}


bool AdministradorAplicacionLocal::almacenar(std::vector<visualizador::modelo::IEntidad*> entidades)
{
    visualizador::modelo::IEntidad* entidad = NULL;
    bool retorno = true;
    for (std::vector<visualizador::modelo::IEntidad*>::iterator it = entidades.begin(); it != entidades.end(); it++)
    {
        entidad = *it;
        std::string clave = entidad->getId()->string();
        std::string grupo = entidad->getGrupo();
        std::string valor = entidad->getValorAlmacenable();

        almacenamiento::IAlmacenableClaveValor* entidad_a_almacenar = new almacenamiento::IAlmacenableClaveValor(clave, grupo, valor);

        retorno = this->admin_almacenamiento->almacenar(entidad_a_almacenar);
        if (false == retorno)
        {
            delete entidad_a_almacenar;
            break;
        }

        delete entidad_a_almacenar;
    }

    return retorno;
}

bool AdministradorAplicacionLocal::recuperar(visualizador::modelo::IEntidad * entidad)
{
	std::string clave = entidad->getId()->string();
	std::string grupo = entidad->getGrupo();

	almacenamiento::IAlmacenableClaveValor* clave_valor_a_recuperar = new almacenamiento::IAlmacenableClaveValor(clave, grupo);

	bool retorno = this->admin_almacenamiento->recuperar(clave_valor_a_recuperar);

	entidad->parsearValorAlmacenable(clave_valor_a_recuperar->getValor());

	delete clave_valor_a_recuperar;

	return retorno;
}

bool AdministradorAplicacionLocal::eliminar(visualizador::modelo::IEntidad * entidad)
{
    std::string clave = entidad->getId()->string();
    std::string grupo = entidad->getGrupo();

    almacenamiento::IAlmacenableClaveValor* entidad_a_eliminar = new almacenamiento::IAlmacenableClaveValor(clave, grupo);

    bool retorno = this->admin_almacenamiento->eliminar(entidad_a_eliminar);

    delete entidad_a_eliminar;

    return retorno;
}

bool AdministradorAplicacionLocal::eliminar(std::vector<visualizador::modelo::IEntidad*> entidades)
{
    visualizador::modelo::IEntidad* entidad = NULL;
    bool retorno = true;
    for (std::vector<visualizador::modelo::IEntidad*>::iterator it = entidades.begin(); it != entidades.end(); it++)
    {
        entidad = *it;
        std::string clave = entidad->getId()->string();
        std::string grupo = entidad->getGrupo();

        almacenamiento::IAlmacenableClaveValor* entidad_a_eliminar = new almacenamiento::IAlmacenableClaveValor(clave, grupo);

        retorno = this->admin_almacenamiento->eliminar(entidad_a_eliminar);
        if (false == retorno)
        {
            delete entidad_a_eliminar;
            break;
        }

        delete entidad_a_eliminar;
    }

    return retorno;
}

bool AdministradorAplicacionLocal::recuperarGrupo(std::string prefijo_grupo, std::vector<visualizador::modelo::IEntidad*>* entidades)
{
	std::vector<almacenamiento::IAlmacenableClaveValor*> grupo;

    this->admin_almacenamiento->recuperarGrupo(prefijo_grupo, grupo);

	visualizador::modelo::IEntidad* entidad = NULL;
	for (std::vector<almacenamiento::IAlmacenableClaveValor*>::iterator it = grupo.begin(); it != grupo.end(); it++)
	{

	}

	return true;
}
