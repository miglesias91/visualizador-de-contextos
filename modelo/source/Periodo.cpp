#include <modelo/include/Periodo.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

// CONSTRUCTORES

Periodo::Periodo(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoPeriodo()), desde(NULL), hasta(NULL)
{
}

Periodo::Periodo(Fecha * desde, Fecha * hasta, std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoPeriodo()),  desde(desde), hasta(hasta)
{
}

Periodo::~Periodo()
{
}

// METODOS

void Periodo::crearContenido()
{
	ContenidoEntidad* contenido = this->getContenido();
	contenido->reset();

	contenido->agregarAtributoValor("id_fecha_desde", this->getDesde()->getId()->numero());
	contenido->agregarAtributoValor("id_fecha_hasta", this->getHasta()->getId()->numero());
}

void Periodo::parsearContenido(IJson* contenido)
{
	unsigned long long int id_fecha_desde = contenido->getAtributoValorUint("id_fecha_desde");
	unsigned long long int id_fecha_hasta = contenido->getAtributoValorUint("id_fecha_hasta");

	Fecha* fecha_desde = new Fecha();
	fecha_desde->setId(new visualizador::aplicacion::ID(id_fecha_desde));

	Fecha* fecha_hasta = new Fecha();
	fecha_hasta->setId(new visualizador::aplicacion::ID(id_fecha_hasta));

	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(fecha_desde);
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(fecha_hasta);

	this->desde = fecha_desde;
	this->hasta = fecha_hasta;
}

std::string Periodo::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoPeriodo();
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
