#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_visualizadordecontexto.h"

class visualizadordecontexto : public QMainWindow
{
	Q_OBJECT

public:
	visualizadordecontexto(QWidget *parent = Q_NULLPTR);

private slots:
    void on_action_abrirTerminos_triggered();

private:
	Ui::visualizadordecontextoClass ui;
};
