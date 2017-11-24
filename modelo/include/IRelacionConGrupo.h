#pragma once

// stl
#include <string>
#include <vector>

// aplicacion
#include <aplicacion/include/ID.h>

// modelo
#include <modelo/include/IAlmacenable.h>
#include <modelo/include/IContieneJson.h>

using namespace visualizador;

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
    
    virtual std::vector<aplicacion::ID*> getIdsGrupo();

    virtual std::vector<unsigned long long int> getIdsGrupoComoUint();

    // SETTERS

    // METODOS

    // 'id' debe ser una COPIA, cuando se destruye la instancia se destruyen los ids que contiene la relacion.
    virtual bool agregarRelacion(aplicacion::ID * id);

    // metodos de IContienJson

    virtual void crearContenido() = 0;

    // parsea el contenido JSON, y devuelve 'true' si el contenido es correcto, devuelve 'false' si el contenido parseado no esta correcto.
    virtual bool parsearContenido(IJson * contenido) = 0;

private:

    std::vector<aplicacion::ID*> ids_grupo;
};

};
};
};

