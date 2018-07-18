#include <aplicacion/include/GestorRelaciones.h>

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>

using namespace visualizador::aplicacion;
using namespace visualizador;

GestorRelaciones::GestorRelaciones()
{
    this->admin_app = IAdministradorAplicacion::getInstanciaAdminEntidades();
}

GestorRelaciones::~GestorRelaciones()
{
}

// VINCULACIONES

bool GestorRelaciones::vincular(modelo::relaciones::RelacionesConcepto * relaciones_concepto, herramientas::utiles::ID * id_concepto)
{
    std::vector<herramientas::utiles::ID*> ids_terminos = relaciones_concepto->getRelacionConTerminos()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_terminos.begin(); it != ids_terminos.end(); it++)
    {
        modelo::relaciones::RelacionesTermino relaciones_termino((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_termino))
        {
            relaciones_termino.agregarRelacionConConcepto(id_concepto);
            this->admin_app->modificar(&relaciones_termino);
        }
    }

    std::vector<herramientas::utiles::ID*> ids_consultas = relaciones_concepto->getRelacionConConsultas()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        modelo::relaciones::RelacionesConsulta relaciones_consulta((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_consulta))
        {
            relaciones_consulta.agregarRelacionConConcepto(id_concepto);
            this->admin_app->modificar(&relaciones_consulta);
        }
    }

    return true;
}

bool GestorRelaciones::vincular(modelo::relaciones::RelacionesConsulta * relaciones_consulta, herramientas::utiles::ID * id_consulta)
{
    std::vector<herramientas::utiles::ID*> ids_conceptos = relaciones_consulta->getRelacionConConceptos()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        modelo::relaciones::RelacionesConcepto relaciones_concepto((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_concepto))
        {
            relaciones_concepto.agregarRelacionConConsulta(id_consulta);
            this->admin_app->modificar(&relaciones_concepto);
        }
    }

    std::vector<herramientas::utiles::ID*> ids_medios_twitter = relaciones_consulta->getRelacionConMediosTwitter()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_medios_twitter.begin(); it != ids_medios_twitter.end(); it++)
    {
        modelo::relaciones::RelacionesMedio relaciones_medio((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_medio))
        {
            relaciones_medio.agregarRelacionConConsulta(id_consulta);
            this->admin_app->modificar(&relaciones_medio);
        }
    }

    std::vector<herramientas::utiles::ID*> ids_secciones = relaciones_consulta->getRelacionConSecciones()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_secciones.begin(); it != ids_secciones.end(); it++)
    {
        modelo::relaciones::RelacionesSeccion relaciones_seccion((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_seccion))
        {
            relaciones_seccion.agregarRelacionConConsulta(id_consulta);
            this->admin_app->modificar(&relaciones_seccion);
        }
    }

    herramientas::utiles::ID id_reporte(relaciones_consulta->getRelacionConReporte());

    modelo::relaciones::RelacionesReporte relaciones_reporte(id_reporte.copia());
    if (this->admin_app->recuperar(&relaciones_reporte))
    {
        relaciones_reporte.agregarRelacionConConsulta(id_consulta);
        this->admin_app->modificar(&relaciones_reporte);
    }

    herramientas::utiles::ID id_periodo(relaciones_consulta->getRelacionConPeriodo());

    modelo::relaciones::RelacionesPeriodo relaciones_periodo(id_periodo.copia());
    if (this->admin_app->recuperar(&relaciones_periodo))
    {
        relaciones_periodo.agregarRelacionConConsulta(id_consulta);
        this->admin_app->modificar(&relaciones_periodo);
    }

    return true;
}

