#include <modelo/include/Consulta.h>

using namespace visualizador::modelo;

// stl
#include <algorithm>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

Consulta::Consulta(std::string etiqueta) :
    IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoConsulta(), NULL), periodo(NULL), reporte(NULL), relaciones_consulta(NULL)
{
    this->relaciones_consulta = new relaciones::RelacionesConsulta();
    this->setRelaciones(this->relaciones_consulta);
}

Consulta::Consulta(Periodo * periodo, Reporte * reporte, std::vector<Concepto*> conceptos, std::vector<Medio*> medios, std::vector<Seccion*> secciones, std::string etiqueta)
	: IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoConsulta(), NULL), relaciones_consulta(NULL)
{
    this->relaciones_consulta = new relaciones::RelacionesConsulta();
    this->setRelaciones(this->relaciones_consulta);

    this->setPeriodo(periodo);
    this->setReporte(reporte);

    for (std::vector<Concepto*>::iterator it = conceptos.begin(); it != conceptos.end(); it++)
    {
        // (*it)->sumarReferencia();
        this->agregarConcepto(*it);
    }

    for (std::vector<Medio*>::iterator it = medios.begin(); it != medios.end(); it++)
    {
        // (*it)->sumarReferencia();
        this->agregarMedio(*it);
    }

    for (std::vector<Seccion*>::iterator it = secciones.begin(); it != secciones.end(); it++)
    {
        // (*it)->sumarReferencia();
        this->agregarSeccion(*it);
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
    this->conceptos.clear();

	for (std::vector<Medio*>::iterator it = this->medios.begin(); it != this->medios.end(); it++)
	{
        if (0 == (*it)->restarReferencia())
        {
            delete (*it);
            (*it) = NULL;
        }
	}
    this->medios.clear();

	for (std::vector<Seccion*>::iterator it = this->secciones.begin(); it != this->secciones.end(); it++)
	{
        if (0 == (*it)->restarReferencia())
        {
            delete (*it);
            (*it) = NULL;
        }
	}
    this->secciones.clear();

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

// GETTERS

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

relaciones::RelacionesConsulta * Consulta::getRelacionesConsulta()
{
    return this->relaciones_consulta;
}

// SETTERS

void Consulta::setPeriodo(Periodo * periodo)
{
	this->periodo = periodo;
    this->periodo->sumarReferencia();

    if (NULL != this->getId())
    {
        this->periodo->getRelacionesPeriodo()->agregarRelacionConConsulta(this->getId());
    }

    if (NULL != this->periodo->getId())
    {
        this->relaciones_consulta->setRelacionConPeriodo(this->periodo->getId()->numero());
    }
}

void Consulta::setReporte(Reporte * reporte)
{
	this->reporte = reporte;
    this->reporte->sumarReferencia();
    
    if (NULL != this->getId())
    {
        this->reporte->getRelacionesReporte()->agregarRelacionConConsulta(this->getId());
    }

    if (NULL != this->reporte->getId())
    {
        this->relaciones_consulta->setRelacionConReporte(this->reporte->getId()->numero());
    }
}

void Consulta::agregarConcepto(Concepto * concepto)
{
	this->conceptos.push_back(concepto);
    concepto->sumarReferencia();

    if (NULL != this->getId())
    {
        concepto->getRelacionesConcepto()->agregarRelacionConConsulta(this->getId());
    }

    if (NULL != concepto->getId())
    {
        //this->relaciones_consulta->getRelacionConConceptos()->agregarRelacion(concepto->getId()->copia());
        this->relaciones_consulta->agregarRelacionConConcepto(concepto->getId());
    }
}

void Consulta::agregarMedio(Medio * medio)
{
	this->medios.push_back(medio);
    medio->sumarReferencia();

    if (NULL != this->getId())
    {
        medio->getRelacionesMedio()->agregarRelacionConConsulta(this->getId());
    }

    if (NULL != medio->getId())
    {
        //this->relaciones_consulta->getRelacionConMedios()->agregarRelacion(medio->getId()->copia());
        this->relaciones_consulta->agregarRelacionConMedio(medio->getId());
    }
}

void Consulta::agregarSeccion(Seccion * seccion)
{
	this->secciones.push_back(seccion);
    seccion->sumarReferencia();

    if (NULL != this->getId())
    {
        seccion->getRelacionesSeccion()->agregarRelacionConConsulta(this->getId());
    }

    if (NULL != seccion->getId())
    {
        //this->relaciones_consulta->getRelacionConSecciones()->agregarRelacion(seccion->getId()->copia());
        this->relaciones_consulta->agregarRelacionConSeccion(seccion->getId());
    }
}

void Consulta::setRelacionesConsulta(relaciones::RelacionesConsulta * relaciones_consulta)
{
    if (NULL != this->relaciones_consulta)
    {
        delete this->relaciones_consulta;
    }

    this->relaciones_consulta = relaciones_consulta;
    this->setRelaciones(this->relaciones_consulta);
}

// METODOS

// metodos de IContieneJson

void Consulta::crearJson()
{
}

bool Consulta::parsearJson(IJson* json)
{
    return true;
}

// metodos de IAlmacenable

std::string Consulta::prefijoGrupo()
{
	return aplicacion::ConfiguracionAplicacion::prefijoConsulta();
}

unsigned int Consulta::hashcode()
{
    return this->getRelacionesConsulta()->getRelacionConConceptos()->hashcode() + this->getRelacionesConsulta()->getRelacionConMedios()->hashcode() + this->getRelacionesConsulta()->getRelacionConSecciones()->hashcode() +
        this->getRelacionesConsulta()->getRelacionConReporte() + this->getRelacionesConsulta()->getRelacionConPeriodo();
}

// metodos de IEntidad

IEntidad * Consulta::clonar()
{
    aplicacion::GestorEntidades gestor;

    Periodo * clon_periodo = gestor.clonar<Periodo>(this->getPeriodo());
    Reporte * clon_reporte = gestor.clonar<Reporte>(this->getReporte());

    std::vector<Concepto*> clon_conceptos;
    for (std::vector<Concepto*>::iterator it = this->conceptos.begin(); it != this->conceptos.end(); it++)
    {
        Concepto * clon_concepto = gestor.clonar<Concepto>((*it));
        clon_conceptos.push_back(clon_concepto);
    }

    std::vector<Medio*> clon_medios;
    for (std::vector<Medio*>::iterator it = this->medios.begin(); it != this->medios.end(); it++)
    {
        Medio * clon_medio = gestor.clonar<Medio>((*it));
        clon_medios.push_back(clon_medio);
    }

    std::vector<Seccion*> clon_secciones;
    for (std::vector<Seccion*>::iterator it = this->secciones.begin(); it != this->secciones.end(); it++)
    {
        Seccion * clon_seccion = gestor.clonar<Seccion>((*it));
        clon_secciones.push_back(clon_seccion);
    }

    Consulta * clon = new Consulta(clon_periodo, clon_reporte, clon_conceptos, clon_medios, clon_secciones, this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setJson(this->getJson()->clonar());

    visualizador::aplicacion::GestorRelaciones gestor_relaciones;
    relaciones::RelacionesConsulta * relaciones_clon = gestor_relaciones.clonar<relaciones::RelacionesConsulta>(this->getRelacionesConsulta());

    clon->setRelacionesConsulta(relaciones_clon);

    return clon;
}

// metodos de IRelacionable

bool Consulta::recuperarContenidoDeRelaciones()
{
    visualizador::aplicacion::GestorEntidades gestor_entidades;

    std::vector<unsigned long long int> ids_conceptos = this->relaciones_consulta->getRelacionConConceptos()->getIdsGrupoComoUint();
    std::vector<unsigned long long int> ids_medios = this->relaciones_consulta->getRelacionConMedios()->getIdsGrupoComoUint();
    std::vector<unsigned long long int> ids_secciones = this->relaciones_consulta->getRelacionConSecciones()->getIdsGrupoComoUint();

    bool contenido_limpio = true;

    Concepto* concepto_nuevo = NULL;
    for (std::vector<unsigned long long int>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        concepto_nuevo = new Concepto();
        concepto_nuevo->setId(new herramientas::utiles::ID(*it));
        if (gestor_entidades.recuperar(concepto_nuevo))
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
        medio_nuevo->setId(new herramientas::utiles::ID(*it));
        if (gestor_entidades.recuperar(medio_nuevo))
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
        seccion_nueva->setId(new herramientas::utiles::ID(*it));
        if (gestor_entidades.recuperar(seccion_nueva))
        {
            this->agregarSeccion(seccion_nueva);
        }
        else
        {
            delete seccion_nueva;
            contenido_limpio = false;
        }
    }

    unsigned long long int id_periodo = this->relaciones_consulta->getRelacionConPeriodo();
    unsigned long long int id_reporte = this->relaciones_consulta->getRelacionConReporte();

    Periodo* periodo_nuevo = new Periodo();
    periodo_nuevo->setId(new herramientas::utiles::ID(id_periodo));
    if (gestor_entidades.recuperar(periodo_nuevo))
    {
        this->setPeriodo(periodo_nuevo);
    }
    else
    {
        delete periodo_nuevo;
        contenido_limpio = false;
    }

    Reporte* reporte_nuevo = new Reporte();
    reporte_nuevo->setId(new herramientas::utiles::ID(id_reporte));
    if (gestor_entidades.recuperar(reporte_nuevo))
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

void Consulta::actualizarRelaciones(herramientas::utiles::ID * id_nuevo, herramientas::utiles::ID * id_viejo)
{
    for (std::vector<Concepto*>::iterator it = this->conceptos.begin(); it != this->conceptos.end(); it++)
    {
        (*it)->getRelacionesConcepto()->actualizarRelacionConConsulta(id_nuevo, id_viejo);
        this->relaciones_consulta->agregarRelacionConConcepto((*it)->getId());
    }

    for (std::vector<Medio*>::iterator it = this->medios.begin(); it != this->medios.end(); it++)
    {
        (*it)->getRelacionesMedio()->actualizarRelacionConConsulta(id_nuevo, id_viejo);
        this->relaciones_consulta->agregarRelacionConMedio((*it)->getId());
    }

    for (std::vector<Seccion*>::iterator it = this->secciones.begin(); it != this->secciones.end(); it++)
    {
        (*it)->getRelacionesSeccion()->actualizarRelacionConConsulta(id_nuevo, id_viejo);
        this->relaciones_consulta->agregarRelacionConSeccion((*it)->getId());
    }

    if (NULL != this->periodo)
    {
        this->periodo->getRelacionesPeriodo()->actualizarRelacionConConsulta(id_nuevo, id_viejo);
        this->relaciones_consulta->setRelacionConPeriodo(this->periodo->getId()->numero());
    }

    if (NULL != this->reporte)
    {
        this->reporte->getRelacionesReporte()->actualizarRelacionConConsulta(id_nuevo, id_viejo);
        this->relaciones_consulta->setRelacionConReporte(this->reporte->getId()->numero());
    }
}

void Consulta::vincular()
{
    visualizador::aplicacion::GestorRelaciones gestor;
    gestor.vincular(this->relaciones_consulta, this->getId());
}

void Consulta::desvincular()
{
    visualizador::aplicacion::GestorRelaciones gestor;
    gestor.desvincular(this->relaciones_consulta, this->getId());
}

bool Consulta::tieneRelacionesDependientes()
{
    return false;
}
