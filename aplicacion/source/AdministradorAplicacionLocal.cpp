#include <aplicacion/include/AdministradorAplicacionLocal.h>

using namespace visualizador::aplicacion;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

// almacenamiento
#include <almacenamiento/include/IAdministradorAlmacenamiento.h>

AdministradorAplicacionLocal::AdministradorAplicacionLocal() : admin_almacenamiento(NULL)
{
	almacenamiento::IAdministradorAlmacenamiento::iniciar(ConfiguracionAplicacion::pathConfiguracion());

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

bool AdministradorAplicacionLocal::borrarBD()
{
    return this->admin_almacenamiento->borrar();
}

//bool AdministradorAplicacionLocal::almacenar(visualizador::modelo::IEntidad * entidad)
bool AdministradorAplicacionLocal::almacenar(visualizador::modelo::IAlmacenable * entidad)
{
	std::string clave = entidad->getId()->string();
	std::string grupo = entidad->getGrupo();
	std::string valor = entidad->getValorAlmacenable();

	almacenamiento::IAlmacenableClaveValor* entidad_a_almacenar = new almacenamiento::IAlmacenableClaveValor(clave, grupo, valor);

	bool retorno = this->admin_almacenamiento->almacenar(entidad_a_almacenar);

	delete entidad_a_almacenar;

	return retorno;
}

//bool AdministradorAplicacionLocal::almacenar(std::vector<visualizador::modelo::IEntidad*> entidades)
bool AdministradorAplicacionLocal::almacenar(std::vector<visualizador::modelo::IAlmacenable*> entidades)
{
    //visualizador::modelo::IEntidad* entidad = NULL;
    visualizador::modelo::IAlmacenable* entidad = NULL;
    bool retorno = true;
    //for (std::vector<visualizador::modelo::IEntidad*>::iterator it = entidades.begin(); it != entidades.end(); it++)
    for (std::vector<visualizador::modelo::IAlmacenable*>::iterator it = entidades.begin(); it != entidades.end(); it++)
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

//bool AdministradorAplicacionLocal::recuperar(visualizador::modelo::IEntidad * entidad)
bool AdministradorAplicacionLocal::recuperar(visualizador::modelo::IAlmacenable * entidad)
{
	std::string clave = entidad->getId()->string();
	std::string grupo = entidad->getGrupo();

	almacenamiento::IAlmacenableClaveValor* clave_valor_a_recuperar = new almacenamiento::IAlmacenableClaveValor(clave, grupo);

	bool existe_valor = this->admin_almacenamiento->recuperar(clave_valor_a_recuperar);

    if (existe_valor)
    {
        entidad->parsearValorAlmacenable(clave_valor_a_recuperar->getValor());
    }

	delete clave_valor_a_recuperar;

	return existe_valor;
}

//bool AdministradorAplicacionLocal::eliminar(visualizador::modelo::IEntidad * entidad)
bool AdministradorAplicacionLocal::eliminar(visualizador::modelo::IAlmacenable * entidad)
{
    std::string clave = entidad->getId()->string();
    std::string grupo = entidad->getGrupo();

    almacenamiento::IAlmacenableClaveValor* entidad_a_eliminar = new almacenamiento::IAlmacenableClaveValor(clave, grupo);

    bool retorno = this->admin_almacenamiento->eliminar(entidad_a_eliminar);

    delete entidad_a_eliminar;

    return retorno;
}

//bool AdministradorAplicacionLocal::eliminar(std::vector<visualizador::modelo::IEntidad*> entidades)
bool AdministradorAplicacionLocal::eliminar(std::vector<visualizador::modelo::IAlmacenable*> entidades)
{
    //visualizador::modelo::IEntidad* entidad = NULL;
    visualizador::modelo::IAlmacenable* entidad = NULL;
    bool retorno = true;
    //for (std::vector<visualizador::modelo::IEntidad*>::iterator it = entidades.begin(); it != entidades.end(); it++)
    for (std::vector<visualizador::modelo::IAlmacenable*>::iterator it = entidades.begin(); it != entidades.end(); it++)
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

//bool AdministradorAplicacionLocal::modificar(visualizador::modelo::IEntidad * entidad)
bool AdministradorAplicacionLocal::modificar(visualizador::modelo::IAlmacenable * entidad)
{
    std::string clave = entidad->getId()->string();
    std::string grupo = entidad->getGrupo();
    std::string valor = entidad->getValorAlmacenable();

    almacenamiento::IAlmacenableClaveValor* entidad_a_modificar = new almacenamiento::IAlmacenableClaveValor(clave, grupo, valor);

    bool retorno = this->admin_almacenamiento->almacenar(entidad_a_modificar);

    delete entidad_a_modificar;

    return retorno;
}

//bool AdministradorAplicacionLocal::modificar(std::vector<visualizador::modelo::IEntidad*> entidades)
bool AdministradorAplicacionLocal::modificar(std::vector<visualizador::modelo::IAlmacenable*> entidades)
{
    //visualizador::modelo::IEntidad* entidad = NULL;
    visualizador::modelo::IAlmacenable* entidad = NULL;
    bool retorno = true;
    //for (std::vector<visualizador::modelo::IEntidad*>::iterator it = entidades.begin(); it != entidades.end(); it++)
    for (std::vector<visualizador::modelo::IAlmacenable*>::iterator it = entidades.begin(); it != entidades.end(); it++)
    {
        entidad = *it;
        std::string clave = entidad->getId()->string();
        std::string grupo = entidad->getGrupo();
        std::string valor = entidad->getValorAlmacenable();

        almacenamiento::IAlmacenableClaveValor* entidad_a_modificar = new almacenamiento::IAlmacenableClaveValor(clave, grupo, valor);

        retorno = this->admin_almacenamiento->modificar(entidad_a_modificar);
        if (false == retorno)
        {
            delete entidad_a_modificar;
            break;
        }

        delete entidad_a_modificar;
    }

    return retorno;
}

//bool AdministradorAplicacionLocal::recuperarGrupo(std::string prefijo_grupo, std::vector<visualizador::modelo::IEntidad*>* entidades)
bool AdministradorAplicacionLocal::recuperarGrupo(std::string prefijo_grupo, std::vector<visualizador::modelo::IAlmacenable*>* entidades)
{
	std::vector<almacenamiento::IAlmacenableClaveValor*> grupo;

    this->admin_almacenamiento->recuperarGrupo(prefijo_grupo, grupo);

	//visualizador::modelo::IEntidad* entidad = NULL;
    visualizador::modelo::IAlmacenable* entidad = NULL;
	for (std::vector<almacenamiento::IAlmacenableClaveValor*>::iterator it = grupo.begin(); it != grupo.end(); it++)
	{

	}

	return true;
}
