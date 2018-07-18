#pragma once

// stl
#include <vector>

// herramientas
#include <utiles/include/Fecha.h>

// scraping
#include <preparacion/include/ResultadoAnalisisDiario.h>

// extraccion
#include <extraccion/include/Medio.h>

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>

// modelo
#include <modelo/include/Concepto.h>
#include <modelo/include/Medio.h>

namespace visualizador
{
namespace aplicacion
{

class GestorResultadosDiarios
{
public:
    GestorResultadosDiarios();

    virtual ~GestorResultadosDiarios();

    // GETTERS

    // SETTERS

    // METODOS
    bool recuperar(scraping::extraccion::Medio * medio) const;

    // la memoria creada para los resultados devueltos HAY QUE ELIMINARLA.
    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> recuperarResultadosEntreRangoDeFechas(herramientas::utiles::Fecha desde, herramientas::utiles::Fecha hasta);

    // la memoria creada para los resultados devueltos HAY QUE ELIMINARLA.
    void recuperarResultados(
        const herramientas::utiles::Fecha & desde,
        const herramientas::utiles::Fecha & hasta,
        const std::vector<modelo::Medio*> & medios,
        const std::vector<modelo::Concepto*> & conceptos,
        std::vector<scraping::preparacion::ResultadoAnalisisDiario*> * resultados_filtrados);


    // CONSULTAS

private:

    // ATRIBUTOS
    aplicacion::IAdministradorAplicacion* admin_resultados;
};


};
};

