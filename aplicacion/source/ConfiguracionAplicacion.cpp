#include <aplicacion/include/ConfiguracionAplicacion.h>

using namespace visualizador::aplicacion;

// stl
#include <fstream>
#include <sstream>

// utiles
#include <utiles/include/Json.h>
#include <utiles/include/ImposibleAbrirArchivo.h>

// aplicacion
#include <aplicacion/include/Logger.h>

std::string ConfiguracionAplicacion::path_config;
std::string ConfiguracionAplicacion::path_scraping;
std::string ConfiguracionAplicacion::path_config_scraping;
std::string ConfiguracionAplicacion::path_config_noticias;

bool ConfiguracionAplicacion::aplicacion_local;
bool ConfiguracionAplicacion::aplicacion_distribuida;
bool ConfiguracionAplicacion::prefijo_habilitado;
unsigned int ConfiguracionAplicacion::prefijo_tamanio;
std::string ConfiguracionAplicacion::prefijo_configuracion;

std::string ConfiguracionAplicacion::prefijo_concepto;
std::string ConfiguracionAplicacion::prefijo_termino;
std::string ConfiguracionAplicacion::prefijo_consulta;
std::string ConfiguracionAplicacion::prefijo_reporte;
std::string ConfiguracionAplicacion::prefijo_seccion;
std::string ConfiguracionAplicacion::prefijo_periodo;
std::string ConfiguracionAplicacion::prefijo_fecha;
std::string ConfiguracionAplicacion::prefijo_medio;

std::string ConfiguracionAplicacion::prefijo_medio_twitter;
std::string ConfiguracionAplicacion::prefijo_medio_facebook;
std::string ConfiguracionAplicacion::prefijo_medio_portal_noticias;

std::string ConfiguracionAplicacion::prefijo_relaciones_concepto;
std::string ConfiguracionAplicacion::prefijo_relaciones_termino;
std::string ConfiguracionAplicacion::prefijo_relaciones_consulta;
std::string ConfiguracionAplicacion::prefijo_relaciones_reporte;
std::string ConfiguracionAplicacion::prefijo_relaciones_seccion;
std::string ConfiguracionAplicacion::prefijo_relaciones_periodo;
std::string ConfiguracionAplicacion::prefijo_relaciones_fecha;
std::string ConfiguracionAplicacion::prefijo_relaciones_medio;

std::string ConfiguracionAplicacion::archivo_config_db_aplicacion_entidades;
std::string ConfiguracionAplicacion::archivo_config_db_resultados_diarios;

std::string ConfiguracionAplicacion::archivo_config_log;
std::string ConfiguracionAplicacion::dir_abm;
std::string ConfiguracionAplicacion::dir_consultas;

std::string ConfiguracionAplicacion::clave_id_actual;

