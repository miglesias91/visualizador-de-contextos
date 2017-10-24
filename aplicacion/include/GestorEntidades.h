#pragma once

// stl
#include <vector>

// aplicacion
#include <almacenamiento/include/IAdministradorAlmacenamiento.h>

// modelo
#include <modelo/include/Termino.h>

namespace visualizador
{
namespace aplicacion
{
// Gestor logico de entidades. Realiza altas, bajas y modificaciones logicas de las entidades, y luego refleja los datos en la bd.
class GestorEntidades
{
public:
    GestorEntidades();

    ~GestorEntidades();

	std::vector<visualizador::modelo::Termino*> gestionarTerminos();

    //static bool almacenar(visualizador::modelo::IEntidad * entidad);

    //static bool almacenar(std::vector<visualizador::modelo::IEntidad*> entidades);

    //static bool eliminar(visualizador::modelo::IEntidad * entidad);

    //static bool eliminar(std::vector<visualizador::modelo::IEntidad*> entidades);

    //static bool recuperar(visualizador::modelo::IEntidad * entidad);

    // chequea que existe el termino en la lista de terminos de la ui.
    bool existe(visualizador::modelo::IEntidad* entidad_a_chequear);

    // almacena logicamente el termino.
    void almacenar(visualizador::modelo::IEntidad* entidad_a_almacenar);

    // elimina logicamente el termino.
    void eliminar(visualizador::modelo::IEntidad* entidad_a_eliminar);

private:

    // lista de terminos que SI ESTAN en la bd y figuran en la lista. se usa para operar logicamente.
    std::vector<visualizador::modelo::IEntidad*> entidades_existentes;

    // lista de terminos que NO ESTAN en la bd y se quieren agregar. se usa para operar logicamente.
    std::vector<visualizador::modelo::IEntidad*> entidades_a_almacenar;

    // lista de terminos que SI ESTAN en la bd y se quieren eliminar. se usa para operar logicamente.
    std::vector<visualizador::modelo::IEntidad*> entidades_a_eliminar;

    std::vector<visualizador::modelo::IEntidad*>::iterator entidades_it;
};
};
};

