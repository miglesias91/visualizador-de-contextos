#include <visualizador-de-contexto/include/Individuo.h>

using namespace graficos::modelo;

Individuo::Individuo(std::string nombre, std::vector<double> datos) : nombre(nombre), datos(datos)
{
}

Individuo::~Individuo()
{
}

// GETTERS

std::string Individuo::getNombre()
{
    return this->nombre;
}

std::vector<double> Individuo::getDatos()
{
    return this->datos;
}

std::vector<double> Individuo::getDatosRelativos(std::vector<double> totales)
{
    std::vector<double> datos_relativos;
    for (unsigned int i = 0; i < this->datos.size(); i++)
    {
        datos_relativos.push_back(this->datos[i] / totales[i]);
    }

    return datos_relativos;
}

// SETTERS

void Individuo::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

void Individuo::setDatos(std::vector<double> datos)
{
    this->datos = datos;
}

// METODOS

// CONSULTAS