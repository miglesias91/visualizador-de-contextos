#include "DialogoEditarConcepto.h"
#include "ui_DialogoEditarConcepto.h"

DialogoEditarConcepto::DialogoEditarConcepto(visualizador::modelo::Concepto * concepto_a_editar, QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoEditarConcepto();
    ui->setupUi(this);

    aplicacion::Logger::info("Iniciando dialogo Editar Conceptos.");

    this->setAttribute(Qt::WA_DeleteOnClose);

    this->cargarListaTerminos(concepto_a_editar);

    this->gestor_terminos_totales.gestionar<visualizador::modelo::Termino>();
}

DialogoEditarConcepto::~DialogoEditarConcepto()
{
    this->descargarListaTerminos();

    aplicacion::Logger::info("Cerrando dialogo Conceptos.");

    delete ui;
}

void DialogoEditarConcepto::on_action_eliminar_triggered()
{

}

void DialogoEditarConcepto::on_action_nuevo_triggered()
{
    std::string texto_termino = "<nuevo valor>";
    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue((*it));
    item->setData(Qt::UserRole, data);
    item->setText(texto_termino.c_str());
    item->setFlags(item->flags() | Qt::ItemIsEditable);

    this->ui->lista->insertItem(0, item);
}

void DialogoEditarConcepto::on_action_ok_triggered()
{
    // recorro todos los items de la lista:
    // 1) actualizo los valores de cada Termino.
    // 2) agrego los nuevos termino de "terminos_nuevos": les asigno un nuevo id y los agrego a la lista de terminos del concepto.
}

void DialogoEditarConcepto::on_action_editar_triggered()
{

}

// METODOS INTERNOS

void DialogoEditarConcepto::cargarListaTerminos(visualizador::modelo::Concepto * concepto_a_editar)
{
    std::vector<visualizador::modelo::Termino*> terminos_actuales = concepto_a_editar->getTerminos();

    for (std::vector<visualizador::modelo::Termino*>::iterator it = terminos_actuales.begin(); it != terminos_actuales.end(); it++)
    {
        (*it)->sumarReferencia();
        std::string texto_termino = (*it)->getValor();
        QListWidgetItem* item = new QListWidgetItem();

        QVariant data = QVariant::fromValue((*it)); 
        item->setData(Qt::UserRole, data);
        item->setText(texto_termino.c_str());
        item->setFlags(item->flags() | Qt::ItemIsEditable);

        this->ui->lista->insertItem(0, item);

        this->gestor_terminos_de_concepto.almacenar((*it)->clonar());
    }

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