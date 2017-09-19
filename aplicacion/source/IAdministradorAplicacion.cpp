#include <aplicacion/include/IAdministradorAplicacion.h>

using namespace visualizador::aplicacion;

// aplicacion
#include <aplicacion/include/AdministradorAplicacionLocal.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

IAdministradorAplicacion* IAdministradorAplicacion::administrador = NULL;

void IAdministradorAplicacion::liberar()
{
	if (true == administradorIniciado())
	{
		delete administrador;
	}
}

void IAdministradorAplicacion::crearAdministradorAplicacionLocal()
{
	administrador = new AdministradorAplicacionLocal();
};

void IAdministradorAplicacion::crearAdministradorAplicacionDistribuida() {};


bool IAdministradorAplicacion::administradorIniciado()
{
	return administrador != NULL;
}

// GETTERS

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
};