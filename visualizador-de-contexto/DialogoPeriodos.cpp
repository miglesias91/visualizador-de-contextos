#include "DialogoPeriodos.h"
#include "ui_DialogoPeriodos.h"

DialogoPeriodos::DialogoPeriodos(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoPeriodos();
    ui->setupUi(this);
}

DialogoPeriodos::~DialogoPeriodos()
{
    delete ui;
}
