#include <modelo/include/RelacionConGrupo.h>

// stl
#include <algorithm>

using namespace visualizador::modelo::relaciones;
using namespace visualizador;

RelacionConGrupo::RelacionConGrupo() : IHashable()
{
}

RelacionConGrupo::~RelacionConGrupo()
{
    for (std::vector<herramientas::utiles::ID*>::iterator it = this->ids_grupo.begin(); it != this->ids_grupo.end(); it++)
    {
        delete *it;
        *it = NULL;
    }
}

// GETTERS

std::vector<herramientas::utiles::ID*> RelacionConGrupo::getIdsGrupo()
{
    return this->ids_grupo;
}

std::vector<unsigned long long int> RelacionConGrupo::getIdsGrupoComoUint()
{
    std::vector<unsigned long long int> ids;
    for (std::vector<herramientas::utiles::ID*>::iterator it = this->ids_grupo.begin(); it != this->ids_grupo.end(); it++)
    {
        ids.push_back((*it)->numero());
    }

    return ids;
}

// SETTERS

// METODOS

bool RelacionConGrupo::existeRelacion(unsigned long long int id)
{
    herramientas::utiles::ID * id_aux = new herramientas::utiles::ID(id);
    
    bool existe = this->existeRelacion(id_aux);

    delete id_aux;

    return existe;
}

bool RelacionConGrupo::existeRelacion(herramientas::utiles::ID * id)
{
    for (std::vector<herramientas::utiles::ID*>::iterator it = this->ids_grupo.begin(); it != this->ids_grupo.end(); it++)
    {
        if ((*it)->numero() == id->numero())
        {// si ya contiene el numero, entonces no agrego la relacion y devuelvo 'false'.
            return true;
        }
    }

    return false;
}

bool RelacionConGrupo::agregarRelacion(unsigned long long int id)
{
    herramientas::utiles::ID * nuevo_id = new herramientas::utiles::ID(id);

    bool agregado = this->agregarRelacion(nuevo_id);

    delete nuevo_id;

    return agregado;

    if (false == this->agregarRelacion(nuevo_id))
    {
        delete nuevo_id;
        return false;
    }
    return true;
}

bool RelacionConGrupo::agregarRelacion(herramientas::utiles::ID * id)
{
    if (this->existeRelacion(id))
    {
        return false;
    }

    this->ids_grupo.push_back(id->copia());

    return true;
}

bool RelacionConGrupo::eliminarRelacion(unsigned long long int id)
{
    herramientas::utiles::ID * id_aux = new herramientas::utiles::ID(id);

    bool existe = this->eliminarRelacion(id_aux);

    delete id_aux;

    return existe;
}

bool RelacionConGrupo::eliminarRelacion(herramientas::utiles::ID * id)
{
    for (std::vector<herramientas::utiles::ID*>::iterator it = this->ids_grupo.begin(); it != this->ids_grupo.end(); it++)
    {
        if ((*it)->numero() == id->numero())
        {// si coincide, entonces lo elimino
            delete *it;
            this->ids_grupo.erase(it);
            return true;
        }
    }

    return false;
}

bool RelacionConGrupo::actualizarRelacion(unsigned long long int id_nuevo, unsigned long long int id_viejo)
{
    herramientas::utiles::ID * id_aux_nuevo = new herramientas::utiles::ID(id_nuevo);
    herramientas::utiles::ID * id_aux_viejo = new herramientas::utiles::ID(id_viejo);

    bool actualizacion = this->actualizarRelacion(id_aux_nuevo, id_aux_viejo);

    delete id_aux_nuevo;
    delete id_aux_viejo;

    return actualizacion;
}

bool RelacionConGrupo::actualizarRelacion(herramientas::utiles::ID * id_nuevo, herramientas::utiles::ID * id_viejo)
{
    if (NULL == id_viejo)
    {// si no hay id_viejo entonces agrego el nuevo de una.
        return this->agregarRelacion(id_nuevo);
    }

    if (false == this->eliminarRelacion(id_viejo))
    {
        return false;
    }
    
    return this->agregarRelacion(id_nuevo);
}

// metodos de IHashable

unsigned int RelacionConGrupo::hashcode()
{
    std::string string_ids = "";

    std::sort(this->ids_grupo.begin(), this->ids_grupo.end(), herramientas::utiles::ID::comparador);

    for (std::vector<herramientas::utiles::ID*>::iterator it = this->ids_grupo.begin(); it != this->ids_grupo.end(); it++)
    {
        string_ids += (*it)->string();
    }

    return IHashable::hashear(string_ids);
}
