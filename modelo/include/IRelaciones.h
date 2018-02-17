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

    //IRelaciones(herramientas::utiles::ID* id_entidad, std::string grupo, IJson * json = new IJson());
    IRelaciones(herramientas::utiles::ID* id_entidad, std::string grupo, IJson * json = new IJson());
    virtual ~IRelaciones();

    // GETTERS

    virtual std::string getValorAlmacenable() = 0;

    // SETTERS

    // METODOS

    virtual IRelaciones * clonar() = 0;

    // metodos de IAlmacenable

    virtual void parsearValorAlmacenable(std::string valor_almacenable) = 0;

    virtual std::string prefijoGrupo() = 0;

    virtual unsigned int hashcode() = 0;

    // CONSULTAS

private:

};

};
};
};

