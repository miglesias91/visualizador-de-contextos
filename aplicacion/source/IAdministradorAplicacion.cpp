#include <aplicacion/include/IAdministradorAplicacion.h>

using namespace visualizador::aplicacion;

// stl
#include <iostream>

// aplicacion
#include <aplicacion/include/AdministradorAplicacionLocal.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>
#include <aplicacion/include/AdminAplicacionIniciadoPreviamente.h>

typedef visualizador::aplicacion::IAdministradorAplicacion* (*admin)();

IAdministradorAplicacion* IAdministradorAplicacion::administrador_entidades = NULL;
herramientas::log::Logger* IAdministradorAplicacion::log = NULL;

IAdministradorAplicacion::IAdministradorAplicacion() : admin_almacenamiento(NULL), handler_almacenamiento(0)
{
}

IAdministradorAplicacion::~IAdministradorAplicacion()
{
}

void IAdministradorAplicacion::iniciar(std::string path_configuracion)
{
    if (administradorEntidadesIniciado())
    {
        log->error("Administrador de aplicación ya fue iniciado.");

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

    log = herramientas::log::AdministradorLog::iniciarNuevo(ConfiguracionAplicacion::archivoConfigLog());

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

void IAdministradorAplicacion::liberar()
{
    if (true == administradorEntidadesIniciado())
    {
        delete administrador_entidades;
    }

    herramientas::log::AdministradorLog::liberarTodo();
}

void IAdministradorAplicacion::crearAdministradorAplicacionLocal()
{
    log->info("creando AdministradorAplicacionLocal. config = " + ConfiguracionAplicacion::pathConfiguracion() + ".");
    try
    {
        administrador_entidades = new AdministradorAplicacionLocal();
        administrador_entidades->iniciarDB(ConfiguracionAplicacion::archivoConfigDBAplicacionEntidades());
    }
    catch (herramientas::utiles::excepciones::Excepcion & e)
    {
        log->error("no se pudo crear AdminstradorAplicacionLocal: " + std::string(e.what()));
        throw;
    }
    log->info("creación AdministradorAplicacionLocal OK");
}

void IAdministradorAplicacion::crearAdministradorAplicacionDistribuida() {};

bool IAdministradorAplicacion::administradorEntidadesIniciado()
{
	return administrador_entidades != NULL;
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
        log->advertencia("Administrador de entidades no inicializado.");
        return NULL;
	}
}

void IAdministradorAplicacion::iniciarDB(std::string path_config_db)
{
    log->info("iniciando nuevo IAdministradorAlmacenamiento. config = " + path_config_db + ".");

    try
    {
        this->handler_almacenamiento = almacenamiento::IAdministradorAlmacenamiento::iniciarNuevo(path_config_db);
        this->admin_almacenamiento = almacenamiento::IAdministradorAlmacenamiento::getInstancia(this->handler_almacenamiento);
    }
    catch (std::exception & e)
    {
        log->error("no se pudo iniciar IAdministradorAlmacenamiento: " + std::string(e.what()));
        throw e;
    }

    log->info("inicio IAdministradorAlmacenamiento OK.");
}
