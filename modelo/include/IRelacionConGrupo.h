#pragma once

// stl
#include <string>
#include <vector>

// aplicacion
#include <aplicacion/include/ID.h>

// modelo
#include <modelo/include/IAlmacenable.h>
#include <modelo/include/IContieneJson.h>

namespace visualizador
{
namespace modelo
{
namespace relaciones
{

class IRelacionConGrupo : public IContieneJson
{
public:
    
    // CONSTRUCTORES

    IRelacionConGrupo(unsigned long long int id_entidad = 0, std::string grupo = "");
    virtual ~IRelacionConGrupo();

    // GETTERS
    
    virtual std::string getValorAlmacenable() = 0;

    // SETTERS

    // METODOS

    virtual void parsearValorAlmacenable(std::string valor_almacenable) = 0;

    virtual std::string prefijoGrupo() = 0;

    virtual unsigned int hashcode() = 0;

    // 'id' debe ser una COPIA, cuando se destruye la instancia se destruyen los ids que contiene la relacion.
    virtual bool agregarRelacion(aplicacion::ID * id);

private:

    std::vector<aplicacion::ID*> ids_relacionados;
};

};
};
};

