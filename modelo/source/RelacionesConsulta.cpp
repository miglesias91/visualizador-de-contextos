#include <modelo/include/RelacionesConsulta.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesConsulta::RelacionesConsulta(visualizador::aplicacion::ID* id_consulta) :
    IRelaciones(id_consulta, aplicacion::ConfiguracionAplicacion::prefijoRelacionesConsulta()),
    IRelacionConConceptos(new RelacionConGrupo()) ,relacion_con_medios(new RelacionConGrupo()), relacion_con_secciones(new RelacionConGrupo()),
    relacion_con_periodo(0), relacion_con_reporte(0)
{
}

RelacionesConsulta::~RelacionesConsulta()
{
    if (NULL != this->relacion_con_medios)
    {
        delete this->relacion_con_medios;
        this->relacion_con_medios = NULL;
    }

    if (NULL != this->relacion_con_secciones)
    {
        delete this->relacion_con_secciones;
        this->relacion_con_secciones = NULL;
    }
}

// GETTERS

// getters de IAlmacenable

std::string RelacionesConsulta::getValorAlmacenable()
{
    this->crearContenido();

    return this->getContenido()->jsonString();
}

// SETTERS

// METODOS

// metodos de IAlmacenable

void RelacionesConsulta::parsearValorAlmacenable(std::string valor_almacenable)
{
    IJson json_almacenable(valor_almacenable);

    this->parsearContenido(&json_almacenable);
}

std::string RelacionesConsulta::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesConsulta();
}

unsigned int RelacionesConsulta::hashcode()
{
    return this->getRelacionConConceptos()->hashcode();
}

// metodos de IContieneJson

void RelacionesConsulta::crearContenido()
{
    IJson * relaciones_consulta = new IJson();

    relaciones_consulta->agregarAtributoValor("id_periodo", this->relacion_con_periodo);
    relaciones_consulta->agregarAtributoValor("id_reporte", this->relacion_con_reporte);

    relaciones_consulta->agregarAtributoArray("ids_conceptos", this->getRelacionConConceptos()->getIdsGrupoComoUint());
    relaciones_consulta->agregarAtributoArray("ids_medios", this->relacion_con_medios->getIdsGrupoComoUint());
    relaciones_consulta->agregarAtributoArray("ids_secciones", this->relacion_con_secciones->getIdsGrupoComoUint());

    IJson* contenido = this->getContenido();
    contenido->reset();

    contenido->agregarAtributoJson("relaciones_consulta", relaciones_consulta);
}

bool RelacionesConsulta::parsearContenido(IJson * contenido)
{
    IJson * json_relaciones_consulta = contenido->getAtributoValorJson("relaciones_consulta");

    std::vector<unsigned long long int> ids_conceptos = json_relaciones_consulta->getAtributoArrayUint("ids_conceptos");

    for (std::vector<unsigned long long int>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        this->getRelacionConConceptos()->agregarRelacion(*it);
    }

    return true;
}