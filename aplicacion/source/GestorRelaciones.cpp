#include <aplicacion/include/GestorRelaciones.h>

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>

using namespace visualizador::aplicacion;
using namespace visualizador;

GestorRelaciones::GestorRelaciones()
{
}

GestorRelaciones::~GestorRelaciones()
{
}

bool GestorRelaciones::vincular(modelo::relaciones::RelacionesTermino * relaciones_termino, aplicacion::ID * id_termino)
{
    std::vector<aplicacion::ID*> ids_conceptos = relaciones_termino->getRelacionConConceptos()->getIdsGrupo();

    for (std::vector<aplicacion::ID*>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        modelo::relaciones::RelacionesConcepto relaciones_concepto(*it);
        IAdministradorAplicacion::getInstancia()->recuperar(&relaciones_concepto);
        relaciones_concepto.agregarRelacionConTermino(id_termino);
        IAdministradorAplicacion::getInstancia()->modificar(&relaciones_concepto);
    }

    return true;
}

bool GestorRelaciones::vincular(modelo::relaciones::RelacionesConcepto * relaciones_concepto, aplicacion::ID * id_concepto)
{
    std::vector<aplicacion::ID*> ids_terminos = relaciones_concepto->getRelacionConTerminos()->getIdsGrupo();

    for (std::vector<aplicacion::ID*>::iterator it = ids_terminos.begin(); it != ids_terminos.end(); it++)
    {
        modelo::relaciones::RelacionesTermino relaciones_termino(*it);
        IAdministradorAplicacion::getInstancia()->recuperar(&relaciones_termino);
        relaciones_termino.agregarRelacionConConcepto(id_concepto);
        IAdministradorAplicacion::getInstancia()->modificar(&relaciones_termino);
    }

    std::vector<aplicacion::ID*> ids_consultas = relaciones_concepto->getRelacionConConsultas()->getIdsGrupo();

    for (std::vector<aplicacion::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        modelo::relaciones::RelacionesConsulta relaciones_consulta(*it);
        IAdministradorAplicacion::getInstancia()->recuperar(&relaciones_consulta);
        relaciones_consulta.agregarRelacionConConcepto(id_concepto);
        IAdministradorAplicacion::getInstancia()->modificar(&relaciones_consulta);
    }

    return true;
}

bool GestorRelaciones::desvincular(modelo::relaciones::RelacionesTermino * relaciones_termino, aplicacion::ID * id_termino)
{
    std::vector<aplicacion::ID*> ids_conceptos = relaciones_termino->getRelacionConConceptos()->getIdsGrupo();

    for (std::vector<aplicacion::ID*>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        modelo::relaciones::RelacionesConcepto relaciones_concepto(*it);
        IAdministradorAplicacion::getInstancia()->recuperar(&relaciones_concepto);
        relaciones_concepto.eliminarRelacionConTermino(id_termino);
        IAdministradorAplicacion::getInstancia()->modificar(&relaciones_concepto);
    }

    return true;
}

bool GestorRelaciones::desvincular(modelo::relaciones::RelacionesConcepto * relaciones_concepto, aplicacion::ID * id_concepto)
{
    std::vector<aplicacion::ID*> ids_terminos = relaciones_concepto->getRelacionConTerminos()->getIdsGrupo();

    for (std::vector<aplicacion::ID*>::iterator it = ids_terminos.begin(); it != ids_terminos.end(); it++)
    {
        modelo::relaciones::RelacionesTermino relaciones_termino(*it);
        IAdministradorAplicacion::getInstancia()->recuperar(&relaciones_termino);
        relaciones_termino.eliminarRelacionConConcepto(id_concepto);
        IAdministradorAplicacion::getInstancia()->modificar(&relaciones_termino);
    }

    return true;
}

