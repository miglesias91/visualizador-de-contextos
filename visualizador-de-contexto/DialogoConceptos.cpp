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

    std::vector<modelo::Termino*> terminos_actuales = this->gestor_terminos.gestionar<modelo::Termino>();

    this->on_action_resetear_concepto_triggered();

    QObject::connect(this->ui->lista_conceptos, &QListWidget::itemDoubleClicked, this, &DialogoConceptos::concepto_dobleclikeado);
}

DialogoConceptos::~DialogoConceptos()
{
    this->descargarListaConceptos();

    aplicacion::Logger::info("Cerrando dialogo Conceptos.");

    delete ui;
}

// ACCIONES

void DialogoConceptos::on_action_actualizar_y_cerrar_triggered()
{
    this->gestor_terminos.guardarCambios();
    this->gestor_conceptos.guardarCambios();
    
    aplicacion::Logger::info("Dialogo Conceptos guardado.");

    this->close();
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
    this->ui->lista_conceptos->clearSelection();

    this->on_action_estado_btn_eliminar_triggered();

    aplicacion::Logger::info("Dialogo Conceptos reseteado.");
}

void DialogoConceptos::on_action_estado_btn_eliminar_triggered()
{
    int items_seleccionados = this->ui->lista_conceptos->selectedItems().size();
    if (0 < items_seleccionados)
    {
        this->ui->btn_eliminar_concepto->setEnabled(true);
    }
    else
    {
        this->ui->btn_eliminar_concepto->setDisabled(true);
    }
}

void DialogoConceptos::concepto_dobleclikeado(QListWidgetItem * item_dobleclikeado)
{
    QVariant data = item_dobleclikeado->data(Qt::UserRole);
    modelo::Concepto * concepto_a_modificar = data.value<modelo::Concepto*>();
    this->dialogo_editar_concepto = new DialogoEditarConcepto(concepto_a_modificar, &this->gestor_terminos);
    if (this->dialogo_editar_concepto->exec())
    {
        if (this->gestor_conceptos.existe(concepto_a_modificar))
        {
            QMessageBox * informacion_concepto_existente = this->crearInformacionConceptoExistente();
            informacion_concepto_existente->exec();

            delete informacion_concepto_existente;
            
            // buscar la forma de volver a ponerle los terminos de antes.

            return;
        }
        this->gestor_conceptos.modificar(concepto_a_modificar);

        aplicacion::Logger::info("Concepto modificado: { '" + aplicacion::Logger::infoLog(concepto_a_modificar) + "' }.");

        // reemplazarlo por su valor en la lista visible.
        std::string texto_item = aplicacion::Logger::infoLog(concepto_a_modificar);

        item_dobleclikeado->setText(texto_item.c_str());
    }
}

void DialogoConceptos::on_action_nuevo_concepto_triggered()
{
    modelo::Concepto * concepto_nuevo = new modelo::Concepto();
    this->dialogo_editar_concepto = new DialogoEditarConcepto(concepto_nuevo, &this->gestor_terminos);
    if (this->dialogo_editar_concepto->exec())
    {
        if (this->gestor_conceptos.almacenar(concepto_nuevo))
        {
            // si se pudo agregar correctamente, lo agrego en la lista visible.
            this->agregarConceptoALista(concepto_nuevo);

            aplicacion::Logger::info("Concepto nuevo: { '" + aplicacion::Logger::infoLog(concepto_nuevo) + "' }.");
        }
        else
        {
            QMessageBox * informacion_concepto_existente = this->crearInformacionConceptoExistente();
            informacion_concepto_existente->exec();

            delete informacion_concepto_existente;

            delete concepto_nuevo;
        }
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

    std::string texto_item = aplicacion::Logger::infoLog(concepto);

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

// mensajes

QMessageBox * DialogoConceptos::crearInformacionConceptoExistente()
{
    std::string texto = u8"El concepto que se quiere agregar ya existe!";
    visualizador::aplicacion::comunicacion::Informacion informacion_concepto_existente(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_concepto_existente);
}
