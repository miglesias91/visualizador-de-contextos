#pragma once

// modelo
#include <modelo/include/IJson.h>

namespace visualizador
{
namespace modelo
{

class ContenidoJson : public IJson
{
public:

	// CONSTRUCTORES

	ContenidoJson();
	virtual ~ContenidoJson();

	// METODOS

    ContenidoJson * clonar();

	// GETTERS

	// SETTERS

private:

};

};
};

