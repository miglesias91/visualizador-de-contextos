#pragma once

// stl
#include <string>

// rapidjson
#include <rapidjson/document.h>

namespace visualizador
{
namespace aplicacion
{

class ConfiguracionAplicacion
{
public:

	static void leerConfiguracion(std::string path_archivo_configuracion);

	// METODOS

	// CONFIGURACIONES

    static std::string pathConfiguracion();

	static bool aplicacionLocal();
	static bool aplicacionDistribuida();
	static bool prefijoHabilitado();
	static unsigned int prefijoTamanio();
	static std::string prefijoConfiguracion();

	static std::string prefijoConcepto();
	static std::string prefijoTermino();
	static std::string prefijoConsulta();
	static std::string prefijoReporte();
	static std::string prefijoSeccion();
	static std::string prefijoPeriodo();
	static std::string prefijoFecha();
    static std::string prefijoMedio();

    static std::string prefijoMedioTwitter();

    static std::string prefijoRelacionesConcepto();
    static std::string prefijoRelacionesTermino();
    static std::string prefijoRelacionesConsulta();
    static std::string prefijoRelacionesReporte();
    static std::string prefijoRelacionesSeccion();
    static std::string prefijoRelacionesPeriodo();
    static std::string prefijoRelacionesFecha();
    static std::string prefijoRelacionesMedio();

	static std::string claveIDActual();
    
    static std::string archivoConfigDBAplicacionEntidades();

    static std::string archivoConfigLog();

protected:

    // TAGS

    static std::string tagAplicacionLocal();
    static std::string tagAplicacionDistribuida();
    static std::string tagPrefijoHabilitado();
    static std::string tagPrefijoTamanio();
    static std::string tagPrefijoConfiguracion();

    static std::string tagPrefijoConcepto();
    static std::string tagPrefijoTermino();
    static std::string tagPrefijoConsulta();
    static std::string tagPrefijoReporte();
    static std::string tagPrefijoSeccion();
    static std::string tagPrefijoPeriodo();
    static std::string tagPrefijoFecha();
    static std::string tagPrefijoMedio();

    static std::string tagPrefijoMedioTwitter();

    static std::string tagPrefijoRelacionesConcepto();
    static std::string tagPrefijoRelacionesTermino();
    static std::string tagPrefijoRelacionesConsulta();
    static std::string tagPrefijoRelacionesReporte();
    static std::string tagPrefijoRelacionesSeccion();
    static std::string tagPrefijoRelacionesPeriodo();
    static std::string tagPrefijoRelacionesFecha();
    static std::string tagPrefijoRelacionesMedio();

    static std::string tagArchivoConfigDBAplicacionEntidades();

    static std::string tagArchivoConfigLog();

private:

	ConfiguracionAplicacion();
	virtual ~ConfiguracionAplicacion();

    static std::string path_config;

	static bool aplicacion_local;
	static bool aplicacion_distribuida;
	static bool prefijo_habilitado;
	static unsigned int prefijo_tamanio;
	static std::string prefijo_configuracion;

	static std::string prefijo_concepto;
	static std::string prefijo_termino;
	static std::string prefijo_consulta;
	static std::string prefijo_reporte;
	static std::string prefijo_seccion;
	static std::string prefijo_periodo;
	static std::string prefijo_fecha;
	static std::string prefijo_medio;

    static std::string prefijo_medio_twitter;

    static std::string prefijo_relaciones_concepto;
    static std::string prefijo_relaciones_termino;
    static std::string prefijo_relaciones_consulta;
    static std::string prefijo_relaciones_reporte;
    static std::string prefijo_relaciones_seccion;
    static std::string prefijo_relaciones_periodo;
    static std::string prefijo_relaciones_fecha;
    static std::string prefijo_relaciones_medio;

    static std::string archivo_config_db_aplicacion_entidades;

    static std::string archivo_config_log;

	static std::string clave_id_actual;
};

};
};

