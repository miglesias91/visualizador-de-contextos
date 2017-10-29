#include "DialogoConceptos.h"
#include "ui_DialogoConceptos.h"

// aplicacion
#include <aplicacion/include/GestorEntidades.h>

// modelo
#include <modelo/include/Concepto.h>

using namespace visualizador;

DialogoConceptos::DialogoConceptos(QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoConceptos();
    ui->setupUi(this);
    
    this->setAttribute(Qt::WA_DeleteOnClose);

    std::vector<modelo::Concepto*> conceptos_actuales = this->gestor_conceptos.gestionar<modelo::Concepto>();
    for (std::vector<modelo::Concepto*>::iterator it = conceptos_actuales.begin(); it != conceptos_actuales.end(); it++)
    {
        this->agregarConceptoALista(*it);
    }

    this->cargarComboBoxTerminos();
}

DialogoConceptos::~DialogoConceptos()
{
    // elimino los conceptos de la lista
    QListWidgetItem* item = NULL;
    modelo::Concepto* concepto_lista = NULL;
    unsigned int count = ui->lista_conceptos->count();
    while (0 != ui->lista_conceptos->count())
    {
        count = ui->lista_conceptos->count();

        item = ui->lista_conceptos->takeItem(0);
        delete item;
    }

    // elimino los terminos del combobox
    modelo::Termino* termino_combo = NULL;
    count = ui->combo_terminos->count();
    while (0 != ui->combo_terminos->count())
    {
        count = ui->combo_terminos->count();

        termino_combo = this->ui->combo_terminos->itemData(0).value<modelo::Termino*>();
        delete termino_combo;

        this->ui->combo_terminos->removeItem(0);
    }

    delete ui;
}

// ACCIONES

// METODOS PRIVADOS

void DialogoConceptos::agregarConceptoALista(modelo::Concepto * concepto)
{
    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(concepto);
    item->setData(Qt::UserRole, data);

    std::vector<modelo::Termino*> terminos = concepto->getTerminos();
    std::string texto_item = concepto->getEtiqueta() + " - " + (*terminos.begin())->getValor();
    for (std::vector<modelo::Termino*>::iterator it = terminos.begin() + 1; it != terminos.end(); it++)
    {
        texto_item += ", " + (*it)->getValor();
    }

    item->setText(texto_item.c_str());

    this->ui->lista_conceptos->insertItem(0, item);
}

void DialogoConceptos::cargarComboBoxTerminos()
{
    aplicacion::GestorEntidades gestor_terminos;
    std::vector<modelo::Termino*> terminos_actuales = gestor_terminos.recuperar<modelo::Termino>();

    for (std::vector<modelo::Termino*>::iterator it = terminos_actuales.begin(); it != terminos_actuales.end(); it++)
    {
        std::string texto_termino = (*it)->getEtiqueta() + " - " + (*it)->getValor();
        this->ui->combo_terminos->insertItem(0, texto_termino.c_str(), QVariant::fromValue(*it));
    }
}
