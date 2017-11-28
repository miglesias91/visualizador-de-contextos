#include <modelo/include/RelacionesConcepto.h>

using namespace visualizador::modelo::relaciones;
using namespace visualizador::modelo;
using namespace visualizador;

RelacionesConcepto::RelacionesConcepto(visualizador::aplicacion::ID* id_concepto) :
    IRelaciones(id_concepto, aplicacion::ConfiguracionAplicacion::prefijoRelacionesConcepto()), relacion_con_terminos(new RelacionConGrupo()), relacion_con_consultas(new RelacionConGrupo())
{
}

RelacionesConcepto::~RelacionesConcepto()
{
    if (NULL != this->relacion_con_terminos)
    {
        delete this->relacion_con_terminos;
        this->relacion_con_terminos = NULL;
    }

    if (NULL != this->relacion_con_consultas)
    {
        delete this->relacion_con_consultas;
        this->relacion_con_consultas = NULL;
    }
}

RelacionConGrupo * RelacionesConcepto::getRelacionConTerminos()
{
    return this->relacion_con_terminos;
}

RelacionConGrupo * RelacionesConcepto::getRelacionConConsultas()
{
    return this->relacion_con_consultas;
}

// GETTERS

// getters de IAlmacenable

std::string RelacionesConcepto::getValorAlmacenable()
{
    this->crearContenido();

    return this->getContenido()->jsonString();
}

// SETTERS

// METODOS

void RelacionesConcepto::agregarRelacionConTermino(visualizador::aplicacion::ID * id_termino)
{
    visualizador::aplicacion::ID * id_termino_copia = id_termino->copia();
    if (false == this->relacion_con_terminos->agregarRelacion(id_termino_copia))
    {// si no lo agrego, entonces destruyo la copia.
        delete id_termino_copia;
    }
}

void RelacionesConcepto::agregarRelacionConConsulta(visualizador::aplicacion::ID * id_consulta)
{
    visualizador::aplicacion::ID * id_consulta_copia = id_consulta->copia();
    if (false == this->relacion_con_consultas->agregarRelacion(id_consulta_copia))
    {// si no lo agrego, entonces destruyo la copia.
        delete id_consulta_copia;
    }
}

void RelacionesConcepto::eliminarRelacionConTermino(visualizador::aplicacion::ID * id_termino)
{
    this->relacion_con_terminos->eliminarRelacion(id_termino);
}

void RelacionesConcepto::eliminarRelacionConConsulta(visualizador::aplicacion::ID * id_consulta)
{
    this->relacion_con_consultas->eliminarRelacion(id_consulta);
}

// metodos de IAlmacenable

void RelacionesConcepto::parsearValorAlmacenable(std::string valor_almacenable)
{
    IJson json_almacenable(valor_almacenable);

    this->parsearContenido(&json_almacenable);
}

std::string RelacionesConcepto::prefijoGrupo()
{
    return aplicacion::ConfiguracionAplicacion::prefijoRelacionesConcepto();
}

unsigned int RelacionesConcepto::hashcode()
{
    return this->relacion_con_terminos->hashcode() + this->relacion_con_consultas->hashcode();
}

// metodos de IContieneJson

void RelacionesConcepto::crearContenido()
{
    IJson * relaciones_concepto = new IJson();

    relaciones_concepto->agregarAtributoArray("ids_terminos", this->relacion_con_terminos->getIdsGrupoComoUint());
    relaciones_concepto->agregarAtributoArray("ids_consultas", this->relacion_con_consultas->getIdsGrupoComoUint());

    IJson* contenido = this->getContenido();
    contenido->reset();

    contenido->agregarAtributoJson("relaciones_concepto", relaciones_concepto);
}

bool RelacionesConcepto::parsearContenido(IJson * contenido)
{
    IJson * json_relaciones_concepto = contenido->getAtributoValorJson("relaciones_concepto");

    std::vector<unsigned long long int> ids_terminos = json_relaciones_concepto->getAtributoArrayUint("ids_terminos");
    std::vector<unsigned long long int> ids_consultas = json_relaciones_concepto->getAtributoArrayUint("ids_consultas");

    for (std::vector<unsigned long long int>::iterator it = ids_terminos.begin(); it != ids_terminos.end(); it++)
    {
        this->relacion_con_terminos->agregarRelacion(*it);
    }
    
    for (std::vector<unsigned long long int>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        this->relacion_con_consultas->agregarRelacion(*it);
    }

    return true;
}