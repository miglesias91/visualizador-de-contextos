#pragma once

#include <QWidget>
namespace Ui { class DialogoMediosFacebook; };

class DialogoMediosFacebook : public QWidget
{
    Q_OBJECT

public:
    DialogoMediosFacebook(QWidget *parent = Q_NULLPTR);
    ~DialogoMediosFacebook();

private:
    Ui::DialogoMediosFacebook *ui;
};
