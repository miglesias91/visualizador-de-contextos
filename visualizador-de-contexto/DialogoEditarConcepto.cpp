#include "DialogoEditarConcepto.h"
#include "ui_DialogoEditarConcepto.h"

DialogoEditarConcepto::DialogoEditarConcepto(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoEditarConcepto();
    ui->setupUi(this);
}

DialogoEditarConcepto::~DialogoEditarConcepto()
{
    delete ui;
}
