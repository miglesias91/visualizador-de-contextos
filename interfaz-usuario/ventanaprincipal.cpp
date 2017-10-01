#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

void VentanaPrincipal::on_btn_termino_released()
{

}

void VentanaPrincipal::on_btn_conceptos_released()
{

}

void VentanaPrincipal::on_btn_fechas_released()
{

}

void VentanaPrincipal::on_btn_periodos_released()
{

}

void VentanaPrincipal::on_btn_secciones_released()
{

}

void VentanaPrincipal::on_btn_medios_released()
{

}

void VentanaPrincipal::on_btn_consulta_released()
{

}
