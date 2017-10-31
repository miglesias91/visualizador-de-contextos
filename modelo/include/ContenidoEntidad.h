#pragma once

// modelo
#include <modelo/include/IJson.h>

namespace visualizador
{
namespace modelo
{

class ContenidoEntidad : public IJson
{
public:

	// CONSTRUCTORES

	ContenidoEntidad();
	virtual ~ContenidoEntidad();

	// METODOS

    ContenidoEntidad * clonar();

	// GETTERS

	// SETTERS

private:

};

};
};

