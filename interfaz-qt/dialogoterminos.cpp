#include "dialogoterminos.h"
#include "ui_dialogoterminos.h"

// aplicacion
#include <aplicacion/include/IAdministradorAplicacion.h>

// modelo
#include <modelo/include/Termino.h>

using namespace visualizador;

DialogoTerminos::DialogoTerminos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogoTerminos)
{
    ui->setupUi(this);
	this->setAttribute(Qt::WidgetAttribute::WA_DeleteOnClose, true);
	
	std::vector<modelo::IEntidad*> terminos;
	aplicacion::IAdministradorAplicacion::getInstancia()->recuperarTerminos(prefijo_terminos, terminos);
}

DialogoTerminos::~DialogoTerminos()
{
    delete ui;
}

void DialogoTerminos::on_buttonBox_rejected()
{
	this->close();
}
