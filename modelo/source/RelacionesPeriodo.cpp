#include <modelo/include/RelacionesPeriodo.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesPeriodo::RelacionesPeriodo(visualizador::aplicacion::ID* id_periodo) : IRelaciones(id_periodo, aplicacion::ConfiguracionAplicacion::prefijoRelacionesPeriodo()),
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
    this->crearJson();

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
    IJson json_almacenable(valor_almacenable);

    this->parsearJson(&json_almacenable);
}

std::string RelacionesPeriodo::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesPeriodo();
}

unsigned int RelacionesPeriodo::hashcode()
{
    return this->relacion_con_fecha_desde + this->relacion_con_fecha_hasta + this->getRelacionConConsultas()->hashcode();
}

// metodos de IContieneJson

void RelacionesPeriodo::crearJson()
{
    IJson * relaciones_periodo = new IJson();

    relaciones_periodo->agregarAtributoValor("id_fecha_desde", this->relacion_con_fecha_desde);
    relaciones_periodo->agregarAtributoValor("id_fecha_hasta", this->relacion_con_fecha_hasta);

    relaciones_periodo->agregarAtributoArray("ids_consultas", this->getRelacionConConsultas()->getIdsGrupoComoUint());

    IJson* json = this->getJson();
    json->reset();

    json->agregarAtributoJson("relaciones_periodo", relaciones_periodo);

    delete relaciones_periodo;
}

bool RelacionesPeriodo::parsearJson(IJson * json)
{
    IJson * json_relaciones_periodo = json->getAtributoValorJson("relaciones_periodo");

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