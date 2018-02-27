#pragma once

// stl
#include <string>
#include <vector>

// herramientas
#include <utiles/include/ID.h>
#include <utiles/include/IHashable.h>

using namespace visualizador;

namespace visualizador
{
namespace modelo
{
namespace relaciones
{

class RelacionConGrupo : public herramientas::utiles::IHashable
{
public:
    
    // CONSTRUCTORES

    RelacionConGrupo();
    virtual ~RelacionConGrupo();

    // GETTERS
    
    virtual std::vector<herramientas::utiles::ID*> getIdsGrupo();

    virtual std::vector<unsigned long long int> getIdsGrupoComoUint();

    // SETTERS

    // METODOS

    virtual bool existeRelacion(unsigned long long int id);

    virtual bool existeRelacion(herramientas::utiles::ID * id);

    virtual bool agregarRelacion(unsigned long long int id);

    virtual bool agregarRelacion(herramientas::utiles::ID * id);

    virtual bool eliminarRelacion(unsigned long long int id);

    virtual bool eliminarRelacion(herramientas::utiles::ID * id);

    virtual bool actualizarRelacion(unsigned long long int id_nuevo, unsigned long long int id_viejo);

    virtual bool actualizarRelacion(herramientas::utiles::ID * id_nuevo, herramientas::utiles::ID * id_viejo);

    // metodos de IHashable

    virtual unsigned long long int hashcode();

private:

    static std::hash<std::string> hasher;

    std::vector<herramientas::utiles::ID*> ids_grupo;
};

};
};
};

