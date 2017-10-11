#include <modelo/include/Consulta.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

Consulta::Consulta(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoConsulta())
{
}

Consulta::Consulta(Periodo * periodo, Reporte * reporte, std::vector<Concepto*> conceptos, std::vector<Medio*> medios, std::vector<Seccion*> secciones, std::string etiqueta)
	: IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoConsulta()), periodo(periodo), reporte(reporte), conceptos(conceptos), medios(medios), secciones(secciones)
{
}

Consulta::~Consulta()
{
}

Periodo * Consulta::getPeriodo()
{
	return this->periodo;
}

Reporte * Consulta::getReporte()
{
	return this->reporte;
}

std::vector<Concepto*> Consulta::getConceptos()
{
	return this->conceptos;
}

std::vector<Medio*> Consulta::getMedios()
{
	return this->medios;
}

std::vector<Seccion*> Consulta::getSecciones()
{
	return this->secciones;
}

void Consulta::setPeriodo(Periodo * periodo)
{
	this->periodo = periodo;
}

void Consulta::setReporte(Reporte * reporte)
{
	this->reporte = reporte;
}

void Consulta::agregarConcepto(Concepto * concepto)
{
	this->conceptos.push_back(concepto);
}

void Consulta::agregarMedio(Medio * medio)
{
	this->medios.push_back(medio);
}

void Consulta::agregarSeccion(Seccion * seccion)
{
	this->secciones.push_back(seccion);
}

void Consulta::crearContenido()
{
	// creo ids de conceptos
	std::vector<unsigned long long int> ids_conceptos;
	for (std::vector<Concepto*>::iterator it = this->conceptos.begin(); it != this->conceptos.end(); it++)
	{
		unsigned long long int id = (*it)->getId()->numero();
		ids_conceptos.push_back(id);
	}

	// creo ids de medios
	std::vector<unsigned long long int> ids_medios;
	for (std::vector<Medio*>::iterator it = this->medios.begin(); it != this->medios.end(); it++)
	{
		unsigned long long int id = (*it)->getId()->numero();
		ids_medios.push_back(id);
	}

	// creo ids de secciones
	std::vector<unsigned long long int> ids_secciones;
	for (std::vector<Seccion*>::iterator it = this->secciones.begin(); it != this->secciones.end(); it++)
	{
		unsigned long long int id = (*it)->getId()->numero();
		ids_secciones.push_back(id);
	}

	ContenidoEntidad* contenido = this->getContenido();
	contenido->reset();

	// agrego periodo
	contenido->agregarAtributoValor("id_periodo", this->getPeriodo()->getId()->numero());

	// agrego reporte
	contenido->agregarAtributoValor("id_reporte", this->getReporte()->getId()->numero());

	// agrego conceptos
	contenido->agregarAtributoArray("ids_conceptos", ids_conceptos);

	// agrego medios
	contenido->agregarAtributoArray("ids_medios", ids_medios);

	// agrego secciones
	contenido->agregarAtributoArray("ids_secciones", ids_secciones);
}

void Consulta::parsearContenido(IJson* contenido)
{
	std::vector<unsigned long long int> ids_conceptos = contenido->getAtributoArrayUint("ids_conceptos");
	std::vector<unsigned long long int> ids_medios = contenido->getAtributoArrayUint("ids_medios");
	std::vector<unsigned long long int> ids_secciones = contenido->getAtributoArrayUint("ids_secciones");
	unsigned long long int id_periodo = contenido->getAtributoValorUint("id_periodo");
	unsigned long long int id_reporte = contenido->getAtributoValorUint("id_reporte");

	Concepto* concepto_nuevo = NULL;
	for (std::vector<unsigned long long int>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
	{
		concepto_nuevo = new Concepto();
		concepto_nuevo->setId(new visualizador::aplicacion::ID(*it));
		visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(concepto_nuevo);
		this->conceptos.push_back(concepto_nuevo);
	}

	Medio* medio_nuevo = NULL;
	for (std::vector<unsigned long long int>::iterator it = ids_medios.begin(); it != ids_medios.end(); it++)
	{
		medio_nuevo = new Medio();
		medio_nuevo->setId(new visualizador::aplicacion::ID(*it));
		visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(medio_nuevo);
		this->medios.push_back(medio_nuevo);
	}

	Seccion* seccion_nueva = NULL;
	for (std::vector<unsigned long long int>::iterator it = ids_secciones.begin(); it != ids_secciones.end(); it++)
	{
		seccion_nueva = new Seccion();
		seccion_nueva->setId(new visualizador::aplicacion::ID(*it));
		visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(seccion_nueva);
		this->secciones.push_back(seccion_nueva);
	}

	Periodo* periodo_nuevo = new Periodo();
	periodo_nuevo->setId(new visualizador::aplicacion::ID(id_periodo));
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(periodo_nuevo);
	this->periodo = periodo_nuevo;

	Reporte* reporte_nuevo = new Reporte();
	reporte_nuevo->setId(new visualizador::aplicacion::ID(id_reporte));
	visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(reporte_nuevo);
	this->reporte = reporte_nuevo;
}

std::string Consulta::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoConsulta();
}
