/********************************************************************************
** Form generated from reading UI file 'DialogoMediosFacebook.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOMEDIOSFACEBOOK_H
#define UI_DIALOGOMEDIOSFACEBOOK_H

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

class Ui_DialogoMediosFacebook
{
public:
    QAction *action_actualizar_y_cerrar;
    QAction *action_resetear;
    QAction *action_guardar;
    QAction *action_eliminar;
    QAction *action_estado_btn_eliminar;
    QAction *action_estado_btn_agregar;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *layout_general;
    QFormLayout *layout_opciones;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta;
    QLabel *lbl_nombre_pagina;
    QPushButton *btn_agregar;
    QPushButton *btn_limpiar;
    QPushButton *btn_eliminar;
    QLineEdit *lineedit_nombre_pagina;
    QVBoxLayout *layout_lista;
    QListWidget *lista_medios_facebook;
    QDialogButtonBox *btnbox_medios_facebook;

    void setupUi(QWidget *DialogoMediosFacebook)
    {
        if (DialogoMediosFacebook->objectName().isEmpty())
            DialogoMediosFacebook->setObjectName(QStringLiteral("DialogoMediosFacebook"));
        DialogoMediosFacebook->resize(800, 400);
        action_actualizar_y_cerrar = new QAction(DialogoMediosFacebook);
        action_actualizar_y_cerrar->setObjectName(QStringLiteral("action_actualizar_y_cerrar"));
        action_actualizar_y_cerrar->setCheckable(true);
        action_resetear = new QAction(DialogoMediosFacebook);
        action_resetear->setObjectName(QStringLiteral("action_resetear"));
        action_resetear->setCheckable(true);
        action_guardar = new QAction(DialogoMediosFacebook);
        action_guardar->setObjectName(QStringLiteral("action_guardar"));
        action_guardar->setCheckable(true);
        action_eliminar = new QAction(DialogoMediosFacebook);
        action_eliminar->setObjectName(QStringLiteral("action_eliminar"));
        action_eliminar->setCheckable(true);
        action_estado_btn_eliminar = new QAction(DialogoMediosFacebook);
        action_estado_btn_eliminar->setObjectName(QStringLiteral("action_estado_btn_eliminar"));
        action_estado_btn_agregar = new QAction(DialogoMediosFacebook);
        action_estado_btn_agregar->setObjectName(QStringLiteral("action_estado_btn_agregar"));
        horizontalLayoutWidget = new QWidget(DialogoMediosFacebook);
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
        lbl_etiqueta = new QLabel(horizontalLayoutWidget);
        lbl_etiqueta->setObjectName(QStringLiteral("lbl_etiqueta"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        lbl_etiqueta->setFont(font);

        layout_opciones->setWidget(0, QFormLayout::LabelRole, lbl_etiqueta);

        lineedit_etiqueta = new QLineEdit(horizontalLayoutWidget);
        lineedit_etiqueta->setObjectName(QStringLiteral("lineedit_etiqueta"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(10);
        font1.setItalic(true);
        lineedit_etiqueta->setFont(font1);

        layout_opciones->setWidget(0, QFormLayout::FieldRole, lineedit_etiqueta);

        lbl_nombre_pagina = new QLabel(horizontalLayoutWidget);
        lbl_nombre_pagina->setObjectName(QStringLiteral("lbl_nombre_pagina"));
        lbl_nombre_pagina->setFont(font);

        layout_opciones->setWidget(1, QFormLayout::LabelRole, lbl_nombre_pagina);

        btn_agregar = new QPushButton(horizontalLayoutWidget);
        btn_agregar->setObjectName(QStringLiteral("btn_agregar"));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(11);
        btn_agregar->setFont(font2);

        layout_opciones->setWidget(2, QFormLayout::FieldRole, btn_agregar);

        btn_limpiar = new QPushButton(horizontalLayoutWidget);
        btn_limpiar->setObjectName(QStringLiteral("btn_limpiar"));
        btn_limpiar->setFont(font2);

        layout_opciones->setWidget(3, QFormLayout::FieldRole, btn_limpiar);

        btn_eliminar = new QPushButton(horizontalLayoutWidget);
        btn_eliminar->setObjectName(QStringLiteral("btn_eliminar"));
        btn_eliminar->setFont(font2);

        layout_opciones->setWidget(4, QFormLayout::FieldRole, btn_eliminar);

        lineedit_nombre_pagina = new QLineEdit(horizontalLayoutWidget);
        lineedit_nombre_pagina->setObjectName(QStringLiteral("lineedit_nombre_pagina"));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        font3.setPointSize(10);
        font3.setBold(false);
        font3.setWeight(50);
        lineedit_nombre_pagina->setFont(font3);

        layout_opciones->setWidget(1, QFormLayout::FieldRole, lineedit_nombre_pagina);


        layout_general->addLayout(layout_opciones);

        layout_lista = new QVBoxLayout();
        layout_lista->setSpacing(0);
        layout_lista->setObjectName(QStringLiteral("layout_lista"));
        lista_medios_facebook = new QListWidget(horizontalLayoutWidget);
        lista_medios_facebook->setObjectName(QStringLiteral("lista_medios_facebook"));
        QFont font4;
        font4.setFamily(QStringLiteral("Calibri"));
        font4.setPointSize(10);
        lista_medios_facebook->setFont(font4);

        layout_lista->addWidget(lista_medios_facebook);


        layout_general->addLayout(layout_lista);

        btnbox_medios_facebook = new QDialogButtonBox(DialogoMediosFacebook);
        btnbox_medios_facebook->setObjectName(QStringLiteral("btnbox_medios_facebook"));
        btnbox_medios_facebook->setGeometry(QRect(320, 370, 156, 23));
        QFont font5;
        font5.setFamily(QStringLiteral("Calibri"));
        font5.setPointSize(11);
        font5.setItalic(true);
        btnbox_medios_facebook->setFont(font5);
        btnbox_medios_facebook->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        retranslateUi(DialogoMediosFacebook);
        QObject::connect(lista_medios_facebook, SIGNAL(itemSelectionChanged()), action_estado_btn_eliminar, SLOT(trigger()));
        QObject::connect(lineedit_nombre_pagina, SIGNAL(textEdited(QString)), action_estado_btn_agregar, SLOT(trigger()));
        QObject::connect(btnbox_medios_facebook, SIGNAL(accepted()), action_actualizar_y_cerrar, SLOT(trigger()));
        QObject::connect(btnbox_medios_facebook, SIGNAL(rejected()), DialogoMediosFacebook, SLOT(close()));
        QObject::connect(btn_agregar, SIGNAL(released()), action_guardar, SLOT(trigger()));
        QObject::connect(btn_eliminar, SIGNAL(released()), action_eliminar, SLOT(trigger()));
        QObject::connect(btn_limpiar, SIGNAL(released()), action_resetear, SLOT(trigger()));

        QMetaObject::connectSlotsByName(DialogoMediosFacebook);
    } // setupUi

    void retranslateUi(QWidget *DialogoMediosFacebook)
    {
        DialogoMediosFacebook->setWindowTitle(QApplication::translate("DialogoMediosFacebook", "P\303\241ginas de Facebook", Q_NULLPTR));
        action_actualizar_y_cerrar->setText(QApplication::translate("DialogoMediosFacebook", "Actualizar y cerrar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_actualizar_y_cerrar->setToolTip(QApplication::translate("DialogoMediosFacebook", "Actualizar y cerrar", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_resetear->setText(QApplication::translate("DialogoMediosFacebook", "Resetear", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_resetear->setToolTip(QApplication::translate("DialogoMediosFacebook", "Resetear", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_resetear->setShortcut(QApplication::translate("DialogoMediosFacebook", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_guardar->setText(QApplication::translate("DialogoMediosFacebook", "Guardar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_guardar->setToolTip(QApplication::translate("DialogoMediosFacebook", "Guardar", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_guardar->setShortcut(QApplication::translate("DialogoMediosFacebook", "Ctrl+G", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_eliminar->setText(QApplication::translate("DialogoMediosFacebook", "Eliminar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_eliminar->setToolTip(QApplication::translate("DialogoMediosFacebook", "Eliminar", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_eliminar->setShortcut(QApplication::translate("DialogoMediosFacebook", "Ctrl+D", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_estado_btn_eliminar->setText(QApplication::translate("DialogoMediosFacebook", "estado btn_eliminar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_estado_btn_eliminar->setToolTip(QApplication::translate("DialogoMediosFacebook", "estado btn eliminar", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_estado_btn_agregar->setText(QApplication::translate("DialogoMediosFacebook", "estado btn_agregar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_estado_btn_agregar->setToolTip(QApplication::translate("DialogoMediosFacebook", "estado btn_agregar", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lbl_etiqueta->setText(QApplication::translate("DialogoMediosFacebook", "Etiqueta", Q_NULLPTR));
        lbl_nombre_pagina->setText(QApplication::translate("DialogoMediosFacebook", "Nombre de p\303\241gina", Q_NULLPTR));
        btn_agregar->setText(QApplication::translate("DialogoMediosFacebook", "Agregar", Q_NULLPTR));
        btn_limpiar->setText(QApplication::translate("DialogoMediosFacebook", "Limpiar", Q_NULLPTR));
        btn_eliminar->setText(QApplication::translate("DialogoMediosFacebook", "Eliminar", Q_NULLPTR));
        lineedit_nombre_pagina->setText(QString());
        lineedit_nombre_pagina->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogoMediosFacebook: public Ui_DialogoMediosFacebook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOMEDIOSFACEBOOK_H
