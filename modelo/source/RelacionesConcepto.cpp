#include <modelo/include/RelacionesConcepto.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesConcepto::RelacionesConcepto(herramientas::utiles::ID* id_concepto) :
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
    this->armarJson();

    return this->getJson()->jsonString();
}

// SETTERS

// METODOS

// metodos de IAlmacenable

void RelacionesConcepto::parsearValorAlmacenable(std::string valor_almacenable)
{
    herramientas::utiles::Json * json_almacenable = new herramientas::utiles::Json(valor_almacenable);

    this->setJson(json_almacenable);
    this->parsearJson();
}

std::string RelacionesConcepto::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesConcepto();
}

unsigned long long int RelacionesConcepto::hashcode()
{
    return this->getRelacionConTerminos()->hashcode() + this->getRelacionConConsultas()->hashcode();
}

// metodos de IContieneJson

bool RelacionesConcepto::armarJson()
{
    herramientas::utiles::Json * relaciones_concepto = new herramientas::utiles::Json();

    relaciones_concepto->agregarAtributoArray("ids_terminos", this->getRelacionConTerminos()->getIdsGrupoComoUint());
    relaciones_concepto->agregarAtributoArray("ids_consultas", this->getRelacionConConsultas()->getIdsGrupoComoUint());

    this->getJson()->reset();

    this->getJson()->agregarAtributoJson("relaciones_concepto", relaciones_concepto);

    delete relaciones_concepto;

    return true;
}

bool RelacionesConcepto::parsearJson()
{
    herramientas::utiles::Json * json_relaciones_concepto = this->getJson()->getAtributoValorJson("relaciones_concepto");

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

IRelaciones * RelacionesConcepto::clonar()
{
    RelacionesConcepto * clon = new RelacionesConcepto(this->getId()->copia());

    std::vector<herramientas::utiles::ID*> ids_consulta = this->getRelacionConConsultas()->getIdsGrupo();
    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consulta.begin(); it != ids_consulta.end(); it++)
    {
        clon->agregarRelacionConConsulta(*it);
    }

    std::vector<herramientas::utiles::ID*> ids_termino = this->getRelacionConTerminos()->getIdsGrupo();
    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_termino.begin(); it != ids_termino.end(); it++)
    {
        clon->agregarRelacionConTermino(*it);
    }

    return clon;
}
