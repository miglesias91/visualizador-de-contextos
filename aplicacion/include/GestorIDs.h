#pragma once

// aplicacion
#include <aplicacion/include/ID.h>

namespace visualizador
{
namespace aplicacion
{

class ID;

class GestorIDs
{
public:

	// GETTERS

	static ID* nuevoID();
	
	static unsigned long long int getIdActual();

	// SETTERS

	static void setIdActual(unsigned long long int id_mas_alto);

private:

	GestorIDs();
	virtual ~GestorIDs();

	// 0 <= id_mas_alto < 18.446744.073709.551616
	static unsigned long long int id_mas_alto;
};

};
};

