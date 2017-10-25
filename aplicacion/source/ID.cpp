#include <aplicacion/include/ID.h>

using namespace visualizador::aplicacion;

// CONSTRUCTORES

ID::ID()
{
}

ID::ID(unsigned long long int id) : id(id)
{
}

ID::~ID()
{
}

// METODOS

unsigned long long int ID::numero()
{
	return this->id;
}

ID * visualizador::aplicacion::ID::copia()
{
    return new ID(this->id);
}

std::string ID::string()
{
	return std::to_string(this->id);
}
