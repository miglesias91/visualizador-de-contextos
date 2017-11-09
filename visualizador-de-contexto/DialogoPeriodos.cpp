#include "DialogoPeriodos.h"
#include "ui_DialogoPeriodos.h"

DialogoPeriodos::DialogoPeriodos(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoPeriodos();
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);
}

DialogoPeriodos::~DialogoPeriodos()
{
    delete ui;
}

void DialogoPeriodos::on_action_guardar_periodo_triggered()
{

}

void DialogoPeriodos::on_action_limpiar_periodo_triggered()
{

}

void DialogoPeriodos::on_action_eliminar_periodo_triggered()
{

}

void DialogoPeriodos::on_action_actualizar_y_cerrar_triggered()
{

}

void DialogoPeriodos::on_action_estado_btn_eliminar_triggered()
{

}
