#include <modelo/Fecha.h>

using namespace visualizador::modelo;

// CONSTRUCTORES

Fecha::Fecha()
{
}

Fecha::Fecha(unsigned int dia, unsigned int mes, unsigned int anio) : dia(dia), mes(mes), anio(anio)
{
}

Fecha::~Fecha()
{
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
