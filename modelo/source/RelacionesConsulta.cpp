#include <modelo/include/RelacionesConsulta.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesConsulta::RelacionesConsulta(herramientas::utiles::ID* id_consulta) :
    IRelaciones(id_consulta, aplicacion::ConfiguracionAplicacion::prefijoRelacionesConsulta()),
    IRelacionConConceptos(new RelacionConGrupo()),
    IRelacionConMedios(new RelacionConGrupo()), 
    IRelacionConSecciones(new RelacionConGrupo()),
    relacion_con_periodo(0), relacion_con_reporte(0)
{
}

RelacionesConsulta::~RelacionesConsulta()
{
}

// GETTERS

unsigned long long int RelacionesConsulta::getRelacionConPeriodo()
{
    return this->relacion_con_periodo;
}

unsigned long long int RelacionesConsulta::getRelacionConReporte()
{
    return this->relacion_con_reporte;
}

// getters de IAlmacenable

std::string RelacionesConsulta::getValorAlmacenable()
{
    this->armarJson();

    return this->getJson()->jsonString();
}

// SETTERS

void RelacionesConsulta::setRelacionConPeriodo(unsigned long long int id_periodo)
{
    this->relacion_con_periodo = id_periodo;
}

void RelacionesConsulta::setRelacionConReporte(unsigned long long int id_reporte)
{
    this->relacion_con_reporte = id_reporte;
}

// METODOS

// metodos de IAlmacenable

void RelacionesConsulta::parsearValorAlmacenable(std::string valor_almacenable)
{
    herramientas::utiles::Json * json_almacenable = new herramientas::utiles::Json(valor_almacenable);

    this->setJson(json_almacenable);
    this->parsearJson();
}

std::string RelacionesConsulta::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesConsulta();
}

unsigned long long int RelacionesConsulta::hashcode()
{
    return this->getRelacionConConceptos()->hashcode() + this->getRelacionConMediosTwitter()->hashcode() + this->getRelacionConSecciones()->hashcode() +
        this->getRelacionConReporte() + this->getRelacionConPeriodo();
}

// metodos de IContieneJson

bool RelacionesConsulta::armarJson()
{
    herramientas::utiles::Json * relaciones_consulta = new herramientas::utiles::Json();

    relaciones_consulta->agregarAtributoValor("id_periodo", this->relacion_con_periodo);
    relaciones_consulta->agregarAtributoValor("id_reporte", this->relacion_con_reporte);

    relaciones_consulta->agregarAtributoArray("ids_conceptos", this->getRelacionConConceptos()->getIdsGrupoComoUint());
    relaciones_consulta->agregarAtributoArray("ids_medios_twitter", this->getRelacionConMediosTwitter()->getIdsGrupoComoUint());
    relaciones_consulta->agregarAtributoArray("ids_secciones", this->getRelacionConSecciones()->getIdsGrupoComoUint());

    this->getJson()->reset();

    this->getJson()->agregarAtributoJson("relaciones_consulta", relaciones_consulta);

    delete relaciones_consulta;

    return true;
}

bool RelacionesConsulta::parsearJson()
{
    herramientas::utiles::Json * json_relaciones_consulta = this->getJson()->getAtributoValorJson("relaciones_consulta");

    std::vector<unsigned long long int> ids_conceptos = json_relaciones_consulta->getAtributoArrayUint("ids_conceptos");
    for (std::vector<unsigned long long int>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        this->getRelacionConConceptos()->agregarRelacion(*it);
    }

    std::vector<unsigned long long int> ids_medios_twitter = json_relaciones_consulta->getAtributoArrayUint("ids_medios_twitter");
    for (std::vector<unsigned long long int>::iterator it = ids_medios_twitter.begin(); it != ids_medios_twitter.end(); it++)
    {
        this->getRelacionConMediosTwitter()->agregarRelacion(*it);
    }

    std::vector<unsigned long long int> ids_secciones = json_relaciones_consulta->getAtributoArrayUint("ids_secciones");
    for (std::vector<unsigned long long int>::iterator it = ids_secciones.begin(); it != ids_secciones.end(); it++)
    {
        this->getRelacionConSecciones()->agregarRelacion(*it);
    }

    this->relacion_con_periodo = json_relaciones_consulta->getAtributoValorUint("id_periodo");
    this->relacion_con_reporte = json_relaciones_consulta->getAtributoValorUint("id_reporte");

    delete json_relaciones_consulta;

    return true;
}

IRelaciones * RelacionesConsulta::clonar()
{
    RelacionesConsulta * clon = new RelacionesConsulta(this->getId()->copia());

    std::vector<herramientas::utiles::ID*> ids_medios_twitter = this->getRelacionConMediosTwitter()->getIdsGrupo();
    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_medios_twitter.begin(); it != ids_medios_twitter.end(); it++)
    {
        clon->agregarRelacionConMedioTwitter(*it);
    }

    std::vector<herramientas::utiles::ID*> ids_secciones = this->getRelacionConSecciones()->getIdsGrupo();
    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_secciones.begin(); it != ids_secciones.end(); it++)
    {
        clon->agregarRelacionConSeccion(*it);
    }

    std::vector<herramientas::utiles::ID*> ids_conceptos = this->getRelacionConConceptos()->getIdsGrupo();
    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        clon->agregarRelacionConConcepto(*it);
    }

    clon->setRelacionConReporte(this->getRelacionConReporte());
    clon->setRelacionConPeriodo(this->getRelacionConPeriodo());

    return clon;
}
