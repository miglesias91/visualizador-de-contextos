#include "DialogoConsultas.h"
#include "ui_DialogoConsultas.h"

DialogoConsultas::DialogoConsultas(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoConsultas();
    ui->setupUi(this);
 
    this->setAttribute(Qt::WA_DeleteOnClose);
}

DialogoConsultas::~DialogoConsultas()
{
    delete ui;
}

void DialogoConsultas::on_action_agregar_conceptos_triggered()
{

}

void DialogoConsultas::on_action_sacar_conceptos_triggered()
{

}

void DialogoConsultas::on_action_setear_periodo_triggered()
{

}

void DialogoConsultas::on_action_agregar_medios_triggered()
{

}

void DialogoConsultas::on_action_agregar_secciones_triggered()
{

}

void DialogoConsultas::on_action_sacar_medios_triggered()
{

}

void DialogoConsultas::on_action_sacar_secciones_triggered()
{

}

void DialogoConsultas::on_action_agregar_reportes_triggered()
{

}

void DialogoConsultas::on_action_sacar_reportes_triggered()
{

}

void DialogoConsultas::on_action_realizar_consulta_y_cerrar_triggered()
{

}
