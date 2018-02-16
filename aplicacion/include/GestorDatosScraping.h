#pragma once

// stl
#include <vector>

// scraping
#include <almacenamiento/include/IAdministradorAlmacenamiento.h>

// herramientas
// #include <>

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

    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> recuperarResultadosEntreRangoDeFechas(const herramientas::utiles::Fecha & desde, const herramientras::utiles::Fecha & hasta);

    // CONSULTAS

private:

    // ATRIBUTOS

    IAdministradorAplicacion * admin_datos_scraping;
};

};
};

