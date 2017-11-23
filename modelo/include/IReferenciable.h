#pragma once


namespace visualizador
{
namespace modelo
{
class IReferenciable
{
public:
    IReferenciable();
    virtual ~IReferenciable();

    bool estaReferenciado();

    unsigned int cantidadReferencias();

    unsigned int sumarReferencia();

    unsigned int restarReferencia();

private:

    unsigned int cantidad_referencias;
};
};
};

