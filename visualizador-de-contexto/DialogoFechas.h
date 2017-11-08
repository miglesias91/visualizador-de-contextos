#pragma once

#include <QWidget>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

namespace Ui { class DialogoFechas; };

class DialogoFechas : public QWidget
{
    Q_OBJECT

public:
    DialogoFechas(QWidget *parent = Q_NULLPTR);
    ~DialogoFechas();

private:
    Ui::DialogoFechas *ui;

    // ATRIBUTOS

    visualizador::aplicacion::GestorEntidades gestor_fechas;

    visualizador::aplicacion::GestorEntidades gestor_periodos;
};
