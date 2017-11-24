#include <modelo/include/IRelacionConGrupo.h>

using namespace visualizador::modelo::relaciones;

IRelacionConGrupo::IRelacionConGrupo(unsigned long long int id_entidad, std::string grupo) : IContieneJson()
{
}

IRelacionConGrupo::~IRelacionConGrupo()
{
}

bool IRelacionConGrupo::agregarRelacion(aplicacion::ID * id)
{
    if (this->ids_relacionados.end() != std::find(this->ids_relacionados.begin(), this->ids_relacionados.end(), id))
    {// si ya contiene el id que se quiere agregar, entonces devuelvo false.
        return false;
    }

    this->ids_relacionados.push_back(id);

    return true;
}
