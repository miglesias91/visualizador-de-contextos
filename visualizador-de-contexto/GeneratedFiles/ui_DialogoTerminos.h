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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoTerminos
{
public:
    QAction *action_actualizarYCerrar;
    QAction *action_resetear_termino;
    QAction *action_guardar_termino;
    QAction *action_eliminar_termino;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QFormLayout *formLayout;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta;
    QLabel *lbl_termino;
    QLineEdit *lineedit_termino;
    QPushButton *btn_guardar_termino;
    QPushButton *btn_limpiar_termino;
    QPushButton *btn_eliminar;
    QVBoxLayout *verticalLayout_2;
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
        action_resetear_termino = new QAction(DialogoTerminos);
        action_resetear_termino->setObjectName(QStringLiteral("action_resetear_termino"));
        action_resetear_termino->setCheckable(true);
        action_guardar_termino = new QAction(DialogoTerminos);
        action_guardar_termino->setObjectName(QStringLiteral("action_guardar_termino"));
        action_guardar_termino->setCheckable(true);
        action_eliminar_termino = new QAction(DialogoTerminos);
        action_eliminar_termino->setObjectName(QStringLiteral("action_eliminar_termino"));
        action_eliminar_termino->setCheckable(true);
        horizontalLayoutWidget = new QWidget(DialogoTerminos);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(20, 15, 468, 194));
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

        btn_guardar_termino = new QPushButton(horizontalLayoutWidget);
        btn_guardar_termino->setObjectName(QStringLiteral("btn_guardar_termino"));

        formLayout->setWidget(2, QFormLayout::FieldRole, btn_guardar_termino);

        btn_limpiar_termino = new QPushButton(horizontalLayoutWidget);
        btn_limpiar_termino->setObjectName(QStringLiteral("btn_limpiar_termino"));

        formLayout->setWidget(3, QFormLayout::FieldRole, btn_limpiar_termino);

        btn_eliminar = new QPushButton(horizontalLayoutWidget);
        btn_eliminar->setObjectName(QStringLiteral("btn_eliminar"));

        formLayout->setWidget(4, QFormLayout::FieldRole, btn_eliminar);


        horizontalLayout->addLayout(formLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lista_terminos = new QListWidget(horizontalLayoutWidget);
        lista_terminos->setObjectName(QStringLiteral("lista_terminos"));

        verticalLayout_2->addWidget(lista_terminos);


        horizontalLayout->addLayout(verticalLayout_2);

        btnbox_terminos = new QDialogButtonBox(DialogoTerminos);
        btnbox_terminos->setObjectName(QStringLiteral("btnbox_terminos"));
        btnbox_terminos->setGeometry(QRect(210, 310, 156, 23));
        btnbox_terminos->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogoTerminos);
        QObject::connect(btnbox_terminos, SIGNAL(rejected()), DialogoTerminos, SLOT(close()));
        QObject::connect(btnbox_terminos, SIGNAL(accepted()), action_actualizarYCerrar, SLOT(trigger()));
        QObject::connect(btn_guardar_termino, SIGNAL(released()), action_guardar_termino, SLOT(trigger()));
        QObject::connect(btn_limpiar_termino, SIGNAL(released()), action_resetear_termino, SLOT(trigger()));
        QObject::connect(btn_eliminar, SIGNAL(released()), action_eliminar_termino, SLOT(trigger()));

        QMetaObject::connectSlotsByName(DialogoTerminos);
    } // setupUi

    void retranslateUi(QWidget *DialogoTerminos)
    {
        DialogoTerminos->setWindowTitle(QApplication::translate("DialogoTerminos", "DialogoTerminos", Q_NULLPTR));
        action_actualizarYCerrar->setText(QApplication::translate("DialogoTerminos", "actualizarYCerrar", Q_NULLPTR));
        action_resetear_termino->setText(QApplication::translate("DialogoTerminos", "resetear_termino", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_resetear_termino->setToolTip(QApplication::translate("DialogoTerminos", "resetear termino", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_resetear_termino->setShortcut(QApplication::translate("DialogoTerminos", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_guardar_termino->setText(QApplication::translate("DialogoTerminos", "guardar_termino", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_guardar_termino->setToolTip(QApplication::translate("DialogoTerminos", "guardar termino", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_guardar_termino->setShortcut(QApplication::translate("DialogoTerminos", "Ctrl+G", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_eliminar_termino->setText(QApplication::translate("DialogoTerminos", "eliminar_termino", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_eliminar_termino->setToolTip(QApplication::translate("DialogoTerminos", "eliminar termino", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_eliminar_termino->setShortcut(QApplication::translate("DialogoTerminos", "Ctrl+D", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        lbl_etiqueta->setText(QApplication::translate("DialogoTerminos", "etiqueta", Q_NULLPTR));
        lbl_termino->setText(QApplication::translate("DialogoTerminos", "termino", Q_NULLPTR));
        btn_guardar_termino->setText(QApplication::translate("DialogoTerminos", "guardar", Q_NULLPTR));
        btn_limpiar_termino->setText(QApplication::translate("DialogoTerminos", "limpiar", Q_NULLPTR));
        btn_eliminar->setText(QApplication::translate("DialogoTerminos", "eliminar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoTerminos: public Ui_DialogoTerminos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOTERMINOS_H
