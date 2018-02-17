#pragma once

// stl
#include <string>

// aplicacion
// #include <aplicacion/include/ID.h>

// herramientas
#include <utiles/include/ID.h>
#include <utiles/include/GestorIDs.h>

// modelo
#include <modelo/include/IHashable.h>

namespace visualizador
{
namespace modelo
{

class IAlmacenable : public IHashable
{
public:
    IAlmacenable(std::string grupo = "");
    virtual ~IAlmacenable();

    // GETTERS

    virtual herramientas::utiles::ID* getId();

    virtual std::string getGrupo();

    virtual std::string getValorAlmacenable() = 0;
    
    static herramientas::utiles::GestorIDs * getGestorIDs();

    // SETTERS

    virtual void setId(herramientas::utiles::ID* id);

    virtual void setGrupo(std::string grupo);

    // METODOS

    virtual void asignarNuevoId();

    virtual void parsearValorAlmacenable(std::string valor_almacenable) = 0;

    virtual std::string prefijoGrupo() = 0;

    static bool comparador(IAlmacenable* a, IAlmacenable* b);

private:

    // ATRIBUTOS

    static herramientas::utiles::GestorIDs gestor_ids;

    //herramientas::utiles::ID* id;
    herramientas::utiles::ID* id;
    std::string grupo;

};
};
};

