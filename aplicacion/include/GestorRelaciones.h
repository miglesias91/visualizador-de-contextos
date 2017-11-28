#pragma once

// modelo
#include <modelo/include/RelacionesConcepto.h>
#include <modelo/include/RelacionesConsulta.h>
#include <modelo/include/RelacionesFecha.h>
#include <modelo/include/RelacionesMedio.h>
#include <modelo/include/RelacionesPeriodo.h>
#include <modelo/include/RelacionesReporte.h>
#include <modelo/include/RelacionesSeccion.h>
#include <modelo/include/RelacionesTermino.h>

using namespace visualizador;

namespace visualizador
{
namespace aplicacion
{

class GestorRelaciones
{
public:
    GestorRelaciones();
    virtual ~GestorRelaciones();

    // GETTERS

    // SETTERS

    // METODOS

    virtual bool vincular(modelo::relaciones::RelacionesTermino * relaciones_termino, aplicacion::ID * id_termino);
    virtual bool vincular(modelo::relaciones::RelacionesConcepto * relaciones_concepto, aplicacion::ID * id_concepto);

    virtual bool desvincular(modelo::relaciones::RelacionesTermino * relaciones_termino, aplicacion::ID * id_termino);
    virtual bool desvincular(modelo::relaciones::RelacionesConcepto * relaciones_termino, aplicacion::ID * id_concepto);

private:

};

};
};


