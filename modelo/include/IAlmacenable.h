#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/ID.h>

namespace visualizador
{
namespace modelo
{

class IAlmacenable
{
public:
    IAlmacenable(std::string grupo = "");
    virtual ~IAlmacenable();

    // GETTERS

    virtual visualizador::aplicacion::ID* getId();

    virtual std::string getGrupo();

    virtual std::string getValorAlmacenable() = 0;

    // SETTERS

    virtual void setId(visualizador::aplicacion::ID* id);

    virtual void setGrupo(std::string grupo);

    // METODOS

    virtual void asignarNuevoId();

    virtual void parsearValorAlmacenable(std::string valor_almacenable) = 0;

    virtual std::string prefijoGrupo() = 0;

    virtual unsigned int hashcode() = 0;

    static bool comparador(IAlmacenable* a, IAlmacenable* b);

private:

    // ATRIBUTOS

    visualizador::aplicacion::ID* id;
    std::string grupo;

};
};
};

