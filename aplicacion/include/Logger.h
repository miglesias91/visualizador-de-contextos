#pragma once

// modelo
#include <modelo/include/Concepto.h>
#include <modelo/include/Consulta.h>
#include <modelo/include/Fecha.h>
#include <modelo/include/Grafico.h>
#include <modelo/include/Periodo.h>
#include <modelo/include/Reporte.h>
#include <modelo/include/Seccion.h>
#include <modelo/include/Termino.h>

// log
#include <log/include/AdministradorLog.h>

namespace visualizador
{
namespace aplicacion
{

class Logger
{
public:

    static void iniciar(std::string config_log);

    // GETTERS

    // SETTERS

    // METODOS

    static std::string infoLog(visualizador::modelo::Concepto * concepto);
    static std::string infoLog(visualizador::modelo::Consulta * consulta);
    static std::string infoLog(visualizador::modelo::Fecha * fecha);
    static std::string infoLog(visualizador::modelo::Grafico * grafico);
    static std::string infoLog(visualizador::modelo::Medio * medio);
    static std::string infoLog(visualizador::modelo::Periodo * periodo);
    static std::string infoLog(visualizador::modelo::Reporte * reporte);
    static std::string infoLog(visualizador::modelo::Seccion * seccion);
    static std::string infoLog(visualizador::modelo::Termino * termino);

    static void marca(std::string mensaje);
    static void debug(std::string mensaje);
    static void info(std::string mensaje);
    static void advertencia(std::string mensaje);
    static void error(std::string mensaje);
    static void critico(std::string mensaje);

protected:

private:

    Logger();
    virtual ~Logger();

    static herramientas::log::Logger * log;
    
};

};
};

