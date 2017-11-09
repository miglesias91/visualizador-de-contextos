#include "DialogoFechas.h"
#include "ui_DialogoFechas.h"

using namespace visualizador;

DialogoFechas::DialogoFechas(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoFechas();
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    std::vector<modelo::Fecha*> fechas_actuales = this->gestor_fechas.gestionar<modelo::Fecha>();
    for (std::vector<modelo::Fecha*>::iterator it = fechas_actuales.begin(); it != fechas_actuales.end(); it++)
    {
        this->agregarFechaALista(*it);
    }

    this->ui->lista_fechas->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);

    this->on_action_limpiar_fecha_triggered();
}

DialogoFechas::~DialogoFechas()
{
    QListWidgetItem* item = nullptr;

    // elimino las fechas de la lista.
    unsigned int count = ui->lista_fechas->count();
    while (0 != ui->lista_fechas->count())
    {
        count = ui->lista_fechas->count();

        item = ui->lista_fechas->takeItem(0);
        delete item;
    }

    delete ui;
}

void DialogoFechas::on_action_guardar_fecha_triggered()
{
    std::string etiqueta = this->ui->lineedit_etiqueta->text().toStdString();

    int dia;
    int mes;
    int anio;
    this->ui->dateedit_fecha->date().getDate(&anio, &mes, &dia);

    modelo::Fecha* fecha_nueva = new modelo::Fecha(dia, mes, anio, etiqueta);

    if (this->gestor_fechas.almacenar(fecha_nueva))
    {
        // si se pudo agregar correctamente, lo agrego en la lista visible.
        this->agregarFechaALista(fecha_nueva);
    }
    else
    {
        delete fecha_nueva;
    }

    this->on_action_limpiar_fecha_triggered();
}

void DialogoFechas::on_action_limpiar_fecha_triggered()
{
    this->ui->lineedit_etiqueta->clear();
    this->ui->dateedit_fecha->setDate(QDate::currentDate());
    this->ui->lista_fechas->clearSelection();
}

void DialogoFechas::on_action_eliminar_fecha_triggered()
{
    QList<QListWidgetItem*> items = ui->lista_fechas->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QVariant data = item->data(Qt::UserRole);
        modelo::Fecha* fecha = data.value<modelo::Fecha*>();

        this->gestor_fechas.eliminar(fecha);

        delete this->ui->lista_fechas->takeItem(ui->lista_fechas->row(item));
    }
}

void DialogoFechas::on_action_actualizar_y_cerrar_triggered()
{
    this->gestor_fechas.guardarCambios();
    this->close();
}

void DialogoFechas::on_action_estado_btn_eliminar_triggered()
{
    int items_seleccionados = this->ui->lista_fechas->selectedItems().size();
    if (0 >= items_seleccionados)
    {
        this->ui->btn_eliminar_fecha->setDisabled(true);
    }
    else
    {
        this->ui->btn_eliminar_fecha->setEnabled(true);
    }
}

void DialogoFechas::agregarFechaALista(visualizador::modelo::Fecha * fecha)
{
    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(fecha);
    item->setData(Qt::UserRole, data);

    std::string texto_item = fecha->getEtiqueta() +" - " + fecha->getStringDDmesAAAA(" ");

    item->setText(texto_item.c_str());

    this->ui->lista_fechas->insertItem(0, item);
}