bool GestorRelaciones::vincular(modelo::relaciones::RelacionesPeriodo * relaciones_periodo, herramientas::utiles::ID * id_periodo)
{
    std::vector<herramientas::utiles::ID*> ids_consultas = relaciones_periodo->getRelacionConConsultas()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        modelo::relaciones::RelacionesConsulta relaciones_consulta((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_consulta))
        {
            relaciones_consulta.setRelacionConPeriodo(id_periodo->numero());
            this->admin_app->modificar(&relaciones_consulta);
        }
    }

    herramientas::utiles::ID id_fecha_desde(relaciones_periodo->getRelacionConFechaDesde());

    modelo::relaciones::RelacionesFecha relaciones_fecha_desde(id_fecha_desde.copia());
    if (this->admin_app->recuperar(&relaciones_fecha_desde))
    {
        relaciones_fecha_desde.agregarRelacionConPeriodo(id_periodo);
        this->admin_app->modificar(&relaciones_fecha_desde);
    }

    herramientas::utiles::ID id_fecha_hasta(relaciones_periodo->getRelacionConFechaHasta());

    modelo::relaciones::RelacionesFecha relaciones_fecha_hasta(id_fecha_hasta.copia());
    if (this->admin_app->recuperar(&relaciones_fecha_hasta))
    {
        relaciones_fecha_hasta.agregarRelacionConPeriodo(id_periodo);
        this->admin_app->modificar(&relaciones_fecha_hasta);
    }

    return true;
}

bool GestorRelaciones::vincular(modelo::relaciones::RelacionesFecha * relaciones_fecha, herramientas::utiles::ID * id_fecha)
{
    return true;
}

bool GestorRelaciones::vincular(modelo::relaciones::RelacionesReporte * relaciones_reporte, herramientas::utiles::ID * id_reporte)
{
    std::vector<herramientas::utiles::ID*> ids_consultas = relaciones_reporte->getRelacionConConsultas()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        modelo::relaciones::RelacionesConsulta relaciones_consulta((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_consulta))
        {
            relaciones_consulta.setRelacionConReporte(id_reporte->numero());
            this->admin_app->modificar(&relaciones_consulta);
        }
    }

    return true;
}

bool GestorRelaciones::vincular(modelo::relaciones::RelacionesSeccion * relaciones_seccion, herramientas::utiles::ID * id_seccion)
{
    std::vector<herramientas::utiles::ID*> ids_consultas = relaciones_seccion->getRelacionConConsultas()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        modelo::relaciones::RelacionesConsulta relaciones_consulta((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_consulta))
        {
            relaciones_consulta.agregarRelacionConSeccion(id_seccion);
            this->admin_app->modificar(&relaciones_consulta);
        }
    }

    return true;
}

bool GestorRelaciones::vincular(modelo::relaciones::RelacionesTermino * relaciones_termino, herramientas::utiles::ID * id_termino)
{
    std::vector<herramientas::utiles::ID*> ids_conceptos = relaciones_termino->getRelacionConConceptos()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        modelo::relaciones::RelacionesConcepto relaciones_concepto((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_concepto))
        {
            relaciones_concepto.agregarRelacionConTermino(id_termino);
            this->admin_app->modificar(&relaciones_concepto);
        }
    }

    return true;
}

bool GestorRelaciones::vincularMedioTwitter(modelo::relaciones::RelacionesMedio * relaciones_medio, herramientas::utiles::ID * id_medio)
{
    std::vector<herramientas::utiles::ID*> ids_consultas = relaciones_medio->getRelacionConConsultas()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        modelo::relaciones::RelacionesConsulta relaciones_consulta((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_consulta))
        {
            relaciones_consulta.agregarRelacionConMedioTwitter(id_medio);
            this->admin_app->modificar(&relaciones_consulta);
        }
    }

    return true;
}

bool GestorRelaciones::vincularMedioFacebook(modelo::relaciones::RelacionesMedio * relaciones_medio, herramientas::utiles::ID * id_medio)
{
    std::vector<herramientas::utiles::ID*> ids_consultas = relaciones_medio->getRelacionConConsultas()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        modelo::relaciones::RelacionesConsulta relaciones_consulta((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_consulta))
        {
            relaciones_consulta.agregarRelacionConMedioFacebook(id_medio);
            this->admin_app->modificar(&relaciones_consulta);
        }
    }

    return true;
}

bool GestorRelaciones::vincularMedioPortalNoticias(modelo::relaciones::RelacionesMedio * relaciones_medio, herramientas::utiles::ID * id_medio)
{
    std::vector<herramientas::utiles::ID*> ids_consultas = relaciones_medio->getRelacionConConsultas()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        modelo::relaciones::RelacionesConsulta relaciones_consulta((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_consulta))
        {
            relaciones_consulta.agregarRelacionConMedioPortalNoticias(id_medio);
            this->admin_app->modificar(&relaciones_consulta);
        }
    }

    return true;
}

