#include "DialogoTerminos.h"
#include "ui_DialogoTerminos.h"

// visualizador-de-contexto
#include <visualizador-de-contexto/include/FabricaMensajes.h>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>
#include <aplicacion/include/Logger.h>

// modelo
#include <modelo/include/Termino.h>

using namespace visualizador;

DialogoTerminos::DialogoTerminos(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::DialogoTerminos();
	ui->setupUi(this);

    aplicacion::Logger::info("Iniciando dialogo Terminos.");

	this->setAttribute(Qt::WA_DeleteOnClose);

    this->cargarListaTerminos();

    this->on_action_resetear_termino_triggered();
}

DialogoTerminos::~DialogoTerminos()
{
    this->descargarListaTerminos();

    aplicacion::Logger::info("Cerrando dialogo Terminos.");

	delete ui;
}

// ACCIONES

void DialogoTerminos::on_action_actualizar_y_cerrar_triggered()
{
    this->gestor_terminos.guardarCambios();

    aplicacion::Logger::info("Dialogo Terminos guardado.");
    
    this->close();
}

void DialogoTerminos::on_action_resetear_termino_triggered()
{
    //this->ui->lineedit_termino->clear();
    this->ui->lista_terminos->clearSelection();

    this->on_action_estado_btn_eliminar_triggered();
    this->on_action_estado_btn_agregar_triggered();
 
    aplicacion::Logger::info("Dialogo Terminos reseteado.");
}

void DialogoTerminos::on_action_guardar_termino_triggered()
{
    //std::string termino = this->ui->lineedit_termino->text().toStdString();

    //modelo::Termino* termino_nuevo = new modelo::Termino(termino, termino);

    //if(this->gestor_terminos.almacenar(termino_nuevo))
    //{
    //    // si se pudo agregar correctamente, lo agrego en la lista visible.
    //    this->agregarTerminoALista(termino_nuevo);

    //    aplicacion::Logger::info("Termino agregado: { " + aplicacion::Logger::infoLog(termino_nuevo) + " }.");
    //}
    //else
    //{
    //    QMessageBox * informacion_termino_existente = this->crearInformacionTerminoExistente();
    //    informacion_termino_existente->exec();

    //    delete informacion_termino_existente;

    //    delete termino_nuevo;
    //}

    //this->on_action_resetear_termino_triggered();
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

        aplicacion::Logger::info("Termino eliminado: '" + termino->getValor() + "'.");

        delete termino;

        delete this->ui->lista_terminos->takeItem(ui->lista_terminos->row(item));
    }
}

void DialogoTerminos::on_action_estado_btn_eliminar_triggered()
{
    //int items_seleccionados = this->ui->lista_terminos->selectedItems().size();
    //if (0 >= items_seleccionados)
    //{
    //    this->ui->btn_eliminar->setDisabled(true);
    //}
    //else
    //{
    //    this->ui->btn_eliminar->setEnabled(true);
    //}
}

void DialogoTerminos::on_action_estado_btn_agregar_triggered()
{
    //std::string texto_termino = this->ui->lineedit_termino->text().toStdString();
    //if (0 == texto_termino.size())
    //{
    //    this->ui->btn_agregar_termino->setDisabled(true);
    //}
    //else
    //{
    //    this->ui->btn_agregar_termino->setEnabled(true);
    //}
}

// METODOS PRIVADOS

void DialogoTerminos::agregarTerminoALista(modelo::Termino * termino)
{
    termino->sumarReferencia();

    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(termino);
    item->setData(Qt::UserRole, data);
    item->setText(termino->getValor().c_str());

    this->ui->lista_terminos->insertItem(0, item);
}

void DialogoTerminos::cargarListaTerminos()
{
    std::vector<modelo::Termino*> terminos_actuales = this->gestor_terminos.gestionar<modelo::Termino>();

    for (std::vector<modelo::Termino*>::iterator it = terminos_actuales.begin(); it != terminos_actuales.end(); it++)
    {
        modelo::Termino * clon = this->gestor_terminos.clonar<modelo::Termino>(*it);
        this->agregarTerminoALista(clon);
    }

    aplicacion::Logger::info(std::to_string(terminos_actuales.size()) + " terminos cargados.");

    this->ui->lista_terminos->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
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

    aplicacion::Logger::info(std::to_string(count) + " terminos descargados.");
}

QMessageBox * DialogoTerminos::crearAdvertenciaTerminoConRelacionesDependientes()
{
    std::string texto = u8"El término que se quiere eliminar forma parte de uno o más conceptos existentes. Para poder eliminar el término, primero elimine el concepto relacionado.";
    visualizador::aplicacion::comunicacion::Advertencia advertencia_termino_con_relaciones_dependientes(texto);
    return comunicacion::FabricaMensajes::fabricar(&advertencia_termino_con_relaciones_dependientes);
}

QMessageBox * DialogoTerminos::crearInformacionTerminoExistente()
{
    std::string texto = u8"El término que se quiere agregar ya existe!";
    visualizador::aplicacion::comunicacion::Informacion informacion_termino_existente(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_termino_existente);
}
