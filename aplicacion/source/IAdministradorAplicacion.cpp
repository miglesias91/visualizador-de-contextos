#include <aplicacion/include/IAdministradorAplicacion.h>

using namespace visualizador::aplicacion;

// stl
#include <iostream>

// aplicacion
#include <aplicacion/include/AdministradorAplicacionLocal.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

typedef visualizador::aplicacion::IAdministradorAplicacion* (*admin)();

IAdministradorAplicacion* IAdministradorAplicacion::administrador_entidades = NULL;
//IAdministradorAplicacion* IAdministradorAplicacion::administrador_datos_scraping = NULL;

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
    if (true == administradorEntidadesIniciado())
    {
        delete administrador_entidades;
    }

    //if (true == administradorDatosScrapingIniciado())
    //{
    //    delete administrador_datos_scraping;
    //}
}

void IAdministradorAplicacion::crearAdministradorAplicacionLocal()
{
    administrador_entidades = new AdministradorAplicacionLocal();
    administrador_entidades->iniciarDB(ConfiguracionAplicacion::archivoConfigDBAplicacionEntidades());

    //administrador_datos_scraping = new AdministradorAplicacionLocal();
    //administrador_datos_scraping->iniciarDB(ConfiguracionAplicacion::archivoConfigDBScraping());
}

void IAdministradorAplicacion::crearAdministradorAplicacionDistribuida() {};

bool IAdministradorAplicacion::administradorEntidadesIniciado()
{
	return administrador_entidades != NULL;
}

//bool IAdministradorAplicacion::administradorDatosScrapingIniciado()
//{
//    return administrador_datos_scraping != NULL;
//}

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
		throw std::exception("Administrador de entidades no inicializado.");
	}
}

//IAdministradorAplicacion* IAdministradorAplicacion::getInstanciaAdminDatosScraping()
//{
//    if (administradorEntidadesIniciado())
//    {
//        return administrador_datos_scraping;
//    }
//    else
//    {
//        throw std::exception("Administrador de datos de scraping no inicializado.");
//    }
//}

void IAdministradorAplicacion::iniciarDB(std::string path_config_db)
{
    this->handler_almacenamiento = almacenamiento::IAdministradorAlmacenamiento::iniciarNuevo(path_config_db);
    this->admin_almacenamiento = almacenamiento::IAdministradorAlmacenamiento::getInstancia(this->handler_almacenamiento);
}
