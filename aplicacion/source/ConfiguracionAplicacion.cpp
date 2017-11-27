#include <aplicacion/include/ConfiguracionAplicacion.h>

using namespace visualizador::aplicacion;

// stl
#include <fstream>
#include <sstream>

std::string ConfiguracionAplicacion::path_config;

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

std::string ConfiguracionAplicacion::prefijo_relaciones_concepto;
std::string ConfiguracionAplicacion::prefijo_relaciones_termino;
std::string ConfiguracionAplicacion::prefijo_relaciones_consulta;
std::string ConfiguracionAplicacion::prefijo_relaciones_reporte;
std::string ConfiguracionAplicacion::prefijo_relaciones_seccion;
std::string ConfiguracionAplicacion::prefijo_relaciones_periodo;
std::string ConfiguracionAplicacion::prefijo_relaciones_fecha;
std::string ConfiguracionAplicacion::prefijo_relaciones_medio;

std::string ConfiguracionAplicacion::clave_id_actual;

const unsigned int ConfiguracionAplicacion::tamanio_alocador = 1024;
rapidjson::Document ConfiguracionAplicacion::documento_alocador;

void ConfiguracionAplicacion::leerConfiguracion(std::string path_archivo_configuracion)
{
	std::ifstream archivo(path_archivo_configuracion);

    path_config = path_archivo_configuracion;

	if (false == archivo.good())
	{
		throw - 1;
	}

	std::ostringstream sstream;
	sstream << archivo.rdbuf();
	const std::string string_config(sstream.str());

	rapidjson::Document config_json;
	config_json.Parse(string_config.c_str());

    rapidjson::Value & config_app_json = config_json["aplicacion"];

	aplicacion_local = config_app_json[ConfiguracionAplicacion::tagAplicacionLocal().c_str()].GetBool();
	aplicacion_distribuida = config_app_json[ConfiguracionAplicacion::tagAplicacionDistribuida().c_str()].GetBool();
	prefijo_habilitado = config_app_json[ConfiguracionAplicacion::tagPrefijoHabilitado().c_str()].GetBool();
	prefijo_tamanio = config_app_json[ConfiguracionAplicacion::tagPrefijoTamanio().c_str()].GetUint();

	prefijo_configuracion = config_app_json[ConfiguracionAplicacion::tagPrefijoConfiguracion().c_str()].GetString();
	prefijo_concepto = config_app_json[ConfiguracionAplicacion::tagPrefijoConcepto().c_str()].GetString();
	prefijo_termino = config_app_json[ConfiguracionAplicacion::tagPrefijoTermino().c_str()].GetString();
	prefijo_consulta = config_app_json[ConfiguracionAplicacion::tagPrefijoConsulta().c_str()].GetString();
	prefijo_reporte = config_app_json[ConfiguracionAplicacion::tagPrefijoReporte().c_str()].GetString();
	prefijo_seccion = config_app_json[ConfiguracionAplicacion::tagPrefijoSeccion().c_str()].GetString();
	prefijo_periodo = config_app_json[ConfiguracionAplicacion::tagPrefijoPeriodo().c_str()].GetString();
	prefijo_fecha = config_app_json[ConfiguracionAplicacion::tagPrefijoFecha().c_str()].GetString();
	prefijo_medio = config_app_json[ConfiguracionAplicacion::tagPrefijoMedio().c_str()].GetString();

    prefijo_relaciones_concepto = config_app_json[ConfiguracionAplicacion::tagPrefijoRelacionesConcepto().c_str()].GetString();
    prefijo_relaciones_termino = config_app_json[ConfiguracionAplicacion::tagPrefijoRelacionesTermino().c_str()].GetString();
    prefijo_relaciones_consulta = config_app_json[ConfiguracionAplicacion::tagPrefijoRelacionesConsulta().c_str()].GetString();
    prefijo_relaciones_reporte = config_app_json[ConfiguracionAplicacion::tagPrefijoRelacionesReporte().c_str()].GetString();
    prefijo_relaciones_seccion = config_app_json[ConfiguracionAplicacion::tagPrefijoRelacionesSeccion().c_str()].GetString();
    prefijo_relaciones_periodo = config_app_json[ConfiguracionAplicacion::tagPrefijoRelacionesPeriodo().c_str()].GetString();
    prefijo_relaciones_fecha = config_app_json[ConfiguracionAplicacion::tagPrefijoRelacionesFecha().c_str()].GetString();
    prefijo_relaciones_medio = config_app_json[ConfiguracionAplicacion::tagPrefijoRelacionesMedio().c_str()].GetString();

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

rapidjson::Document::AllocatorType * ConfiguracionAplicacion::getAlocador()
{
	return &documento_alocador.GetAllocator();
}

std::string ConfiguracionAplicacion::pathConfiguracion()
{
    return path_config;
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

ConfiguracionAplicacion::ConfiguracionAplicacion()
{
}

ConfiguracionAplicacion::~ConfiguracionAplicacion()
{
}
