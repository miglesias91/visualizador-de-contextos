#include <modelo/include/IJson.h>

using namespace visualizador::modelo;

// stl
#include <iostream>
#include <sstream>

// rapidjson
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/prettywriter.h>

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

rapidjson::Document IJson::documento_alocador;

IJson::IJson() : valor(new rapidjson::Value(rapidjson::kObjectType))
{
}

IJson::IJson(rapidjson::Value* valor) : valor(valor)
{
}

IJson::IJson(std::string json) : valor(NULL)
{
	rapidjson::Document* documento = new rapidjson::Document();
	documento->Parse(json.c_str());

	this->valor = new rapidjson::Value(*documento, documento_alocador.GetAllocator());

	delete documento;
}

IJson::~IJson()
{
	delete this->valor;
	this->valor = NULL;
}

void IJson::reset()
{
	if (NULL != this->valor)
	{
		delete this->valor;
	}

	this->valor = new rapidjson::Value(rapidjson::kObjectType);
}

void IJson::agregarAtributoValor(std::string clave, std::string valor)
{
	rapidjson::Document::AllocatorType* alocador = &documento_alocador.GetAllocator();

	rapidjson::Value tag(clave.c_str(), *alocador);
	rapidjson::Value json_valor(valor.c_str(), *alocador);
	this->valor->AddMember(tag, json_valor, *alocador);
}

void IJson::agregarAtributoValor(std::string clave, unsigned int valor)
{
	rapidjson::Document::AllocatorType* alocador = &documento_alocador.GetAllocator();

	rapidjson::Value tag(clave.c_str(), *alocador);
	rapidjson::Value json_valor(valor);
	this->valor->AddMember(tag, json_valor, *alocador);
}

void IJson::agregarAtributoArray(std::string clave, std::vector<unsigned long long int> array_valores)
{
	rapidjson::Document::AllocatorType* alocador = &documento_alocador.GetAllocator();

	rapidjson::Value json_valores(rapidjson::kArrayType);

	for (std::vector<unsigned long long int>::iterator it = array_valores.begin(); it != array_valores.end(); it++)
	{
		unsigned long long int valor = (*it);
		json_valores.PushBack(valor, *alocador);
	}

	rapidjson::Value tag(clave.c_str(), *alocador);
	this->valor->AddMember(tag, json_valores, *alocador);
}

void IJson::agregarAtributoArray(std::string clave, std::vector<std::string> array_valores)
{
	rapidjson::Document::AllocatorType* alocador = &documento_alocador.GetAllocator();

	rapidjson::Value json_valores(rapidjson::kArrayType);

	for (std::vector<std::string>::iterator it = array_valores.begin(); it != array_valores.end(); it++)
	{
		rapidjson::Value valor((*it).c_str(), *alocador);
		json_valores.PushBack(valor, *alocador);
	}

	rapidjson::Value tag(clave.c_str(), *alocador);
	this->valor->AddMember(tag, json_valores, *alocador);
}

void IJson::agregarAtributoJson(std::string clave, IJson * json)
{
	rapidjson::Document::AllocatorType* alocador = &documento_alocador.GetAllocator();

	rapidjson::Value tag(clave.c_str(), *alocador);
	this->valor->AddMember(tag, *json->getValor(), *alocador);
}

unsigned long long int IJson::getAtributoValorUint(std::string clave)
{
	unsigned long long int valor = (*this->valor)[clave.c_str()].GetUint64();

	return valor;
}

std::string IJson::getAtributoValorString(std::string clave)
{
	std::string valor = (*this->valor)[clave.c_str()].GetString();

	return valor;
}

IJson * IJson::getAtributoValorJson(std::string clave)
{
	rapidjson::Value* valor = &(*this->valor)[clave.c_str()];

	rapidjson::Value* valor_nuevo = new rapidjson::Value(rapidjson::kObjectType);

	valor_nuevo->CopyFrom(*valor, documento_alocador.GetAllocator());

	IJson* json = new IJson(valor_nuevo);

	return json;
}

std::vector<unsigned long long int> IJson::getAtributoArrayUint(std::string clave)
{
	std::vector<unsigned long long int> valores;

	rapidjson::Value* vector = &(*this->valor)[clave.c_str()];

	for (rapidjson::Value::ValueIterator it = vector->Begin(); it != vector->End(); it++)
	{
		unsigned long long int valor = it->GetUint64();
		valores.push_back(valor);
	}

	return valores;
}

std::vector<std::string> IJson::getAtributoArrayString(std::string clave)
{
	std::vector<std::string> valores;

	rapidjson::Value* vector = &(*this->valor)[clave.c_str()];

	for (rapidjson::Value::ValueIterator it = vector->Begin(); it != vector->End(); it++)
	{
		std::string valor = it->GetString();
		valores.push_back(valor);
	}

	return valores;
}

void IJson::setValor(rapidjson::Value * valor)
{
	this->valor = valor;
}

rapidjson::Value* IJson::getValor()
{
	return this->valor;
}

std::string IJson::jsonString()
{
	std::stringstream sstream;
	rapidjson::OStreamWrapper osw(sstream);

	rapidjson::Writer<rapidjson::OStreamWrapper> writer(osw);
	this->getValor()->Accept(writer);

	writer.Flush();

	return sstream.str();
}