void ConfiguracionAplicacion::leerConfiguracion(std::string path_archivo_configuracion)
{
    std::ifstream archivo(path_archivo_configuracion);

    path_config = path_archivo_configuracion;

    if (false == archivo.good())
    {
        std::ofstream error("error.txt");
        error << "no se puede abrir el archivo de config: " + path_archivo_configuracion + ".";
        error.flush();
        throw herramientas::utiles::excepciones::ImposibleAbrirArchivo(path_archivo_configuracion);
    }

    std::ostringstream sstream;
    sstream << archivo.rdbuf();
    const std::string string_config(sstream.str());

    herramientas::utiles::Json * config_json = NULL;
    herramientas::utiles::Json * config_app_json = NULL;

    try
    {
        config_json = new herramientas::utiles::Json(string_config);
        config_app_json = config_json->getAtributoValorJson("aplicacion");

        path_scraping = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPathScraping());
        path_config_scraping = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPathConfiguracionScraping());
        path_config_noticias = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPathConfiguracionNoticias());

        aplicacion_local = config_app_json->getAtributoValorBool(ConfiguracionAplicacion::tagAplicacionLocal());
        aplicacion_distribuida = config_app_json->getAtributoValorBool(ConfiguracionAplicacion::tagAplicacionDistribuida());
        prefijo_habilitado = config_app_json->getAtributoValorBool(ConfiguracionAplicacion::tagPrefijoHabilitado());
        prefijo_tamanio = config_app_json->getAtributoValorUint(ConfiguracionAplicacion::tagPrefijoTamanio());

        prefijo_configuracion = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoConfiguracion());
        prefijo_concepto = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoConcepto());
        prefijo_termino = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoTermino());
        prefijo_consulta = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoConsulta());
        prefijo_reporte = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoReporte());
        prefijo_seccion = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoSeccion());
        prefijo_periodo = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoPeriodo());
        prefijo_fecha = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoFecha());
        prefijo_medio = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoMedio());

        prefijo_medio_twitter = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoMedioTwitter());
        prefijo_medio_facebook = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoMedioFacebook());
        prefijo_medio_portal_noticias = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoMedioPortalNoticias());

        prefijo_relaciones_concepto = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoRelacionesConcepto());
        prefijo_relaciones_termino = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoRelacionesTermino());
        prefijo_relaciones_consulta = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoRelacionesConsulta());
        prefijo_relaciones_reporte = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoRelacionesReporte());
        prefijo_relaciones_seccion = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoRelacionesSeccion());
        prefijo_relaciones_periodo = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoRelacionesPeriodo());
        prefijo_relaciones_fecha = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoRelacionesFecha());
        prefijo_relaciones_medio = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagPrefijoRelacionesMedio());

        archivo_config_db_aplicacion_entidades = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagArchivoConfigDBAplicacionEntidades());
        archivo_config_db_resultados_diarios = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagArchivoConfigDBResultadosDiarios());

        dir_abm = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagDirABM());
        dir_consultas = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagDirConsultas());

        archivo_config_log = config_app_json->getAtributoValorString(ConfiguracionAplicacion::tagArchivoConfigLog());
    }
    catch (herramientas::utiles::excepciones::Excepcion & e)
    {
        delete config_app_json;
        delete config_json;

        std::ofstream error("error.txt");
        error << "error abriendo archivo de config.";
        error.flush();

        throw;
    }

    delete config_app_json;
    delete config_json;

	// recorto el prefijo al tamanio indicado en el archivo de config.
	prefijo_configuracion.erase(prefijo_configuracion.begin() + prefijo_tamanio, prefijo_configuracion.end());
	prefijo_concepto.erase(prefijo_concepto.begin() + prefijo_tamanio, prefijo_concepto.end());
	prefijo_termino.erase(prefijo_termino.begin() + prefijo_tamanio, prefijo_termino.end());
	prefijo_consulta.erase(prefijo_consulta.begin() + prefijo_tamanio, prefijo_consulta.end());
	prefijo_reporte.erase(prefijo_reporte.begin() + prefijo_tamanio, prefijo_reporte.end());
	prefijo_seccion.erase(prefijo_seccion.begin() + prefijo_tamanio, prefijo_seccion.end());
	prefijo_fecha.erase(prefijo_fecha.begin() + prefijo_tamanio, prefijo_fecha.end());
	prefijo_medio.erase(prefijo_medio.begin() + prefijo_tamanio, prefijo_medio.end());

    prefijo_relaciones_concepto.erase(prefijo_relaciones_concepto.begin() + prefijo_tamanio, prefijo_relaciones_concepto.end());
    prefijo_relaciones_termino.erase(prefijo_relaciones_termino.begin() + prefijo_tamanio, prefijo_relaciones_termino.end());
    prefijo_relaciones_consulta.erase(prefijo_relaciones_consulta.begin() + prefijo_tamanio, prefijo_relaciones_consulta.end());
    prefijo_relaciones_reporte.erase(prefijo_relaciones_reporte.begin() + prefijo_tamanio, prefijo_relaciones_reporte.end());
    prefijo_relaciones_seccion.erase(prefijo_relaciones_seccion.begin() + prefijo_tamanio, prefijo_relaciones_seccion.end());
    prefijo_relaciones_fecha.erase(prefijo_relaciones_fecha.begin() + prefijo_tamanio, prefijo_relaciones_fecha.end());
    prefijo_relaciones_medio.erase(prefijo_relaciones_medio.begin() + prefijo_tamanio, prefijo_relaciones_medio.end());
}

