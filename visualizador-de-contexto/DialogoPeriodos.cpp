#include "DialogoPeriodos.h"
#include "ui_DialogoPeriodos.h"

// visualizador-de-contexto
#include <visualizador-de-contexto/include/FabricaMensajes.h>

// aplicacion
#include <aplicacion/include/Logger.h>

using namespace visualizador;

DialogoPeriodos::DialogoPeriodos(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoPeriodos();
    ui->setupUi(this);

    aplicacion::Logger::info("Iniciando dialogo Periodos.");

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->cargarListaPeriodos();

    this->cargarComboboxesDesdeYHasta();

    this->limpiar_periodo();
}

DialogoPeriodos::~DialogoPeriodos()
{
    this->descargarComboboxesDesdeYHasta();

    this->descargarListaPeriodos();

    aplicacion::Logger::info("Cerrando dialogo Periodos.");

    delete ui;
}

void DialogoPeriodos::hideEvent(QHideEvent *) {
    emit se_cerro();
}

void DialogoPeriodos::showEvent(QShowEvent *) {
    emit se_abrio();
}

void DialogoPeriodos::actualizar_y_cerrar()
{
    this->gestor_periodos.guardarCambios();

    aplicacion::Logger::info("Dialogo Periodos guardado.");

    this->close();
}

void DialogoPeriodos::guardar_periodo()
{
}

void DialogoPeriodos::eliminar_periodo()
{
    QList<QListWidgetItem*> items = ui->lista_periodos->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QVariant data = item->data(Qt::UserRole);
        modelo::Periodo* periodo = data.value<modelo::Periodo*>();

        this->gestor_periodos.eliminar(periodo);

        aplicacion::Logger::info("Periodo eliminado: '" + aplicacion::Logger::infoLog(periodo) + "'.");

        delete periodo;

        delete this->ui->lista_periodos->takeItem(ui->lista_periodos->row(item));
    }
}

void DialogoPeriodos::limpiar_periodo()
{
    this->ui->lista_periodos->clearSelection();
    //this->ui->combobox_desde->setCurrentIndex(-1);
    //this->ui->combobox_hasta->setCurrentIndex(-1);

    this->estado_btn_eliminar();
    this->estado_btn_agregar();

    aplicacion::Logger::info("Dialogo Periodos reseteado.");
}

void DialogoPeriodos::estado_btn_eliminar()
{
    int items_seleccionados = this->ui->lista_periodos->selectedItems().size();
    if (0 >= items_seleccionados)
    {
        this->ui->btn_eliminar_periodo->setDisabled(true);
    }
    else
    {
        this->ui->btn_eliminar_periodo->setEnabled(true);
    }
}

void DialogoPeriodos::estado_btn_agregar()
{
}

void DialogoPeriodos::guardar() {

    this->actualizar_y_cerrar();
}

void DialogoPeriodos::cerrar() {

    this->close();
}

// METODOS INTERNOS

void DialogoPeriodos::agregarPeriodoALista(visualizador::modelo::Periodo * periodo)
{
    periodo->sumarReferencia();

    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(periodo);
    item->setData(Qt::UserRole, data);

    std::string texto_item = periodo->getEtiqueta() + " - [" + periodo->getDesde()->getStringDDmesAAAA(" ") + ", " + periodo->getHasta()->getStringDDmesAAAA(" ") + "]";

    item->setText(texto_item.c_str());

    this->ui->lista_periodos->insertItem(0, item);
}

