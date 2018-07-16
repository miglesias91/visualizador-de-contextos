#include <aplicacion/include/IAdministradorAplicacion.h>

using namespace visualizador::aplicacion;

// stl
#include <iostream>

// aplicacion
#include <aplicacion/include/AdministradorAplicacionLocal.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>
#include <aplicacion/include/Logger.h>
#include <aplicacion/include/AdminAplicacionIniciadoPreviamente.h>

typedef visualizador::aplicacion::IAdministradorAplicacion* (*admin)();

IAdministradorAplicacion* IAdministradorAplicacion::administrador_entidades = nullptr;
IAdministradorAplicacion* IAdministradorAplicacion::administrador_resultados = nullptr;

IAdministradorAplicacion::IAdministradorAplicacion() : admin_almacenamiento(nullptr), handler_almacenamiento(0)
{
}

IAdministradorAplicacion::~IAdministradorAplicacion()
{
}

void IAdministradorAplicacion::iniciar(std::string path_configuracion)
{
    if (administradorEntidadesIniciado() || administradorResultadosIniciado())
    {
        Logger::error("Administrador de aplicación ya fue iniciado.");

        throw excepciones::AdminAplicacionIniciadoPreviamente();
    }

    try
    {
        ConfiguracionAplicacion::leerConfiguracion(path_configuracion);
    }
    catch (herramientas::utiles::excepciones::Excepcion & e)
    {
        throw;
    }

    Logger::iniciar(ConfiguracionAplicacion::archivoConfigLog());
    Logger::marca("INICIO APP");

    try
    {
        if (ConfiguracionAplicacion::aplicacionLocal())
        {
            crearAdministradorAplicacionLocal();
        }
        else
        {
            crearAdministradorAplicacionDistribuida();
        }
    }
    catch (herramientas::utiles::excepciones::Excepcion & e)
    {
        throw;
    }
}

void IAdministradorAplicacion::liberar() {
    if (true == administradorEntidadesIniciado()) {
        delete administrador_entidades;
    }

    if (true == administradorResultadosIniciado()) {
        delete administrador_resultados;
    }

    Logger::marca("FIN APP");

    herramientas::log::AdministradorLog::liberarTodo();
}

void IAdministradorAplicacion::crearAdministradorAplicacionLocal()
{
    Logger::info("creando AdministradorAplicacionLocal. config = " + ConfiguracionAplicacion::pathConfiguracion() + ".");
    try
    {
        administrador_entidades = new AdministradorAplicacionLocal();
        administrador_entidades->iniciarDB(ConfiguracionAplicacion::archivoConfigDBAplicacionEntidades());
    }
    catch (herramientas::utiles::excepciones::Excepcion & e)
    {
        Logger::error("no se pudo crear AdminstradorAplicacionLocal: " + std::string(e.what()));
        throw;
    }

    Logger::info("creando AdministradorAplicacionLocal. config = " + ConfiguracionAplicacion::pathConfiguracion() + ".");
    try
    {
        administrador_resultados = new AdministradorAplicacionLocal();
        administrador_resultados->iniciarDB(ConfiguracionAplicacion::archivoConfigDBResultadosDiarios());
    }
    catch (herramientas::utiles::excepciones::Excepcion & e)
    {
        Logger::error("no se pudo crear AdminstradorAplicacionLocal: " + std::string(e.what()));
        throw;
    }
    Logger::info("creación AdministradorAplicacionLocal OK");
}

void IAdministradorAplicacion::crearAdministradorAplicacionDistribuida() {};

bool IAdministradorAplicacion::administradorEntidadesIniciado() {
	return administrador_entidades != NULL;
}

bool IAdministradorAplicacion::administradorResultadosIniciado() {
    return administrador_resultados != NULL;
}

// GETTERS

almacenamiento::IAdministradorAlmacenamiento * IAdministradorAplicacion::getAdminAlmacenamiento()
{
    return admin_almacenamiento;
}

IAdministradorAplicacion* IAdministradorAplicacion::getInstanciaAdminEntidades()
{
	if (administradorEntidadesIniciado())
	{
		return administrador_entidades;
	}
	else
	{
        Logger::advertencia("Administrador de entidades no inicializado.");
        return NULL;
	}
}

IAdministradorAplicacion* IAdministradorAplicacion::getInstanciaAdminResultados()
{
    if (administradorResultadosIniciado())
    {
        return administrador_resultados;
    }
    else
    {
        Logger::advertencia("Administrador de resultados no inicializado.");
        return NULL;
    }
}

void IAdministradorAplicacion::iniciarDB(std::string path_config_db)
{
    Logger::info("iniciando nuevo IAdministradorAlmacenamiento. config = " + path_config_db + ".");

    try
    {
        this->handler_almacenamiento = almacenamiento::IAdministradorAlmacenamiento::iniciarNuevo(path_config_db);
        this->admin_almacenamiento = almacenamiento::IAdministradorAlmacenamiento::getInstancia(this->handler_almacenamiento);
    }
    catch (std::exception & e)
    {
        Logger::error("no se pudo iniciar IAdministradorAlmacenamiento: " + std::string(e.what()));
        throw e;
    }

    Logger::info("inicio IAdministradorAlmacenamiento OK.");
}
