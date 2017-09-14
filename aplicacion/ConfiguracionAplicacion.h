#pragma once

// stl
#include <string>

namespace visualizador
{
namespace aplicacion
{

class ConfiguracionAplicacion
{
public:

	static void leerConfiguracion(std::string path_archivo_configuracion);

	// CONFIGURACIONES

	static bool prefijoHabilitado();
	static unsigned int prefijoTamanio();
	static std::string prefijoConcepto();
	static std::string prefijoTermino();
	static std::string prefijoConsulta();
	static std::string prefijoGrafico();
	static std::string prefijoSeccion();

	// TAGS

	static std::string tagPrefijoHabilitado();
	static std::string tagPrefijoTamanio();
	static std::string tagPrefijoConcepto();
	static std::string tagPrefijoTermino();
	static std::string tagPrefijoConsulta();
	static std::string tagPrefijoGrafico();
	static std::string tagPrefijoSeccion();

private:

	ConfiguracionAplicacion();
	virtual ~ConfiguracionAplicacion();

	static bool prefijo_habilitado;
	static unsigned int prefijo_tamanio;
	static std::string prefijo_concepto;
	static std::string prefijo_termino;
	static std::string prefijo_consulta;
	static std::string prefijo_grafico;
	static std::string prefijo_seccion;
};

};
};

