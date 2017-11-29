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
    for (std::vector<aplicacion::ID*>::iterator it = this->ids_grupo.begin(); it != this->ids_grupo.end(); it++)
    {
        delete *it;
        *it = NULL;
    }
}

// GETTERS

std::vector<aplicacion::ID*> RelacionConGrupo::getIdsGrupo()
{
    return this->ids_grupo;
}

std::vector<unsigned long long int> RelacionConGrupo::getIdsGrupoComoUint()
{
    std::vector<unsigned long long int> ids;
    for (std::vector<aplicacion::ID*>::iterator it = this->ids_grupo.begin(); it != this->ids_grupo.end(); it++)
    {
        ids.push_back((*it)->numero());
    }

    return ids;
}

// SETTERS

// METODOS

bool RelacionConGrupo::existeRelacion(unsigned long long int id)
{
    aplicacion::ID * id_aux = new aplicacion::ID(id);
    
    bool existe = this->existeRelacion(id_aux);

    delete id_aux;

    return existe;
}

bool RelacionConGrupo::existeRelacion(aplicacion::ID * id)
{
    for (std::vector<aplicacion::ID*>::iterator it = this->ids_grupo.begin(); it != this->ids_grupo.end(); it++)
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
    aplicacion::ID * nuevo_id = new aplicacion::ID(id);
    if (false == this->agregarRelacion(nuevo_id))
    {
        delete nuevo_id;
        return false;
    }
    return true;
}

bool RelacionConGrupo::agregarRelacion(aplicacion::ID * id)
{
    if (this->existeRelacion(id))
    {
        return false;
    }

    this->ids_grupo.push_back(id);

    return true;
}

bool RelacionConGrupo::eliminarRelacion(unsigned long long int id)
{
    aplicacion::ID * id_aux = new aplicacion::ID(id);

    bool existe = this->eliminarRelacion(id_aux);

    delete id_aux;

    return existe;
}

bool RelacionConGrupo::eliminarRelacion(aplicacion::ID * id)
{
    for (std::vector<aplicacion::ID*>::iterator it = this->ids_grupo.begin(); it != this->ids_grupo.end(); it++)
    {
        if ((*it)->numero() == id->numero())
        {// si coincide, entonces lo elimino
            this->ids_grupo.erase(it);
            return true;
        }
    }

    return false;
}

// metodos de IHashable

unsigned int RelacionConGrupo::hashcode()
{
    std::string string_ids = "";

    std::sort(this->ids_grupo.begin(), this->ids_grupo.end(), aplicacion::ID::comparador);

    for (std::vector<aplicacion::ID*>::iterator it = this->ids_grupo.begin(); it != this->ids_grupo.end(); it++)
    {
        string_ids += (*it)->string();
    }

    return IHashable::hashearString(string_ids);
}
