#include <modelo/include/Fecha.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

std::string Fecha::nombres_meses[] = { "enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto", "septiembre", "octubre", "noviembre", "diciembre" };

// CONSTRUCTORES

Fecha::Fecha(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoFecha(), NULL), dia(0), mes(0), anio(0), relaciones_fecha(NULL)
{
    this->relaciones_fecha = new relaciones::RelacionesFecha();
    this->setRelaciones(this->relaciones_fecha);
}

Fecha::Fecha(unsigned int dia, unsigned int mes, unsigned int anio, std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoFecha(), NULL), dia(dia), mes(mes), anio(anio)
{
    this->relaciones_fecha = new relaciones::RelacionesFecha();
    this->setRelaciones(this->relaciones_fecha);
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

std::string Fecha::getNombreMes()
{
    return nombres_meses[this->mes - 1];
}

std::string Fecha::getStringDDMMAAAA(std::string separador)
{
    return this->getStringDia() + separador + this->getStringMes() + separador + this->getStringAnio();
}

std::string Fecha::getStringDDmesAAAA(std::string separador)
{
    return this->getStringDia() + separador + this->getNombreMes() + separador + this->getStringAnio();
}

relaciones::RelacionesFecha * Fecha::getRelacionesFecha()
{
    return this->relaciones_fecha;;
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

void Fecha::setRelacionesFecha(relaciones::RelacionesFecha * relaciones_fecha)
{
    this->relaciones_fecha = relaciones_fecha;
}

// METODOS

// metodos de IContieneJson

void Fecha::crearJson()
{
    IJson* json = this->getJson();
    json->reset();

    json->agregarAtributoValor("dia", this->getDia());
    json->agregarAtributoValor("mes", this->getMes());
    json->agregarAtributoValor("anio", this->getAnio());
}

bool Fecha::parsearJson(IJson* json)
{
    unsigned long long int dia = json->getAtributoValorUint("dia");
    unsigned long long int mes = json->getAtributoValorUint("mes");
    unsigned long long int anio = json->getAtributoValorUint("anio");

    this->dia = dia;
    this->mes = mes;
    this->anio = anio;

    return true;
}

// metodos de IAlmacenable

std::string Fecha::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoFecha();
}

unsigned int Fecha::hashcode()
{
    return IHashable::hashear(this->dia) + IHashable::hashear(this->mes) + IHashable::hashear(this->anio);
}

// metodos de IEntidad

IEntidad * Fecha::clonar()
{
    Fecha * clon = new Fecha(this->dia, this->mes, this->anio, this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setJson(this->getJson()->clonar());
    return clon;
}

// metodos de IRelacionable

bool Fecha::recuperarContenidoDeRelaciones()
{
    return true;
}

void Fecha::actualizarRelaciones()
{
}

void Fecha::vincular()
{
}

void Fecha::desvincular()
{
}
