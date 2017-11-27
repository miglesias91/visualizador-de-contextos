#pragma once

// modelo
#include <modelo/include/IAlmacenable.h>
#include <modelo/include/IContieneJson.h>

namespace visualizador
{
namespace modelo
{
namespace relaciones
{

class IRelaciones : public IAlmacenable, public IContieneJson
{
public:

    // CONSTRUCTORES

    IRelaciones(visualizador::aplicacion::ID* id_entidad = NULL, std::string grupo = "");
    IRelaciones(IJson * contenido, visualizador::aplicacion::ID* id_entidad = NULL, std::string grupo = "");
    virtual ~IRelaciones();

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
};