void DialogoPeriodos::cargarListaPeriodos()
{
    std::vector<modelo::Periodo*> periodos_actuales = this->gestor_periodos.gestionar<modelo::Periodo>();
    for (std::vector<modelo::Periodo*>::iterator it = periodos_actuales.begin(); it != periodos_actuales.end(); it++)
    {
        modelo::Periodo * clon = this->gestor_periodos.clonar<modelo::Periodo>(*it);
        this->agregarPeriodoALista(clon);
    }

    aplicacion::Logger::info(std::to_string(periodos_actuales.size()) + " periodos cargados.");

    this->ui->lista_periodos->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoPeriodos::descargarListaPeriodos()
{
    QListWidgetItem* item = nullptr;

    // elimino los periodos de la lista
    modelo::Periodo* periodo_lista = nullptr;
    unsigned int count = ui->lista_periodos->count();
    while (0 != ui->lista_periodos->count())
    {
        count = ui->lista_periodos->count();

        periodo_lista = this->ui->lista_periodos->item(0)->data(Qt::UserRole).value<modelo::Periodo*>();

        if (0 == periodo_lista->restarReferencia())
        {
            delete periodo_lista;
        }

        item = this->ui->lista_periodos->takeItem(0);
        delete item;
    }

    aplicacion::Logger::info(std::to_string(count) + " periodos descargados.");
}

void DialogoPeriodos::cargarComboboxesDesdeYHasta()
{
    //aplicacion::GestorEntidades gestor_fechas;
    //std::vector<modelo::Fecha*> fechas_actuales = gestor_fechas.recuperar<modelo::Fecha>();

    //for (std::vector<modelo::Fecha*>::iterator it = fechas_actuales.begin(); it != fechas_actuales.end(); it++)
    //{
    //    modelo::Fecha* fecha = *it;
    //    std::string texto_fecha = fecha->getEtiqueta() + " (" + fecha->getStringDDMMAAAA("/") + ")";

    //    QVariant data = QVariant::fromValue(fecha);
    //    QString texto_item(texto_fecha.c_str());

    //    this->ui->combobox_desde->insertItem(0, texto_item, data);
    //    fecha->sumarReferencia();

    //    this->ui->combobox_hasta->insertItem(0, texto_item, data);
    //    fecha->sumarReferencia();
    //}

    //aplicacion::Logger::info(std::to_string(fechas_actuales.size()) + " fechas para periodos cargadas.");
}

void DialogoPeriodos::descargarComboboxesDesdeYHasta()
{
    //// elimino las fechas del combobox 'desde'
    //modelo::Fecha* fecha_combobox = nullptr;
    //unsigned int count = ui->combobox_desde->count();
    //while (0 != ui->combobox_desde->count())
    //{
    //    count = ui->combobox_desde->count();

    //    fecha_combobox = this->ui->combobox_desde->itemData(0, Qt::UserRole).value<modelo::Fecha*>();

    //    if (0 == fecha_combobox->restarReferencia())
    //    {
    //        delete fecha_combobox;
    //    }

    //    this->ui->combobox_desde->removeItem(0);
    //}

    //// elimino las fechas del combobox 'hasta'
    //count += ui->combobox_hasta->count();
    //while (0 != ui->combobox_hasta->count())
    //{
    //    count = ui->combobox_hasta->count();

    //    fecha_combobox = this->ui->combobox_hasta->itemData(0, Qt::UserRole).value<modelo::Fecha*>();

    //    if (0 == fecha_combobox->restarReferencia())
    //    {
    //        delete fecha_combobox;
    //    }

    //    this->ui->combobox_hasta->removeItem(0);
    //}

    //aplicacion::Logger::info(std::to_string(count) + " fechas para periodos descargadas.");

}

//modelo::Fecha * DialogoPeriodos::fechaDesdeSeleccionada()
//{
//    return this->ui->combobox_desde->currentData(Qt::UserRole).value<modelo::Fecha*>();
//}
//
//modelo::Fecha * DialogoPeriodos::fechaHastaSeleccionada()
//{
//    return this->ui->combobox_hasta->currentData(Qt::UserRole).value<modelo::Fecha*>();
//}

// MENSAJES

QMessageBox * DialogoPeriodos::crearInformacionPeriodoExistente()
{
    std::string texto = u8"El período que se quiere agregar ya existe!";
    visualizador::aplicacion::comunicacion::Informacion informacion_periodo_existente(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_periodo_existente);
}

QMessageBox * DialogoPeriodos::crearErrorFechaDesdeMayorAFechaHasta()
{
    std::string texto = u8"La fecha 'hasta' debe ser menor a la fecha 'desde'.";
    visualizador::aplicacion::comunicacion::Error error_fecha_desde_mayor_fecha_hasta(texto);
    return comunicacion::FabricaMensajes::fabricar(&error_fecha_desde_mayor_fecha_hasta);
}