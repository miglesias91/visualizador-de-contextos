#include "DialogoFechas.h"
#include "ui_DialogoFechas.h"

DialogoFechas::DialogoFechas(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoFechas();
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

}

DialogoFechas::~DialogoFechas()
{
    delete ui;
}
