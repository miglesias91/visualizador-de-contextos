#pragma once

#include <QWidget>

// modelo
#include <modelo/include/Concepto.h>
#include <modelo/include/Consulta.h>
#include <modelo/include/Fecha.h>
#include <modelo/include/Periodo.h>
#include <modelo/include/Termino.h>

Q_DECLARE_METATYPE(visualizador::modelo::Concepto*)
Q_DECLARE_METATYPE(visualizador::modelo::Fecha*)
Q_DECLARE_METATYPE(visualizador::modelo::Periodo*)
Q_DECLARE_METATYPE(visualizador::modelo::Termino*)
Q_DECLARE_METATYPE(visualizador::modelo::Consulta*)
