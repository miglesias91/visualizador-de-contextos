#include "DialogoConceptos.h"
#include "ui_DialogoConceptos.h"

// stl
#include <memory>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

// modelo
#include <modelo/include/Concepto.h>
#include <modelo/include/Termino.h>

using namespace visualizador;

DialogoConceptos::DialogoConceptos(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoConceptos();
    ui->setupUi(this);
    
    this->setAttribute(Qt::WA_DeleteOnClose);

    std::vector<modelo::Concepto*> conceptos_actuales = this->gestor_conceptos.gestionar<modelo::Concepto>();
    for (std::vector<modelo::Concepto*>::iterator it = conceptos_actuales.begin(); it != conceptos_actuales.end(); it++)
    {
        this->agregarConceptoALista(*it);
    }

    this->cargarListaTerminos();
    this->ui->lista_conceptos->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
    this->ui->lista_terminos->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

DialogoConceptos::~DialogoConceptos()
{
    QListWidgetItem* item = nullptr;

    // elimino los conceptos de la lista
    unsigned int count = ui->lista_conceptos->count();
    while (0 != ui->lista_conceptos->count())
    {
        count = ui->lista_conceptos->count();

        item = ui->lista_conceptos->takeItem(0);
        delete item;
    }

    // elimino los terminos de la lista
    modelo::Termino* termino_lista = nullptr;
    count = ui->lista_terminos->count();
    while (0 != ui->lista_terminos->count())
    {
        count = ui->lista_terminos->count();

        termino_lista = this->ui->lista_terminos->item(0)->data(Qt::UserRole).value<modelo::Termino*>();

        if( 0 == termino_lista->restarReferencia())
        {
            delete termino_lista;
        }

        item = this->ui->lista_terminos->takeItem(0);
        delete item;
    }

    delete ui;
}

// ACCIONES

void DialogoConceptos::on_action_actualizar_y_cerrar_triggered()
{
    this->gestor_conceptos.guardarCambios();
    this->close();
}

void DialogoConceptos::on_action_resetear_concepto_triggered()
{
    this->ui->lineedit_etiqueta->clear();
    this->ui->lineedit_terminos->clear();
    this->ui->lista_terminos->clearSelection();
    this->ui->lista_conceptos->clearSelection();
}

void DialogoConceptos::on_action_eliminar_concepto_triggered()
{
    QList<QListWidgetItem*> items = ui->lista_conceptos->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QVariant data = item->data(Qt::UserRole);
        modelo::Concepto* concepto = data.value<modelo::Concepto*>();

        this->gestor_conceptos.eliminar(concepto);

        delete this->ui->lista_conceptos->takeItem(ui->lista_conceptos->row(item));
    }
}

void DialogoConceptos::on_action_guardar_concepto_triggered()
{
    std::string etiqueta = this->ui->lineedit_etiqueta->text().toStdString();

    std::vector<modelo::Termino*> terminos_seleccionados = this->terminosSeleccionados();

    modelo::Concepto* concepto_nuevo = new modelo::Concepto(terminos_seleccionados, etiqueta);

    if (this->gestor_conceptos.almacenar(concepto_nuevo))
    {
        // si se pudo agregar correctamente, lo agrego en la lista visible.
        this->agregarConceptoALista(concepto_nuevo);
    }
    else
    {
        delete concepto_nuevo;
    }

    this->on_action_resetear_concepto_triggered();
}

void DialogoConceptos::on_action_estado_btn_eliminar_triggered()
{
    int items_seleccionados = this->ui->lista_conceptos->selectedItems().size();
    if (0 >= items_seleccionados)
    {
        this->ui->btn_eliminar_concepto->setDisabled(true);
    }
    else
    {
        this->ui->btn_eliminar_concepto->setEnabled(true);
    }
}

// METODOS PRIVADOS

void DialogoConceptos::agregarConceptoALista(modelo::Concepto * concepto)
{
    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(concepto);
    item->setData(Qt::UserRole, data);

    std::vector<modelo::Termino*> terminos = concepto->getTerminos();

    std::string texto_item = concepto->getEtiqueta() + " - ";
    if (false == terminos.empty())
    {
        texto_item += (*terminos.begin())->getValor();
        for (std::vector<modelo::Termino*>::iterator it = terminos.begin() + 1; it != terminos.end(); it++)
        {
            texto_item += ", " + (*it)->getValor();
        }
    }

    item->setText(texto_item.c_str());

    this->ui->lista_conceptos->insertItem(0, item);
}

std::vector<modelo::Termino*> DialogoConceptos::terminosSeleccionados()
{
    std::vector<modelo::Termino*> terminos_seleccionados;
    QList<QListWidgetItem*> items = ui->lista_terminos->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QVariant data = item->data(Qt::UserRole);
        modelo::Termino* termino = data.value<modelo::Termino*>();

        terminos_seleccionados.push_back(termino);
    }

    return terminos_seleccionados;
}

void DialogoConceptos::cargarListaTerminos()
{
    aplicacion::GestorEntidades gestor_terminos;
    std::vector<modelo::Termino*> terminos_actuales = gestor_terminos.recuperar<modelo::Termino>();

    for (std::vector<modelo::Termino*>::iterator it = terminos_actuales.begin(); it != terminos_actuales.end(); it++)
    {
        (*it)->sumarReferencia();
        std::string texto_termino = (*it)->getValor();
        QListWidgetItem* item = new QListWidgetItem();

        QVariant data = QVariant::fromValue((*it));
        item->setData(Qt::UserRole, data);
        item->setText(texto_termino.c_str());

        this->ui->lista_terminos->insertItem(0, item);
    }
}
