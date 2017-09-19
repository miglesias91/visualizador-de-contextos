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

	unsigned long long int numero();

private:

	ID();
	ID(unsigned long long int id);

	virtual ~ID();

	unsigned long long int id;

	friend class GestorIDs;
};

};
};

