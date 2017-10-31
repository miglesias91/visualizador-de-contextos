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
    QAction *action_actualizar_y_cerrar;
    QAction *action_resetear_termino;
    QAction *action_guardar_termino;
    QAction *action_eliminar_termino;
    QAction *action_estado_btn_eliminar;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *layout_general;
    QFormLayout *layout_opciones;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta;
    QLabel *lbl_termino;
    QLineEdit *lineedit_termino;
    QPushButton *btn_guardar_termino;
    QPushButton *btn_limpiar_termino;
    QPushButton *btn_eliminar;
    QVBoxLayout *layout_lista;
    QListWidget *lista_terminos;
    QDialogButtonBox *btnbox_terminos;

    void setupUi(QWidget *DialogoTerminos)
    {
        if (DialogoTerminos->objectName().isEmpty())
            DialogoTerminos->setObjectName(QStringLiteral("DialogoTerminos"));
        DialogoTerminos->resize(577, 345);
        action_actualizar_y_cerrar = new QAction(DialogoTerminos);
        action_actualizar_y_cerrar->setObjectName(QStringLiteral("action_actualizar_y_cerrar"));
        action_actualizar_y_cerrar->setCheckable(true);
        action_resetear_termino = new QAction(DialogoTerminos);
        action_resetear_termino->setObjectName(QStringLiteral("action_resetear_termino"));
        action_resetear_termino->setCheckable(true);
        action_guardar_termino = new QAction(DialogoTerminos);
        action_guardar_termino->setObjectName(QStringLiteral("action_guardar_termino"));
        action_guardar_termino->setCheckable(true);
        action_eliminar_termino = new QAction(DialogoTerminos);
        action_eliminar_termino->setObjectName(QStringLiteral("action_eliminar_termino"));
        action_eliminar_termino->setCheckable(true);
        action_estado_btn_eliminar = new QAction(DialogoTerminos);
        action_estado_btn_eliminar->setObjectName(QStringLiteral("action_estado_btn_eliminar"));
        horizontalLayoutWidget = new QWidget(DialogoTerminos);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 551, 291));
        layout_general = new QHBoxLayout(horizontalLayoutWidget);
        layout_general->setSpacing(6);
        layout_general->setContentsMargins(11, 11, 11, 11);
        layout_general->setObjectName(QStringLiteral("layout_general"));
        layout_general->setContentsMargins(0, 0, 0, 0);
        layout_opciones = new QFormLayout();
        layout_opciones->setSpacing(6);
        layout_opciones->setObjectName(QStringLiteral("layout_opciones"));
        lbl_etiqueta = new QLabel(horizontalLayoutWidget);
        lbl_etiqueta->setObjectName(QStringLiteral("lbl_etiqueta"));

        layout_opciones->setWidget(0, QFormLayout::LabelRole, lbl_etiqueta);

        lineedit_etiqueta = new QLineEdit(horizontalLayoutWidget);
        lineedit_etiqueta->setObjectName(QStringLiteral("lineedit_etiqueta"));

        layout_opciones->setWidget(0, QFormLayout::FieldRole, lineedit_etiqueta);

        lbl_termino = new QLabel(horizontalLayoutWidget);
        lbl_termino->setObjectName(QStringLiteral("lbl_termino"));

        layout_opciones->setWidget(1, QFormLayout::LabelRole, lbl_termino);

        lineedit_termino = new QLineEdit(horizontalLayoutWidget);
        lineedit_termino->setObjectName(QStringLiteral("lineedit_termino"));

        layout_opciones->setWidget(1, QFormLayout::FieldRole, lineedit_termino);

        btn_guardar_termino = new QPushButton(horizontalLayoutWidget);
        btn_guardar_termino->setObjectName(QStringLiteral("btn_guardar_termino"));

        layout_opciones->setWidget(2, QFormLayout::FieldRole, btn_guardar_termino);

        btn_limpiar_termino = new QPushButton(horizontalLayoutWidget);
        btn_limpiar_termino->setObjectName(QStringLiteral("btn_limpiar_termino"));

        layout_opciones->setWidget(3, QFormLayout::FieldRole, btn_limpiar_termino);

        btn_eliminar = new QPushButton(horizontalLayoutWidget);
        btn_eliminar->setObjectName(QStringLiteral("btn_eliminar"));

        layout_opciones->setWidget(4, QFormLayout::FieldRole, btn_eliminar);


        layout_general->addLayout(layout_opciones);

        layout_lista = new QVBoxLayout();
        layout_lista->setSpacing(0);
        layout_lista->setObjectName(QStringLiteral("layout_lista"));
        lista_terminos = new QListWidget(horizontalLayoutWidget);
        lista_terminos->setObjectName(QStringLiteral("lista_terminos"));

        layout_lista->addWidget(lista_terminos);


        layout_general->addLayout(layout_lista);

        btnbox_terminos = new QDialogButtonBox(DialogoTerminos);
        btnbox_terminos->setObjectName(QStringLiteral("btnbox_terminos"));
        btnbox_terminos->setGeometry(QRect(210, 310, 156, 23));
        btnbox_terminos->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogoTerminos);
        QObject::connect(btnbox_terminos, SIGNAL(rejected()), DialogoTerminos, SLOT(close()));
        QObject::connect(btnbox_terminos, SIGNAL(accepted()), action_actualizar_y_cerrar, SLOT(trigger()));
        QObject::connect(btn_guardar_termino, SIGNAL(released()), action_guardar_termino, SLOT(trigger()));
        QObject::connect(btn_limpiar_termino, SIGNAL(released()), action_resetear_termino, SLOT(trigger()));
        QObject::connect(btn_eliminar, SIGNAL(released()), action_eliminar_termino, SLOT(trigger()));
        QObject::connect(lista_terminos, SIGNAL(itemSelectionChanged()), action_estado_btn_eliminar, SLOT(trigger()));

        QMetaObject::connectSlotsByName(DialogoTerminos);
    } // setupUi

    void retranslateUi(QWidget *DialogoTerminos)
    {
        DialogoTerminos->setWindowTitle(QApplication::translate("DialogoTerminos", "DialogoTerminos", Q_NULLPTR));
        action_actualizar_y_cerrar->setText(QApplication::translate("DialogoTerminos", "actualiza_y_cerrar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_actualizar_y_cerrar->setToolTip(QApplication::translate("DialogoTerminos", "actualizar y cerrar", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
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
        action_estado_btn_eliminar->setText(QApplication::translate("DialogoTerminos", "estado_btn_eliminar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_estado_btn_eliminar->setToolTip(QApplication::translate("DialogoTerminos", "estado btn eliminar", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
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
