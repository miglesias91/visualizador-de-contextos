#pragma once

#include <QWidget>
namespace Ui { class DialogoConsultas; };

class DialogoConsultas : public QWidget
{
    Q_OBJECT

public:
    DialogoConsultas(QWidget *parent = Q_NULLPTR);
    ~DialogoConsultas();

private:
    Ui::DialogoConsultas *ui;
};
