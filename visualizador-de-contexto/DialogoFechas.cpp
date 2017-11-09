#include "DialogoFechas.h"
#include "ui_DialogoFechas.h"

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

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
}

DialogoFechas::~DialogoFechas()
{
    delete ui;
}

void DialogoFechas::on_action_guardar_fecha_triggered()
{

}

void DialogoFechas::on_action_limpiar_fecha_triggered()
{

}

void DialogoFechas::on_action_eliminar_fecha_triggered()
{

}

void DialogoFechas::on_action_actualizar_y_cerrar_triggered()
{

}

void DialogoFechas::on_action_estado_btn_eliminar_triggered()
{

}

void DialogoFechas::agregarFechaALista(visualizador::modelo::Fecha * fecha)
{
    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(fecha);
    item->setData(Qt::UserRole, data);

    std::string texto_item = fecha->getEtiqueta() + " - " + fecha->get;

    item->setText(texto_item.c_str());

    this->ui->lista_fechas->insertItem(0, item);
}
