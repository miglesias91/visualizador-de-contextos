#include "DialogoTerminos.h"
#include "ui_DialogoTerminos.h"

// modelo
#include <modelo/include/Termino.h>

using namespace visualizador;

DialogoTerminos::DialogoTerminos(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::DialogoTerminos();
	ui->setupUi(this);

	this->setAttribute(Qt::WA_DeleteOnClose);
}

DialogoTerminos::~DialogoTerminos()
{
	delete ui;
}

void DialogoTerminos::on_action_actualizarYCerrar_triggered()
{
	this->actualizarTerminos();
	this->close();
}

void DialogoTerminos::on_action_resetear_triggered()
{
	this->ui->lineedit_etiqueta->clear();
	this->ui->lineedit_termino->clear();
}

void DialogoTerminos::on_action_guardar_triggered()
{
	std::string etiqueta = this->ui->lineedit_etiqueta->text().toStdString();
	std::string termino = this->ui->lineedit_termino->text().toStdString();

	modelo::Termino* nuevo_termino = new modelo::Termino(termino, etiqueta);

	QString item((etiqueta + " / " + termino).c_str());

	this->ui->lista_terminos->insertItem(0, item);

	this->on_action_resetear_triggered();
}

void DialogoTerminos::actualizarTerminos()
{
}
