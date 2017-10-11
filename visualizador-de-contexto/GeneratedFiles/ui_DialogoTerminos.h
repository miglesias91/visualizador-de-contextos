/********************************************************************************
** Form generated from reading UI file 'DialogoTerminos.ui'
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
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoTerminos
{
public:
    QAction *action_actualizarYCerrar;
    QAction *action_resetear;
    QAction *action_guardar;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta;
    QLabel *lbl_termino;
    QLineEdit *lineedit_termino;
    QDialogButtonBox *btnbox_guardar_termino;
    QListWidget *lista_terminos;
    QDialogButtonBox *btnbox_terminos;

    void setupUi(QWidget *DialogoTerminos)
    {
        if (DialogoTerminos->objectName().isEmpty())
            DialogoTerminos->setObjectName(QStringLiteral("DialogoTerminos"));
        DialogoTerminos->resize(577, 345);
        action_actualizarYCerrar = new QAction(DialogoTerminos);
        action_actualizarYCerrar->setObjectName(QStringLiteral("action_actualizarYCerrar"));
        action_actualizarYCerrar->setCheckable(true);
        action_resetear = new QAction(DialogoTerminos);
        action_resetear->setObjectName(QStringLiteral("action_resetear"));
        action_resetear->setCheckable(true);
        action_guardar = new QAction(DialogoTerminos);
        action_guardar->setObjectName(QStringLiteral("action_guardar"));
        action_guardar->setCheckable(true);
        horizontalLayoutWidget = new QWidget(DialogoTerminos);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 15, 541, 291));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        lbl_etiqueta = new QLabel(horizontalLayoutWidget);
        lbl_etiqueta->setObjectName(QStringLiteral("lbl_etiqueta"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lbl_etiqueta);

        lineedit_etiqueta = new QLineEdit(horizontalLayoutWidget);
        lineedit_etiqueta->setObjectName(QStringLiteral("lineedit_etiqueta"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineedit_etiqueta);

        lbl_termino = new QLabel(horizontalLayoutWidget);
        lbl_termino->setObjectName(QStringLiteral("lbl_termino"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lbl_termino);

        lineedit_termino = new QLineEdit(horizontalLayoutWidget);
        lineedit_termino->setObjectName(QStringLiteral("lineedit_termino"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineedit_termino);

        btnbox_guardar_termino = new QDialogButtonBox(horizontalLayoutWidget);
        btnbox_guardar_termino->setObjectName(QStringLiteral("btnbox_guardar_termino"));
        btnbox_guardar_termino->setOrientation(Qt::Horizontal);
        btnbox_guardar_termino->setStandardButtons(QDialogButtonBox::Reset|QDialogButtonBox::Save);
        btnbox_guardar_termino->setCenterButtons(false);

        formLayout->setWidget(2, QFormLayout::FieldRole, btnbox_guardar_termino);


        horizontalLayout->addLayout(formLayout);

        lista_terminos = new QListWidget(horizontalLayoutWidget);
        lista_terminos->setObjectName(QStringLiteral("lista_terminos"));

        horizontalLayout->addWidget(lista_terminos);

        btnbox_terminos = new QDialogButtonBox(DialogoTerminos);
        btnbox_terminos->setObjectName(QStringLiteral("btnbox_terminos"));
        btnbox_terminos->setGeometry(QRect(210, 310, 156, 23));
        btnbox_terminos->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogoTerminos);
        QObject::connect(btnbox_terminos, SIGNAL(rejected()), DialogoTerminos, SLOT(close()));
        QObject::connect(btnbox_terminos, SIGNAL(accepted()), action_actualizarYCerrar, SLOT(trigger()));
        QObject::connect(btnbox_guardar_termino, SIGNAL(rejected()), action_resetear, SLOT(trigger()));

        QMetaObject::connectSlotsByName(DialogoTerminos);
    } // setupUi

    void retranslateUi(QWidget *DialogoTerminos)
    {
        DialogoTerminos->setWindowTitle(QApplication::translate("DialogoTerminos", "DialogoTerminos", Q_NULLPTR));
        action_actualizarYCerrar->setText(QApplication::translate("DialogoTerminos", "actualizarYCerrar", Q_NULLPTR));
        action_resetear->setText(QApplication::translate("DialogoTerminos", "resetear", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_resetear->setShortcut(QApplication::translate("DialogoTerminos", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_guardar->setText(QApplication::translate("DialogoTerminos", "guardar", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_guardar->setShortcut(QApplication::translate("DialogoTerminos", "Ctrl+G", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        lbl_etiqueta->setText(QApplication::translate("DialogoTerminos", "etiqueta", Q_NULLPTR));
        lbl_termino->setText(QApplication::translate("DialogoTerminos", "termino", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoTerminos: public Ui_DialogoTerminos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOTERMINOS_H
