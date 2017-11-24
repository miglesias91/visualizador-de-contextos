#include "IRelacion.h"

using namespace visualizador::modelo;

IRelacion::IRelacion(unsigned long long int id_entidad, std::string grupo) : IAlmacenable(grupo), IContieneJson()
{
}

IRelacion::~IRelacion()
{
}

bool IRelacion::agregarRelacion(aplicacion::ID * id)
{
    if (this->ids_relacionados.end() != std::find(this->ids_relacionados.begin(), this->ids_relacionados.end(), id))
    {// si ya contiene el id que se quiere agregar, entonces devuelvo false.
        return false;
    }

    this->ids_relacionados.push_back(id);

    return true;
}
