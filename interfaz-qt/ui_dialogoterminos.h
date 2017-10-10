/********************************************************************************
** Form generated from reading UI file 'dialogoterminos.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOTERMINOS_H
#define UI_DIALOGOTERMINOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoTerminos
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QFormLayout *layout_campos;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta;
    QLabel *lbl_termino;
    QLineEdit *lineedit_termino;
    QPushButton *btn_limpiar;
    QPushButton *btn_guardar;
    QListWidget *lista_terminos;

    void setupUi(QDialog *DialogoTerminos)
    {
        if (DialogoTerminos->objectName().isEmpty())
            DialogoTerminos->setObjectName(QStringLiteral("DialogoTerminos"));
        DialogoTerminos->resize(400, 300);
        buttonBox = new QDialogButtonBox(DialogoTerminos);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(DialogoTerminos);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 381, 211));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        layout_campos = new QFormLayout();
        layout_campos->setObjectName(QStringLiteral("layout_campos"));
        lbl_etiqueta = new QLabel(horizontalLayoutWidget);
        lbl_etiqueta->setObjectName(QStringLiteral("lbl_etiqueta"));

        layout_campos->setWidget(0, QFormLayout::LabelRole, lbl_etiqueta);

        lineedit_etiqueta = new QLineEdit(horizontalLayoutWidget);
        lineedit_etiqueta->setObjectName(QStringLiteral("lineedit_etiqueta"));

        layout_campos->setWidget(0, QFormLayout::FieldRole, lineedit_etiqueta);

        lbl_termino = new QLabel(horizontalLayoutWidget);
        lbl_termino->setObjectName(QStringLiteral("lbl_termino"));

        layout_campos->setWidget(1, QFormLayout::LabelRole, lbl_termino);

        lineedit_termino = new QLineEdit(horizontalLayoutWidget);
        lineedit_termino->setObjectName(QStringLiteral("lineedit_termino"));

        layout_campos->setWidget(1, QFormLayout::FieldRole, lineedit_termino);

        btn_limpiar = new QPushButton(horizontalLayoutWidget);
        btn_limpiar->setObjectName(QStringLiteral("btn_limpiar"));

        layout_campos->setWidget(2, QFormLayout::LabelRole, btn_limpiar);

        btn_guardar = new QPushButton(horizontalLayoutWidget);
        btn_guardar->setObjectName(QStringLiteral("btn_guardar"));

        layout_campos->setWidget(2, QFormLayout::FieldRole, btn_guardar);


        horizontalLayout->addLayout(layout_campos);

        lista_terminos = new QListWidget(horizontalLayoutWidget);
        lista_terminos->setObjectName(QStringLiteral("lista_terminos"));
        lista_terminos->setEnabled(true);

        horizontalLayout->addWidget(lista_terminos);


        retranslateUi(DialogoTerminos);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogoTerminos, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogoTerminos, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogoTerminos);
    } // setupUi

    void retranslateUi(QDialog *DialogoTerminos)
    {
        DialogoTerminos->setWindowTitle(QApplication::translate("DialogoTerminos", "Dialog", Q_NULLPTR));
        lbl_etiqueta->setText(QApplication::translate("DialogoTerminos", "etiqueta", Q_NULLPTR));
        lbl_termino->setText(QApplication::translate("DialogoTerminos", "termino", Q_NULLPTR));
        btn_limpiar->setText(QApplication::translate("DialogoTerminos", "Limpiar", Q_NULLPTR));
        btn_guardar->setText(QApplication::translate("DialogoTerminos", "Guardar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoTerminos: public Ui_DialogoTerminos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOTERMINOS_H
