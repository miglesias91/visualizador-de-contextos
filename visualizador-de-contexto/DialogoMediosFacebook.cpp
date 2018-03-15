#include "DialogoMediosFacebook.h"
#include "ui_DialogoMediosFacebook.h"

// visualizador-de-contexto
#include <visualizador-de-contexto/include/FabricaMensajes.h>

// aplicacion
#include <aplicacion/include/Logger.h>

// modelo
#include <modelo/include/MedioFacebook.h>

// scraping
#include <scraping/include/ConfiguracionScraping.h>

DialogoMediosFacebook::DialogoMediosFacebook(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoMediosFacebook();
    ui->setupUi(this);

    aplicacion::Logger::info("Iniciando dialogo Medios Facebook.");

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->cargarListaMediosFacebook();

    this->on_action_resetear_triggered();
}

DialogoMediosFacebook::~DialogoMediosFacebook()
{
    this->descargarListaMediosFacebook();

    aplicacion::Logger::info("Cerrando dialogo Medios Facebook.");

    delete ui;
}

// SLOTS

void DialogoMediosFacebook::on_action_actualizar_y_cerrar_triggered()
{
    this->gestor_medios.guardarCambios();

    aplicacion::Logger::info("Dialogo Medios Facebook guardado.");

    this->close();
}

void DialogoMediosFacebook::on_action_resetear_triggered()
{
    this->ui->lineedit_etiqueta->clear();
    this->ui->lineedit_nombre_pagina->clear();
    this->ui->lista_medios_facebook->clearSelection();

    this->on_action_estado_btn_eliminar_triggered();
    this->on_action_estado_btn_agregar_triggered();

    aplicacion::Logger::info("Dialogo Medios Facebook reseteado.");
}

void DialogoMediosFacebook::on_action_guardar_triggered()
{
    std::string etiqueta = this->ui->lineedit_etiqueta->text().toStdString();
    std::string nombre_pagina = this->ui->lineedit_nombre_pagina->text().toStdString();

    modelo::MedioFacebook * medio_nuevo = new modelo::MedioFacebook(nombre_pagina, etiqueta);

    if (false == this->gestor_medios.existe(medio_nuevo))
    {
        // si NO existe, creo su cuenta de scraping asociada y se la seteo...
        scraping::facebook::modelo::Pagina * nueva_pagina = new scraping::facebook::modelo::Pagina(nombre_pagina);
        nueva_pagina->asignarNuevoId();
        medio_nuevo->setPaginaAScrapear(nueva_pagina);

        // y lo agrego en la lista visible.
        this->agregarMedioFacebookALista(medio_nuevo);

        // ahora si la almaceno.
        this->gestor_medios.almacenar(medio_nuevo);

        aplicacion::Logger::info("Medio Facebbok agregado: { " + aplicacion::Logger::infoLog(medio_nuevo) + " }.");
    }
    else
    {
        QMessageBox * informacion_termino_existente = this->crearInformacionMedioFacebookExistente();
        informacion_termino_existente->exec();

        delete informacion_termino_existente;

        delete medio_nuevo;
    }

    this->on_action_resetear_triggered();
}

void DialogoMediosFacebook::on_action_eliminar_triggered()
{
    QList<QListWidgetItem*> items = ui->lista_medios_facebook->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QVariant data = item->data(Qt::UserRole);
        modelo::MedioFacebook* medio = data.value<modelo::MedioFacebook*>();

        this->gestor_medios.eliminar(medio);

        aplicacion::Logger::info("Medio Facebook eliminado: '" + aplicacion::Logger::infoLog(medio) + "'.");

        delete medio;

        delete this->ui->lista_medios_facebook->takeItem(ui->lista_medios_facebook->row(item));
    }
}

void DialogoMediosFacebook::on_action_estado_btn_eliminar_triggered()
{
    int items_seleccionados = this->ui->lista_medios_facebook->selectedItems().size();
    if (0 >= items_seleccionados)
    {
        this->ui->btn_eliminar->setDisabled(true);
    }
    else
    {
        this->ui->btn_eliminar->setEnabled(true);
    }
}

void DialogoMediosFacebook::on_action_estado_btn_agregar_triggered()
{
    std::string texto_termino = this->ui->lineedit_nombre_pagina->text().toStdString();
    if (0 == texto_termino.size())
    {
        this->ui->btn_agregar->setDisabled(true);
    }
    else
    {
        this->ui->btn_agregar->setEnabled(true);
    }
}

// METODOS PRIVADOS

