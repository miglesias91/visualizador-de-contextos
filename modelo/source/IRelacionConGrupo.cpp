#include <modelo/include/IRelacionConGrupo.h>

// stl
#include <algorithm>

using namespace visualizador::modelo::relaciones;
using namespace visualizador;

IRelacionConGrupo::IRelacionConGrupo() : IContieneJson(), IHashable()
{
}

IRelacionConGrupo::~IRelacionConGrupo()
{
    for (std::vector<aplicacion::ID*>::iterator it = this->ids_grupo.begin(); it != this->ids_grupo.end(); it++)
    {
        delete *it;
        *it = NULL;
    }
}

// GETTERS

std::vector<aplicacion::ID*> IRelacionConGrupo::getIdsGrupo()
{
    return this->ids_grupo;
}

std::vector<unsigned long long int> IRelacionConGrupo::getIdsGrupoComoUint()
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

bool IRelacionConGrupo::existeRelacion(unsigned long long int id)
{
    aplicacion::ID * id_aux = new aplicacion::ID(id);
    
    bool existe = this->existeRelacion(id_aux);

    delete id_aux;

    return existe;
}

bool IRelacionConGrupo::existeRelacion(aplicacion::ID * id)
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

bool IRelacionConGrupo::agregarRelacion(unsigned long long int id)
{
    aplicacion::ID * nuevo_id = new aplicacion::ID(id);
    if (false == this->agregarRelacion(nuevo_id))
    {
        delete nuevo_id;
        return false;
    }
    return true;
}

bool IRelacionConGrupo::agregarRelacion(aplicacion::ID * id)
{
    if (this->existeRelacion(id))
    {
        return false;
    }

    this->ids_grupo.push_back(id);

    return true;
}

// metodos de IHashable

unsigned int IRelacionConGrupo::hashcode()
{
    std::string string_ids = "";

    std::sort(this->ids_grupo.begin(), this->ids_grupo.end(), aplicacion::ID::comparador);

    for (std::vector<aplicacion::ID*>::iterator it = this->ids_grupo.begin(); it != this->ids_grupo.end(); it++)
    {
        string_ids += (*it)->string();
    }

    return IHashable::hashearString(string_ids);
}
