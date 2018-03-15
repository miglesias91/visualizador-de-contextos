#pragma once

// stl
#include <string>
#include <vector>

namespace graficos
{
namespace modelo
{

class Categoria
{
public:
    Categoria(std::string nombre, double total);
    virtual ~Categoria();

    // GETTERS

    virtual std::string getNombre();
    virtual double getTotal();

    // SETTERS

    virtual void setNombre(std::string nombre);
    virtual void setTotal(double total);

    // METODOS

    // CONSULTAS

private:

    // ATRIBUTOS

    std::string nombre;
    double total;
};

};
};

