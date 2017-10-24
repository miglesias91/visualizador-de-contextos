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

	std::vector<visualizador::modelo::Termino*> terminos_actuales = this->gestor_terminos.gestionarTerminos();
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
	unsigned int count = ui->lista_terminos->count();
	while(0 != ui->lista_terminos->count())
	{
		count = ui->lista_terminos->count();

		item = ui->lista_terminos->takeItem(0);
		delete item;
	}

	delete ui;
}

void DialogoTerminos::on_action_actualizarYCerrar_triggered()
{
	this->close();
}

// METODOS PRIVADOS

void DialogoTerminos::agregarTerminoALista(modelo::Termino * termino)
{
	QListWidgetItem* item = new QListWidgetItem();

	QVariant data = QVariant::fromValue(termino);
	item->setData(Qt::UserRole, data);
	item->setText((termino->getEtiqueta() + " - " + termino->getValor()).c_str());

	this->ui->lista_terminos->addItem(item);
}

void DialogoTerminos::on_action_resetear_termino_triggered()
{
    this->ui->lineedit_etiqueta->clear();
    this->ui->lineedit_termino->clear();
}

void DialogoTerminos::on_action_guardar_termino_triggered()
{
    std::string etiqueta = this->ui->lineedit_etiqueta->text().toStdString();
    std::string termino = this->ui->lineedit_termino->text().toStdString();

    modelo::Termino* termino_nuevo = new modelo::Termino(termino, etiqueta);

    if (this->gestor_terminos.existe(termino_nuevo))
    {
        // TODO implementar 'ExcepcionTerminoExistente'.
        std::string mensaje("El t�rmino '" + termino_nuevo->getValor() + "' ya existe.");
        throw std::exception(mensaje.c_str());
        return;
    }

    // lo agrego en la lista visible.
    this->agregarTerminoALista(termino_nuevo);

    this->gestor_terminos.almacenar(termino_nuevo);

    this->on_action_resetear_termino_triggered();
}

void DialogoTerminos::on_action_eliminar_termino_triggered()
{
    QList<QListWidgetItem*> items = ui->lista_terminos->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QVariant data = item->data(Qt::UserRole);
        modelo::Termino* termino = data.value<modelo::Termino*>();

        this->gestor_terminos.eliminar(termino);

        delete ui->lista_terminos->takeItem(ui->lista_terminos->row(item));
    }
}
