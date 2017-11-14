#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/ID.h>

// modelo
#include <modelo/include/IAlmacenable.h>

namespace visualizador
{
namespace modelo
{

class IRelacion : public IAlmacenable
{
public:
    
    // CONSTRUCTORES

    IRelacion(std::string grupo = "");
    ~IRelacion();

    // GETTERS
    
    virtual std::string getValorAlmacenable() = 0;

    // SETTERS

    // METODOS

    virtual void parsearValorAlmacenable(std::string valor_almacenable) = 0;

    virtual std::string prefijoGrupo() = 0;

    virtual unsigned int hashcode() = 0;

private:

};

};
};

