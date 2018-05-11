#pragma once

#include <QWidget>
namespace Ui { class DialogoResultadoConsulta; };

class DialogoResultadoConsulta : public QWidget
{
    Q_OBJECT

public:
    DialogoResultadoConsulta(QWidget *parent = Q_NULLPTR);
    ~DialogoResultadoConsulta();

private:
    Ui::DialogoResultadoConsulta *ui;
};
