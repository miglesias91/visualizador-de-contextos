#include <aplicacion/include/GestorConsultas.h>

// utiles
#include <utiles/include/FuncionesString.h>

using namespace visualizador::aplicacion;

GestorConsultas::GestorConsultas()
{
}

GestorConsultas::~GestorConsultas()
{
}

void GestorConsultas::setMedios(std::vector<modelo::Medio*> medios)
{
    this->medios = medios;
}

void GestorConsultas::setConceptos(std::vector<modelo::Concepto*> conceptos)
{
    this->conceptos = conceptos;
}

void GestorConsultas::setData(std::vector<scraping::preparacion::ResultadoAnalisisDiario*> resultados)
{
    this->resultados = resultados;
}

bool GestorConsultas::fuerzaDeConceptosEnMedios(std::vector<graficos::modelo::Individuo*> & individuos, std::vector<graficos::modelo::Categoria*> & categorias)
{
    for (std::vector<modelo::Concepto*>::iterator it_conceptos = this->conceptos.begin(); it_conceptos != this->conceptos.end(); it_conceptos++)
    {
        std::vector<double> datos_fuerzas_individuo;
        for (std::vector<modelo::Medio*>::iterator it_medios = this->medios.begin(); it_medios != this->medios.end(); it_medios++)
        {
            float fuerza_concepto_en_medio = 0.0f;
            for (std::vector<scraping::preparacion::ResultadoAnalisisDiario*>::iterator it_resultados = this->resultados.begin(); it_resultados != this->resultados.end(); it_resultados++)
            {
                scraping::preparacion::ResultadoAnalisisMedio* resultado_medio = (*it_resultados)->getResultadoMedio((*it_medios)->getMedioAScrapear()->getId()->numero());

                if (NULL == resultado_medio)
                {
                    continue;
                }

                std::vector<modelo::Termino*> terminos_a_analizar = (*it_conceptos)->getTerminos();
                for (std::vector<modelo::Termino*>::iterator it_terminos = terminos_a_analizar.begin(); it_terminos != terminos_a_analizar.end(); it_terminos++)
                {
                    // IF TERMINO TIENE COMODIN; CALCULAR LA FUERZA CON EL COMODIN.
                    float fuerza_termino = this->calcularFuerzaDeTermino((*it_terminos), resultado_medio->getResultadoFuerzaEnNoticia());
                    //float fuerza_termino = resultado_medio->getResultadoFuerzaEnNoticia()->getFuerza((*it_terminos)->getValor());
                    fuerza_concepto_en_medio += fuerza_termino;
                }
            }
            datos_fuerzas_individuo.push_back(fuerza_concepto_en_medio);
        }
        graficos::modelo::Individuo * nuevo_individuo = new graficos::modelo::Individuo((*it_conceptos)->getEtiqueta(), datos_fuerzas_individuo);
        individuos.push_back(nuevo_individuo);
    }

    for (std::vector<modelo::Medio*>::iterator it_medios = this->medios.begin(); it_medios != this->medios.end(); it_medios++)
    {
        double fuerza_total = 0.0f;
        for (std::vector<scraping::preparacion::ResultadoAnalisisDiario*>::iterator it_resultados = this->resultados.begin(); it_resultados != this->resultados.end(); it_resultados++)
        {
            scraping::preparacion::ResultadoAnalisisMedio* resultado_medio = (*it_resultados)->getResultadoMedio((*it_medios)->getMedioAScrapear()->getId()->numero());

            if (NULL == resultado_medio)
            {
                continue;
            }

            fuerza_total += resultado_medio->getResultadoFuerzaEnNoticia()->getFuerzaTotal();
        }
        categorias.push_back(new graficos::modelo::Categoria((*it_medios)->getEtiqueta(), fuerza_total));
    }

    return true;
}

// GETTERS

// SETTERS

// METODOS

// CONSULTAS

// METODOS PRIVADOS

double GestorConsultas::calcularFuerzaDeTermino(modelo::Termino * termino, scraping::analisis::tecnicas::ResultadoFuerzaEnNoticia * resultado_fuerza_en_noticia)
{
    float fuerza_termino = 0.0f;
    std::string valor_termino = termino->getValor();

    // si el termino termina con "*", quiere decir que es un comodin y tengo que buscar todas las palabras que matcheen el termino.
    if ('*' == *(valor_termino.end() - 1))
    {
        std::string valor_termino_a_buscar(valor_termino.begin(), valor_termino.end() - 1);
        std::vector<std::pair<std::string, float>> fuerzas = resultado_fuerza_en_noticia->getFuerzas();

        for (std::vector<std::pair<std::string, float>>::iterator it = fuerzas.begin(); it != fuerzas.end(); it++)
        {
            if (herramientas::utiles::FuncionesString::empiezaCon(it->first, valor_termino_a_buscar))
            {
                fuerza_termino += it->second;
            }
        }
    }
    else
    {
        fuerza_termino = resultado_fuerza_en_noticia->getFuerza(termino->getValor());
    }

    return fuerza_termino;
}