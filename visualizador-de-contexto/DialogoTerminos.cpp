#include "DialogoTerminos.h"
#include "ui_DialogoTerminos.h"

// visualizador-de-contexto
#include <visualizador-de-contexto/include/FabricaMensajes.h>

// aplicacion
#include <aplicacion/include/GestorEntidades.h>
#include <aplicacion/include/Logger.h>

// modelo
#include <modelo/include/Termino.h>

using namespace visualizador;

DialogoTerminos::DialogoTerminos(QWidget *parent)
	: QWidget(parent)
{
	ui = new Ui::DialogoTerminos();
	ui->setupUi(this);

    this->conectar_componentes();

    aplicacion::Logger::info("Iniciando dialogo Terminos.");

	this->setAttribute(Qt::WA_DeleteOnClose);

    this->cargarListaTerminos();
}

DialogoTerminos::~DialogoTerminos()
{
    this->descargarListaTerminos();

    aplicacion::Logger::info("Cerrando dialogo Terminos.");

	delete ui;
}

void DialogoTerminos::hideEvent(QHideEvent *) {
    emit se_cerro();
}

void DialogoTerminos::showEvent(QShowEvent *) {
    emit se_abrio();
}


void DialogoTerminos::guardar() {

    this->close();
}

void DialogoTerminos::cerrar() {

    this->close();
}

// METODOS PRIVADOS

void DialogoTerminos::agregarTerminoALista(modelo::Termino * termino)
{
    termino->sumarReferencia();

    QListWidgetItem* item = new QListWidgetItem();

    QVariant data = QVariant::fromValue(termino);
    item->setData(Qt::UserRole, data);
    item->setText(termino->getValor().c_str());

    this->ui->lista_terminos->insertItem(0, item);
}

void DialogoTerminos::cargarListaTerminos()
{
    std::vector<modelo::Termino*> terminos_actuales = this->gestor_terminos.gestionar<modelo::Termino>();

    for (std::vector<modelo::Termino*>::iterator it = terminos_actuales.begin(); it != terminos_actuales.end(); it++)
    {
        modelo::Termino * clon = this->gestor_terminos.clonar<modelo::Termino>(*it);
        this->agregarTerminoALista(clon);
    }

    aplicacion::Logger::info(std::to_string(terminos_actuales.size()) + " terminos cargados.");

    this->ui->lista_terminos->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
}

void DialogoTerminos::descargarListaTerminos()
{
    QListWidgetItem* item = nullptr;

    // elimino los periodos de la lista
    modelo::Termino* termino_lista = nullptr;
    unsigned int count = ui->lista_terminos->count();
    while (0 != ui->lista_terminos->count())
    {
        count = ui->lista_terminos->count();

        termino_lista = this->ui->lista_terminos->item(0)->data(Qt::UserRole).value<modelo::Termino*>();

        if (0 == termino_lista->restarReferencia())
        {
            delete termino_lista;
        }

        item = this->ui->lista_terminos->takeItem(0);
        delete item;
    }

    aplicacion::Logger::info(std::to_string(count) + " terminos descargados.");
}

QMessageBox * DialogoTerminos::crearAdvertenciaTerminoConRelacionesDependientes()
{
    std::string texto = u8"El término que se quiere eliminar forma parte de uno o más conceptos existentes. Para poder eliminar el término, primero elimine el concepto relacionado.";
    visualizador::aplicacion::comunicacion::Advertencia advertencia_termino_con_relaciones_dependientes(texto);
    return comunicacion::FabricaMensajes::fabricar(&advertencia_termino_con_relaciones_dependientes);
}

QMessageBox * DialogoTerminos::crearInformacionTerminoExistente()
{
    std::string texto = u8"El término que se quiere agregar ya existe!";
    visualizador::aplicacion::comunicacion::Informacion informacion_termino_existente(texto);
    return comunicacion::FabricaMensajes::fabricar(&informacion_termino_existente);
}

void DialogoTerminos::conectar_componentes() {

    QObject::connect(this->ui->btn_cerrar, &QPushButton::released, this, &DialogoTerminos::close);

}