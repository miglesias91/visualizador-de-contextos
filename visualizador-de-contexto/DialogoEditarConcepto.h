#pragma once

#include <QWidget>
namespace Ui { class DialogoEditarConcepto; };

class DialogoEditarConcepto : public QWidget
{
    Q_OBJECT

public:
    DialogoEditarConcepto(QWidget *parent = Q_NULLPTR);
    ~DialogoEditarConcepto();

private:
    Ui::DialogoEditarConcepto *ui;
};
