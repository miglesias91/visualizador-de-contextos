#include <modelo/include/Fecha.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

// CONSTRUCTORES

std::hash<unsigned int> Fecha::hasher;

Fecha::Fecha(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoFecha()), dia(0), mes(0), anio(0)
{
}

Fecha::Fecha(unsigned int dia, unsigned int mes, unsigned int anio, std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoFecha()), dia(dia), mes(mes), anio(anio)
{
}

Fecha::~Fecha()
{
}

// METODOS

void Fecha::crearContenido()
{
	ContenidoEntidad* contenido = this->getContenido();
	contenido->reset();

	contenido->agregarAtributoValor("dia", this->getDia());
	contenido->agregarAtributoValor("mes", this->getMes());
	contenido->agregarAtributoValor("anio", this->getAnio());
}

void Fecha::parsearContenido(IJson* contenido)
{
	unsigned long long int dia = contenido->getAtributoValorUint("dia");
	unsigned long long int mes = contenido->getAtributoValorUint("mes");
	unsigned long long int anio = contenido->getAtributoValorUint("anio");

	this->dia = dia;
	this->mes = mes;
	this->anio = anio;
}

std::string Fecha::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoFecha();
}

unsigned int Fecha::hashcode()
{
	return hasher(this->dia) + hasher(this->mes) + hasher(this->anio);
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
