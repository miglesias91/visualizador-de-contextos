#pragma once

// stl
#include <string>
#include <vector>

namespace graficos
{
namespace modelo
{

class Individuo
{
public:
    Individuo(std::string nombre, std::vector<double> datos);
    virtual ~Individuo();

    // GETTERS

    virtual std::string getNombre();
    virtual std::vector<double> getDatos();

    // SETTERS

    virtual void setNombre(std::string nombre);
    virtual void setDatos(std::vector<double> datos);

    // METODOS

    // CONSULTAS

private:

    // ATRIBUTOS

    std::string nombre;

    std::vector<double> datos;
};

};
};

