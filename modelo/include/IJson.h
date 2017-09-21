#pragma once

// stl
#include <vector>

// rapidjson
#include <rapidjson/document.h>

namespace visualizador
{
namespace modelo
{

class IJson
{
public:
	IJson();
	virtual ~IJson();

	// METODOS

	void reset();

	void agregarAtributoValor(std::string clave, std::string valor);
	void agregarAtributoValor(std::string clave, unsigned int valor);

	void agregarAtributoArray(std::string clave, std::vector<unsigned  long long int> array_valores);
	void agregarAtributoArray(std::string clave, std::vector<std::string> array_valores);

	// GETTERS

	rapidjson::Value* getValor();

	std::string jsonString();

	// SETTERS
	void setValor(rapidjson::Value* valor);

private:

	rapidjson::Value* valor;

	static rapidjson::Document documento_alocador;

};
};
};

