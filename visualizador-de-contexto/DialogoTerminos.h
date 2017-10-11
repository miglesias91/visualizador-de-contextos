#pragma once

#include <QWidget>
namespace Ui { class DialogoTerminos; };

class DialogoTerminos : public QWidget
{
	Q_OBJECT

public:
	DialogoTerminos(QWidget *parent = Q_NULLPTR);
	~DialogoTerminos();

private slots:
    void on_action_actualizarYCerrar_triggered();

    void on_action_resetear_triggered();

    void on_action_guardar_triggered();

private:
	Ui::DialogoTerminos *ui;

	// METODOS
	void actualizarTerminos();
};