// DESVINCULACIONES

bool GestorRelaciones::desvincular(modelo::relaciones::RelacionesConcepto * relaciones_concepto, herramientas::utiles::ID * id_concepto)
{
    std::vector<herramientas::utiles::ID*> ids_terminos = relaciones_concepto->getRelacionConTerminos()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_terminos.begin(); it != ids_terminos.end(); it++)
    {
        modelo::relaciones::RelacionesTermino relaciones_termino((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_termino))
        {
            relaciones_termino.eliminarRelacionConConcepto(id_concepto);
            this->admin_app->modificar(&relaciones_termino);
        }
    }

    std::vector<herramientas::utiles::ID*> ids_consultas = relaciones_concepto->getRelacionConConsultas()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        modelo::relaciones::RelacionesConsulta relaciones_consulta((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_consulta))
        {
            relaciones_consulta.eliminarRelacionConConcepto(id_concepto);
            this->admin_app->modificar(&relaciones_consulta);
        }

    }

    return true;
}

bool GestorRelaciones::desvincular(modelo::relaciones::RelacionesConsulta * relaciones_consulta, herramientas::utiles::ID * id_consulta)
{
    std::vector<herramientas::utiles::ID*> ids_conceptos = relaciones_consulta->getRelacionConConceptos()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        modelo::relaciones::RelacionesConcepto relaciones_concepto((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_concepto))
        {
            relaciones_concepto.eliminarRelacionConConsulta(id_consulta);
            this->admin_app->modificar(&relaciones_concepto);
        }
    }

    std::vector<herramientas::utiles::ID*> ids_medios = relaciones_consulta->getRelacionConMediosTwitter()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_medios.begin(); it != ids_medios.end(); it++)
    {
        modelo::relaciones::RelacionesMedio relaciones_medio((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_medio))
        {
            relaciones_medio.eliminarRelacionConConsulta(id_consulta);
            this->admin_app->modificar(&relaciones_medio);
        }
    }

    std::vector<herramientas::utiles::ID*> ids_secciones = relaciones_consulta->getRelacionConSecciones()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_secciones.begin(); it != ids_secciones.end(); it++)
    {
        modelo::relaciones::RelacionesSeccion relaciones_seccion((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_seccion))
        {
            relaciones_seccion.eliminarRelacionConConsulta(id_consulta);
            this->admin_app->modificar(&relaciones_seccion);
        }
    }

    herramientas::utiles::ID id_reporte(relaciones_consulta->getRelacionConReporte());

    modelo::relaciones::RelacionesReporte relaciones_reporte(id_reporte.copia());
    if (this->admin_app->recuperar(&relaciones_reporte))
    {
        relaciones_reporte.eliminarRelacionConConsulta(id_consulta);
        this->admin_app->modificar(&relaciones_reporte);
    }

    herramientas::utiles::ID id_periodo(relaciones_consulta->getRelacionConPeriodo());

    modelo::relaciones::RelacionesPeriodo relaciones_periodo(id_periodo.copia());
    if (this->admin_app->recuperar(&relaciones_periodo))
    {
        relaciones_periodo.eliminarRelacionConConsulta(id_consulta);
        this->admin_app->modificar(&relaciones_periodo);
    }

    return true;
}

bool GestorRelaciones::desvincular(modelo::relaciones::RelacionesFecha * relaciones_fecha, herramientas::utiles::ID * id_fecha)
{
    return false;
}

bool GestorRelaciones::desvincular(modelo::relaciones::RelacionesPeriodo * relaciones_periodo, herramientas::utiles::ID * id_periodo)
{
    std::vector<herramientas::utiles::ID*> ids_consultas = relaciones_periodo->getRelacionConConsultas()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        modelo::relaciones::RelacionesConsulta relaciones_consulta((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_consulta))
        {
            relaciones_consulta.setRelacionConPeriodo(0);
            this->admin_app->modificar(&relaciones_consulta);
        }
    }

    herramientas::utiles::ID id_fecha_desde(relaciones_periodo->getRelacionConFechaDesde());

    modelo::relaciones::RelacionesFecha relaciones_fecha_desde(id_fecha_desde.copia());
    if (this->admin_app->recuperar(&relaciones_fecha_desde))
    {
        relaciones_fecha_desde.eliminarRelacionConPeriodo(id_periodo);
        this->admin_app->modificar(&relaciones_fecha_desde);
    }

    herramientas::utiles::ID id_fecha_hasta(relaciones_periodo->getRelacionConFechaHasta());

    modelo::relaciones::RelacionesFecha relaciones_fecha_hasta(id_fecha_hasta.copia());
    if (this->admin_app->recuperar(&relaciones_fecha_hasta))
    {
        relaciones_fecha_hasta.eliminarRelacionConPeriodo(id_periodo);
        this->admin_app->modificar(&relaciones_fecha_hasta);
    }

    return true;
}

