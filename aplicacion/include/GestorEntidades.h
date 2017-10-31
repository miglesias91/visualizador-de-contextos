#pragma once

// stl
#include <vector>

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>
#include <aplicacion/include/IAdministradorAplicacion.h>

// modelo
#include <modelo/include/Termino.h>

// almacenamiento
#include <almacenamiento/include/IAdministradorAlmacenamiento.h>

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

    //static bool almacenar(visualizador::modelo::IEntidad * entidad);

    //static bool almacenar(std::vector<visualizador::modelo::IEntidad*> entidades);

    //static bool eliminar(visualizador::modelo::IEntidad * entidad);

    //static bool eliminar(std::vector<visualizador::modelo::IEntidad*> entidades);

    //static bool recuperar(visualizador::modelo::IEntidad * entidad);

    template <class ENTIDAD>
    std::vector<ENTIDAD*> gestionar();

    template <class ENTIDAD>
    std::vector<ENTIDAD*> recuperar();

    template <class ENTIDAD>
    ENTIDAD* clonar(visualizador::modelo::IEntidad* entidad_a_clonar);

    // chequea que existe el termino en la lista de terminos de la ui.
    bool existe(visualizador::modelo::IEntidad* entidad_a_chequear);

    // almacena logicamente el termino.
    bool almacenar(visualizador::modelo::IEntidad* entidad_a_almacenar);

    // elimina logicamente el termino.
    void eliminar(visualizador::modelo::IEntidad* entidad_a_eliminar);

    bool guardarCambios();

private:

    // lista de terminos que SI ESTAN en la bd y figuran en la lista. se usa para operar logicamente.
    std::vector<visualizador::modelo::IEntidad*> entidades_existentes;

    // lista de terminos que NO ESTAN en la bd y se quieren agregar. se usa para operar logicamente.
    std::vector<visualizador::modelo::IEntidad*> entidades_a_almacenar;

    // lista de terminos que SI ESTAN en la bd y se quieren eliminar. se usa para operar logicamente.
    std::vector<visualizador::modelo::IEntidad*> entidades_a_eliminar;

    std::vector<visualizador::modelo::IEntidad*>::iterator entidades_it;

    IAdministradorAplicacion * admin_app;
    almacenamiento::IAdministradorAlmacenamiento * admin_bd;
};

template <class ENTIDAD>
std::vector<ENTIDAD*> GestorEntidades::gestionar()
{
    std::vector<almacenamiento::IAlmacenableClaveValor*> grupo;

    ENTIDAD entidad_para_obtener_prefijo;
    this->admin_bd->recuperarGrupo(entidad_para_obtener_prefijo.prefijoGrupo(), grupo);

    ENTIDAD* entidad_recuperada = NULL;
    std::vector<ENTIDAD*> entidades_recuperadas;
    for (std::vector<almacenamiento::IAlmacenableClaveValor*>::iterator it = grupo.begin(); it != grupo.end(); it++)
    {
        entidad_recuperada = new ENTIDAD();
        unsigned long long int id = std::stoull((*it)->getClave());
        entidad_recuperada->setId(new visualizador::aplicacion::ID(id));

        entidad_recuperada->parsearValorAlmacenable((*it)->getValor());
        this->entidades_existentes.push_back(entidad_recuperada);

        entidades_recuperadas.push_back(entidad_recuperada);
        delete *it;
    }
    grupo.clear();

    return entidades_recuperadas;
};


template <class ENTIDAD>
std::vector<ENTIDAD*> GestorEntidades::recuperar()
{
    std::vector<almacenamiento::IAlmacenableClaveValor*> grupo;

    ENTIDAD entidad_para_obtener_prefijo;
    this->admin_bd->recuperarGrupo(entidad_para_obtener_prefijo.prefijoGrupo(), grupo);

    ENTIDAD* entidad_recuperada = NULL;
    std::vector<ENTIDAD*> entidades_recuperadas;
    for (std::vector<almacenamiento::IAlmacenableClaveValor*>::iterator it = grupo.begin(); it != grupo.end(); it++)
    {
        entidad_recuperada = new ENTIDAD();
        unsigned long long int id = std::stoull((*it)->getClave());
        entidad_recuperada->setId(new visualizador::aplicacion::ID(id));

        entidad_recuperada->parsearValorAlmacenable((*it)->getValor());

        entidades_recuperadas.push_back(entidad_recuperada);
        delete *it;
    }
    grupo.clear();

    return entidades_recuperadas;
};

template <class ENTIDAD>
ENTIDAD* GestorEntidades::clonar(visualizador::modelo::IEntidad* entidad_a_clonar)
{
    visualizador::modelo::IEntidad* entidad_clonada = entidad_a_clonar->clonar();
    return static_cast<ENTIDAD*>(entidad_clonada);
}

};
};

