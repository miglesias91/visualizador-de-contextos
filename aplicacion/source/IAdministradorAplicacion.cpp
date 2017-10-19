#include <aplicacion/include/IAdministradorAplicacion.h>

using namespace visualizador::aplicacion;

// stl
#include <iostream>

// almacenamiento
#include <almacenamiento/include/IAdministradorAlmacenamiento.h>

// aplicacion
#include <aplicacion/include/AdministradorAplicacionLocal.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

typedef visualizador::aplicacion::IAdministradorAplicacion* (*admin)();

IAdministradorAplicacion* IAdministradorAplicacion::administrador = NULL;

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
}

unsigned long long int IAdministradorAplicacion::recuperarIDActual()
{
	std::string clave = ConfiguracionAplicacion::claveIDActual();
	std::string grupo = ConfiguracionAplicacion::prefijoConfiguracion();

	almacenamiento::IAlmacenableClaveValor* clave_valor_a_recuperar = new almacenamiento::IAlmacenableClaveValor(clave, grupo);

	bool retorno = almacenamiento::IAdministradorAlmacenamiento::getInstancia()->recuperar(clave_valor_a_recuperar);

	std::string string_id_actual = clave_valor_a_recuperar->getValor();

	unsigned long long int id_actual = 0;
	if (false == string_id_actual.empty())
	{
		id_actual = std::stoull(string_id_actual);
	}

	GestorIDs::setIdActual(id_actual);

	delete clave_valor_a_recuperar;

	return id_actual;
}

void IAdministradorAplicacion::almacenarIDActual()
{
	std::string clave = ConfiguracionAplicacion::claveIDActual();
	std::string grupo = ConfiguracionAplicacion::prefijoConfiguracion();
	std::string valor = std::to_string(GestorIDs::getIdActual());

	almacenamiento::IAlmacenableClaveValor* clave_valor_a_recuperar = new almacenamiento::IAlmacenableClaveValor(clave, grupo, valor);

	bool retorno = almacenamiento::IAdministradorAlmacenamiento::getInstancia()->modificar(clave_valor_a_recuperar);

	delete clave_valor_a_recuperar;
}
