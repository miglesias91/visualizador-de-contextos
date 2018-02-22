#include "DialogoMediosTwitter.h"
#include "ui_DialogoMediosTwitter.h"

// visualizador-de-contexto
#include <visualizador-de-contexto/include/FabricaMensajes.h>

// modelo
#include <modelo/include/MedioTwitter.h>

// scraping
#include <scraping/include/ConfiguracionScraping.h>

DialogoMediosTwitter::DialogoMediosTwitter(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoMediosTwitter();
    ui->setupUi(this);

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->cargarListaMediosTwitter();

    this->on_action_resetear_cuenta_triggered();
}

DialogoMediosTwitter::~DialogoMediosTwitter()
{
    this->descargarListaMediosTwitter();

    delete ui;
}

void DialogoMediosTwitter::on_action_actualizar_y_cerrar_triggered()
{
    this->gestor_medios.guardarCambios();
    this->close();
}

void DialogoMediosTwitter::on_action_resetear_cuenta_triggered()
{
    this->ui->lineedit_etiqueta->clear();
    this->ui->lineedit_nombre_usuario->clear();
    this->ui->lista_medios_twitter->clearSelection();

    this->on_action_estado_btn_eliminar_triggered();
    this->on_action_estado_btn_agregar_triggered();
}

void DialogoMediosTwitter::on_action_guardar_cuenta_triggered()
{
    std::string etiqueta = this->ui->lineedit_etiqueta->text().toStdString();
    std::string nombre_usuario = this->ui->lineedit_nombre_usuario->text().toStdString();

    modelo::MedioTwitter * medio_nuevo = new modelo::MedioTwitter(etiqueta);

    scraping::twitter::modelo::Cuenta * nueva_cuenta = new scraping::twitter::modelo::Cuenta(nombre_usuario);
    medio_nuevo->setCuentaAScrapear(nueva_cuenta);

    if (this->gestor_medios.almacenar(medio_nuevo))
    {
        // si se pudo agregar correctamente, lo agrego en la lista visible.
        this->agregarMedioTwitterALista(medio_nuevo);
    }
    else
    {
        QMessageBox * informacion_termino_existente = this->crearInformacionMedioTwitterExistente();
        informacion_termino_existente->exec();

        delete informacion_termino_existente;

        delete medio_nuevo;
    }

    this->on_action_resetear_cuenta_triggered();
}

void DialogoMediosTwitter::on_action_eliminar_cuenta_triggered()
{
    QList<QListWidgetItem*> items = ui->lista_medios_twitter->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QVariant data = item->data(Qt::UserRole);
        modelo::Medio* medio = data.value<modelo::Medio*>();

        this->gestor_medios.eliminar(medio);

        delete medio;

        delete this->ui->lista_medios_twitter->takeItem(ui->lista_medios_twitter->row(item));
    }
}

void DialogoMediosTwitter::on_action_estado_btn_eliminar_triggered()
{
    int items_seleccionados = this->ui->lista_medios_twitter->selectedItems().size();
    if (0 >= items_seleccionados)
    {
        this->ui->btn_eliminar->setDisabled(true);
    }
    else
    {
        this->ui->btn_eliminar->setEnabled(true);
    }
}

void DialogoMediosTwitter::on_action_estado_btn_agregar_triggered()
{
    std::string texto_termino = this->ui->lineedit_nombre_usuario->text().toStdString();
    if (0 == texto_termino.size())
    {
        this->ui->btn_agregar->setDisabled(true);
    }
    else
    {
        this->ui->btn_agregar->setEnabled(true);
    }
}

void DialogoMediosTwitter::cargarListaMediosTwitter()
{
    std::vector<modelo::MedioTwitter*> medios_actuales = this->gestor_medios.gestionar<modelo::MedioTwitter>();

    for (std::vector<modelo::MedioTwitter*>::iterator it = medios_actuales.begin(); it != medios_actuales.end(); it++)
    {
        modelo::MedioTwitter * clon = this->gestor_medios.clonar<modelo::MedioTwitter>(*it);
        this->agregarMedioTwitterALista(clon);
    }

    this->ui->lista_medios_twitter->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoMediosTwitter::descargarListaMediosTwitter()
{
    QListWidgetItem* item = nullptr;

    // elimino los periodos de la lista
    modelo::Medio* medio_lista = nullptr;
    unsigned int count = ui->lista_medios_twitter->count();
    while (0 != ui->lista_medios_twitter->count())
    {
        count = ui->lista_medios_twitter->count();

        medio_lista = this->ui->lista_medios_twitter->item(0)->data(Qt::UserRole).value<modelo::Medio*>();

        if (0 == medio_lista->restarReferencia())
        {
            delete medio_lista;
        }

        item = this->ui->lista_medios_twitter->takeItem(0);
        delete item;
    }
}

void DialogoMediosTwitter::agregarMedioTwitterALista(modelo::MedioTwitter * medio_twitter)
{
    medio_twitter->sumarReferencia();

    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(medio_twitter);
    item->setData(Qt::UserRole, data);

    item->setText((medio_twitter->getEtiqueta() + "(@" + medio_twitter->getCuentaAScrapear()->getNombre() + ")").c_str());

    this->ui->lista_medios_twitter->insertItem(0, item);
}

QMessageBox * DialogoMediosTwitter::crearInformacionMedioTwitterExistente()
{
    std::string texto = "La cuenta de Twitter que se quiere agregar ya existe!";
    visualizador::aplicacion::comunicacion::Informacion informacion_termino_existente(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_termino_existente);
}