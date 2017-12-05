#include "DialogoTerminos.h"
#include "ui_DialogoTerminos.h"

// visualizador-de-contexto
#include <visualizador-de-contexto/include/FabricaMensajes.h>

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

    this->cargarListaTerminos();

    this->on_action_resetear_termino_triggered();
}

DialogoTerminos::~DialogoTerminos()
{
    this->descargarListaTerminos();

	delete ui;
}

// ACCIONES

void DialogoTerminos::on_action_actualizar_y_cerrar_triggered()
{
    this->gestor_terminos.guardarCambios();
	this->close();
}

void DialogoTerminos::on_action_resetear_termino_triggered()
{
    this->ui->lineedit_etiqueta->clear();
    this->ui->lineedit_termino->clear();

    this->on_action_estado_btn_eliminar_triggered();
}

void DialogoTerminos::on_action_guardar_termino_triggered()
{
    std::string etiqueta = this->ui->lineedit_etiqueta->text().toStdString();
    std::string termino = this->ui->lineedit_termino->text().toStdString();

    modelo::Termino* termino_nuevo = new modelo::Termino(termino, etiqueta);

    if(this->gestor_terminos.almacenar(termino_nuevo))
    {
        // si se pudo agregar correctamente, lo agrego en la lista visible.
        this->agregarTerminoALista(termino_nuevo);
    }
    else
    {
        delete termino_nuevo;
    }

    this->on_action_resetear_termino_triggered();
}

void DialogoTerminos::on_action_eliminar_termino_triggered()
{
    QList<QListWidgetItem*> items = ui->lista_terminos->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QVariant data = item->data(Qt::UserRole);
        modelo::Termino* termino = data.value<modelo::Termino*>();

        if (termino->tieneRelacionesDependientes())
        {
            QMessageBox * advertencia_termino_con_relaciones_dependientes = this->crearAdvertenciaTerminoConRelacionesDependientes();
            advertencia_termino_con_relaciones_dependientes->exec();

            delete advertencia_termino_con_relaciones_dependientes;

            return;
        }

        this->gestor_terminos.eliminar(termino);

        delete termino;

        delete this->ui->lista_terminos->takeItem(ui->lista_terminos->row(item));
    }
}

void DialogoTerminos::on_action_estado_btn_eliminar_triggered()
{
    int items_seleccionados = this->ui->lista_terminos->selectedItems().size();
    if (0 >= items_seleccionados)
    {
        this->ui->btn_eliminar->setDisabled(true);
    }
    else
    {
        this->ui->btn_eliminar->setEnabled(true);
    }
}


// METODOS PRIVADOS

void DialogoTerminos::agregarTerminoALista(modelo::Termino * termino)
{
    termino->sumarReferencia();

    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(termino);
    item->setData(Qt::UserRole, data);
    item->setText((termino->getEtiqueta() + " - " + termino->getValor()).c_str());

    this->ui->lista_terminos->insertItem(0, item);
}

void DialogoTerminos::descargarListaTerminos()
{
    QListWidgetItem* item = nullptr;

    // elimino los periodos de la lista
    modelo::Termino* termino_lista = nullptr;
    unsigned int count = ui->lista_terminos->count();
    while (0 != ui->lista_terminos->count())
    {
        count = ui->lista_terminos->count();

        termino_lista = this->ui->lista_terminos->item(0)->data(Qt::UserRole).value<modelo::Termino*>();

        if (0 == termino_lista->restarReferencia())
        {
            delete termino_lista;
        }

        item = this->ui->lista_terminos->takeItem(0);
        delete item;
    }
}

QMessageBox * DialogoTerminos::crearAdvertenciaTerminoConRelacionesDependientes()
{
    std::string texto = "El termino que se quiere eliminar forma parte de uno o mas conceptos existentes. Para poder eliminar el termino, primero elimine el concepto relacionado.";
    visualizador::aplicacion::comunicacion::Advertencia advertencia_termino_con_relaciones_dependientes(texto);
    return comunicacion::FabricaMensajes::fabricar(&advertencia_termino_con_relaciones_dependientes);
}

void DialogoTerminos::cargarListaTerminos()
{
    std::vector<modelo::Termino*> terminos_actuales = this->gestor_terminos.gestionar<modelo::Termino>();

    for (std::vector<modelo::Termino*>::iterator it = terminos_actuales.begin(); it != terminos_actuales.end(); it++)
    {
        modelo::Termino * clon = this->gestor_terminos.clonar<modelo::Termino>(*it);
        this->agregarTerminoALista(clon);
    }

    this->ui->lista_terminos->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}
