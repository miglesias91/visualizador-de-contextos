#pragma once

// stl
#include <vector>

// almacenamiento
#include <almacenamiento/include/IAdministradorAlmacenamiento.h>

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>
#include <aplicacion/include/GestorRelaciones.h>

// modelo
#include <modelo/include/IEntidad.h>

namespace visualizador
{
namespace aplicacion
{
// Gestor logico de entidades. Realiza altas, bajas y modificaciones logicas de las entidades, y luego refleja los datos en la bd.
class GestorEntidades
{
public:
    GestorEntidades();

    virtual ~GestorEntidades();

    // GETTERS

    std::vector<visualizador::modelo::IEntidad*> getEntidadesAAlmacenar();

    std::vector<visualizador::modelo::IEntidad*> getEntidadesAEliminar();

    // SETTERS

    // METODOS
    template <class ENTIDAD>
    void gestionar(std::vector<ENTIDAD*> entidades_a_gestionar);

    template <class ENTIDAD>
    std::vector<ENTIDAD*> gestionar();

    template <class ENTIDAD>
    std::vector<ENTIDAD*> recuperar();

    // clona la entidad devolviendo un puntero de la clase especifica de la entidad.
    // Similar al metodo "clonar" de cada entidad, solo que agrega el tipo de entidad indicado en <ENTIDAD>.
    template <class ENTIDAD>
    ENTIDAD* clonar(visualizador::modelo::IEntidad* entidad_a_clonar);

    // recupera la entidad junto con sus relaciones y el contenido de sus relaciones.
    bool recuperar(visualizador::modelo::IEntidad* entidad_a_recuperar);

    // chequea que existe el termino en la lista de terminos de la ui.
    bool existe(visualizador::modelo::IEntidad* entidad_a_chequear);

    // almacena logicamente el termino.
    bool almacenar(visualizador::modelo::IEntidad* entidad_a_almacenar);

    // modificar logicamente el termino.
    bool modificar(visualizador::modelo::IEntidad* entidad_a_modificar);

    // elimina logicamente el termino.
    bool eliminar(visualizador::modelo::IEntidad* entidad_a_eliminar);

    // devuelve el puntero a la entidad en caso que se encuentre en la lista de 'existentes' o de 'a almacenar'
    template <class ENTIDAD>
    ENTIDAD* encontrar(ENTIDAD* entidad_a_encontrar);

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
    GestorRelaciones gestor_relaciones;
};
template <class ENTIDAD>
void GestorEntidades::gestionar(std::vector<ENTIDAD*> entidades_a_gestionar)
{
    for (std::vector<ENTIDAD*>::iterator it = entidades_a_gestionar.begin(); it != entidades_a_gestionar.end(); it++)
    {
        this->entidades_existentes.push_back((*it)->clonar());
    }
};

template <class ENTIDAD>
std::vector<ENTIDAD*> GestorEntidades::gestionar()
{
    std::vector<ENTIDAD*> entidades_recuperadas;

    ENTIDAD entidad_para_obtener_prefijo;
    this->admin_app->recuperarGrupo<ENTIDAD>(entidad_para_obtener_prefijo.prefijoGrupo(), &entidades_recuperadas);

    for (std::vector<ENTIDAD*>::iterator it = entidades_recuperadas.begin(); it != entidades_recuperadas.end(); it++)
    {
        this->recuperar(*it);
        this->entidades_existentes.push_back(*it);
    }

    return entidades_recuperadas;
};

template <class ENTIDAD>
std::vector<ENTIDAD*> GestorEntidades::recuperar()
{
    std::vector<ENTIDAD*> entidades_recuperadas;

    ENTIDAD entidad_para_obtener_prefijo;
    this->admin_app->recuperarGrupo<ENTIDAD>(entidad_para_obtener_prefijo.prefijoGrupo(), &entidades_recuperadas);

    for (std::vector<ENTIDAD*>::iterator it = entidades_recuperadas.begin(); it != entidades_recuperadas.end(); it++)
    {
        this->recuperar(*it);
    }

    return entidades_recuperadas;
};

template <class ENTIDAD>
ENTIDAD* GestorEntidades::clonar(visualizador::modelo::IEntidad* entidad_a_clonar)
{
    visualizador::modelo::IEntidad* entidad_clonada = entidad_a_clonar->clonar();
    return static_cast<ENTIDAD*>(entidad_clonada);
}

template <class ENTIDAD>
ENTIDAD * GestorEntidades::encontrar(ENTIDAD * entidad_a_encontrar)
{
    for (this->entidades_it = this->entidades_existentes.begin(); this->entidades_it != this->entidades_existentes.end(); this->entidades_it++)
    {
        if ((*this->entidades_it)->hashcode() == entidad_a_encontrar->hashcode())
        {
            return static_cast<ENTIDAD*>(*this->entidades_it);
        }
    }

    for (this->entidades_it = this->entidades_a_almacenar.begin(); this->entidades_it != this->entidades_a_almacenar.end(); this->entidades_it++)
    {
        if ((*this->entidades_it)->hashcode() == entidad_a_encontrar->hashcode())
        {
            return static_cast<ENTIDAD*>(*this->entidades_it);
        }
    }

    return NULL;
}

};
};

