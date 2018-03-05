#include <aplicacion/include/AdministradorAplicacionLocal.h>

using namespace visualizador::aplicacion;

// almacenamiento
#include <almacenamiento/include/IAdministradorAlmacenamiento.h>

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>
#include <aplicacion/include/Logger.h>

AdministradorAplicacionLocal::AdministradorAplicacionLocal() : IAdministradorAplicacion()
{
}

AdministradorAplicacionLocal::~AdministradorAplicacionLocal()
{
    almacenamiento::IAdministradorAlmacenamiento::liberar(this->handler_almacenamiento);
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

bool AdministradorAplicacionLocal::almacenar(visualizador::modelo::IAlmacenable * entidad)
{
	std::string clave = entidad->getId()->string();
	std::string grupo = entidad->getGrupo();
	std::string valor = entidad->getValorAlmacenable();

	almacenamiento::IAlmacenableClaveValor* entidad_a_almacenar = new almacenamiento::IAlmacenableClaveValor(clave, grupo, valor);

    bool retorno = this->admin_almacenamiento->almacenar(entidad_a_almacenar);

    if (retorno)
    {
        Logger::debug("almacenar{ grupo: '" + grupo + "' - clave: '" + clave + "' }");
    }
    else
    {
        Logger::debug("almacenar{ grupo: '" + grupo + "' - clave: '" + clave + "' - NO SE ALMACENO NINGUN VALOR }");
    }

	delete entidad_a_almacenar;

	return retorno;
}

bool AdministradorAplicacionLocal::almacenar(std::vector<visualizador::modelo::IAlmacenable*> entidades)
{
    visualizador::modelo::IAlmacenable* entidad = NULL;
    bool retorno = true;

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
            Logger::debug("almacenar_vector{ grupo: '" + grupo + "' - clave: '" + clave + "' - NO SE PUDO ALMACENAR }");

            delete entidad_a_almacenar;
            break;
        }

        Logger::debug("almacenar_vector{ grupo: '" + grupo + "' - clave: '" + clave + "' - valor: '" + valor + "' }");

        delete entidad_a_almacenar;
    }

    return retorno;
}

bool AdministradorAplicacionLocal::recuperar(visualizador::modelo::IAlmacenable * entidad)
{
	std::string clave = entidad->getId()->string();
	std::string grupo = entidad->getGrupo();

	almacenamiento::IAlmacenableClaveValor* clave_valor_a_recuperar = new almacenamiento::IAlmacenableClaveValor(clave, grupo);

	bool existe_valor = this->admin_almacenamiento->recuperar(clave_valor_a_recuperar);

    if (existe_valor)
    {
        Logger::debug("recuperar{ grupo: '" + grupo + "' - clave: '" + clave + "' - valor recuperado: '" + clave_valor_a_recuperar->getValor() + "' }");
        entidad->parsearValorAlmacenable(clave_valor_a_recuperar->getValor());
    }
    else
    {
        Logger::debug("recuperar{ grupo: '" + grupo + "' - clave: '" + clave + "' - NO SE RECUPERO NINGUN VALOR }");
    }

	delete clave_valor_a_recuperar;

	return existe_valor;
}

bool AdministradorAplicacionLocal::eliminar(visualizador::modelo::IAlmacenable * entidad)
{
    std::string clave = entidad->getId()->string();
    std::string grupo = entidad->getGrupo();

    almacenamiento::IAlmacenableClaveValor* entidad_a_eliminar = new almacenamiento::IAlmacenableClaveValor(clave, grupo);

    bool retorno = this->admin_almacenamiento->eliminar(entidad_a_eliminar);

    if (retorno)
    {
        Logger::debug("eliminar{ grupo: '" + grupo + "' - clave: '" + clave + "' }");
    }
    else
    {
        Logger::debug("eliminar{ grupo: '" + grupo + "' - clave: '" + clave + "' - NO SE ELIMINO NINGUN VALOR }");
    }

    delete entidad_a_eliminar;

    return retorno;
}

