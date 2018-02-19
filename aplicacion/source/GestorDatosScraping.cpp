#include <aplicacion/include/GestorDatosScraping.h>

using namespace visualizador::aplicacion;

// scraping
#include <scraping/include/ConfiguracionScraping.h>

GestorDatosScraping::GestorDatosScraping()
{
    this->admin_datos_scraping = scraping::IAdministradorScraping::getInstanciaAdminResultadosAnalisisDiario();
}

GestorDatosScraping::~GestorDatosScraping()
{
}

// GETTERS

// SETTERS

// METODOS

// la memoria creada para los resultados devueltos HAY QUE ELIMINARLA.
std::vector<scraping::preparacion::ResultadoAnalisisDiario*> GestorDatosScraping::recuperarResultadosEntreRangoDeFechas(herramientas::utiles::Fecha desde, herramientas::utiles::Fecha hasta)
{
    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados_recuperados;
    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados_entre_rango;

    this->admin_datos_scraping->recuperarGrupo<scraping::preparacion::ResultadoAnalisisDiario>(scraping::ConfiguracionScraping::prefijoResultadoDiario(), &resultados_recuperados);

    for (std::vector<scraping::preparacion::ResultadoAnalisisDiario*>::iterator it = resultados_recuperados.begin(); it != resultados_recuperados.end(); it++)
    {
        herramientas::utiles::Fecha fecha_resultado = herramientas::utiles::Fecha::parsearFormatoAAAAMMDD((*it)->getId()->string());

        if (desde < fecha_resultado && fecha_resultado < hasta)
        {// si esta dentro del rango de fecha, lo pongo en el vector que voy a devolver.
            resultados_entre_rango.push_back(*it);
        }
        else
        {// si NO esta dentro del rango, libero la memoria.
            delete *it;
        }
    }

    return resultados_entre_rango;
}

// CONSULTAS