#include <aplicacion/include/IAdministradorAplicacion.h>

using namespace visualizador::aplicacion;

// stl
#include <iostream>

// aplicacion
#include <aplicacion/include/AdministradorAplicacionLocal.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

typedef visualizador::aplicacion::IAdministradorAplicacion* (*admin)();

IAdministradorAplicacion* IAdministradorAplicacion::administrador = NULL;

IAdministradorAplicacion::IAdministradorAplicacion() : admin_almacenamiento(NULL), handler_almacenamiento(0)
{
}

IAdministradorAplicacion::~IAdministradorAplicacion()
{
}

void IAdministradorAplicacion::iniciar(std::string path_configuracion)
{
	if (administradorIniciado())
	{
		// TODO agregar log.
		std::cout << "Administrador ya fue iniciado." << std::endl;
		return;
		// throw std::exception("Administrador ya fue iniciado.");
	}

	ConfiguracionAplicacion::leerConfiguracion(path_configuracion);

	if (ConfiguracionAplicacion::aplicacionLocal())
	{
		crearAdministradorAplicacionLocal();
	}
	else
	{
		crearAdministradorAplicacionDistribuida();
	}
}

void IAdministradorAplicacion::liberar()
{
	if (true == administradorIniciado())
	{
		delete administrador;
	}
}

void IAdministradorAplicacion::crearAdministradorAplicacionLocal()
{
	//administrador = new AdministradorAplicacionLocal();
    administrador = new AdministradorAplicacionLocal();
    administrador->iniciarDB(ConfiguracionAplicacion::archivoConfigDBAplicacion());
}

void IAdministradorAplicacion::crearAdministradorAplicacionDistribuida() {};


bool IAdministradorAplicacion::administradorIniciado()
{
	return administrador != NULL;
}

// GETTERS

almacenamiento::IAdministradorAlmacenamiento * IAdministradorAplicacion::getAdminAlmacenamiento()
{
    return admin_almacenamiento;
}

IAdministradorAplicacion* IAdministradorAplicacion::getInstancia()
{
	if (administradorIniciado())
	{
		return administrador;
	}
	else
	{
		throw std::exception("Administrador de aplicacion no inicializado.");
	}
}


void IAdministradorAplicacion::iniciarDB(std::string path_config_db)
{
    this->handler_almacenamiento = almacenamiento::IAdministradorAlmacenamiento::iniciarNuevo(path_config_db);
    this->admin_almacenamiento = almacenamiento::IAdministradorAlmacenamiento::getInstancia(this->handler_almacenamiento);
}
