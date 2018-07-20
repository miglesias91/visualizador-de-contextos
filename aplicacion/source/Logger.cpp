#include <aplicacion/include/Logger.h>

using namespace visualizador::aplicacion;

// stl
#include <iostream>

// utiles
#include <utiles/include/FuncionesString.h>

herramientas::log::Logger * Logger::log = NULL;

Logger::Logger()
{
}

Logger::~Logger()
{
}

void Logger::iniciar(std::string config_log)
{
    log = herramientas::log::AdministradorLog::iniciarNuevo(config_log);
}

void Logger::marca(std::string mensaje)
{
    log->marca(mensaje);
}

void Logger::debug(std::string mensaje)
{
    log->debug(mensaje);
}

void Logger::info(std::string mensaje)
{
    log->info(mensaje);
}

void Logger::advertencia(std::string mensaje)
{
    log->advertencia(mensaje);
}

void Logger::error(std::string mensaje)
{
    log->error(mensaje);
}

void Logger::critico(std::string mensaje)
{
    log->critico(mensaje);
}

std::string Logger::infoLog(visualizador::modelo::Concepto * concepto)
{
    std::vector<visualizador::modelo::Termino*> terminos = concepto->getTerminos();

    std::vector<std::string> strings_terminos;
    for (std::vector<visualizador::modelo::Termino*>::iterator it = terminos.begin(); it != terminos.end(); it++)
    {
        strings_terminos.push_back((*it)->getValor());
    }

    return concepto->getEtiqueta() + ": " + herramientas::utiles::FuncionesString::unir(strings_terminos, ", ") + ".";
}

std::string Logger::infoLog(visualizador::modelo::Consulta * consulta)
{
    std::vector<visualizador::modelo::Concepto*> conceptos = consulta->getConceptos();
    std::vector<std::string> strings_conceptos;
    for (std::vector<visualizador::modelo::Concepto*>::iterator it = conceptos.begin(); it != conceptos.end(); it++)
    {
        strings_conceptos.push_back((*it)->getEtiqueta());
    }

    std::vector<visualizador::modelo::MedioTwitter*> medios_twitter = consulta->getMediosTwitter();
    std::vector<std::string> strings_medios_twitter;
    for (std::vector<visualizador::modelo::MedioTwitter*>::iterator it = medios_twitter.begin(); it != medios_twitter.end(); it++)
    {
        strings_medios_twitter.push_back((*it)->getNombreUsuario());
    }
    
    std::string string_periodo = consulta->getPeriodo()->getDesde()->getStringAAAAMMDD() + " - " + consulta->getPeriodo()->getHasta()->getStringAAAAMMDD();
    std::string string_conceptos = herramientas::utiles::FuncionesString::unir(strings_conceptos, ", ");
    std::string string_medios_twitter = herramientas::utiles::FuncionesString::unir(strings_medios_twitter, ", ");


    return "conceptos: " + string_conceptos + " - medios twitter: " + string_medios_twitter + " - periodo: " + string_periodo;
}

std::string Logger::infoLog(visualizador::modelo::Fecha * fecha)
{
    return fecha->getStringDDmesAAAA();
}

std::string Logger::infoLog(visualizador::modelo::Grafico * grafico)
{
    return grafico->getEtiqueta();
}

std::string Logger::infoLog(visualizador::modelo::Medio * medio) {
    std::string etiqueta = medio->getEtiqueta();
    std::string nombre_medio = "/" + medio->getNombre();

    std::string info_analisis = "sin contenido para visualizar";

    unsigned long long int cantidad_de_contenidos_historicos = medio->contenidos_analizados();
    if (cantidad_de_contenidos_historicos  != 0)
    {
        std::string fecha_contenido_mas_reciente = medio->fecha_contenido_mas_reciente().getStringDDMMAAAA("/");
        std::string fecha_contenido_mas_antiguo = medio->fecha_contenido_mas_antiguo().getStringDDMMAAAA("/");
        std::string string_cantidad_de_contenidos_historicos = std::to_string(cantidad_de_contenidos_historicos );
        std::string string_tamanio_total = std::to_string(medio->tamanio());

        info_analisis = fecha_contenido_mas_antiguo + " - " + fecha_contenido_mas_reciente + " | " + string_cantidad_de_contenidos_historicos + " | " + string_tamanio_total;
    }

    return etiqueta + " (" + nombre_medio + ") | " + info_analisis;
}

std::string Logger::infoLog(visualizador::modelo::Periodo * periodo)
{
    return periodo->getEtiqueta() + " - [ " + periodo->getDesde()->getStringDDmesAAAA(" ") + " , " + periodo->getHasta()->getStringDDmesAAAA(" ") + " ]";
}

std::string Logger::infoLog(visualizador::modelo::Reporte * reporte)
{
    return reporte->getEtiqueta();
}

std::string Logger::infoLog(visualizador::modelo::Seccion * seccion)
{
    return seccion->getEtiqueta();
}

std::string Logger::infoLog(visualizador::modelo::Termino * termino)
{
    return termino->getValor();
}
