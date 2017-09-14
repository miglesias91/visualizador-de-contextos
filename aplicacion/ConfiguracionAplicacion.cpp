#include <aplicacion/ConfiguracionAplicacion.h>

using namespace visualizador::aplicacion;

// stl
#include <fstream>
#include <sstream>

// rapidjson
#include <rapidjson/document.h>

bool ConfiguracionAplicacion::prefijo_habilitado;
unsigned int ConfiguracionAplicacion::prefijo_tamanio;
std::string ConfiguracionAplicacion::prefijo_concepto;
std::string ConfiguracionAplicacion::prefijo_termino;
std::string ConfiguracionAplicacion::prefijo_consulta;
std::string ConfiguracionAplicacion::prefijo_grafico;
std::string ConfiguracionAplicacion::prefijo_seccion;

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
	prefijo_grafico = config_json[ConfiguracionAplicacion::tagPrefijoGrafico().c_str()].GetString();
	prefijo_seccion = config_json[ConfiguracionAplicacion::tagPrefijoSeccion().c_str()].GetString();

	// recorto el prefijo al tamanio indicado en el archivo de config.
	prefijo_concepto.erase(prefijo_concepto.begin() + prefijo_tamanio, prefijo_concepto.end());
	prefijo_termino.erase(prefijo_termino.begin() + prefijo_tamanio, prefijo_termino.end());
	prefijo_consulta.erase(prefijo_consulta.begin() + prefijo_tamanio, prefijo_consulta.end());
	prefijo_grafico.erase(prefijo_grafico.begin() + prefijo_tamanio, prefijo_grafico.end());
	prefijo_seccion.erase(prefijo_seccion.begin() + prefijo_tamanio, prefijo_seccion.end());
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

std::string ConfiguracionAplicacion::prefijoGrafico()
{
	return prefijo_grafico;
}

std::string ConfiguracionAplicacion::prefijoSeccion()
{
	return prefijo_seccion;
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

std::string ConfiguracionAplicacion::tagPrefijoGrafico()
{
	return "prefijo_grafico";
}

std::string ConfiguracionAplicacion::tagPrefijoSeccion()
{
	return "prefijo_seccion";
}

ConfiguracionAplicacion::ConfiguracionAplicacion()
{
}

ConfiguracionAplicacion::~ConfiguracionAplicacion()
{
}
