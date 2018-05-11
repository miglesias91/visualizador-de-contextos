#include <aplicacion/include/GestorDatosScraping.h>

using namespace visualizador::aplicacion;

// scraping
#include <scraping/include/ConfiguracionScraping.h>

GestorDatosScraping::GestorDatosScraping()
{
    this->admin_datos_scraping = scraping::IAdministradorScraping::getInstanciaAdminResultadosAnalisisDiario();

    this->admin_info_scraping = scraping::IAdministradorScraping::getInstanciaAdminInfo();
}

GestorDatosScraping::~GestorDatosScraping()
{
}

// GETTERS

// SETTERS

// METODOS

bool GestorDatosScraping::almacenarMedio(scraping::extraccion::Medio * medio_a_almacenar)
{
    medio_a_almacenar->setGrupo(medio_a_almacenar->getGrupoMedio());

    return scraping::IAdministradorScraping::getInstanciaAdminInfo()->almacenar(medio_a_almacenar);
}

bool GestorDatosScraping::recuperarMedio(scraping::extraccion::Medio * medio_a_recuperar)
{
    medio_a_recuperar->setGrupo(medio_a_recuperar->getGrupoMedio());

    return scraping::IAdministradorScraping::getInstanciaAdminInfo()->recuperar(medio_a_recuperar);
}

bool GestorDatosScraping::eliminarMedio(scraping::extraccion::Medio * medio_a_eliminar)
{
    medio_a_eliminar->setGrupo(medio_a_eliminar->getGrupoMedio());

    return scraping::IAdministradorScraping::getInstanciaAdminInfo()->eliminar(medio_a_eliminar);
}

bool GestorDatosScraping::almacenarIDActualMedio()
{
    return scraping::IAdministradorScraping::getInstanciaAdminInfo()->almacenarIDActual<scraping::extraccion::Medio>();
}

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

void GestorDatosScraping::recuperarResultados(
    const herramientas::utiles::Fecha & desde,
    const herramientas::utiles::Fecha & hasta,
    const std::vector<visualizador::modelo::Medio*> & medios,
    const std::vector<visualizador::modelo::Concepto*> & conceptos,
    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> * resultados_filtrados)
{

    // recupero TODOS los resultados diarios.
    this->admin_datos_scraping->recuperarGrupo<scraping::preparacion::ResultadoAnalisisDiario>(scraping::ConfiguracionScraping::prefijoResultadoDiario(), resultados_filtrados);

    // elimino los que no estan dentro del rango
    herramientas::utiles::Fecha copia_desde = desde;
    herramientas::utiles::Fecha copia_hasta = hasta;
    resultados_filtrados->erase(
        std::remove_if(resultados_filtrados->begin(), resultados_filtrados->end(),
            [&copia_desde, &copia_hasta](scraping::preparacion::ResultadoAnalisisDiario * resultado_diario)
    {
        herramientas::utiles::Fecha fecha_resultado = herramientas::utiles::Fecha::parsearFormatoAAAAMMDD(resultado_diario->getId()->string());

        if (copia_desde <= fecha_resultado && fecha_resultado <= copia_hasta)
        {
            return false;
        }
        else
        {
            delete resultado_diario;
            return true;
        }
    }),
        resultados_filtrados->end());

    // junto los ids de los terminos
    std::vector<std::string> terminos_a_filtrar;
    std::for_each(conceptos.begin(), conceptos.end(),
        [&terminos_a_filtrar](visualizador::modelo::Concepto * concepto)
    {
        std::vector<visualizador::modelo::Termino*> terminos = concepto->getTerminos();

        std::for_each(terminos.begin(), terminos.end(),
            [&terminos_a_filtrar](visualizador::modelo::Termino * termino)
        {
            terminos_a_filtrar.push_back(termino->getValor());
        });
    });

    // junto los ids de los medios
    std::vector<unsigned long long int> medios_a_filtrar;
    std::for_each(medios.begin(), medios.end(),
        [&medios_a_filtrar](visualizador::modelo::Medio * medio)
    {
        unsigned long long int id = medio->getMedioAScrapear()->getId()->numero();

        medios_a_filtrar.push_back(id);
    });

    // filtro los medios de los resultados, y los terminos de los medios.
    std::for_each(resultados_filtrados->begin(), resultados_filtrados->end(),
        [&medios_a_filtrar, &terminos_a_filtrar](scraping::preparacion::ResultadoAnalisisDiario * resultado)
    {
        resultado->filtrar(medios_a_filtrar, terminos_a_filtrar);
    });
}

// CONSULTAS