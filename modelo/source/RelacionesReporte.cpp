#include <modelo/include/RelacionesReporte.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesReporte::RelacionesReporte(visualizador::aplicacion::ID* id_reporte) :
    IRelaciones(id_reporte, aplicacion::ConfiguracionAplicacion::prefijoRelacionesReporte()),
    IRelacionConConsultas(new RelacionConGrupo())
{
}

RelacionesReporte::~RelacionesReporte()
{
}

// GETTERS

// getters de IAlmacenable

std::string RelacionesReporte::getValorAlmacenable()
{
    this->crearJson();

    return this->getJson()->jsonString();
}

// SETTERS

// METODOS

// metodos de IAlmacenable

void RelacionesReporte::parsearValorAlmacenable(std::string valor_almacenable)
{
    IJson json_almacenable(valor_almacenable);

    this->parsearJson(&json_almacenable);
}

std::string RelacionesReporte::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesReporte();
}

unsigned int RelacionesReporte::hashcode()
{
    return this->getRelacionConConsultas()->hashcode();
}

// metodos de IContieneJson

void RelacionesReporte::crearJson()
{
    IJson * relaciones_reporte = new IJson();

    relaciones_reporte->agregarAtributoArray("ids_consultas", this->getRelacionConConsultas()->getIdsGrupoComoUint());

    IJson* json = this->getJson();
    json->reset();

    json->agregarAtributoJson("relaciones_reporte", relaciones_reporte);

    delete relaciones_reporte;
}

bool RelacionesReporte::parsearJson(IJson * json)
{
    IJson * json_relaciones_reporte = json->getAtributoValorJson("relaciones_reporte");

    std::vector<unsigned long long int> ids_consultas = json_relaciones_reporte->getAtributoArrayUint("ids_consultas");

    for (std::vector<unsigned long long int>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        this->getRelacionConConsultas()->agregarRelacion(*it);
    }

    delete json_relaciones_reporte;

    return true;
}