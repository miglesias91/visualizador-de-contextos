#pragma once

// stl
#include <string>

namespace visualizador
{
namespace aplicacion
{
namespace comunicacion
{

class Mensaje
{
public:
    Mensaje();
    Mensaje(std::string titulo, std::string texto);
    virtual ~Mensaje();

    // GETTERS

    virtual std::string getTitulo();
    virtual std::string getTexto();

    // SETTERS

    virtual void setTitulo(std::string titulo);
    virtual void setTexto(std::string texto);

    // METODOS

    // CONSULTAS

private:

    std::string titulo;
    std::string texto;
};

};
};
};


