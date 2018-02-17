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
    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados;

    this->admin_datos_scraping->recuperarGrupo<scraping::preparacion::ResultadoAnalisisDiario>(scraping::ConfiguracionScraping::prefijoResultadoDiario(), &resultados);

    for (std::vector<scraping::preparacion::ResultadoAnalisisDiario*>::iterator it = resultados.begin(); it != resultados.end(); it++)
    {
        herramientas::utiles::Fecha fecha_resultado = herramientas::utiles::Fecha::parsearFormatoAAAAMMDD((*it)->getId()->string());

        if (fecha_resultado < desde || fecha_resultado > hasta)
        {
            delete *it;
            it = resultados.erase(it);

            if (resultados.end() == it)
            {
                break;
            }
        }
    }

    return resultados;
}

// CONSULTAS