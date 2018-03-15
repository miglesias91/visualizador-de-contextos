#pragma once

// scraping
#include <preparacion/include/ResultadoAnalisisDiario.h>

// modelo
#include <modelo/include/Concepto.h>
#include <modelo/include/Medio.h>

// visualizador
#include <visualizador-de-contexto/include/Individuo.h>
#include <visualizador-de-contexto/include/Categoria.h>

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

    void setMedios(std::vector<modelo::Medio*> medios);

    void setConceptos(std::vector<modelo::Concepto*> conceptos);

    void setData(std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados);

    // METODOS

    bool fuerzaDeConceptosEnMedios(std::vector<graficos::modelo::Individuo*> & individuos, std::vector<graficos::modelo::Categoria*> & categorias);

    // CONSULTAS

private:

    // METODOS PRIVADOS
    double calcularFuerzaDeTermino(modelo::Termino * termino, scraping::analisis::tecnicas::ResultadoFuerzaEnNoticia * resultado_fuerza_en_noticia);

    // ATRIBUTOS

    std::vector<modelo::Medio*> medios;
    std::vector<modelo::Concepto*> conceptos;
    std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados;
};

};
};

