#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal), dialogo_terminos(NULL)
{
    ui->setupUi(this);
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::on_actionAbrirTerminos_triggered()
{
    this->dialogo_terminos = new DialogoTerminos();
    dialogo_terminos->show();

	std::cout << "HOLA" << std::endl;
}
