#include <modelo/include/Consulta.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/ConfiguracionAplicacion.h>

Consulta::Consulta() : IEntidad()
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