bool GestorRelaciones::desvincular(modelo::relaciones::RelacionesReporte * relaciones_reporte, herramientas::utiles::ID * id_reporte)
{
    std::vector<herramientas::utiles::ID*> ids_consultas = relaciones_reporte->getRelacionConConsultas()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        modelo::relaciones::RelacionesConsulta relaciones_consulta((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_consulta))
        {
            relaciones_consulta.setRelacionConReporte(0);
            this->admin_app->modificar(&relaciones_consulta);
        }
    }

    return true;
}

bool GestorRelaciones::desvincular(modelo::relaciones::RelacionesSeccion * relaciones_seccion, herramientas::utiles::ID * id_seccion)
{
    std::vector<herramientas::utiles::ID*> ids_consultas = relaciones_seccion->getRelacionConConsultas()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        modelo::relaciones::RelacionesConsulta relaciones_consulta((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_consulta))
        {
            relaciones_consulta.eliminarRelacionConSeccion(id_seccion);
            this->admin_app->modificar(&relaciones_consulta);
        }
    }

    return true;
}

bool GestorRelaciones::desvincular(modelo::relaciones::RelacionesTermino * relaciones_termino, herramientas::utiles::ID * id_termino)
{
    std::vector<herramientas::utiles::ID*> ids_conceptos = relaciones_termino->getRelacionConConceptos()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_conceptos.begin(); it != ids_conceptos.end(); it++)
    {
        modelo::relaciones::RelacionesConcepto relaciones_concepto((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_concepto))
        {
            relaciones_concepto.eliminarRelacionConTermino(id_termino);
            this->admin_app->modificar(&relaciones_concepto);
        }
    }

    return true;
}

bool GestorRelaciones::desvincularMedioTwitter(modelo::relaciones::RelacionesMedio * relaciones_medio, herramientas::utiles::ID * id_medio)
{
    std::vector<herramientas::utiles::ID*> ids_consultas = relaciones_medio->getRelacionConConsultas()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        modelo::relaciones::RelacionesConsulta relaciones_consulta((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_consulta))
        {
            relaciones_consulta.eliminarRelacionConMedioTwitter(id_medio);
            this->admin_app->modificar(&relaciones_consulta);
        }
    }

    return true;
}

bool GestorRelaciones::desvincularMedioFacebook(modelo::relaciones::RelacionesMedio * relaciones_medio, herramientas::utiles::ID * id_medio)
{
    std::vector<herramientas::utiles::ID*> ids_consultas = relaciones_medio->getRelacionConConsultas()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        modelo::relaciones::RelacionesConsulta relaciones_consulta((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_consulta))
        {
            relaciones_consulta.eliminarRelacionConMedioFacebook(id_medio);
            this->admin_app->modificar(&relaciones_consulta);
        }
    }

    return true;
}

bool GestorRelaciones::desvincularMedioPortalNoticias(modelo::relaciones::RelacionesMedio * relaciones_medio, herramientas::utiles::ID * id_medio)
{
    std::vector<herramientas::utiles::ID*> ids_consultas = relaciones_medio->getRelacionConConsultas()->getIdsGrupo();

    for (std::vector<herramientas::utiles::ID*>::iterator it = ids_consultas.begin(); it != ids_consultas.end(); it++)
    {
        modelo::relaciones::RelacionesConsulta relaciones_consulta((*it)->copia());
        if (this->admin_app->recuperar(&relaciones_consulta))
        {
            relaciones_consulta.eliminarRelacionConMedioPortalNoticias(id_medio);
            this->admin_app->modificar(&relaciones_consulta);
        }
    }

    return true;
}
