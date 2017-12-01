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
	IJson(rapidjson::Value* valor);
	IJson(std::string json);

	virtual ~IJson();

	// METODOS

	void reset();

	void agregarAtributoValor(std::string clave, std::string valor);
	void agregarAtributoValor(std::string clave, unsigned int valor);

	void agregarAtributoArray(std::string clave, std::vector<unsigned long long int> array_valores);
	void agregarAtributoArray(std::string clave, std::vector<std::string> array_valores);

	void agregarAtributoJson(std::string clave, IJson* json);

    IJson * clonar();

	// GETTERS

	unsigned long long int getAtributoValorUint(std::string clave);
	std::string getAtributoValorString(std::string clave);
	IJson* getAtributoValorJson(std::string clave);

	std::vector<unsigned long long int> getAtributoArrayUint(std::string clave);
	std::vector<std::string> getAtributoArrayString(std::string clave);

	rapidjson::Value* getValor();

	std::string jsonString();

	// SETTERS
	void setValor(rapidjson::Value* valor);

private:

	rapidjson::Value* valor;

    rapidjson::Document * documento_alocador;

    std::vector<IJson*> copia_atributos_json;
};
};
};

