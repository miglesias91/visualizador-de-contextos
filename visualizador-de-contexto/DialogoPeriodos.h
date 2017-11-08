#pragma once

#include <QWidget>
namespace Ui { class DialogoPeriodos; };

class DialogoPeriodos : public QWidget
{
    Q_OBJECT

public:
    DialogoPeriodos(QWidget *parent = Q_NULLPTR);
    ~DialogoPeriodos();

private:
    Ui::DialogoPeriodos *ui;
};
