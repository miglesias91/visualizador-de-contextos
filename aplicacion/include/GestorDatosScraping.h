#pragma once

// stl
#include <vector>

// herramientas
#include <utiles/include/Fecha.h>

// scraping
#include <scraping/include/IAdministradorScraping.h>
#include <preparacion/include/ResultadoAnalisisDiario.h>

// extraccion
#include <extraccion/include/Medio.h>

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

    bool recuperarMedio(scraping::extraccion::Medio * medio_a_recuperar);

    bool eliminarMedio(scraping::extraccion::Medio * medio_a_eliminar);

    bool almacenarMedio(scraping::extraccion::Medio * medio_a_almacenar);

    // la memoria creada para los resultados devueltos HAY QUE ELIMINARLA.
    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> recuperarResultadosEntreRangoDeFechas(herramientas::utiles::Fecha desde, herramientas::utiles::Fecha hasta);

    // CONSULTAS

private:

    // ATRIBUTOS

    scraping::IAdministradorScraping * admin_datos_scraping;
    scraping::IAdministradorScraping * admin_info_scraping;
};

};
};

