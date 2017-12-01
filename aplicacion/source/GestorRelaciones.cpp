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

// VINCULACIONES

bool GestorRelaciones::vincular(modelo::relaciones::RelacionesConcepto * relaciones_concepto, aplicacion::ID * id_concepto)
{
    std::vector<aplicacion::ID*> ids_terminos = relaciones_concepto->getRelacionConTerminos()->getIdsGrupo();

    for (std::vector<aplicacion::ID*>::iterator it = ids_terminos.begin(); it != ids_terminos.end(); it++)
    {
        modelo::relaciones::RelacionesTermino relaciones_termino((*it)->copia());
        IAdministradorAplicacion::getInstancia()->recuperar(&relaciones_termino);
        relaciones_termino.agregarRelacionConConcepto(id_concepto);
        IAdministradorAplicacion::getInstancia()->modificar(&relaciones_termino);
    }

    std::vector<aplicacion::ID*> ids_consultas = relaciones_concepto->getRelacionConConsultas()->getIdsGrupo();

    for (std::vector<aplicacion::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        modelo::relaciones::RelacionesConsulta relaciones_consulta((*it)->copia());
        IAdministradorAplicacion::getInstancia()->recuperar(&relaciones_consulta);
        relaciones_consulta.agregarRelacionConConcepto(id_concepto);
        IAdministradorAplicacion::getInstancia()->modificar(&relaciones_consulta);
    }

    return true;
}

bool GestorRelaciones::vincular(modelo::relaciones::RelacionesConsulta * relaciones_consulta, aplicacion::ID * id_consulta)
{
    std::vector<aplicacion::ID*> ids_conceptos = relaciones_consulta->getRelacionConConceptos()->getIdsGrupo();

    for (std::vector<aplicacion::ID*>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        modelo::relaciones::RelacionesConcepto relaciones_concepto((*it)->copia());
        IAdministradorAplicacion::getInstancia()->recuperar(&relaciones_concepto);
        relaciones_concepto.agregarRelacionConConsulta(id_consulta);
        IAdministradorAplicacion::getInstancia()->modificar(&relaciones_concepto);
    }

    std::vector<aplicacion::ID*> ids_medios = relaciones_consulta->getRelacionConMedios()->getIdsGrupo();

    for (std::vector<aplicacion::ID*>::iterator it = ids_medios.begin(); it != ids_medios.end(); it++)
    {
        modelo::relaciones::RelacionesMedio relaciones_medio((*it)->copia());
        IAdministradorAplicacion::getInstancia()->recuperar(&relaciones_medio);
        relaciones_medio.agregarRelacionConConsulta(id_consulta);
        IAdministradorAplicacion::getInstancia()->modificar(&relaciones_medio);
    }

    std::vector<aplicacion::ID*> ids_secciones = relaciones_consulta->getRelacionConSecciones()->getIdsGrupo();

    for (std::vector<aplicacion::ID*>::iterator it = ids_secciones.begin(); it != ids_secciones.end(); it++)
    {
        modelo::relaciones::RelacionesSeccion relaciones_seccion((*it)->copia());
        IAdministradorAplicacion::getInstancia()->recuperar(&relaciones_seccion);
        relaciones_seccion.agregarRelacionConConsulta(id_consulta);
        IAdministradorAplicacion::getInstancia()->modificar(&relaciones_seccion);
    }

    aplicacion::ID id_reporte(relaciones_consulta->getRelacionConReporte());

    modelo::relaciones::RelacionesReporte relaciones_reporte(id_reporte.copia());
    IAdministradorAplicacion::getInstancia()->recuperar(&relaciones_reporte);
    relaciones_reporte.agregarRelacionConConsulta(id_consulta);
    IAdministradorAplicacion::getInstancia()->modificar(&relaciones_reporte);

    aplicacion::ID id_periodo(relaciones_consulta->getRelacionConPeriodo());

    modelo::relaciones::RelacionesPeriodo relaciones_periodo(id_periodo.copia());
    IAdministradorAplicacion::getInstancia()->recuperar(&relaciones_periodo);
    relaciones_periodo.agregarRelacionConConsulta(id_consulta);
    IAdministradorAplicacion::getInstancia()->modificar(&relaciones_periodo);

    return true;
}

bool GestorRelaciones::vincularFechaDesde(modelo::relaciones::RelacionesFecha * relaciones_fecha, aplicacion::ID * id_fecha)
{
    std::vector<aplicacion::ID*> ids_periodos = relaciones_fecha->getRelacionConPeriodos()->getIdsGrupo();

    for (std::vector<aplicacion::ID*>::iterator it = ids_periodos.begin(); it != ids_periodos.end(); it++)
    {
        modelo::relaciones::RelacionesPeriodo relaciones_periodo((*it)->copia());
        IAdministradorAplicacion::getInstancia()->recuperar(&relaciones_periodo);
        relaciones_periodo.setRelacionConFechaDesde(id_fecha);
        IAdministradorAplicacion::getInstancia()->modificar(&relaciones_periodo);
    }

    return true;
}

