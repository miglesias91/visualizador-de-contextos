#include "DialogoFechas.h"
#include "ui_DialogoFechas.h"

// visualizador-de-contexto
#include <visualizador-de-contexto/include/FabricaMensajes.h>

// aplicacion
#include <aplicacion/include/Logger.h>

using namespace visualizador;

DialogoFechas::DialogoFechas(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoFechas();
    ui->setupUi(this);
    
    aplicacion::Logger::info("Iniciando dialogo Fechas.");

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->cargarListaFechas();

    this->limpiar_fecha();
}

DialogoFechas::~DialogoFechas()
{
    this->descargarListaFechas();

    aplicacion::Logger::info("Cerrando dialogo Fechas.");

    delete ui;
}

void DialogoFechas::hideEvent(QHideEvent *) {
    emit se_cerro();
}

void DialogoFechas::showEvent(QShowEvent *) {
    emit se_abrio();
}


void DialogoFechas::guardar() {

    this->actualizar_y_cerrar();
}

void DialogoFechas::cerrar() {

    this->close();
}

void DialogoFechas::guardar_fecha()
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

        aplicacion::Logger::info("Fecha agregada: { " + aplicacion::Logger::infoLog(fecha_nueva) + " }.");
    }
    else
    {
        QMessageBox * informacion_fecha_existente = this->crearInformacionFechaExistente();
        informacion_fecha_existente->exec();

        delete informacion_fecha_existente;

        delete fecha_nueva;
    }

    this->limpiar_fecha();
}

void DialogoFechas::limpiar_fecha()
{
    this->ui->lineedit_etiqueta->clear();
    this->ui->dateedit_fecha->setDate(QDate::currentDate());
    this->ui->lista_fechas->clearSelection();

    aplicacion::Logger::info("Dialogo Fechas reseteado.");

    this->estado_btn_eliminar();
}

void DialogoFechas::eliminar_fecha()
{
    QList<QListWidgetItem*> items = ui->lista_fechas->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QVariant data = item->data(Qt::UserRole);
        modelo::Fecha* fecha = data.value<modelo::Fecha*>();

        if (fecha->tieneRelacionesDependientes())
        {
            QMessageBox * advertencia_fecha_con_relaciones_dependientes = this->crearAdvertenciaFechaConRelacionesDependientes();
            advertencia_fecha_con_relaciones_dependientes->exec();

            delete advertencia_fecha_con_relaciones_dependientes;

            return;
        }

        this->gestor_fechas.eliminar(fecha);

        aplicacion::Logger::info("Fecha eliminada: '" + aplicacion::Logger::infoLog(fecha) + "'.");

        delete fecha;

        delete this->ui->lista_fechas->takeItem(ui->lista_fechas->row(item));
    }
}

void DialogoFechas::actualizar_y_cerrar()
{
    this->gestor_fechas.guardarCambios();

    aplicacion::Logger::info("Dialogo Fechas guardado.");
    
    this->close();
}

void DialogoFechas::estado_btn_eliminar()
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
    fecha->sumarReferencia();

    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(fecha);
    item->setData(Qt::UserRole, data);

    std::string texto_item = fecha->getEtiqueta() +" - " + fecha->getStringDDmesAAAA(" ");

    item->setText(texto_item.c_str());

    this->ui->lista_fechas->insertItem(0, item);
}

void DialogoFechas::cargarListaFechas()
{
    std::vector<modelo::Fecha*> fechas_actuales = this->gestor_fechas.gestionar<modelo::Fecha>();
    for (std::vector<modelo::Fecha*>::iterator it = fechas_actuales.begin(); it != fechas_actuales.end(); it++)
    {
        modelo::Fecha * clon = this->gestor_fechas.clonar<modelo::Fecha>(*it);
        this->agregarFechaALista(clon);
    }

    this->ui->lista_fechas->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);

    aplicacion::Logger::info(std::to_string(fechas_actuales.size()) + " fechas descargadas.");
}

void DialogoFechas::descargarListaFechas()
{
    QListWidgetItem* item = nullptr;

    // elimino las fechas de la lista
    modelo::Fecha* fecha_lista = nullptr;
    unsigned int count = ui->lista_fechas->count();
    while (0 != ui->lista_fechas->count())
    {
        count = ui->lista_fechas->count();

        fecha_lista = this->ui->lista_fechas->item(0)->data(Qt::UserRole).value<modelo::Fecha*>();

        if (0 == fecha_lista->restarReferencia())
        {
            delete fecha_lista;
        }

        item = this->ui->lista_fechas->takeItem(0);
        delete item;
    }

    aplicacion::Logger::info(std::to_string(count) + " fechas descargadas.");
}

// mensajes

QMessageBox * DialogoFechas::crearAdvertenciaFechaConRelacionesDependientes()
{
    std::string texto = u8"La fecha que se quiere eliminar forma parte de uno o más períodos existentes. Para poder eliminar la fecha, primero elimine el período relacionado.";
    visualizador::aplicacion::comunicacion::Advertencia advertencia_fecha_con_relaciones_dependientes(texto);
    return comunicacion::FabricaMensajes::fabricar(&advertencia_fecha_con_relaciones_dependientes, this);
}

QMessageBox * DialogoFechas::crearInformacionFechaExistente()
{
    std::string texto = u8"La fecha que se quiere agregar ya existe!";
    visualizador::aplicacion::comunicacion::Informacion informacion_fecha_existente(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_fecha_existente, this);
}
