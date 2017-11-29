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
    this->crearContenido();

    return this->getContenido()->jsonString();
}

// SETTERS

// METODOS

// metodos de IAlmacenable

void RelacionesReporte::parsearValorAlmacenable(std::string valor_almacenable)
{
    IJson json_almacenable(valor_almacenable);

    this->parsearContenido(&json_almacenable);
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

void RelacionesReporte::crearContenido()
{
    IJson * relaciones_reporte = new IJson();

    relaciones_reporte->agregarAtributoArray("ids_consultas", this->getRelacionConConsultas()->getIdsGrupoComoUint());

    IJson* contenido = this->getContenido();
    contenido->reset();

    contenido->agregarAtributoJson("relaciones_reporte", relaciones_reporte);
}

bool RelacionesReporte::parsearContenido(IJson * contenido)
{
    IJson * json_relaciones_reporte = contenido->getAtributoValorJson("relaciones_reporte");

    std::vector<unsigned long long int> ids_consultas = json_relaciones_reporte->getAtributoArrayUint("ids_consultas");

    for (std::vector<unsigned long long int>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        this->getRelacionConConsultas()->agregarRelacion(*it);
    }

    return true;
}