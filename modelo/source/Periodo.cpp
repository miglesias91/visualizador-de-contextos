#include <modelo/include/Periodo.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

// CONSTRUCTORES

Periodo::Periodo()
{
}

Periodo::Periodo(std::string etiqueta, Fecha * desde, Fecha * hasta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoPeriodo()),  desde(desde), hasta(hasta)
{
}

Periodo::~Periodo()
{
}

// METODOS

void Periodo::crearContenido()
{
	rapidjson::Value* json_contenido = new rapidjson::Value(rapidjson::kObjectType);

	rapidjson::Document::AllocatorType* alocador = visualizador::aplicacion::ConfiguracionAplicacion::getAlocador();

	rapidjson::Value tag_desde("id_fecha_desde", *alocador);
	rapidjson::Value fecha_desde(this->getDesde()->getId()->numero());
	json_contenido->AddMember(tag_desde, fecha_desde, *alocador);

	rapidjson::Value tag_hasta("id_fecha_hasta", *alocador);
	rapidjson::Value fecha_hasta(this->getHasta()->getId()->numero());
	json_contenido->AddMember(tag_hasta, fecha_hasta, *alocador);

	this->getContenido()->setValor(json_contenido);
}

// GETTERS

Fecha * Periodo::getDesde()
{
	return this->desde;
}

Fecha * Periodo::getHasta()
{
	return this->hasta;
}

// SETTERS

void Periodo::setDesde(Fecha * desde)
{
	this->desde = desde;
}

void Periodo::setHasta(Fecha * hasta)
{
	this->hasta = hasta;
}