void DialogoMediosFacebook::cargarListaMediosFacebook()
{
    std::vector<modelo::MedioFacebook*> medios_actuales = this->gestor_medios.gestionar<modelo::MedioFacebook>();

    for (std::vector<modelo::MedioFacebook*>::iterator it = medios_actuales.begin(); it != medios_actuales.end(); it++)
    {
        modelo::MedioFacebook * clon = this->gestor_medios.clonar<modelo::MedioFacebook>(*it);
        this->agregarMedioFacebookALista(clon);
    }

    aplicacion::Logger::info(std::to_string(medios_actuales.size()) + " medios facebook cargados.");

    this->ui->lista_medios_facebook->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoMediosFacebook::descargarListaMediosFacebook()
{
    QListWidgetItem* item = nullptr;

    // elimino los periodos de la lista
    modelo::MedioFacebook* medio_lista = nullptr;
    unsigned int count = ui->lista_medios_facebook->count();
    while (0 != ui->lista_medios_facebook->count())
    {
        count = ui->lista_medios_facebook->count();

        medio_lista = this->ui->lista_medios_facebook->item(0)->data(Qt::UserRole).value<modelo::MedioFacebook*>();

        if (0 == medio_lista->restarReferencia())
        {
            delete medio_lista;
        }

        item = this->ui->lista_medios_facebook->takeItem(0);
        delete item;
    }

    aplicacion::Logger::info(std::to_string(count) + " medios facebook descargados.");
}

void DialogoMediosFacebook::agregarMedioFacebookALista(modelo::MedioFacebook * medio_facebook)
{
    medio_facebook->sumarReferencia();

    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(medio_facebook);
    item->setData(Qt::UserRole, data);

    //std::string etiqueta = medio_twitter->getEtiqueta();
    //std::string nombre_usuario = "@" + medio_twitter->getNombreUsuario();

    //std::string info_analisis = u8"sin contenido para visualizar";

    //unsigned long long int cantidad_de_tweets_historicos = medio_twitter->getCuentaAScrapear()->getCantidadDeContenidosHistoricos();
    //if (cantidad_de_tweets_historicos != 0)
    //{
    //    std::string fecha_tweets_mas_reciente = medio_twitter->getCuentaAScrapear()->getFechaContenidoHistoricoMasReciente().getStringDDMMAAAA("/");
    //    std::string fecha_tweets_mas_antiguo = medio_twitter->getCuentaAScrapear()->getFechaContenidoHistoricoMasAntiguo().getStringDDMMAAAA("/");
    //    std::string string_cantidad_de_tweets_historicos = std::to_string(cantidad_de_tweets_historicos);

    //    info_analisis = fecha_tweets_mas_antiguo + " - " + fecha_tweets_mas_reciente + " | " + string_cantidad_de_tweets_historicos;
    //}

    //std::string texto_item = etiqueta + " (" + nombre_usuario + ") | " + info_analisis;

    std::string texto_item = aplicacion::Logger::infoLog(medio_facebook);

    item->setText(texto_item.c_str());

    this->ui->lista_medios_facebook->insertItem(0, item);
}

QMessageBox * DialogoMediosFacebook::crearInformacionMedioFacebookExistente()
{
    std::string texto = u8"La cuenta de Facebook que se quiere agregar ya existe!";
    visualizador::aplicacion::comunicacion::Informacion informacion_termino_existente(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_termino_existente);
}
void DialogoMediosFacebook::on_action_nueva_pagina_triggered()
{
    modelo::MedioFacebook * medio_facebook_nuevo = new modelo::MedioFacebook();
    this->dialogo_editar_medio_facebook = new DialogoEditarMedioFacebook(medio_facebook_nuevo, &this->gestor_medios);
    if (this->dialogo_editar_medio_facebook->exec())
    {
        if (false == this->gestor_medios.existe(medio_facebook_nuevo))
        {
            // si NO existe, creo su cuenta de scraping asociada y se la seteo...
            std::string nombre_pagina = medio_facebook_nuevo->getNombrePagina();
            scraping::facebook::modelo::Pagina * nueva_pagina = new scraping::facebook::modelo::Pagina(nombre_pagina);
            nueva_pagina->asignarNuevoId();
            medio_facebook_nuevo->setPaginaAScrapear(nueva_pagina);

            // y lo agrego en la lista visible.
            this->agregarMedioFacebookALista(medio_facebook_nuevo);

            // ahora si la almaceno.
            this->gestor_medios.almacenar(medio_facebook_nuevo);

            aplicacion::Logger::info("Medio Facebbok agregado: { " + aplicacion::Logger::infoLog(medio_facebook_nuevo) + " }.");
        }
        else
        {
            QMessageBox * informacion_termino_existente = this->crearInformacionMedioFacebookExistente();
            informacion_termino_existente->exec();

            delete informacion_termino_existente;

            delete medio_facebook_nuevo;
        }

        this->on_action_resetear_triggered();
    }
}
