#pragma once

// scraping
#include <preparacion/include/ResultadoAnalisisDiario.h>

// modelo
#include <modelo/include/Concepto.h>
#include <modelo/include/Medio.h>

namespace visualizador
{
namespace aplicacion
{

class GestorConsultas
{
public:
    GestorConsultas();
    virtual ~GestorConsultas();

    // GETTERS

    // SETTERS

    void setMedios(std::vector<modelo::Medio*> medios_seleccionados);

    void setConceptos(std::vector<modelo::Concepto*> conceptos_seleccionados);

    void setData(std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados);

    // METODOS

    bool fuerzaDeConceptosEnMedios(std::vector<graficos::modelo::Individuo*> & individuos, std::vector<std::string> & categorias);

    // CONSULTAS

private:

    // ATRIBUTOS

    std::vector<modelo::Medio*> medios_seleccionados;
    std::vector<modelo::Concepto*> conceptos_seleccionados;
    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados;
};

};
};

