#ifndef DIALOGOTERMINOS_H
#define DIALOGOTERMINOS_H

#include <QtWidgets/qdialog.h>

namespace Ui {
class DialogoTerminos;
}

class DialogoTerminos : public QDialog
{
    Q_OBJECT

public:
    explicit DialogoTerminos(QWidget *parent = 0);
    ~DialogoTerminos();

private slots:
    void on_buttonBox_rejected();

private:
    Ui::DialogoTerminos *ui;
};

#endif // DIALOGOTERMINOS_H
