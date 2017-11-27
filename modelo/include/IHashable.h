#pragma once

// stl
#include <string>

namespace visualizador
{
namespace modelo
{

class IHashable
{
public:

    IHashable();
    virtual ~IHashable();

    virtual unsigned int hashcode() = 0;

    static unsigned int hashearString(std::string string_a_hashear);

    static unsigned int hashearUInt(unsigned int uint_a_hashear);

private:

    static std::hash<std::string> hasher_string;
    static std::hash<unsigned int> hasher_uint;

};

};
};


