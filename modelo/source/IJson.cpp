#include <modelo/include/IJson.h>

using namespace visualizador::modelo;

// stl
#include <sstream>

// rapidjson
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/prettywriter.h>

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

rapidjson::Document IJson::documento_alocador;

IJson::IJson()
{
}

IJson::~IJson()
{
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