#pragma once

#include <QWidget>

namespace Ui { class DialogoMediosTwitter; };

class DialogoMediosTwitter : public QWidget
{
    Q_OBJECT

public:
    DialogoMediosTwitter(QWidget *parent = Q_NULLPTR);
    ~DialogoMediosTwitter();

private slots:
    void on_action_actualizar_y_cerrar_triggered();

    void on_action_resetear_cuenta_triggered();

    void on_action_guardar_cuenta_triggered();

    void on_action_eliminar_cuenta_triggered();

    void on_action_estado_btn_eliminar_triggered();

    void on_action_estado_btn_agregar_triggered();

private:
    Ui::DialogoMediosTwitter *ui;
};
