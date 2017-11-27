#include <modelo/include/Consulta.h>

using namespace visualizador::modelo;

// stl
#include <algorithm>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>
// #include <aplicacion/include/IAdministradorAplicacion.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

Consulta::Consulta(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoConsulta(), NULL), periodo(NULL), reporte(NULL)
{
}

Consulta::Consulta(Periodo * periodo, Reporte * reporte, std::vector<Concepto*> conceptos, std::vector<Medio*> medios, std::vector<Seccion*> secciones, std::string etiqueta)
	: IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoConsulta(), NULL), periodo(periodo), reporte(reporte), conceptos(conceptos), medios(medios), secciones(secciones)
{
    this->periodo->sumarReferencia();
    this->reporte->sumarReferencia();

    for (std::vector<Concepto*>::iterator it = this->conceptos.begin(); it != this->conceptos.end(); it++)
    {
        (*it)->sumarReferencia();
    }

    for (std::vector<Medio*>::iterator it = this->medios.begin(); it != this->medios.end(); it++)
    {
        (*it)->sumarReferencia();
    }

    for (std::vector<Seccion*>::iterator it = this->secciones.begin(); it != this->secciones.end(); it++)
    {
        (*it)->sumarReferencia();
    }
}

Consulta::~Consulta()
{
	for (std::vector<Concepto*>::iterator it = this->conceptos.begin(); it != this->conceptos.end(); it++)
	{
        if (0 == (*it)->restarReferencia())
        {
            delete (*it);
            (*it) = NULL;
        }
	}

	for (std::vector<Medio*>::iterator it = this->medios.begin(); it != this->medios.end(); it++)
	{
        if (0 == (*it)->restarReferencia())
        {
            delete (*it);
            (*it) = NULL;
        }
	}

	for (std::vector<Seccion*>::iterator it = this->secciones.begin(); it != this->secciones.end(); it++)
	{
        if (0 == (*it)->restarReferencia())
        {
            delete (*it);
            (*it) = NULL;
        }
	}

    if (0 == this->periodo->restarReferencia())
    {
        delete this->periodo;
        periodo = NULL;
    }
    if (0 == this->reporte->restarReferencia())
    {
        delete this->reporte;
        reporte = NULL;
    }
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
    this->periodo->sumarReferencia();
}

void Consulta::setReporte(Reporte * reporte)
{
	this->reporte = reporte;
    this->reporte->sumarReferencia();
}

void Consulta::agregarConcepto(Concepto * concepto)
{
	this->conceptos.push_back(concepto);
    concepto->sumarReferencia();
}

void Consulta::agregarMedio(Medio * medio)
{
	this->medios.push_back(medio);
    medio->sumarReferencia();
}

void Consulta::agregarSeccion(Seccion * seccion)
{
	this->secciones.push_back(seccion);
    seccion->sumarReferencia();
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

	IJson* contenido = this->getContenido();
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

bool Consulta::parsearContenido(IJson* contenido)
{
    std::vector<unsigned long long int> ids_conceptos = contenido->getAtributoArrayUint("ids_conceptos");
    std::vector<unsigned long long int> ids_medios = contenido->getAtributoArrayUint("ids_medios");
    std::vector<unsigned long long int> ids_secciones = contenido->getAtributoArrayUint("ids_secciones");
    unsigned long long int id_periodo = contenido->getAtributoValorUint("id_periodo");
    unsigned long long int id_reporte = contenido->getAtributoValorUint("id_reporte");

    bool contenido_limpio = true;

    Concepto* concepto_nuevo = NULL;
    for (std::vector<unsigned long long int>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        concepto_nuevo = new Concepto();
        concepto_nuevo->setId(new visualizador::aplicacion::ID(*it));
        if (visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(concepto_nuevo))
        {
            this->agregarConcepto(concepto_nuevo);
        }
        else
        {
            delete concepto_nuevo;
            contenido_limpio = false;
        }
    }

    Medio* medio_nuevo = NULL;
    for (std::vector<unsigned long long int>::iterator it = ids_medios.begin(); it != ids_medios.end(); it++)
    {
        medio_nuevo = new Medio();
        medio_nuevo->setId(new visualizador::aplicacion::ID(*it));
        if (visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(medio_nuevo))
        {
            this->agregarMedio(medio_nuevo);
        }
        else
        {
            delete medio_nuevo;
            contenido_limpio = false;
        }
    }

    Seccion* seccion_nueva = NULL;
    for (std::vector<unsigned long long int>::iterator it = ids_secciones.begin(); it != ids_secciones.end(); it++)
    {
        seccion_nueva = new Seccion();
        seccion_nueva->setId(new visualizador::aplicacion::ID(*it));
        if (visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(seccion_nueva))
        {
            this->agregarSeccion(seccion_nueva);
        }
        else
        {
            delete seccion_nueva;
            contenido_limpio = false;
        }
    }

    Periodo* periodo_nuevo = new Periodo();
    periodo_nuevo->setId(new visualizador::aplicacion::ID(id_periodo));
    if (visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(periodo_nuevo))
    {
        this->setPeriodo(periodo_nuevo);
    }
    else
    {
        delete periodo_nuevo;
        contenido_limpio = false;
    }

	Reporte* reporte_nuevo = new Reporte();
	reporte_nuevo->setId(new visualizador::aplicacion::ID(id_reporte));
    if (visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(reporte_nuevo))
    {
        this->setReporte(reporte_nuevo);
    }
    else
    {
        delete reporte_nuevo;
        contenido_limpio = false;
    }

    return contenido_limpio;
}

std::string Consulta::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoConsulta();
}

unsigned int Consulta::hashcode()
{
	std::vector<Concepto*> conceptos = this->getConceptos();
	std::sort(conceptos.begin(), conceptos.end(), IEntidad::comparador);

	std::vector<Medio*> medios = this->getMedios();
	std::sort(medios.begin(), medios.end(), IEntidad::comparador);

	std::vector<Seccion*> secciones = this->getSecciones();
	std::sort(secciones.begin(), secciones.end(), IEntidad::comparador);

	unsigned int hashcode_periodo = this->getPeriodo()->hashcode();
	unsigned int hashcode_reporte = this->getReporte()->hashcode();

	unsigned long long int hashcode_conceptos = 0;
	for (std::vector<Concepto*>::iterator it = conceptos.begin(); it != conceptos.end(); it++)
	{
		hashcode_conceptos += (*it)->hashcode();
	}

	unsigned long long int hashcode_medios = 0;
	for (std::vector<Medio*>::iterator it = medios.begin(); it != medios.end(); it++)
	{
		hashcode_medios += (*it)->hashcode();
	}

	unsigned long long int hashcode_secciones = 0;
	for (std::vector<Seccion*>::iterator it = secciones.begin(); it != secciones.end(); it++)
	{
		hashcode_secciones += (*it)->hashcode();
	}

	return hashcode_conceptos + hashcode_medios + hashcode_secciones + hashcode_periodo + hashcode_reporte;
}

IEntidad * Consulta::clonar()
{
    aplicacion::GestorEntidades gestor;

    Periodo * clon_periodo = gestor.clonar<Periodo>(this->getPeriodo());
    Reporte * clon_reporte = gestor.clonar<Reporte>(this->getReporte());

    //Periodo * clon_periodo = this->getPeriodo()->clonar();
    //Reporte * clon_reporte = this->getReporte()->clonar();

    std::vector<Concepto*> clon_conceptos;
    for (std::vector<Concepto*>::iterator it = this->conceptos.begin(); it != this->conceptos.end(); it++)
    {
        //clon_conceptos.push_back((*it)->clonar());
        Concepto * clon_concepto = gestor.clonar<Concepto>((*it));
        clon_conceptos.push_back(clon_concepto);
    }

    std::vector<Medio*> clon_medios;
    for (std::vector<Medio*>::iterator it = this->medios.begin(); it != this->medios.end(); it++)
    {
        //clon_medios.push_back((*it)->clonar());
        Medio * clon_medio = gestor.clonar<Medio>((*it));
        clon_medios.push_back(clon_medio);
    }

    std::vector<Seccion*> clon_secciones;
    for (std::vector<Seccion*>::iterator it = this->secciones.begin(); it != this->secciones.end(); it++)
    {
        //clon_secciones.push_back((*it)->clonar());
        Seccion * clon_seccion = gestor.clonar<Seccion>((*it));
        clon_secciones.push_back(clon_seccion);
    }

    Consulta * clon = new Consulta(clon_periodo, clon_reporte, clon_conceptos, clon_medios, clon_secciones, this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setContenido(this->getContenido()->clonar());
    return clon;
}
