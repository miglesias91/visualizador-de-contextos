/********************************************************************************
** Form generated from reading UI file 'DialogoEditarCuentaTwitter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOEDITARCUENTATWITTER_H
#define UI_DIALOGOEDITARCUENTATWITTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoEditarCuentaTwitter
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *layout_formulario;
    QLabel *lbl_etiqueta;
    QLabel *lbl_nombre_pagina;
    QLineEdit *lineedit_etiqueta;
    QLineEdit *lineedit_nombre_pagina;
    QDialogButtonBox *btnbox;

    void setupUi(QDialog *DialogoEditarCuentaTwitter)
    {
        if (DialogoEditarCuentaTwitter->objectName().isEmpty())
            DialogoEditarCuentaTwitter->setObjectName(QStringLiteral("DialogoEditarCuentaTwitter"));
        DialogoEditarCuentaTwitter->resize(400, 100);
        formLayoutWidget = new QWidget(DialogoEditarCuentaTwitter);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 381, 51));
        layout_formulario = new QFormLayout(formLayoutWidget);
        layout_formulario->setSpacing(6);
        layout_formulario->setContentsMargins(11, 11, 11, 11);
        layout_formulario->setObjectName(QStringLiteral("layout_formulario"));
        layout_formulario->setContentsMargins(0, 0, 0, 0);
        lbl_etiqueta = new QLabel(formLayoutWidget);
        lbl_etiqueta->setObjectName(QStringLiteral("lbl_etiqueta"));

        layout_formulario->setWidget(0, QFormLayout::LabelRole, lbl_etiqueta);

        lbl_nombre_pagina = new QLabel(formLayoutWidget);
        lbl_nombre_pagina->setObjectName(QStringLiteral("lbl_nombre_pagina"));

        layout_formulario->setWidget(1, QFormLayout::LabelRole, lbl_nombre_pagina);

        lineedit_etiqueta = new QLineEdit(formLayoutWidget);
        lineedit_etiqueta->setObjectName(QStringLiteral("lineedit_etiqueta"));

        layout_formulario->setWidget(0, QFormLayout::FieldRole, lineedit_etiqueta);

        lineedit_nombre_pagina = new QLineEdit(formLayoutWidget);
        lineedit_nombre_pagina->setObjectName(QStringLiteral("lineedit_nombre_pagina"));

        layout_formulario->setWidget(1, QFormLayout::FieldRole, lineedit_nombre_pagina);

        btnbox = new QDialogButtonBox(DialogoEditarCuentaTwitter);
        btnbox->setObjectName(QStringLiteral("btnbox"));
        btnbox->setGeometry(QRect(120, 70, 156, 23));
        btnbox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);

        retranslateUi(DialogoEditarCuentaTwitter);

        QMetaObject::connectSlotsByName(DialogoEditarCuentaTwitter);
    } // setupUi

    void retranslateUi(QDialog *DialogoEditarCuentaTwitter)
    {
        DialogoEditarCuentaTwitter->setWindowTitle(QApplication::translate("DialogoEditarCuentaTwitter", "DialogoEditarCuentaTwitter", Q_NULLPTR));
        lbl_etiqueta->setText(QApplication::translate("DialogoEditarCuentaTwitter", "Etiqueta:", Q_NULLPTR));
        lbl_nombre_pagina->setText(QApplication::translate("DialogoEditarCuentaTwitter", "Nombre p\303\241gina", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoEditarCuentaTwitter: public Ui_DialogoEditarCuentaTwitter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOEDITARCUENTATWITTER_H
