#include <aplicacion/include/IAdministradorAplicacion.h>

using namespace visualizador::aplicacion;

// stl
#include <iostream>
#include <filesystem>

// utiles
#include <utiles/include/FuncionesString.h>

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
        aplicacion::Logger::info("leyendo config.");
        ConfiguracionAplicacion::leerConfiguracion(path_configuracion);
    }
    catch (herramientas::utiles::excepciones::Excepcion & e)
    {
        throw;
    }

    Logger::iniciar(ConfiguracionAplicacion::archivoConfigLog());
    Logger::info("INICIO APP");

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

        almacenamiento::ConfiguracionAlmacenamiento config_resultados(ConfiguracionAplicacion::archivoConfigDBResultadosDiarios());
        config_resultados.pathDB(obtener_path_db_mas_reciente(config_resultados.pathDB()));

        //administrador_resultados->iniciarDB(ConfiguracionAplicacion::archivoConfigDBResultadosDiarios());
        administrador_resultados->iniciarDB(config_resultados);
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

void IAdministradorAplicacion::iniciarDB(const almacenamiento::ConfiguracionAlmacenamiento & config_db) {
    Logger::info("iniciando nuevo IAdministradorAlmacenamiento. config = " + config_db.pathDB() + ".");

    try
    {
        this->handler_almacenamiento = almacenamiento::IAdministradorAlmacenamiento::iniciarNuevo(config_db);
        this->admin_almacenamiento = almacenamiento::IAdministradorAlmacenamiento::getInstancia(this->handler_almacenamiento);
    }
    catch (std::exception & e)
    {
        Logger::error("no se pudo iniciar IAdministradorAlmacenamiento: " + std::string(e.what()));
        throw e;
    }

    Logger::info("inicio IAdministradorAlmacenamiento OK.");
}

std::string IAdministradorAplicacion::obtener_path_db_mas_reciente(const std::string & path_db_resultados_diarios) {

    std::experimental::filesystem::path path_db(path_db_resultados_diarios);

    std::experimental::filesystem::path path_mas_reciente = path_db;
    herramientas::utiles::Fecha fecha_mas_reciente;
    for(auto entrada_directorio : std::experimental::filesystem::directory_iterator(path_db.parent_path())) {
        herramientas::utiles::Fecha fecha_de_creacion = herramientas::utiles::Fecha::parsear(std::experimental::filesystem::last_write_time(entrada_directorio));

        if (fecha_mas_reciente < fecha_de_creacion && herramientas::utiles::FuncionesString::empiezaCon(entrada_directorio.path().u8string(), path_db.u8string())) {
            fecha_mas_reciente = fecha_de_creacion;
            path_mas_reciente = entrada_directorio;
        }
    }

    return path_mas_reciente.u8string();
}
