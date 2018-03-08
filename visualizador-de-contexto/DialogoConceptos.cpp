#include "DialogoConceptos.h"
#include "ui_DialogoConceptos.h"

// stl
#include <memory>

// visualizador-de-contexto
#include <visualizador-de-contexto/include/FabricaMensajes.h>

// aplicacion
#include <aplicacion/include/Logger.h>

// modelo
#include <modelo/include/Concepto.h>
#include <modelo/include/Termino.h>

using namespace visualizador;

DialogoConceptos::DialogoConceptos(QWidget *parent)
    : dialogo_editar_concepto(NULL), QWidget(parent)
{
    ui = new Ui::DialogoConceptos();
    ui->setupUi(this);

    aplicacion::Logger::info("Iniciando dialogo Conceptos.");

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->cargarListaConceptos();

    this->cargarListaTerminos();

    this->on_action_resetear_concepto_triggered();
}

DialogoConceptos::~DialogoConceptos()
{
    this->descargarListaTerminos();

    this->descargarListaConceptos();

    aplicacion::Logger::info("Cerrando dialogo Conceptos.");

    delete ui;
}

// ACCIONES

void DialogoConceptos::on_action_actualizar_y_cerrar_triggered()
{
    this->gestor_conceptos.guardarCambios();
    
    aplicacion::Logger::info("Dialogo Conceptos guardado.");

    this->close();
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

        aplicacion::Logger::info("Concepto agregado: { '" + aplicacion::Logger::infoLog(concepto_nuevo) + "' }.");
    }
    else
    {
        QMessageBox * informacion_concepto_existente = this->crearInformacionConceptoExistente();
        informacion_concepto_existente->exec();

        delete informacion_concepto_existente;

        delete concepto_nuevo;
    }

    this->on_action_resetear_concepto_triggered();
}

void DialogoConceptos::on_action_eliminar_concepto_triggered()
{
    QList<QListWidgetItem*> items = ui->lista_conceptos->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QVariant data = item->data(Qt::UserRole);
        modelo::Concepto* concepto = data.value<modelo::Concepto*>();

        this->gestor_conceptos.eliminar(concepto);

        aplicacion::Logger::info("Concepto eliminado: { " + aplicacion::Logger::infoLog(concepto) + " }.");

        delete concepto;

        delete this->ui->lista_conceptos->takeItem(ui->lista_conceptos->row(item));
    }
}

void DialogoConceptos::on_action_resetear_concepto_triggered()
{
    this->ui->lineedit_etiqueta->clear();
    this->ui->lista_terminos->clearSelection();
    this->ui->lista_conceptos->clearSelection();

    this->on_action_estado_btn_eliminar_triggered();
    this->on_action_estado_btn_agregar_triggered();

    aplicacion::Logger::info("Dialogo Conceptos reseteado.");
}

void DialogoConceptos::on_action_estado_btn_eliminar_triggered()
{
    int items_seleccionados = this->ui->lista_conceptos->selectedItems().size();
    if (0 < items_seleccionados)
    {
        this->ui->btn_eliminar_concepto->setEnabled(true);
        this->ui->btn_editar_concepto->setEnabled(true);
    }
    else
    {
        this->ui->btn_eliminar_concepto->setDisabled(true);
        this->ui->btn_editar_concepto->setEnabled(true);
    }
}

void DialogoConceptos::on_action_estado_btn_agregar_triggered()
{
    int items_seleccionados = this->ui->lista_terminos->selectedItems().size();
    if (0 < items_seleccionados)
    {
        this->ui->btn_agregar_concepto->setEnabled(true);
    }
    else
    {
        this->ui->btn_agregar_concepto->setDisabled(true);
    }
}

// METODOS PRIVADOS

void DialogoConceptos::agregarConceptoALista(modelo::Concepto * concepto)
{
    concepto->sumarReferencia();

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

void DialogoConceptos::cargarListaConceptos()
{
    std::vector<modelo::Concepto*> conceptos_actuales = this->gestor_conceptos.gestionar<modelo::Concepto>();
    for (std::vector<modelo::Concepto*>::iterator it = conceptos_actuales.begin(); it != conceptos_actuales.end(); it++)
    {
        modelo::Concepto * clon = this->gestor_conceptos.clonar<modelo::Concepto>(*it);
        this->agregarConceptoALista(clon);
    }

    aplicacion::Logger::info(std::to_string(conceptos_actuales.size()) + " conceptos cargados.");

    this->ui->lista_conceptos->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoConceptos::descargarListaConceptos()
{
    QListWidgetItem* item = nullptr;

    // elimino los conceptos de la lista
    modelo::Concepto* concepto_lista = nullptr;
    unsigned int count = ui->lista_conceptos->count();
    while (0 != ui->lista_conceptos->count())
    {
        count = ui->lista_conceptos->count();

        concepto_lista = this->ui->lista_conceptos->item(0)->data(Qt::UserRole).value<modelo::Concepto*>();

        if (0 == concepto_lista->restarReferencia())
        {
            delete concepto_lista;
        }

        item = this->ui->lista_conceptos->takeItem(0);
        delete item;
    }

    aplicacion::Logger::info(std::to_string(count) + " conceptos descargados.");
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

std::vector<modelo::Concepto*> DialogoConceptos::conceptosSeleccionados()
{
    std::vector<modelo::Concepto*> conceptos_seleccionados;
    QList<QListWidgetItem*> items = ui->lista_conceptos->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QVariant data = item->data(Qt::UserRole);
        modelo::Concepto * concepto = data.value<modelo::Concepto*>();

        conceptos_seleccionados.push_back(concepto);
    }

    return conceptos_seleccionados;
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

    aplicacion::Logger::info(std::to_string(terminos_actuales.size()) + " terminos cargados.");

    this->ui->lista_terminos->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoConceptos::descargarListaTerminos()
{
    QListWidgetItem* item = nullptr;

    // elimino los terminos de la lista
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

// mensajes

QMessageBox * DialogoConceptos::crearInformacionConceptoExistente()
{
    std::string texto = u8"El concepto que se quiere agregar ya existe!";
    visualizador::aplicacion::comunicacion::Informacion informacion_concepto_existente(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_concepto_existente);
}

void DialogoConceptos::on_action_editar_concepto_triggered()
{
    std::vector<modelo::Concepto*> conceptos_seleccionados = this->conceptosSeleccionados();
    this->dialogo_editar_concepto = new DialogoEditarConcepto(conceptos_seleccionados[0]);
    this->dialogo_editar_concepto->show();
}
