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

	std::vector<visualizador::modelo::Termino*> terminos_actuales = aplicacion::GestorEntidades::recuperarTerminos();
	for (std::vector<modelo::Termino*>::iterator it = terminos_actuales.begin(); it != terminos_actuales.end(); it++)
	{
		this->agregarTerminoALista(*it);
	}
}

DialogoTerminos::~DialogoTerminos()
{
	// elimino los terminos de la lista
	QListWidgetItem* item = NULL;
	modelo::Termino* termino_lista = NULL;
	for (int i = 0; i < ui->lista_terminos->count(); ++i)
	{
		item = ui->lista_terminos->item(i);
		QVariant data = item->data(Qt::UserRole);
		termino_lista = data.value<modelo::Termino*>();
		delete termino_lista;
	}

	// elimino los terminos de la lista a eliminar
	for (this->terminos_it = this->terminos_a_eliminar.begin(); this->terminos_it != this->terminos_a_eliminar.end(); this->terminos_it++)
	{
		delete (*this->terminos_it);
	}

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

	modelo::Termino* termino_nuevo = new modelo::Termino(termino, etiqueta);

	if (this->existeTermino(termino_nuevo))
	{
		// TODO implementar 'ExcepcionTerminoExistente'.
		std::string mensaje("El término '" + termino_nuevo->getValor() + "' ya existe.");
		throw std::exception(mensaje.c_str());
		return;
	}

	// lo agrego en la lista visible.
	this->agregarTerminoALista(termino_nuevo);

	this->almacenarTermino(termino_nuevo);

	this->on_action_resetear_triggered();
}

void DialogoTerminos::on_action_eliminar_triggered()
{
	QList<QListWidgetItem*> items = ui->lista_terminos->selectedItems();
	foreach(QListWidgetItem * item, items)
	{
		QVariant data = item->data(Qt::UserRole);
		modelo::Termino* termino = data.value<modelo::Termino*>();

		this->eliminarTermino(termino);

		delete ui->lista_terminos->takeItem(ui->lista_terminos->row(item));
	}
}

// METODOS PRIVADOS

void DialogoTerminos::actualizarTerminos()
{
}

void DialogoTerminos::almacenarTermino(visualizador::modelo::Termino * termino_nuevo)
{
	// chequeo que el termino a agregar no este en la lista de eliminados:
	// si estaba en la lista de eliminados, entonces quiere decir que esta en la bd y se quiere sacar.
	// Entonces lo que hago es sacarlo de la lista de "a eliminar" y lo vuelvo a agregar a la QListWidget.
	for (this->terminos_it = this->terminos_a_eliminar.begin(); this->terminos_it != this->terminos_a_eliminar.end(); this->terminos_it++)
	{
		if ((*this->terminos_it)->hashcode() == termino_nuevo->hashcode())
		{
			this->terminos_a_eliminar.erase(this->terminos_it);
			return;
		}
	}

	// si no estaba en la lista de eliminados, entonces lo agregar a la lista de 'a almacenar'.
	this->terminos_a_almacenar.push_back(termino_nuevo);
}

void DialogoTerminos::eliminarTermino(visualizador::modelo::Termino * termino)
{
	this->terminos_it = std::find(this->terminos_a_almacenar.begin(), this->terminos_a_almacenar.end(), termino);
	if (this->terminos_a_almacenar.end() != this->terminos_it)
	{
		this->terminos_a_almacenar.erase(this->terminos_it);
	}
	else
	{
		this->terminos_a_eliminar.push_back(termino);
	}
}

bool DialogoTerminos::existeTermino(visualizador::modelo::Termino * termino)
{
	// chequeo que no exista el termino que se quiere agregar.
	QListWidgetItem* item = NULL;
	modelo::Termino* termino_lista = NULL;
	for (int i = 0; i < this->ui->lista_terminos->count(); ++i)
	{
		item = this->ui->lista_terminos->item(i);
		QVariant data = item->data(Qt::UserRole);
		termino_lista = data.value<modelo::Termino*>();

		if (termino_lista->hashcode() == termino->hashcode())
		{
			return true;
		}
	}
	return false;
}

void DialogoTerminos::agregarTerminoALista(modelo::Termino * termino)
{
	QListWidgetItem* item = new QListWidgetItem();

	QVariant data = QVariant::fromValue(termino);
	// data.fromValue(termino);
	item->setData(Qt::UserRole, data);
	item->setText((termino->getEtiqueta() + " - " + termino->getValor()).c_str());

	this->ui->lista_terminos->addItem(item);
}