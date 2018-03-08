#pragma once

#include <QWidget>

// visualizador-de-contexto
#include <visualizador-de-contexto/include/FabricaMensajes.h>

// aplicacion
#include <aplicacion/include/Logger.h>

// modelo
#include <modelo/include/Concepto.h>

// visualizador
#include <declaraciones_metatipos.h>

namespace Ui { class DialogoEditarConcepto; };

class DialogoEditarConcepto : public QWidget
{
    Q_OBJECT

public:
    DialogoEditarConcepto(visualizador::modelo::Concepto * concepto_a_editar, QWidget *parent = Q_NULLPTR);
    ~DialogoEditarConcepto();

private:
    Ui::DialogoEditarConcepto *ui;
};
