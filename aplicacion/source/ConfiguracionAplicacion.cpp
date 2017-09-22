#include <aplicacion/include/ConfiguracionAplicacion.h>

using namespace visualizador::aplicacion;

// stl
#include <fstream>
#include <sstream>

bool ConfiguracionAplicacion::prefijo_habilitado;
unsigned int ConfiguracionAplicacion::prefijo_tamanio;
std::string ConfiguracionAplicacion::prefijo_concepto;
std::string ConfiguracionAplicacion::prefijo_termino;
std::string ConfiguracionAplicacion::prefijo_consulta;
std::string ConfiguracionAplicacion::prefijo_reporte;
std::string ConfiguracionAplicacion::prefijo_seccion;
std::string ConfiguracionAplicacion::prefijo_periodo;
std::string ConfiguracionAplicacion::prefijo_fecha;
std::string ConfiguracionAplicacion::prefijo_medio;
const unsigned int ConfiguracionAplicacion::tamanio_alocador = 1024;
rapidjson::Document ConfiguracionAplicacion::documento_alocador;

void ConfiguracionAplicacion::leerConfiguracion(std::string path_archivo_configuracion)
{
	std::ifstream archivo(path_archivo_configuracion);

	if (false == archivo.good())
	{
		throw - 1;
	}

	std::ostringstream sstream;
	sstream << archivo.rdbuf();
	const std::string string_config(sstream.str());

	rapidjson::Document config_json;
	config_json.Parse(string_config.c_str());

	prefijo_habilitado = config_json[ConfiguracionAplicacion::tagPrefijoHabilitado().c_str()].GetBool();
	prefijo_tamanio = config_json[ConfiguracionAplicacion::tagPrefijoTamanio().c_str()].GetUint();

	prefijo_concepto = config_json[ConfiguracionAplicacion::tagPrefijoConcepto().c_str()].GetString();
	prefijo_termino = config_json[ConfiguracionAplicacion::tagPrefijoTermino().c_str()].GetString();
	prefijo_consulta = config_json[ConfiguracionAplicacion::tagPrefijoConsulta().c_str()].GetString();
	prefijo_reporte = config_json[ConfiguracionAplicacion::tagPrefijoReporte().c_str()].GetString();
	prefijo_seccion = config_json[ConfiguracionAplicacion::tagPrefijoSeccion().c_str()].GetString();
	prefijo_periodo = config_json[ConfiguracionAplicacion::tagPrefijoPeriodo().c_str()].GetString();
	prefijo_fecha = config_json[ConfiguracionAplicacion::tagPrefijoFecha().c_str()].GetString();
	prefijo_medio = config_json[ConfiguracionAplicacion::tagPrefijoMedio().c_str()].GetString();

	// recorto el prefijo al tamanio indicado en el archivo de config.
	prefijo_concepto.erase(prefijo_concepto.begin() + prefijo_tamanio, prefijo_concepto.end());
	prefijo_termino.erase(prefijo_termino.begin() + prefijo_tamanio, prefijo_termino.end());
	prefijo_consulta.erase(prefijo_consulta.begin() + prefijo_tamanio, prefijo_consulta.end());
	prefijo_reporte.erase(prefijo_reporte.begin() + prefijo_tamanio, prefijo_reporte.end());
	prefijo_seccion.erase(prefijo_seccion.begin() + prefijo_tamanio, prefijo_seccion.end());
	prefijo_fecha.erase(prefijo_fecha.begin() + prefijo_tamanio, prefijo_fecha.end());
	prefijo_medio.erase(prefijo_medio.begin() + prefijo_tamanio, prefijo_medio.end());
}

rapidjson::Document::AllocatorType * ConfiguracionAplicacion::getAlocador()
{
	return &documento_alocador.GetAllocator();
}

bool ConfiguracionAplicacion::prefijoHabilitado()
{
	return prefijo_habilitado;
}

unsigned int ConfiguracionAplicacion::prefijoTamanio()
{
	return prefijo_tamanio;
}

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

std::string ConfiguracionAplicacion::tagPrefijoHabilitado()
{
	return "prefijo_habilitado";
}

std::string ConfiguracionAplicacion::tagPrefijoTamanio()
{
	return "prefijo_tamanio";
}

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

ConfiguracionAplicacion::ConfiguracionAplicacion()
{
}

ConfiguracionAplicacion::~ConfiguracionAplicacion()
{
}
