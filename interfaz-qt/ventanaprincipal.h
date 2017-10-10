#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

// stl
#include <iostream>

// qt
#include <QtWidgets/qmainwindow.h>

// dialogos
#include "dialogoterminos.h"

namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaPrincipal(QWidget *parent = 0);
    ~VentanaPrincipal();

private slots:

    void on_actionAbrirTerminos_triggered();

private:
    Ui::VentanaPrincipal *ui;

	DialogoTerminos* dialogo_terminos;
};

#endif // VENTANAPRINCIPAL_H
