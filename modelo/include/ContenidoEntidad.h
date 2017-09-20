#pragma once

// rapidjson
#include <rapidjson/document.h>

namespace visualizador
{
namespace modelo
{

class ContenidoEntidad
{
public:

	// CONSTRUCTORES

	ContenidoEntidad();
	virtual ~ContenidoEntidad();

	// GETTERS

	rapidjson::Value* getValor();

	std::string jsonString();

	// SETTERS

	void setValor(rapidjson::Value* valor);

private:

	rapidjson::Value* valor;

};

};
};

