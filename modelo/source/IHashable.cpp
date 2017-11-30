#include <modelo/include/IHashable.h>

using namespace visualizador::modelo;

std::hash<std::string> IHashable::hasher_string;
std::hash<unsigned int> IHashable::hasher_uint;

IHashable::IHashable()
{
}

IHashable::~IHashable()
{
}

unsigned int IHashable::hashear(std::string string_a_hashear)
{
    return hasher_string(string_a_hashear);
}

unsigned int IHashable::hashear(unsigned int uint_a_hashear)
{
    return hasher_uint(uint_a_hashear);
}