std::string ConfiguracionAplicacion::pathConfiguracion()
{
    return path_config;
}

std::string ConfiguracionAplicacion::pathScraping()
{
    return path_scraping;
}

std::string ConfiguracionAplicacion::pathConfiguracionScraping()
{
    return path_config_scraping;
}

std::string ConfiguracionAplicacion::pathConfiguracionNoticias() {
    return path_config_noticias;
}

bool ConfiguracionAplicacion::aplicacionLocal()
{
	return aplicacion_local;
}

bool ConfiguracionAplicacion::aplicacionDistribuida()
{
	return aplicacion_distribuida;
}

bool ConfiguracionAplicacion::prefijoHabilitado()
{
	return prefijo_habilitado;
}

unsigned int ConfiguracionAplicacion::prefijoTamanio()
{
	return prefijo_tamanio;
}

std::string ConfiguracionAplicacion::prefijoConfiguracion()
{
	return prefijo_configuracion;
}

// ENTIDADES
std::string ConfiguracionAplicacion::prefijoConcepto()
{
	return prefijo_concepto;
}

std::string ConfiguracionAplicacion::prefijoTermino()
{
	return prefijo_termino;
}

std::string ConfiguracionAplicacion::prefijoConsulta()
{
	return prefijo_consulta;
}

std::string ConfiguracionAplicacion::prefijoReporte()
{
	return prefijo_reporte;
}

std::string ConfiguracionAplicacion::prefijoSeccion()
{
	return prefijo_seccion;
}

std::string ConfiguracionAplicacion::prefijoPeriodo()
{
	return prefijo_periodo;
}

std::string ConfiguracionAplicacion::prefijoFecha()
{
	return prefijo_fecha;
}

std::string ConfiguracionAplicacion::prefijoMedio()
{
	return prefijo_medio;
}

std::string ConfiguracionAplicacion::prefijoMedioTwitter()
{
    return prefijo_medio_twitter;
}

std::string ConfiguracionAplicacion::prefijoMedioFacebook()
{
    return prefijo_medio_facebook;
}

std::string ConfiguracionAplicacion::prefijoMedioPortalNoticias()
{
    return prefijo_medio_portal_noticias;
}

// relaciones
std::string ConfiguracionAplicacion::prefijoRelacionesConcepto()
{
    return prefijo_relaciones_concepto;
}

std::string ConfiguracionAplicacion::prefijoRelacionesTermino()
{
    return prefijo_relaciones_termino;
}

std::string ConfiguracionAplicacion::prefijoRelacionesConsulta()
{
    return prefijo_relaciones_consulta;
}

std::string ConfiguracionAplicacion::prefijoRelacionesReporte()
{
    return prefijo_relaciones_reporte;
}

std::string ConfiguracionAplicacion::prefijoRelacionesSeccion()
{
    return prefijo_relaciones_seccion;
}

std::string ConfiguracionAplicacion::prefijoRelacionesPeriodo()
{
    return prefijo_relaciones_periodo;
}

std::string ConfiguracionAplicacion::prefijoRelacionesFecha()
{
    return prefijo_relaciones_fecha;
}

std::string ConfiguracionAplicacion::prefijoRelacionesMedio()
{
    return prefijo_relaciones_medio;
}

std::string ConfiguracionAplicacion::archivoConfigDBAplicacionEntidades()
{
    return archivo_config_db_aplicacion_entidades;
}

std::string ConfiguracionAplicacion::archivoConfigDBResultadosDiarios()
{
    return archivo_config_db_resultados_diarios;
}

std::string ConfiguracionAplicacion::archivoConfigLog()
{
    return archivo_config_log;
}

std::string ConfiguracionAplicacion::dirABM() {
    return dir_abm;
}

std::string ConfiguracionAplicacion::dirConsultas() {
    return dir_consultas;
}

std::string ConfiguracionAplicacion::tagPathScraping()
{
    return "path_scraping";
}

std::string ConfiguracionAplicacion::tagPathConfiguracionScraping()
{
    return "path_config_scraping";
}

