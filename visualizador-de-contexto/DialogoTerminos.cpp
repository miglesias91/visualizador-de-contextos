#include "DialogoTerminos.h"
#include "ui_DialogoTerminos.h"

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

// modelo
#include <modelo/include/Termino.h>

using namespace visualizador;

DialogoTerminos::DialogoTerminos(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::DialogoTerminos();
	ui->setupUi(this);

	this->setAttribute(Qt::WA_DeleteOnClose);

	this->terminos_actuales = aplicacion::GestorEntidades::recuperarTerminos();
	for (std::vector<modelo::Termino*>::iterator it = this->terminos_actuales.begin(); it != this->terminos_actuales.end(); it++)
	{
		this->agregarTerminoALista(*it);
	}
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

	this->agregarTerminoALista(nuevo_termino);

	this->terminos_a_agregar.push_back(nuevo_termino);

	this->on_action_resetear_triggered();
}

void DialogoTerminos::on_action_eliminar_triggered()
{
	QList<QListWidgetItem*> items = ui->lista_terminos->selectedItems();
	foreach(QListWidgetItem * item, items)
	{
		QVariant data = item->data(Qt::UserRole);
		modelo::Termino* termino = data.value<modelo::Termino*>();
		this->terminos_a_eliminar.push_back(termino);

		delete ui->lista_terminos->takeItem(ui->listWidget->row(item));
	}

}

// METODOS PRIVADOS

void DialogoTerminos::actualizarTerminos()
{
}

void DialogoTerminos::agregarTerminoALista(modelo::Termino * termino)
{
	QListWidgetItem* item = new QListWidgetItem();

	QVariant data;
	data.fromValue(termino);
	item->setData(Qt::UserRole, data);
	item->setText((termino->getEtiqueta() + " - " + termino->getValor()).c_str());

	this->ui->lista_terminos->addItem(item);
}
