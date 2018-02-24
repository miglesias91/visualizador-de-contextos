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
    QAction *action_estado_btn_agregar;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *layout_general;
    QFormLayout *layout_opciones;
    QLabel *lbl_termino;
    QLineEdit *lineedit_termino;
    QPushButton *btn_agregar_termino;
    QPushButton *btn_limpiar_termino;
    QPushButton *btn_eliminar;
    QVBoxLayout *layout_lista;
    QListWidget *lista_terminos;
    QDialogButtonBox *btnbox_terminos;

    void setupUi(QWidget *DialogoTerminos)
    {
        if (DialogoTerminos->objectName().isEmpty())
            DialogoTerminos->setObjectName(QStringLiteral("DialogoTerminos"));
        DialogoTerminos->resize(800, 400);
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
        action_estado_btn_agregar = new QAction(DialogoTerminos);
        action_estado_btn_agregar->setObjectName(QStringLiteral("action_estado_btn_agregar"));
        horizontalLayoutWidget = new QWidget(DialogoTerminos);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 781, 351));
        layout_general = new QHBoxLayout(horizontalLayoutWidget);
        layout_general->setSpacing(6);
        layout_general->setContentsMargins(11, 11, 11, 11);
        layout_general->setObjectName(QStringLiteral("layout_general"));
        layout_general->setContentsMargins(0, 0, 0, 0);
        layout_opciones = new QFormLayout();
        layout_opciones->setSpacing(6);
        layout_opciones->setObjectName(QStringLiteral("layout_opciones"));
        lbl_termino = new QLabel(horizontalLayoutWidget);
        lbl_termino->setObjectName(QStringLiteral("lbl_termino"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        lbl_termino->setFont(font);

        layout_opciones->setWidget(0, QFormLayout::LabelRole, lbl_termino);

        lineedit_termino = new QLineEdit(horizontalLayoutWidget);
        lineedit_termino->setObjectName(QStringLiteral("lineedit_termino"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(10);
        font1.setItalic(false);
        lineedit_termino->setFont(font1);

        layout_opciones->setWidget(0, QFormLayout::FieldRole, lineedit_termino);

        btn_agregar_termino = new QPushButton(horizontalLayoutWidget);
        btn_agregar_termino->setObjectName(QStringLiteral("btn_agregar_termino"));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(11);
        btn_agregar_termino->setFont(font2);

        layout_opciones->setWidget(1, QFormLayout::FieldRole, btn_agregar_termino);

        btn_limpiar_termino = new QPushButton(horizontalLayoutWidget);
        btn_limpiar_termino->setObjectName(QStringLiteral("btn_limpiar_termino"));
        btn_limpiar_termino->setFont(font2);

        layout_opciones->setWidget(2, QFormLayout::FieldRole, btn_limpiar_termino);

        btn_eliminar = new QPushButton(horizontalLayoutWidget);
        btn_eliminar->setObjectName(QStringLiteral("btn_eliminar"));
        btn_eliminar->setFont(font2);

        layout_opciones->setWidget(3, QFormLayout::FieldRole, btn_eliminar);


        layout_general->addLayout(layout_opciones);

        layout_lista = new QVBoxLayout();
        layout_lista->setSpacing(0);
        layout_lista->setObjectName(QStringLiteral("layout_lista"));
        lista_terminos = new QListWidget(horizontalLayoutWidget);
        lista_terminos->setObjectName(QStringLiteral("lista_terminos"));
        lista_terminos->setFont(font1);

        layout_lista->addWidget(lista_terminos);


        layout_general->addLayout(layout_lista);

        btnbox_terminos = new QDialogButtonBox(DialogoTerminos);
        btnbox_terminos->setObjectName(QStringLiteral("btnbox_terminos"));
        btnbox_terminos->setGeometry(QRect(325, 370, 156, 23));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        font3.setPointSize(11);
        font3.setItalic(true);
        btnbox_terminos->setFont(font3);
        btnbox_terminos->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogoTerminos);
        QObject::connect(btnbox_terminos, SIGNAL(rejected()), DialogoTerminos, SLOT(close()));
        QObject::connect(btnbox_terminos, SIGNAL(accepted()), action_actualizar_y_cerrar, SLOT(trigger()));
        QObject::connect(btn_agregar_termino, SIGNAL(released()), action_guardar_termino, SLOT(trigger()));
        QObject::connect(btn_limpiar_termino, SIGNAL(released()), action_resetear_termino, SLOT(trigger()));
        QObject::connect(btn_eliminar, SIGNAL(released()), action_eliminar_termino, SLOT(trigger()));
        QObject::connect(lista_terminos, SIGNAL(itemSelectionChanged()), action_estado_btn_eliminar, SLOT(trigger()));
        QObject::connect(lineedit_termino, SIGNAL(textEdited(QString)), action_estado_btn_agregar, SLOT(trigger()));

        QMetaObject::connectSlotsByName(DialogoTerminos);
    } // setupUi

    void retranslateUi(QWidget *DialogoTerminos)
    {
        DialogoTerminos->setWindowTitle(QApplication::translate("DialogoTerminos", "T\303\251rminos", Q_NULLPTR));
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
        action_estado_btn_agregar->setText(QApplication::translate("DialogoTerminos", "estado_btn_agregar", Q_NULLPTR));
        lbl_termino->setText(QApplication::translate("DialogoTerminos", "T\303\251rmino", Q_NULLPTR));
        btn_agregar_termino->setText(QApplication::translate("DialogoTerminos", "Agregar", Q_NULLPTR));
        btn_limpiar_termino->setText(QApplication::translate("DialogoTerminos", "Limpiar", Q_NULLPTR));
        btn_eliminar->setText(QApplication::translate("DialogoTerminos", "Eliminar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoTerminos: public Ui_DialogoTerminos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOTERMINOS_H
