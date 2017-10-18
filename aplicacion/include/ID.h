#pragma once

// stl
#include <string>

// aplicacion
#include <aplicacion/include/GestorIDs.h>

namespace visualizador
{
namespace aplicacion
{

class GestorIDs;

class ID
{
public:

	ID();
	ID(unsigned long long int id);
	virtual ~ID();

	unsigned long long int numero();

	std::string string();

private:

	unsigned long long int id;

	friend class GestorIDs;
};

};
};