std::string ConfiguracionAplicacion::tagPathConfiguracionNoticias() {
    return "path_config_noticias";
}

std::string ConfiguracionAplicacion::claveIDActual()
{
	return "id_actual";
}

std::string ConfiguracionAplicacion::tagAplicacionLocal()
{
	return "aplicacion_local";
}

std::string ConfiguracionAplicacion::tagAplicacionDistribuida()
{
	return "aplicacion_distribuida";
}

std::string ConfiguracionAplicacion::tagPrefijoHabilitado()
{
	return "prefijo_habilitado";
}

std::string ConfiguracionAplicacion::tagPrefijoTamanio()
{
	return "prefijo_tamanio";
}

std::string ConfiguracionAplicacion::tagPrefijoConfiguracion()
{
	return "prefijo_configuracion";
}

// ENTIDADES
std::string ConfiguracionAplicacion::tagPrefijoConcepto()
{
	return "prefijo_concepto";
}

std::string ConfiguracionAplicacion::tagPrefijoTermino()
{
	return "prefijo_termino";
}

std::string ConfiguracionAplicacion::tagPrefijoConsulta()
{
	return "prefijo_consulta";
}

std::string ConfiguracionAplicacion::tagPrefijoReporte()
{
	return "prefijo_reporte";
}

std::string ConfiguracionAplicacion::tagPrefijoSeccion()
{
	return "prefijo_seccion";
}

std::string ConfiguracionAplicacion::tagPrefijoPeriodo()
{
	return "prefijo_periodo";
}

std::string ConfiguracionAplicacion::tagPrefijoFecha()
{
	return "prefijo_fecha";
}

std::string ConfiguracionAplicacion::tagPrefijoMedio()
{
	return "prefijo_medio";
}

std::string ConfiguracionAplicacion::tagPrefijoMedioTwitter()
{
    return "prefijo_medio_twitter";
}

std::string ConfiguracionAplicacion::tagPrefijoMedioFacebook()
{
    return "prefijo_medio_facebook";
}

std::string ConfiguracionAplicacion::tagPrefijoMedioPortalNoticias()
{
    return "prefijo_medio_portal_noticias";
}

// RELACIONES
std::string ConfiguracionAplicacion::tagPrefijoRelacionesConcepto()
{
    return "prefijo_relaciones_concepto";
}

std::string ConfiguracionAplicacion::tagPrefijoRelacionesTermino()
{
    return "prefijo_relaciones_termino";
}

std::string ConfiguracionAplicacion::tagPrefijoRelacionesConsulta()
{
    return "prefijo_relaciones_consulta";
}

std::string ConfiguracionAplicacion::tagPrefijoRelacionesReporte()
{
    return "prefijo_relaciones_reporte";
}

std::string ConfiguracionAplicacion::tagPrefijoRelacionesSeccion()
{
    return "prefijo_relaciones_seccion";
}

std::string ConfiguracionAplicacion::tagPrefijoRelacionesPeriodo()
{
    return "prefijo_relaciones_periodo";
}

std::string ConfiguracionAplicacion::tagPrefijoRelacionesFecha()
{
    return "prefijo_relaciones_fecha";
}

std::string ConfiguracionAplicacion::tagPrefijoRelacionesMedio()
{
    return "prefijo_relaciones_medio";
}

std::string ConfiguracionAplicacion::tagArchivoConfigDBAplicacionEntidades()
{
    return "db_aplicacion_entidades";
}

std::string ConfiguracionAplicacion::tagArchivoConfigDBResultadosDiarios()
{
    return "db_resultados_diarios";
}

std::string ConfiguracionAplicacion::tagArchivoConfigLog()
{
    return "log_aplicacion";
}

std::string ConfiguracionAplicacion::tagDirABM() {
    return "dir_abm";
}

std::string ConfiguracionAplicacion::tagDirConsultas() {
    return "dir_consultas";
}

ConfiguracionAplicacion::ConfiguracionAplicacion()
{
}

ConfiguracionAplicacion::~ConfiguracionAplicacion()
{
}
