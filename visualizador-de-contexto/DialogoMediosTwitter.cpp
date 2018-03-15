#include "DialogoMediosTwitter.h"
#include "ui_DialogoMediosTwitter.h"

// visualizador-de-contexto
#include <visualizador-de-contexto/include/FabricaMensajes.h>

// aplicacion
#include <aplicacion/include/Logger.h>

// modelo
#include <modelo/include/MedioTwitter.h>

// scraping
#include <scraping/include/ConfiguracionScraping.h>

using namespace visualizador;

DialogoMediosTwitter::DialogoMediosTwitter(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoMediosTwitter();
    ui->setupUi(this);

    aplicacion::Logger::info("Iniciando dialogo Medios Twitter.");

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->cargarListaMediosTwitter();

    this->on_action_resetear_cuenta_triggered();
}

DialogoMediosTwitter::~DialogoMediosTwitter()
{
    this->descargarListaMediosTwitter();

    aplicacion::Logger::info("Cerrando dialogo Medios Twitter.");

    delete ui;
}

void DialogoMediosTwitter::on_action_actualizar_y_cerrar_triggered()
{
    this->gestor_medios.guardarCambios();
    
    aplicacion::Logger::info("Dialogo Medios Twitter guardado.");
    
    this->close();
}

void DialogoMediosTwitter::on_action_resetear_cuenta_triggered()
{
    this->ui->lista_medios_twitter->clearSelection();

    this->on_action_estado_btn_eliminar_triggered();

    aplicacion::Logger::info("Dialogo Medios Twitter reseteado.");
}

void DialogoMediosTwitter::on_action_guardar_cuenta_triggered()
{
    //std::string etiqueta = this->ui->lineedit_etiqueta->text().toStdString();
    //std::string nombre_usuario = this->ui->lineedit_nombre_usuario->text().toStdString();

    //modelo::MedioTwitter * medio_nuevo = new modelo::MedioTwitter(nombre_usuario, etiqueta);

    //if (false == this->gestor_medios.existe(medio_nuevo))
    //{
    //    // si NO existe, creo su cuenta de scraping asociada y se la seteo...
    //    scraping::twitter::modelo::Cuenta * nueva_cuenta = new scraping::twitter::modelo::Cuenta(nombre_usuario);
    //    nueva_cuenta->asignarNuevoId();
    //    medio_nuevo->setCuentaAScrapear(nueva_cuenta);

    //    // y lo agrego en la lista visible.
    //    this->agregarMedioTwitterALista(medio_nuevo);

    //    // ahora si la almaceno.
    //    this->gestor_medios.almacenar(medio_nuevo);

    //    aplicacion::Logger::info("Medio Twitter agregado: { " + aplicacion::Logger::infoLog(medio_nuevo) + " }.");
    //}
    //else
    //{
    //    QMessageBox * informacion_termino_existente = this->crearInformacionMedioTwitterExistente();
    //    informacion_termino_existente->exec();

    //    delete informacion_termino_existente;

    //    delete medio_nuevo;
    //}

    //this->on_action_resetear_cuenta_triggered();
}

void DialogoMediosTwitter::on_action_eliminar_cuenta_triggered()
{
    QList<QListWidgetItem*> items = ui->lista_medios_twitter->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QVariant data = item->data(Qt::UserRole);
        modelo::MedioTwitter* medio = data.value<modelo::MedioTwitter*>();

        this->gestor_medios.eliminar(medio);

        aplicacion::Logger::info("Medio Twitter eliminado: '" + aplicacion::Logger::infoLog(medio) + "'.");

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

void DialogoMediosTwitter::cargarListaMediosTwitter()
{
    std::vector<modelo::MedioTwitter*> medios_actuales = this->gestor_medios.gestionar<modelo::MedioTwitter>();

    for (std::vector<modelo::MedioTwitter*>::iterator it = medios_actuales.begin(); it != medios_actuales.end(); it++)
    {
        modelo::MedioTwitter * clon = this->gestor_medios.clonar<modelo::MedioTwitter>(*it);
        this->agregarMedioTwitterALista(clon);
    }

    aplicacion::Logger::info(std::to_string(medios_actuales.size()) + " medios twitter cargados.");

    this->ui->lista_medios_twitter->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoMediosTwitter::descargarListaMediosTwitter()
{
    QListWidgetItem* item = nullptr;

    // elimino los periodos de la lista
    modelo::MedioTwitter* medio_lista = nullptr;
    unsigned int count = ui->lista_medios_twitter->count();
    while (0 != ui->lista_medios_twitter->count())
    {
        count = ui->lista_medios_twitter->count();

        medio_lista = this->ui->lista_medios_twitter->item(0)->data(Qt::UserRole).value<modelo::MedioTwitter*>();

        if (0 == medio_lista->restarReferencia())
        {
            delete medio_lista;
        }

        item = this->ui->lista_medios_twitter->takeItem(0);
        delete item;
    }

    aplicacion::Logger::info(std::to_string(count) + " medios twitter descargados.");
}

void DialogoMediosTwitter::agregarMedioTwitterALista(modelo::MedioTwitter * medio_twitter)
{
    medio_twitter->sumarReferencia();

    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(medio_twitter);
    item->setData(Qt::UserRole, data);
    
    std::string texto_item = aplicacion::Logger::infoLog(medio_twitter);

    item->setText(texto_item.c_str());

    this->ui->lista_medios_twitter->insertItem(0, item);
}

QMessageBox * DialogoMediosTwitter::crearInformacionMedioTwitterExistente()
{
    std::string texto = u8"La cuenta de Twitter que se quiere agregar ya existe!";
    visualizador::aplicacion::comunicacion::Informacion informacion_termino_existente(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_termino_existente);
}
void DialogoMediosTwitter::on_action_nueva_cuenta_triggered()
{
    modelo::MedioTwitter * medio_twitter_nuevo = new modelo::MedioTwitter();
    this->dialogo_editar_medio_twitter = new DialogoEditarCuentaTwitter(medio_twitter_nuevo, &this->gestor_medios);
    if (this->dialogo_editar_medio_twitter->exec())
    {
        if (false == this->gestor_medios.existe(medio_twitter_nuevo))
        {
            // si NO existe, creo su cuenta de scraping asociada y se la seteo...
            std::string nombre_cuenta = medio_twitter_nuevo->getNombreUsuario();
            scraping::twitter::modelo::Cuenta * nueva_cuenta = new scraping::twitter::modelo::Cuenta(nombre_cuenta);
            nueva_cuenta->asignarNuevoId();
            medio_twitter_nuevo->setCuentaAScrapear(nueva_cuenta);

            // y lo agrego en la lista visible.
            this->agregarMedioTwitterALista(medio_twitter_nuevo);

            // ahora si la almaceno.
            this->gestor_medios.almacenar(medio_twitter_nuevo);

            aplicacion::Logger::info("Medio Twitter agregado: { " + aplicacion::Logger::infoLog(medio_twitter_nuevo) + " }.");
        }
        else
        {
            QMessageBox * informacion_termino_existente = this->crearInformacionMedioTwitterExistente();
            informacion_termino_existente->exec();

            delete informacion_termino_existente;

            delete medio_twitter_nuevo;
        }

        this->on_action_resetear_cuenta_triggered();
    }
    else
    {
        delete medio_twitter_nuevo;
    }
}
