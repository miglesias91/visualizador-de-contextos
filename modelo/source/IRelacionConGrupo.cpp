#include <modelo/include/IRelacionConGrupo.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador;

IRelacionConGrupo::IRelacionConGrupo(unsigned long long int id_entidad, std::string grupo) : IContieneJson()
{
}

IRelacionConGrupo::~IRelacionConGrupo()
{
}

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

bool IRelacionConGrupo::agregarRelacion(aplicacion::ID * id)
{
    if (this->ids_grupo.end() != std::find(this->ids_grupo.begin(), this->ids_grupo.end(), id))
    {// si ya contiene el id que se quiere agregar, entonces devuelvo false.
        return false;
    }

    this->ids_grupo.push_back(id);

    return true;
}
