#include "DialogoResultadoConsulta.h"
#include "ui_DialogoResultadoConsulta.h"

DialogoResultadoConsulta::DialogoResultadoConsulta(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoResultadoConsulta();
    ui->setupUi(this);
}

DialogoResultadoConsulta::~DialogoResultadoConsulta()
{
    delete ui;
}
