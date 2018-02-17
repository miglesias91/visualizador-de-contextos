#pragma once

// stl
#include <vector>

// scraping
#include <scraping/include/IAdministradorScraping.h>
#include <preparacion/include/ResultadoAnalisisDiario.h>

// herramientas
#include <utiles/include/Fecha.h>

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>

namespace visualizador
{
namespace aplicacion
{

class GestorDatosScraping
{
public:
    GestorDatosScraping();

    virtual ~GestorDatosScraping();

    // GETTERS

    // SETTERS

    // METODOS

    // la memoria creada para los resultados devueltos HAY QUE ELIMINARLA.
    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> recuperarResultadosEntreRangoDeFechas(herramientas::utiles::Fecha desde, herramientas::utiles::Fecha hasta);

    // CONSULTAS

private:

    // ATRIBUTOS

    scraping::IAdministradorScraping * admin_datos_scraping;
};

};
};