bool GestorRelaciones::vincular(modelo::relaciones::RelacionesMedio * relaciones_medio, aplicacion::ID * id_medio)
{
    relaciones_medio->get
    return false;
}

bool GestorRelaciones::vincular(modelo::relaciones::RelacionesPeriodo * relaciones_periodo, aplicacion::ID * id_periodo)
{
    return false;
}

bool GestorRelaciones::vincular(modelo::relaciones::RelacionesReporte * relaciones_reporte, aplicacion::ID * id_reporte)
{
    return false;
}

bool GestorRelaciones::vincular(modelo::relaciones::RelacionesSeccion * relaciones_seccion, aplicacion::ID * id_seccion)
{
    return false;
}

bool GestorRelaciones::vincular(modelo::relaciones::RelacionesTermino * relaciones_termino, aplicacion::ID * id_termino)
{
    std::vector<aplicacion::ID*> ids_conceptos = relaciones_termino->getRelacionConConceptos()->getIdsGrupo();

    for (std::vector<aplicacion::ID*>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        modelo::relaciones::RelacionesConcepto relaciones_concepto((*it)->copia());
        IAdministradorAplicacion::getInstancia()->recuperar(&relaciones_concepto);
        relaciones_concepto.agregarRelacionConTermino(id_termino);
        IAdministradorAplicacion::getInstancia()->modificar(&relaciones_concepto);
    }

    return true;
}

// DESVINCULACIONES

bool GestorRelaciones::desvincular(modelo::relaciones::RelacionesConcepto * relaciones_concepto, aplicacion::ID * id_concepto)
{
    std::vector<aplicacion::ID*> ids_terminos = relaciones_concepto->getRelacionConTerminos()->getIdsGrupo();

    for (std::vector<aplicacion::ID*>::iterator it = ids_terminos.begin(); it != ids_terminos.end(); it++)
    {
        modelo::relaciones::RelacionesTermino relaciones_termino((*it)->copia());
        IAdministradorAplicacion::getInstancia()->recuperar(&relaciones_termino);
        relaciones_termino.eliminarRelacionConConcepto(id_concepto);
        IAdministradorAplicacion::getInstancia()->modificar(&relaciones_termino);
    }

    std::vector<aplicacion::ID*> ids_consultas = relaciones_concepto->getRelacionConConsultas()->getIdsGrupo();

    for (std::vector<aplicacion::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        modelo::relaciones::RelacionesConsulta relaciones_consulta((*it)->copia());
        IAdministradorAplicacion::getInstancia()->recuperar(&relaciones_consulta);
        relaciones_consulta.eliminarRelacionConConcepto(id_concepto);
        IAdministradorAplicacion::getInstancia()->modificar(&relaciones_consulta);
    }

    return true;
}

bool GestorRelaciones::desvincular(modelo::relaciones::RelacionesConsulta * relaciones_consulta, aplicacion::ID * id_consulta)
{
    return false;
}

bool GestorRelaciones::desvincular(modelo::relaciones::RelacionesFecha * relaciones_fecha, aplicacion::ID * id_fecha)
{
    return false;
}

bool GestorRelaciones::desvincular(modelo::relaciones::RelacionesMedio * relaciones_medio, aplicacion::ID * id_medio)
{
    return false;
}

bool GestorRelaciones::desvincular(modelo::relaciones::RelacionesPeriodo * relaciones_periodo, aplicacion::ID * id_periodo)
{
    return false;
}

bool GestorRelaciones::desvincular(modelo::relaciones::RelacionesReporte * relaciones_reporte, aplicacion::ID * id_reporte)
{
    return false;
}

bool GestorRelaciones::desvincular(modelo::relaciones::RelacionesSeccion * relaciones_seccion, aplicacion::ID * id_seccion)
{
    return false;
}

bool GestorRelaciones::desvincular(modelo::relaciones::RelacionesTermino * relaciones_termino, aplicacion::ID * id_termino)
{
    std::vector<aplicacion::ID*> ids_conceptos = relaciones_termino->getRelacionConConceptos()->getIdsGrupo();

    for (std::vector<aplicacion::ID*>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        modelo::relaciones::RelacionesConcepto relaciones_concepto((*it)->copia());
        IAdministradorAplicacion::getInstancia()->recuperar(&relaciones_concepto);
        relaciones_concepto.eliminarRelacionConTermino(id_termino);
        IAdministradorAplicacion::getInstancia()->modificar(&relaciones_concepto);
    }

    return true;
}
