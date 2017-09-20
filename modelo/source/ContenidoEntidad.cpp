#include <modelo/include/ContenidoEntidad.h>

using namespace visualizador::modelo;

// stl
#include <sstream>

// rapidjson
#include <rapidjson/ostreamwrapper.h>
#include <rapidjson/prettywriter.h>

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

ContenidoEntidad::ContenidoEntidad() : valor(NULL)
{
}

ContenidoEntidad::~ContenidoEntidad()
{
}

void ContenidoEntidad::setValor(rapidjson::Value * valor)
{
	if (NULL != this->valor)
	{
		delete this->valor;
	}
	this->valor = valor;
}

rapidjson::Value* ContenidoEntidad::getValor()
{
	return this->valor;
}

std::string ContenidoEntidad::jsonString()
{
	std::stringstream sstream;
	rapidjson::OStreamWrapper osw(sstream);

	rapidjson::Writer<rapidjson::OStreamWrapper> writer(osw);
	this->getValor()->Accept(writer);

	writer.Flush();

	return sstream.str();
}
