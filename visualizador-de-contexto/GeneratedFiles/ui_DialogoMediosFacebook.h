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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QAction *action_nueva_pagina;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *layout_general;
    QVBoxLayout *layout_lista;
    QHBoxLayout *layout_superior;
    QLabel *label;
    QPushButton *btn_eliminar;
    QPushButton *btn_nueva;
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
        action_nueva_pagina = new QAction(DialogoMediosFacebook);
        action_nueva_pagina->setObjectName(QStringLiteral("action_nueva_pagina"));
        verticalLayout = new QVBoxLayout(DialogoMediosFacebook);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        layout_general = new QHBoxLayout();
        layout_general->setSpacing(0);
        layout_general->setObjectName(QStringLiteral("layout_general"));
        layout_lista = new QVBoxLayout();
        layout_lista->setSpacing(0);
        layout_lista->setObjectName(QStringLiteral("layout_lista"));
        layout_superior = new QHBoxLayout();
        layout_superior->setSpacing(6);
        layout_superior->setObjectName(QStringLiteral("layout_superior"));
        label = new QLabel(DialogoMediosFacebook);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        layout_superior->addWidget(label);

        btn_eliminar = new QPushButton(DialogoMediosFacebook);
        btn_eliminar->setObjectName(QStringLiteral("btn_eliminar"));
        btn_eliminar->setMinimumSize(QSize(0, 30));
        btn_eliminar->setMaximumSize(QSize(80, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(11);
        btn_eliminar->setFont(font1);

        layout_superior->addWidget(btn_eliminar);

        btn_nueva = new QPushButton(DialogoMediosFacebook);
        btn_nueva->setObjectName(QStringLiteral("btn_nueva"));
        btn_nueva->setMinimumSize(QSize(0, 30));
        btn_nueva->setMaximumSize(QSize(80, 16777215));
        btn_nueva->setFont(font1);

        layout_superior->addWidget(btn_nueva);


        layout_lista->addLayout(layout_superior);

        lista_medios_facebook = new QListWidget(DialogoMediosFacebook);
        lista_medios_facebook->setObjectName(QStringLiteral("lista_medios_facebook"));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(10);
        lista_medios_facebook->setFont(font2);

        layout_lista->addWidget(lista_medios_facebook);


        layout_general->addLayout(layout_lista);


        verticalLayout->addLayout(layout_general);

        btnbox_medios_facebook = new QDialogButtonBox(DialogoMediosFacebook);
        btnbox_medios_facebook->setObjectName(QStringLiteral("btnbox_medios_facebook"));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        font3.setPointSize(11);
        font3.setItalic(false);
        btnbox_medios_facebook->setFont(font3);
        btnbox_medios_facebook->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        btnbox_medios_facebook->setCenterButtons(true);

        verticalLayout->addWidget(btnbox_medios_facebook);


        retranslateUi(DialogoMediosFacebook);
        QObject::connect(lista_medios_facebook, SIGNAL(itemSelectionChanged()), action_estado_btn_eliminar, SLOT(trigger()));
        QObject::connect(btnbox_medios_facebook, SIGNAL(accepted()), action_actualizar_y_cerrar, SLOT(trigger()));
        QObject::connect(btnbox_medios_facebook, SIGNAL(rejected()), DialogoMediosFacebook, SLOT(close()));
        QObject::connect(btn_nueva, SIGNAL(released()), action_nueva_pagina, SLOT(trigger()));
        QObject::connect(btn_eliminar, SIGNAL(released()), action_eliminar, SLOT(trigger()));

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
        action_nueva_pagina->setText(QApplication::translate("DialogoMediosFacebook", "Nueva pagina", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_nueva_pagina->setToolTip(QApplication::translate("DialogoMediosFacebook", "Nueva pagina", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("DialogoMediosFacebook", "Lista de p\303\241ginas de Facebook", Q_NULLPTR));
        btn_eliminar->setText(QApplication::translate("DialogoMediosFacebook", "Eliminar", Q_NULLPTR));
        btn_nueva->setText(QApplication::translate("DialogoMediosFacebook", "Nueva", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoMediosFacebook: public Ui_DialogoMediosFacebook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOMEDIOSFACEBOOK_H
