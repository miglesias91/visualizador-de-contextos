#include <modelo/include/Periodo.h>

using namespace visualizador::modelo;

// aplicacion
#include <aplicacion/include/GestorEntidades.h>
// #include <aplicacion/include/IAdministradorAplicacion.h>
#include <aplicacion/include/ConfiguracionAplicacion.h>

// CONSTRUCTORES

Periodo::Periodo(std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoPeriodo(), NULL),
    desde(NULL), hasta(NULL), relaciones_periodo(NULL)
{
    this->relaciones_periodo = new relaciones::RelacionesPeriodo();
    this->setRelaciones(this->relaciones_periodo);
}

Periodo::Periodo(Fecha * desde, Fecha * hasta, std::string etiqueta) : IEntidad(etiqueta, visualizador::aplicacion::ConfiguracionAplicacion::prefijoPeriodo(), NULL),
    // desde(desde), hasta(hasta)
    relaciones_periodo(NULL)
{
    this->relaciones_periodo = new relaciones::RelacionesPeriodo();
    this->setRelaciones(this->relaciones_periodo);

    this->setDesde(desde);
    this->setHasta(hasta);
}

Periodo::~Periodo()
{
    if (this->desde != NULL && 0 == this->desde->restarReferencia())
    {
        delete this->desde;
        this->desde = NULL;
    }

    if (this->hasta != NULL && 0 == this->hasta->restarReferencia())
    {
        delete this->hasta;
        this->hasta = NULL;
    }
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

relaciones::RelacionesPeriodo * Periodo::getRelacionesPeriodo()
{
    return this->relaciones_periodo;
}

// SETTERS

void Periodo::setDesde(Fecha * desde)
{
	this->desde = desde;
    this->desde->sumarReferencia();

    if (NULL != this->getId())
    {
        this->desde->getRelacionesFecha()->agregarRelacionConPeriodo(this->getId());
    }

    if (NULL != this->desde->getId())
    {
        this->relaciones_periodo->setRelacionConFechaDesde(this->desde->getId()->numero());
    }
}

void Periodo::setHasta(Fecha * hasta)
{
	this->hasta = hasta;
    this->hasta->sumarReferencia();

    if (NULL != this->getId())
    {
        this->hasta->getRelacionesFecha()->agregarRelacionConPeriodo(this->getId());
    }

    if (NULL != this->hasta->getId())
    {
        this->relaciones_periodo->setRelacionConFechaDesde(this->hasta->getId()->numero());
    }
}

void Periodo::setRelacionesPeriodo(relaciones::RelacionesPeriodo * relaciones_periodo)
{
    this->relaciones_periodo = relaciones_periodo;
}


// METODOS

// metodos IContieneJson

void Periodo::crearJson()
{
    //IJson* json = this->getJson();
    //   json->reset();

    //   json->agregarAtributoValor("id_fecha_desde", this->getDesde()->getId()->numero());
    //   json->agregarAtributoValor("id_fecha_hasta", this->getHasta()->getId()->numero());
}

bool Periodo::parsearJson(IJson* json)
{
    //unsigned long long int id_fecha_desde = json->getAtributoValorUint("id_fecha_desde");
    //unsigned long long int id_fecha_hasta = json->getAtributoValorUint("id_fecha_hasta");

    //Fecha* fecha_desde = new Fecha();
    //fecha_desde->setId(new visualizador::aplicacion::ID(id_fecha_desde));

    //Fecha* fecha_hasta = new Fecha();
    //fecha_hasta->setId(new visualizador::aplicacion::ID(id_fecha_hasta));

    //   bool contenido_limpio = true;

    //   if (visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(fecha_desde))
    //   {
    //       this->setDesde(fecha_desde);
    //   }
    //   else
    //   {
    //       delete fecha_desde;
    //       contenido_limpio = false;
    //   }

    //   if (visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(fecha_hasta))
    //   {
    //       this->setHasta(fecha_hasta);
    //   }
    //   else
    //   {
    //       delete fecha_hasta;
    //       contenido_limpio = false;
    //   }

    //   return contenido_limpio;
    return true;
}

// metodos IAlmacenable

std::string Periodo::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoPeriodo();
}

unsigned int Periodo::hashcode()
{
    return this->getDesde()->hashcode() + this->getHasta()->hashcode();
}

// metodos IEntidad

IEntidad * Periodo::clonar()
{
    aplicacion::GestorEntidades gestor;

    Fecha * clon_desde = gestor.clonar<Fecha>(this->getDesde());
    Fecha * clon_hasta = gestor.clonar<Fecha>(this->getHasta());

    Periodo * clon = new Periodo(clon_desde, clon_hasta, this->getEtiqueta());
    clon->setId(this->getId()->copia());
    clon->setJson(this->getJson()->clonar());
    return clon;
}

// metodos IRelacionable

bool Periodo::recuperarContenidoDeRelaciones()
{
    unsigned long long int id_fecha_desde = this->relaciones_periodo->getRelacionConFechaDesde();
    unsigned long long int id_fecha_hasta = this->relaciones_periodo->getRelacionConFechaHasta();

    Fecha* fecha_desde = new Fecha();
    fecha_desde->setId(new visualizador::aplicacion::ID(id_fecha_desde));

    Fecha* fecha_hasta = new Fecha();
    fecha_hasta->setId(new visualizador::aplicacion::ID(id_fecha_hasta));

    bool contenido_limpio = true;

    if (visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(fecha_desde))
    {
        this->setDesde(fecha_desde);
    }
    else
    {
        delete fecha_desde;
        contenido_limpio = false;
    }

    if (visualizador::aplicacion::IAdministradorAplicacion::getInstancia()->recuperar(fecha_hasta))
    {
        this->setHasta(fecha_hasta);
    }
    else
    {
        delete fecha_hasta;
        contenido_limpio = false;
    }

    return contenido_limpio;
}

void Periodo::actualizarRelaciones()
{
    this->desde->getRelacionesFecha()->agregarRelacionConPeriodo(this->getId());
    this->relaciones_periodo->setRelacionConFechaDesde(this->desde->getId()->numero());

    this->hasta->getRelacionesFecha()->agregarRelacionConPeriodo(this->getId());
    this->relaciones_periodo->setRelacionConFechaDesde(this->hasta->getId()->numero());
}

void Periodo::vincular()
{
}

void Periodo::desvincular()
{
}