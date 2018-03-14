#include "DialogoEditarConcepto.h"
#include "ui_DialogoEditarConcepto.h"

DialogoEditarConcepto::DialogoEditarConcepto(visualizador::modelo::Concepto * concepto_a_editar, visualizador::aplicacion::GestorEntidades * gestor_terminos, QWidget *parent)
    : concepto_a_editar(concepto_a_editar), gestor_terminos(gestor_terminos), QDialog(parent)
{
    ui = new Ui::DialogoEditarConcepto();
    ui->setupUi(this);

    aplicacion::Logger::info("Iniciando dialogo Editar Conceptos.");

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->ui->lineedit_etiqueta->setText(concepto_a_editar->getEtiqueta().c_str());
    this->etiqueta_original = concepto_a_editar->getEtiqueta();

    this->cargarListaTerminos(concepto_a_editar);

    QObject::connect(this->ui->lista, &QListWidget::itemChanged, this, &DialogoEditarConcepto::termino_actualizado);
    QObject::connect(this->ui->lista, &QListWidget::currentItemChanged, this, &DialogoEditarConcepto::guardar_termino_sin_editar);
}

DialogoEditarConcepto::~DialogoEditarConcepto()
{
    this->descargarListaTerminos();

    aplicacion::Logger::info("Cerrando dialogo Conceptos.");

    delete ui;
}

void DialogoEditarConcepto::on_action_eliminar_triggered()
{
    QList<QListWidgetItem*> items = ui->lista->selectedItems();
    foreach(QListWidgetItem * item, items)
    {
        QVariant data = item->data(Qt::UserRole);
        modelo::Termino* termino = data.value<modelo::Termino*>();

        this->gestor_terminos_de_concepto.eliminar(termino);

        aplicacion::Logger::info("Termino eliminado: { " + aplicacion::Logger::infoLog(termino) + " }.");

        if (0 == termino->restarReferencia())
        {
            delete termino;
        }

        delete this->ui->lista->takeItem(ui->lista->row(item));
    }
}

void DialogoEditarConcepto::on_action_nuevo_triggered()
{
    std::string texto_nuevo_valor = "<nuevo valor>";
    this->termino_sin_editar = texto_nuevo_valor;

    visualizador::modelo::Termino * nuevo_termino = new visualizador::modelo::Termino(texto_nuevo_valor);
    nuevo_termino->sumarReferencia();

    QListWidgetItem* item = new QListWidgetItem();

    item->setText(texto_nuevo_valor.c_str());
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    QVariant data = QVariant::fromValue(nuevo_termino);

    this->ui->lista->blockSignals(true);
    item->setData(Qt::UserRole, data);
    this->ui->lista->blockSignals(false);

    this->ui->lista->insertItem(0, item);

    this->ui->lista->editItem(item);
}

void DialogoEditarConcepto::on_action_ok_triggered()
{
    if (false == this->etiquetaModificada() && false == this->listaDeTerminosModificada())
    {
        this->close();
        return;
    }

    if (this->ui->lineedit_etiqueta->text().isEmpty())
    {
        QMessageBox * informacion_etiqueta_vacia = this->crearInformacionEtiquetaVacia();
        informacion_etiqueta_vacia->exec();

        delete informacion_etiqueta_vacia;

        return;
    }

    if (0 == this->ui->lista->count())
    {
        QMessageBox * informacion_lista_de_terminos_vacia = this->crearInformacionListaDeTerminosVacia();
        informacion_lista_de_terminos_vacia->exec();

        delete informacion_lista_de_terminos_vacia;

        return;
    }

    this->concepto_a_editar->setEtiqueta(this->ui->lineedit_etiqueta->text().toStdString());

    std::vector<visualizador::modelo::IEntidad*> entidades_a_almacenar = this->gestor_terminos_de_concepto.getEntidadesAAlmacenar();
    for (std::vector<visualizador::modelo::IEntidad*>::iterator it = entidades_a_almacenar.begin(); it != entidades_a_almacenar.end(); it++)
    {
        this->gestor_terminos->almacenar(*it);

        this->concepto_a_editar->agregarTermino(this->gestor_terminos->clonar<visualizador::modelo::Termino>(*it));
    }

    std::vector<visualizador::modelo::IEntidad*> entidades_a_eliminar = this->gestor_terminos_de_concepto.getEntidadesAEliminar();
    for (std::vector<visualizador::modelo::IEntidad*>::iterator it = entidades_a_eliminar.begin(); it != entidades_a_eliminar.end(); it++)
    {
        visualizador::modelo::Termino * termino_a_sacar = this->gestor_terminos->clonar<visualizador::modelo::Termino>(*it);
        this->concepto_a_editar->sacarTermino(termino_a_sacar);
        delete termino_a_sacar;
    }

    this->accept();
}

