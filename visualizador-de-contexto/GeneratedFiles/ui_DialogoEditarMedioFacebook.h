/********************************************************************************
** Form generated from reading UI file 'DialogoEditarMedioFacebook.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOEDITARMEDIOFACEBOOK_H
#define UI_DIALOGOEDITARMEDIOFACEBOOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoEditarMedioFacebook
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_campos;
    QVBoxLayout *layout_campos;
    QWidget *widget_etiqueta;
    QHBoxLayout *layout_etiqueta;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta;
    QWidget *widget_nombre;
    QHBoxLayout *layout_nombre;
    QLabel *lbl_nombre_pagina;
    QLineEdit *lineedit_nombre_pagina;
    QWidget *widget_opciones;
    QHBoxLayout *layout_opciones;
    QPushButton *btn_guardar;
    QPushButton *btn_cancelar;

    void setupUi(QDialog *DialogoEditarMedioFacebook)
    {
        if (DialogoEditarMedioFacebook->objectName().isEmpty())
            DialogoEditarMedioFacebook->setObjectName(QStringLiteral("DialogoEditarMedioFacebook"));
        DialogoEditarMedioFacebook->resize(400, 75);
        verticalLayout = new QVBoxLayout(DialogoEditarMedioFacebook);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 1, 2, 1);
        widget_campos = new QWidget(DialogoEditarMedioFacebook);
        widget_campos->setObjectName(QStringLiteral("widget_campos"));
        layout_campos = new QVBoxLayout(widget_campos);
        layout_campos->setSpacing(2);
        layout_campos->setContentsMargins(11, 11, 11, 11);
        layout_campos->setObjectName(QStringLiteral("layout_campos"));
        layout_campos->setContentsMargins(0, 0, 0, 0);
        widget_etiqueta = new QWidget(widget_campos);
        widget_etiqueta->setObjectName(QStringLiteral("widget_etiqueta"));
        layout_etiqueta = new QHBoxLayout(widget_etiqueta);
        layout_etiqueta->setSpacing(2);
        layout_etiqueta->setContentsMargins(11, 11, 11, 11);
        layout_etiqueta->setObjectName(QStringLiteral("layout_etiqueta"));
        layout_etiqueta->setContentsMargins(0, 0, 0, 0);
        lbl_etiqueta = new QLabel(widget_etiqueta);
        lbl_etiqueta->setObjectName(QStringLiteral("lbl_etiqueta"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(10);
        lbl_etiqueta->setFont(font);

        layout_etiqueta->addWidget(lbl_etiqueta);

        lineedit_etiqueta = new QLineEdit(widget_etiqueta);
        lineedit_etiqueta->setObjectName(QStringLiteral("lineedit_etiqueta"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(10);
        font1.setItalic(true);
        lineedit_etiqueta->setFont(font1);

        layout_etiqueta->addWidget(lineedit_etiqueta);


        layout_campos->addWidget(widget_etiqueta);

        widget_nombre = new QWidget(widget_campos);
        widget_nombre->setObjectName(QStringLiteral("widget_nombre"));
        layout_nombre = new QHBoxLayout(widget_nombre);
        layout_nombre->setSpacing(2);
        layout_nombre->setContentsMargins(11, 11, 11, 11);
        layout_nombre->setObjectName(QStringLiteral("layout_nombre"));
        layout_nombre->setContentsMargins(0, 0, 0, 0);
        lbl_nombre_pagina = new QLabel(widget_nombre);
        lbl_nombre_pagina->setObjectName(QStringLiteral("lbl_nombre_pagina"));
        lbl_nombre_pagina->setFont(font);

        layout_nombre->addWidget(lbl_nombre_pagina);

        lineedit_nombre_pagina = new QLineEdit(widget_nombre);
        lineedit_nombre_pagina->setObjectName(QStringLiteral("lineedit_nombre_pagina"));
        lineedit_nombre_pagina->setFont(font1);

        layout_nombre->addWidget(lineedit_nombre_pagina);


        layout_campos->addWidget(widget_nombre);


        verticalLayout->addWidget(widget_campos);

        widget_opciones = new QWidget(DialogoEditarMedioFacebook);
        widget_opciones->setObjectName(QStringLiteral("widget_opciones"));
        layout_opciones = new QHBoxLayout(widget_opciones);
        layout_opciones->setSpacing(2);
        layout_opciones->setContentsMargins(11, 11, 11, 11);
        layout_opciones->setObjectName(QStringLiteral("layout_opciones"));
        layout_opciones->setContentsMargins(0, 0, 0, 0);
        btn_guardar = new QPushButton(widget_opciones);
        btn_guardar->setObjectName(QStringLiteral("btn_guardar"));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(12);
        btn_guardar->setFont(font2);

        layout_opciones->addWidget(btn_guardar);

        btn_cancelar = new QPushButton(widget_opciones);
        btn_cancelar->setObjectName(QStringLiteral("btn_cancelar"));
        btn_cancelar->setFont(font2);

        layout_opciones->addWidget(btn_cancelar);


        verticalLayout->addWidget(widget_opciones, 0, Qt::AlignHCenter);


        retranslateUi(DialogoEditarMedioFacebook);

        QMetaObject::connectSlotsByName(DialogoEditarMedioFacebook);
    } // setupUi

    void retranslateUi(QDialog *DialogoEditarMedioFacebook)
    {
        DialogoEditarMedioFacebook->setWindowTitle(QApplication::translate("DialogoEditarMedioFacebook", "Editar cuenta de Facebook", Q_NULLPTR));
        lbl_etiqueta->setText(QApplication::translate("DialogoEditarMedioFacebook", "Etiqueta", Q_NULLPTR));
        lbl_nombre_pagina->setText(QApplication::translate("DialogoEditarMedioFacebook", "Nombre p\303\241gina", Q_NULLPTR));
        btn_guardar->setText(QApplication::translate("DialogoEditarMedioFacebook", "Guardar", Q_NULLPTR));
        btn_cancelar->setText(QApplication::translate("DialogoEditarMedioFacebook", "Cancelar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoEditarMedioFacebook: public Ui_DialogoEditarMedioFacebook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOEDITARMEDIOFACEBOOK_H
