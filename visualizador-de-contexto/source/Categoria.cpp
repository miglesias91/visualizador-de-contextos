#include <visualizador-de-contexto/include/Categoria.h>

using namespace graficos::modelo;

Categoria::Categoria(std::string nombre, double total) : nombre(nombre), total(total)
{
}

Categoria::~Categoria()
{
}

// GETTERS

std::string Categoria::getNombre()
{
    return this->nombre;
}

double Categoria::getTotal()
{
    return this->total;
}

// SETTERS

void Categoria::setNombre(std::string nombre)
{
    this->nombre = nombre;
}

void Categoria::setTotal(double total)
{
    this->total = total;
}

// METODOS

// CONSULTAS