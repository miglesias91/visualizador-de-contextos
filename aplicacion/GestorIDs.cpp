#include <aplicacion/GestorIDs.h>

using namespace visualizador::aplicacion;

unsigned long long int GestorIDs::id_mas_alto = 0;

// CONSTRUCTORES

GestorIDs::GestorIDs()
{
}

GestorIDs::~GestorIDs()
{
}

// SETTERS

void GestorIDs::setIdActual(unsigned long long int id_mas_alto)
{
	GestorIDs::id_mas_alto = id_mas_alto;
}

// METODOS

ID * GestorIDs::nuevoID()
{
	ID* id_nuevo = new ID(id_mas_alto);
	id_mas_alto++;
	return id_nuevo;
}

