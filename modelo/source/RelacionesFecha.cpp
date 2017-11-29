#include <modelo/include/RelacionesFecha.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesFecha::RelacionesFecha(visualizador::aplicacion::ID* id_fecha) :
    IRelaciones(id_fecha, aplicacion::ConfiguracionAplicacion::prefijoRelacionesFecha()),
    IRelacionConPeriodos(new RelacionConGrupo())
{
}

RelacionesFecha::~RelacionesFecha()
{
}

// GETTERS

// getters de IAlmacenable

std::string RelacionesFecha::getValorAlmacenable()
{
    this->crearJson();

    return this->getJson()->jsonString();
}

// SETTERS

// METODOS

// metodos de IAlmacenable

void RelacionesFecha::parsearValorAlmacenable(std::string valor_almacenable)
{
    IJson json_almacenable(valor_almacenable);

    this->parsearJson(&json_almacenable);
}

std::string RelacionesFecha::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesFecha();
}

unsigned int RelacionesFecha::hashcode()
{
    return this->getRelacionConPeriodos()->hashcode();
}

// metodos de IContieneJson

void RelacionesFecha::crearJson()
{
    IJson * relaciones_fecha = new IJson();

    relaciones_fecha->agregarAtributoArray("ids_periodos", this->getRelacionConPeriodos()->getIdsGrupoComoUint());

    IJson* json = this->getJson();
    json->reset();

    json->agregarAtributoJson("relaciones_fecha", relaciones_fecha);
}

bool RelacionesFecha::parsearJson(IJson * json)
{
    IJson * json_relaciones_fecha = json->getAtributoValorJson("relaciones_fecha");

    std::vector<unsigned long long int> ids_periodos = json_relaciones_fecha->getAtributoArrayUint("ids_periodos");

    for (std::vector<unsigned long long int>::iterator it = ids_periodos.begin(); it != ids_periodos.end(); it++)
    {
        this->getRelacionConPeriodos()->agregarRelacion(*it);
    }

    return true;
}