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

class RelacionConGrupo : public IHashable
{
public:
    
    // CONSTRUCTORES

    RelacionConGrupo();
    virtual ~RelacionConGrupo();

    // GETTERS
    
    virtual std::vector<aplicacion::ID*> getIdsGrupo();

    virtual std::vector<unsigned long long int> getIdsGrupoComoUint();

    // SETTERS

    // METODOS

    virtual bool existeRelacion(unsigned long long int id);

    virtual bool existeRelacion(aplicacion::ID * id);

    virtual bool agregarRelacion(unsigned long long int id);

    virtual bool agregarRelacion(aplicacion::ID * id);

    virtual bool eliminarRelacion(unsigned long long int id);

    virtual bool eliminarRelacion(aplicacion::ID * id);

    virtual bool actualizarRelacion(unsigned long long int id_nuevo, unsigned long long int id_viejo);

    virtual bool actualizarRelacion(aplicacion::ID * id_nuevo, aplicacion::ID * id_viejo);

    // metodos de IHashable

    virtual unsigned int hashcode();

private:

    static std::hash<std::string> hasher;

    std::vector<aplicacion::ID*> ids_grupo;
};

};
};
};

