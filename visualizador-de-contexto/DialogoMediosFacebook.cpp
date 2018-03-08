#include "DialogoMediosFacebook.h"
#include "ui_DialogoMediosFacebook.h"

DialogoMediosFacebook::DialogoMediosFacebook(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoMediosFacebook();
    ui->setupUi(this);
}

DialogoMediosFacebook::~DialogoMediosFacebook()
{
    delete ui;
}
