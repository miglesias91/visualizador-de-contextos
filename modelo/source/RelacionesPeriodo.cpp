#include <modelo/include/RelacionesPeriodo.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesPeriodo::RelacionesPeriodo(herramientas::utiles::ID* id_periodo) : IRelaciones(id_periodo, aplicacion::ConfiguracionAplicacion::prefijoRelacionesPeriodo()),
    IRelacionConConsultas(new RelacionConGrupo()), relacion_con_fecha_desde(0), relacion_con_fecha_hasta(0)
{
}

RelacionesPeriodo::~RelacionesPeriodo()
{
}

// GETTERS

unsigned long long int RelacionesPeriodo::getRelacionConFechaDesde()
{
    return this->relacion_con_fecha_desde;
}

unsigned long long int RelacionesPeriodo::getRelacionConFechaHasta()
{
    return this->relacion_con_fecha_hasta;
}

// getters de IAlmacenable

std::string RelacionesPeriodo::getValorAlmacenable()
{
    this->armarJson();

    return this->getJson()->jsonString();
}

// SETTERS

void RelacionesPeriodo::setRelacionConFechaDesde(unsigned long long int id_fecha_desde)
{
    this->relacion_con_fecha_desde = id_fecha_desde;
}

void RelacionesPeriodo::setRelacionConFechaHasta(unsigned long long int id_fecha_hasta)
{
    this->relacion_con_fecha_hasta = id_fecha_hasta;
}

// METODOS

// metodos de IAlmacenable

void RelacionesPeriodo::parsearValorAlmacenable(std::string valor_almacenable)
{
    herramientas::utiles::Json * json_almacenable = new herramientas::utiles::Json(valor_almacenable);

    this->setJson(json_almacenable);
    this->parsearJson();
}

std::string RelacionesPeriodo::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesPeriodo();
}

unsigned long long int RelacionesPeriodo::hashcode()
{
    return this->relacion_con_fecha_desde + this->relacion_con_fecha_hasta + this->getRelacionConConsultas()->hashcode();
}

// metodos de IContieneJson

bool RelacionesPeriodo::armarJson()
{
    herramientas::utiles::Json * relaciones_periodo = new herramientas::utiles::Json();

    relaciones_periodo->agregarAtributoValor("id_fecha_desde", this->relacion_con_fecha_desde);
    relaciones_periodo->agregarAtributoValor("id_fecha_hasta", this->relacion_con_fecha_hasta);

    relaciones_periodo->agregarAtributoArray("ids_consultas", this->getRelacionConConsultas()->getIdsGrupoComoUint());

    this->getJson()->reset();

    this->getJson()->agregarAtributoJson("relaciones_periodo", relaciones_periodo);

    delete relaciones_periodo;

    return true;
}

bool RelacionesPeriodo::parsearJson()
{
    herramientas::utiles::Json * json_relaciones_periodo = this->getJson()->getAtributoValorJson("relaciones_periodo");

    std::vector<unsigned long long int> ids_consultas = json_relaciones_periodo->getAtributoArrayUint("ids_consultas");

    for (std::vector<unsigned long long int>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        this->getRelacionConConsultas()->agregarRelacion(*it);
    }

    this->relacion_con_fecha_desde = json_relaciones_periodo->getAtributoValorUint("id_fecha_desde");
    this->relacion_con_fecha_hasta = json_relaciones_periodo->getAtributoValorUint("id_fecha_hasta");

    delete json_relaciones_periodo;

    return true;
}

IRelaciones * RelacionesPeriodo::clonar()
{
    RelacionesPeriodo * clon = new RelacionesPeriodo(this->getId()->copia());

    std::vector<herramientas::utiles::ID*> ids_consultas = this->getRelacionConConsultas()->getIdsGrupo();
    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        clon->agregarRelacionConConsulta(*it);
    }

    clon->setRelacionConFechaDesde(this->getRelacionConFechaDesde());

    clon->setRelacionConFechaHasta(this->getRelacionConFechaHasta());

    return clon;
}
