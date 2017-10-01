#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

// #include <QMainWindow>
#include <QtWidgets/qmainwindow.h>

namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaPrincipal(QWidget *parent = 0);
    ~VentanaPrincipal();

private slots:
    void on_btn_termino_released();

    void on_btn_conceptos_released();

    void on_btn_fechas_released();

    void on_btn_periodos_released();

    void on_btn_secciones_released();

    void on_btn_medios_released();

    void on_btn_consulta_released();

private:
    Ui::VentanaPrincipal *ui;
};

#endif // VENTANAPRINCIPAL_H
