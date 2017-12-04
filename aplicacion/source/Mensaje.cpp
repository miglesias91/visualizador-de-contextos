#include <aplicacion/include/Mensaje.h>

using namespace visualizador::aplicacion::comunicacion;

Mensaje::Mensaje()
{
}

Mensaje::Mensaje(std::string titulo, std::string texto) : titulo(titulo), texto(texto)
{
}

Mensaje::~Mensaje()
{
}


// GETTERS

std::string Mensaje::getTitulo()
{
    return this->titulo;
}

std::string Mensaje::getTexto()
{
    return this->texto;
}

// SETTERS

void Mensaje::setTitulo(std::string titulo)
{
    this->titulo = titulo;
}

void Mensaje::setTexto(std::string texto)
{
    this->texto = texto;
}

// METODOS

// CONSULTAS