bool AdministradorAplicacionLocal::eliminar(std::vector<visualizador::modelo::IAlmacenable*> entidades)
{
    visualizador::modelo::IAlmacenable* entidad = NULL;
    bool retorno = true;

    for (std::vector<visualizador::modelo::IAlmacenable*>::iterator it = entidades.begin(); it != entidades.end(); it++)
    {
        entidad = *it;
        std::string clave = entidad->getId()->string();
        std::string grupo = entidad->getGrupo();

        almacenamiento::IAlmacenableClaveValor* entidad_a_eliminar = new almacenamiento::IAlmacenableClaveValor(clave, grupo);

        retorno = this->admin_almacenamiento->eliminar(entidad_a_eliminar);
        if (false == retorno)
        {
            Logger::debug("eliminar_vector{ grupo: '" + grupo + "' - clave: '" + clave + "' - NO SE ELIMINO NINGUN VALOR }");
            delete entidad_a_eliminar;
            break;
        }

        Logger::debug("eliminar_vector{ grupo: '" + grupo + "' - clave: '" + clave + "' }");

        delete entidad_a_eliminar;
    }

    return retorno;
}

bool AdministradorAplicacionLocal::modificar(visualizador::modelo::IAlmacenable * entidad)
{
    std::string clave = entidad->getId()->string();
    std::string grupo = entidad->getGrupo();
    std::string valor = entidad->getValorAlmacenable();

    almacenamiento::IAlmacenableClaveValor* entidad_a_modificar = new almacenamiento::IAlmacenableClaveValor(clave, grupo, valor);

    bool retorno = this->admin_almacenamiento->almacenar(entidad_a_modificar);

    if (retorno)
    {
        Logger::debug("modificar{ grupo: '" + grupo + "' - clave: '" + clave + "' }");
    }
    else
    {
        Logger::debug("modificar{ grupo: '" + grupo + "' - clave: '" + clave + "' - NO SE MODIFICO NINGUN VALOR }");
    }

    delete entidad_a_modificar;

    return retorno;
}

bool AdministradorAplicacionLocal::modificar(std::vector<visualizador::modelo::IAlmacenable*> entidades)
{
    visualizador::modelo::IAlmacenable* entidad = NULL;
    bool retorno = true;

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
            Logger::debug("modificar_vector{ grupo: '" + grupo + "' - clave: '" + clave + "' - NO SE MODIFICO NINGUN VALOR }");
            delete entidad_a_modificar;
            break;
        }

        Logger::debug("modificar_vector{ grupo: '" + grupo + "' - clave: '" + clave + "' - nuevo valor: '" + valor + "' }");
        
        delete entidad_a_modificar;
    }

    return retorno;
}

unsigned long long int AdministradorAplicacionLocal::recuperarIDActual()
{
    std::string clave = ConfiguracionAplicacion::claveIDActual();
    std::string grupo = ConfiguracionAplicacion::prefijoConfiguracion();

    almacenamiento::IAlmacenableClaveValor* clave_valor_a_recuperar = new almacenamiento::IAlmacenableClaveValor(clave, grupo);

    bool retorno = almacenamiento::IAdministradorAlmacenamiento::getInstancia(this->handler_almacenamiento)->recuperar(clave_valor_a_recuperar);

    std::string string_id_actual = clave_valor_a_recuperar->getValor();

    Logger::debug("recuperarIDActual: { id actual recuperado: " + string_id_actual + ".");

    unsigned long long int id_actual = 1;
    if (false == string_id_actual.empty())
    {
        id_actual = std::stoull(string_id_actual);
    }

    //GestorIDs::setIdActual(id_actual);
    modelo::IAlmacenable::getGestorIDs()->setIdActual(id_actual);

    delete clave_valor_a_recuperar;

    return id_actual;
}

void AdministradorAplicacionLocal::almacenarIDActual()
{
    std::string clave = ConfiguracionAplicacion::claveIDActual();
    std::string grupo = ConfiguracionAplicacion::prefijoConfiguracion();
    std::string valor = std::to_string(modelo::IAlmacenable::getGestorIDs()->getIdActual());

    almacenamiento::IAlmacenableClaveValor* clave_valor_a_recuperar = new almacenamiento::IAlmacenableClaveValor(clave, grupo, valor);

    Logger::debug("almacenarIDActual: { id actual: " + valor + ".");

    bool retorno = almacenamiento::IAdministradorAlmacenamiento::getInstancia(this->handler_almacenamiento)->modificar(clave_valor_a_recuperar);

    delete clave_valor_a_recuperar;
}
