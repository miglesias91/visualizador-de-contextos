#include "DialogoEditarConcepto.h"
#include "ui_DialogoEditarConcepto.h"

DialogoEditarConcepto::DialogoEditarConcepto(visualizador::modelo::Concepto * concepto_a_editar, QWidget *parent)
    : QWidget(parent)
{
    ui = new Ui::DialogoEditarConcepto();
    ui->setupUi(this);

    aplicacion::Logger::info("Iniciando dialogo Editar Conceptos.");

    std::vector<modelo::Termino*> terminos_actuales = concepto_a_editar->getTerminos();

    for (std::vector<modelo::Termino*>::iterator it = terminos_actuales.begin(); it != terminos_actuales.end(); it++)
    {
        (*it)->sumarReferencia();
        std::string texto_termino = (*it)->getValor();
        QListWidgetItem* item = new QListWidgetItem();

        QVariant data = QVariant::fromValue((*it));
        item->setData(Qt::UserRole, data);
        item->setText(texto_termino.c_str());

        this->ui->lista->insertItem(0, item);
    }

    aplicacion::Logger::info(std::to_string(terminos_actuales.size()) + " terminos cargados.");

    this->ui->lista->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

DialogoEditarConcepto::~DialogoEditarConcepto()
{
    delete ui;
}
