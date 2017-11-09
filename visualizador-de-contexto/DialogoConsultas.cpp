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
