#include <modelo/include/RelacionesConcepto.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesConcepto::RelacionesConcepto(visualizador::aplicacion::ID* id_concepto) :
    IRelaciones(id_concepto, aplicacion::ConfiguracionAplicacion::prefijoRelacionesConcepto()),
    IRelacionConTerminos(new RelacionConGrupo()),
    IRelacionConConsultas(new RelacionConGrupo())
{
}

RelacionesConcepto::~RelacionesConcepto()
{
}

// GETTERS

// getters de IAlmacenable

std::string RelacionesConcepto::getValorAlmacenable()
{
    this->crearJson();

    return this->getJson()->jsonString();
}

// SETTERS

// METODOS

// metodos de IAlmacenable

void RelacionesConcepto::parsearValorAlmacenable(std::string valor_almacenable)
{
    IJson json_almacenable(valor_almacenable);

    this->parsearJson(&json_almacenable);
}

std::string RelacionesConcepto::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesConcepto();
}

unsigned int RelacionesConcepto::hashcode()
{
    return this->getRelacionConTerminos()->hashcode() + this->getRelacionConConsultas()->hashcode();
}

// metodos de IContieneJson

void RelacionesConcepto::crearJson()
{
    IJson * relaciones_concepto = new IJson();

    relaciones_concepto->agregarAtributoArray("ids_terminos", this->getRelacionConTerminos()->getIdsGrupoComoUint());
    relaciones_concepto->agregarAtributoArray("ids_consultas", this->getRelacionConConsultas()->getIdsGrupoComoUint());

    IJson* json = this->getJson();
    json->reset();

    json->agregarAtributoJson("relaciones_concepto", relaciones_concepto);

    delete relaciones_concepto;
}

bool RelacionesConcepto::parsearJson(IJson * json)
{
    IJson * json_relaciones_concepto = json->getAtributoValorJson("relaciones_concepto");

    std::vector<unsigned long long int> ids_terminos = json_relaciones_concepto->getAtributoArrayUint("ids_terminos");
    std::vector<unsigned long long int> ids_consultas = json_relaciones_concepto->getAtributoArrayUint("ids_consultas");

    for (std::vector<unsigned long long int>::iterator it = ids_terminos.begin(); it != ids_terminos.end(); it++)
    {
        this->getRelacionConTerminos()->agregarRelacion(*it);
    }
    
    for (std::vector<unsigned long long int>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        this->getRelacionConConsultas()->agregarRelacion(*it);
    }

    delete json_relaciones_concepto;

    return true;
}