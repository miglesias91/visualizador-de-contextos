#pragma once

// stl
#include <string>
#include <vector>

// aplicacion
#include <aplicacion/include/ID.h>

// modelo
#include <modelo/include/IContieneJson.h>
#include <modelo/include/IHashable.h>

using namespace visualizador;

namespace visualizador
{
namespace modelo
{
namespace relaciones
{

class IRelacionConGrupo : public IContieneJson, public IHashable
{
public:
    
    // CONSTRUCTORES

    IRelacionConGrupo();
    virtual ~IRelacionConGrupo();

    // GETTERS
    
    virtual std::vector<aplicacion::ID*> getIdsGrupo();

    virtual std::vector<unsigned long long int> getIdsGrupoComoUint();

    // SETTERS

    // METODOS

    virtual bool existeRelacion(unsigned long long int id);

    virtual bool existeRelacion(aplicacion::ID * id);

    virtual bool agregarRelacion(unsigned long long int id);

    // 'id' debe ser una COPIA, cuando se destruye la instancia se destruyen los ids que contiene la relacion.
    virtual bool agregarRelacion(aplicacion::ID * id);

    // metodos de IHashable

    virtual unsigned int hashcode();

private:

    static std::hash<std::string> hasher;

    std::vector<aplicacion::ID*> ids_grupo;
};

};
};
};

