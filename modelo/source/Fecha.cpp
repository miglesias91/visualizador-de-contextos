#include <modelo/include/Fecha.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

// CONSTRUCTORES

Fecha::Fecha()
{
}

Fecha::Fecha(std::string etiqueta, unsigned int dia, unsigned int mes, unsigned int anio) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoFecha()), dia(dia), mes(mes), anio(anio)
{
}

Fecha::~Fecha()
{
}

// METODOS

void Fecha::crearContenido()
{
	rapidjson::Value* json_contenido = new rapidjson::Value(rapidjson::kObjectType);

	rapidjson::Document::AllocatorType* alocador = visualizador::aplicacion::ConfiguracionAplicacion::getAlocador();

	rapidjson::Value tag_dia("dia", *alocador);
	rapidjson::Value dia(this->getDia());
	json_contenido->AddMember(tag_dia, dia, *alocador);

	rapidjson::Value tag_mes("mes", *alocador);
	rapidjson::Value mes(this->getMes());
	json_contenido->AddMember(tag_mes, mes, *alocador);

	rapidjson::Value tag_anio("anio", *alocador);
	rapidjson::Value anio(this->getAnio());
	json_contenido->AddMember(tag_anio, anio, *alocador);

	this->getContenido()->setValor(json_contenido);
}

// GETTERS

unsigned int Fecha::getDia()
{
	return this->dia;
}

unsigned int Fecha::getMes()
{
	return this->mes;
}

unsigned int Fecha::getAnio()
{
	return this->anio;
}

std::string Fecha::getStringDia()
{
	return std::to_string(this->dia);
}

std::string Fecha::getStringMes()
{
	return std::to_string(this->mes);
}

std::string Fecha::getStringAnio()
{
	return std::to_string(this->anio);
}

// SETTERS

void Fecha::setDia(std::string dia)
{
	this->dia = std::stoi(dia);
}

void Fecha::setMes(std::string mes)
{
	this->mes = std::stoi(mes);
}

void Fecha::setAnio(std::string anio)
{
	this->anio = std::stoi(anio);
}

void Fecha::setDia(unsigned int dia)
{
	this->dia = dia;
}

void Fecha::setMes(unsigned int mes)
{
	this->mes = mes;
}

void Fecha::setAnio(unsigned int anio)
{
	this->anio = anio;
}