void DialogoEditarConcepto::termino_actualizado(QListWidgetItem * item_actualizado)
{
    visualizador::modelo::Termino * nuevo_termino = new visualizador::modelo::Termino(item_actualizado->text().toStdString());

    if (this->termino_sin_editar == nuevo_termino->getValor())
    {// si se deja el mismo valor, entonces no se hace nada.
        delete nuevo_termino;

        return;
    }

    if (this->gestor_terminos_de_concepto.existe(nuevo_termino))
    {// si ya hay un termino con el mismo valor, entonces se vuelve al valor anterior.
        QMessageBox * informacion_termino_existente = this->crearInformacionTerminoExistente();
        informacion_termino_existente->exec();

        this->ui->lista->blockSignals(true);
        item_actualizado->setText(QString(this->termino_sin_editar.c_str()));
        this->ui->lista->blockSignals(false);

        delete informacion_termino_existente;

        delete nuevo_termino;

        return;
    }
    
    visualizador::modelo::Termino * termino_a_agregar_a_lista = NULL;

    visualizador::modelo::Termino * termino_encontrado = this->gestor_terminos->encontrar(nuevo_termino);
    if (NULL != termino_encontrado)
    {// si lo encontro, entonces el termino ya existe. lo que hago es clonarlo y usar el clon, y dsp reemplazarlo en la lista visible.
        termino_a_agregar_a_lista = this->gestor_terminos->clonar<visualizador::modelo::Termino>(termino_encontrado);
        delete nuevo_termino;
    }
    else
    {// si no lo encontro, entonces el termino es nuevo. lo agrego a la lista de terminos a agregar.
        termino_a_agregar_a_lista = nuevo_termino;
    }
    this->gestor_terminos_de_concepto.almacenar(termino_a_agregar_a_lista);
    termino_a_agregar_a_lista->sumarReferencia();

    visualizador::modelo::Termino * termino_lista = item_actualizado->data(Qt::UserRole).value<visualizador::modelo::Termino*>();

    if (NULL != termino_lista && 0 == termino_lista->restarReferencia())
    {// si el item ya tiene asignado un termino, entonces lo elimino.
        delete termino_lista;
    }

    QVariant data = QVariant::fromValue(termino_a_agregar_a_lista);
    this->ui->lista->blockSignals(true);
    item_actualizado->setData(Qt::UserRole, data);
    this->ui->lista->blockSignals(false);
}

void DialogoEditarConcepto::guardar_termino_sin_editar(QListWidgetItem * item_actual, QListWidgetItem * item_previo)
{
    if(NULL != item_actual)
    {
        this->termino_sin_editar = item_actual->text().toStdString();
    }
}

// METODOS INTERNOS

bool DialogoEditarConcepto::etiquetaModificada()
{
    return this->ui->lineedit_etiqueta->text().toStdString() != this->etiqueta_original;
}

bool DialogoEditarConcepto::listaDeTerminosModificada()
{
    return (this->gestor_terminos_de_concepto.getEntidadesAAlmacenar().size() != 0 || this->gestor_terminos_de_concepto.getEntidadesAEliminar().size() != 0);
}

void DialogoEditarConcepto::cargarListaTerminos(visualizador::modelo::Concepto * concepto_a_editar)
{
    std::vector<visualizador::modelo::Termino*> terminos_actuales = concepto_a_editar->getTerminos();

    for (std::vector<visualizador::modelo::Termino*>::iterator it = terminos_actuales.begin(); it != terminos_actuales.end(); it++)
    {
        //(*it)->sumarReferencia();
        std::string texto_termino = (*it)->getValor();
        QListWidgetItem* item = new QListWidgetItem();

        visualizador::modelo::Termino* termino_item = this->gestor_terminos->clonar<visualizador::modelo::Termino>(*it);
        termino_item->sumarReferencia();
        QVariant data = QVariant::fromValue(termino_item);
        item->setData(Qt::UserRole, data);
        item->setText(texto_termino.c_str());
        item->setFlags(item->flags() | Qt::ItemIsEditable);

        this->ui->lista->insertItem(0, item);
    }

    this->gestor_terminos_de_concepto.gestionar<visualizador::modelo::Termino>(terminos_actuales);

    aplicacion::Logger::info(std::to_string(terminos_actuales.size()) + " terminos cargados.");

    this->ui->lista->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoEditarConcepto::descargarListaTerminos()
{
    QListWidgetItem * item = nullptr;

    // elimino los terminos de la lista
    visualizador::modelo::Termino * termino_lista = nullptr;
    unsigned int count = ui->lista->count();
    while (0 != ui->lista->count())
    {
        count = ui->lista->count();

        termino_lista = this->ui->lista->item(0)->data(Qt::UserRole).value<visualizador::modelo::Termino*>();

        if (0 == termino_lista->restarReferencia())
        {
            delete termino_lista;
        }

        item = this->ui->lista->takeItem(0);
        delete item;
    }

    aplicacion::Logger::info(std::to_string(count) + " terminos descargados.");
}

// mensajes

QMessageBox * DialogoEditarConcepto::crearInformacionTerminoExistente()
{
    std::string texto = u8"El término que se quiere agregar ya existe!";
    visualizador::aplicacion::comunicacion::Informacion informacion_termino_existente(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_termino_existente);
}

QMessageBox * DialogoEditarConcepto::crearInformacionEtiquetaVacia()
{
    std::string texto = u8"No se asigno la etiqueta. La etiqueta sirve para describir e identificar al concepto en las consultas.";
    visualizador::aplicacion::comunicacion::Informacion informacion_etiqueta_vacia(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_etiqueta_vacia);
}

QMessageBox * DialogoEditarConcepto::crearInformacionListaDeTerminosVacia()
{
    std::string texto = u8"El concepto no tiene términos. La lista de términos no puede estar vacía.";
    visualizador::aplicacion::comunicacion::Informacion informacion_etiqueta_vacia(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_etiqueta_vacia);
}
