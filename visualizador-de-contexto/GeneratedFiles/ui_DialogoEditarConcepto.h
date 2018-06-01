/********************************************************************************
** Form generated from reading UI file 'DialogoEditarConcepto.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOEDITARCONCEPTO_H
#define UI_DIALOGOEDITARCONCEPTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoEditarConcepto
{
public:
    QVBoxLayout *layout_dialogo;
    QWidget *widget_general;
    QVBoxLayout *layout_general;
    QWidget *widget_superior;
    QHBoxLayout *layout_superior;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta;
    QPushButton *btn_eliminar;
    QPushButton *btn_nuevo;
    QListWidget *lista;
    QWidget *widget_opciones;
    QHBoxLayout *layout_opciones;
    QPushButton *btn_guardar;
    QPushButton *btn_cancelar;

    void setupUi(QWidget *DialogoEditarConcepto)
    {
        if (DialogoEditarConcepto->objectName().isEmpty())
            DialogoEditarConcepto->setObjectName(QStringLiteral("DialogoEditarConcepto"));
        DialogoEditarConcepto->setWindowModality(Qt::NonModal);
        DialogoEditarConcepto->resize(404, 300);
        layout_dialogo = new QVBoxLayout(DialogoEditarConcepto);
        layout_dialogo->setSpacing(0);
        layout_dialogo->setContentsMargins(11, 11, 11, 11);
        layout_dialogo->setObjectName(QStringLiteral("layout_dialogo"));
        layout_dialogo->setContentsMargins(2, 1, 2, 1);
        widget_general = new QWidget(DialogoEditarConcepto);
        widget_general->setObjectName(QStringLiteral("widget_general"));
        layout_general = new QVBoxLayout(widget_general);
        layout_general->setSpacing(1);
        layout_general->setContentsMargins(11, 11, 11, 11);
        layout_general->setObjectName(QStringLiteral("layout_general"));
        layout_general->setContentsMargins(0, 0, 0, 0);
        widget_superior = new QWidget(widget_general);
        widget_superior->setObjectName(QStringLiteral("widget_superior"));
        layout_superior = new QHBoxLayout(widget_superior);
        layout_superior->setSpacing(3);
        layout_superior->setContentsMargins(11, 11, 11, 11);
        layout_superior->setObjectName(QStringLiteral("layout_superior"));
        layout_superior->setContentsMargins(0, 0, 0, 0);
        lbl_etiqueta = new QLabel(widget_superior);
        lbl_etiqueta->setObjectName(QStringLiteral("lbl_etiqueta"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        lbl_etiqueta->setFont(font);

        layout_superior->addWidget(lbl_etiqueta);

        lineedit_etiqueta = new QLineEdit(widget_superior);
        lineedit_etiqueta->setObjectName(QStringLiteral("lineedit_etiqueta"));

        layout_superior->addWidget(lineedit_etiqueta);

        btn_eliminar = new QPushButton(widget_superior);
        btn_eliminar->setObjectName(QStringLiteral("btn_eliminar"));
        btn_eliminar->setMinimumSize(QSize(0, 30));
        btn_eliminar->setMaximumSize(QSize(80, 16777215));
        btn_eliminar->setFont(font);

        layout_superior->addWidget(btn_eliminar);

        btn_nuevo = new QPushButton(widget_superior);
        btn_nuevo->setObjectName(QStringLiteral("btn_nuevo"));
        btn_nuevo->setMinimumSize(QSize(0, 30));
        btn_nuevo->setMaximumSize(QSize(80, 16777215));
        btn_nuevo->setFont(font);

        layout_superior->addWidget(btn_nuevo);


        layout_general->addWidget(widget_superior);

        lista = new QListWidget(widget_general);
        lista->setObjectName(QStringLiteral("lista"));

        layout_general->addWidget(lista);

        widget_opciones = new QWidget(widget_general);
        widget_opciones->setObjectName(QStringLiteral("widget_opciones"));
        layout_opciones = new QHBoxLayout(widget_opciones);
        layout_opciones->setSpacing(3);
        layout_opciones->setContentsMargins(11, 11, 11, 11);
        layout_opciones->setObjectName(QStringLiteral("layout_opciones"));
        layout_opciones->setContentsMargins(0, 0, 0, 0);
        btn_guardar = new QPushButton(widget_opciones);
        btn_guardar->setObjectName(QStringLiteral("btn_guardar"));
        btn_guardar->setFont(font);

        layout_opciones->addWidget(btn_guardar);

        btn_cancelar = new QPushButton(widget_opciones);
        btn_cancelar->setObjectName(QStringLiteral("btn_cancelar"));
        btn_cancelar->setFont(font);

        layout_opciones->addWidget(btn_cancelar);


        layout_general->addWidget(widget_opciones, 0, Qt::AlignHCenter);


        layout_dialogo->addWidget(widget_general);


        retranslateUi(DialogoEditarConcepto);

        QMetaObject::connectSlotsByName(DialogoEditarConcepto);
    } // setupUi

    void retranslateUi(QWidget *DialogoEditarConcepto)
    {
        DialogoEditarConcepto->setWindowTitle(QApplication::translate("DialogoEditarConcepto", "Editar Concepto", Q_NULLPTR));
        lbl_etiqueta->setText(QApplication::translate("DialogoEditarConcepto", "Etiqueta:", Q_NULLPTR));
        btn_eliminar->setText(QApplication::translate("DialogoEditarConcepto", "Eliminar", Q_NULLPTR));
        btn_nuevo->setText(QApplication::translate("DialogoEditarConcepto", "Nuevo", Q_NULLPTR));
        btn_guardar->setText(QApplication::translate("DialogoEditarConcepto", "Guardar", Q_NULLPTR));
        btn_cancelar->setText(QApplication::translate("DialogoEditarConcepto", "Cancelar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoEditarConcepto: public Ui_DialogoEditarConcepto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOEDITARCONCEPTO_H
