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
#include <QtWidgets/QFrame>
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
    QWidget *widget_general;
    QHBoxLayout *layout_general;
    QWidget *widget_lista;
    QVBoxLayout *layout_lista;
    QWidget *widget_superior;
    QHBoxLayout *layout_superior;
    QLabel *label;
    QPushButton *btn_eliminar;
    QPushButton *btn_nueva;
    QWidget *widget_opciones;
    QHBoxLayout *layout_opciones;
    QFrame *line;
    QPushButton *btn_guardar;
    QPushButton *btn_cancelar;
    QListWidget *lista_medios_facebook;

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
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_general = new QWidget(DialogoMediosFacebook);
        widget_general->setObjectName(QStringLiteral("widget_general"));
        layout_general = new QHBoxLayout(widget_general);
        layout_general->setSpacing(0);
        layout_general->setContentsMargins(11, 11, 11, 11);
        layout_general->setObjectName(QStringLiteral("layout_general"));
        layout_general->setContentsMargins(0, 0, 0, 0);
        widget_lista = new QWidget(widget_general);
        widget_lista->setObjectName(QStringLiteral("widget_lista"));
        layout_lista = new QVBoxLayout(widget_lista);
        layout_lista->setSpacing(2);
        layout_lista->setContentsMargins(11, 11, 11, 11);
        layout_lista->setObjectName(QStringLiteral("layout_lista"));
        layout_lista->setContentsMargins(0, 0, 0, 0);
        widget_superior = new QWidget(widget_lista);
        widget_superior->setObjectName(QStringLiteral("widget_superior"));
        layout_superior = new QHBoxLayout(widget_superior);
        layout_superior->setSpacing(3);
        layout_superior->setContentsMargins(11, 11, 11, 11);
        layout_superior->setObjectName(QStringLiteral("layout_superior"));
        layout_superior->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_superior);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        label->setFont(font);
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        layout_superior->addWidget(label);

        btn_eliminar = new QPushButton(widget_superior);
        btn_eliminar->setObjectName(QStringLiteral("btn_eliminar"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_eliminar->sizePolicy().hasHeightForWidth());
        btn_eliminar->setSizePolicy(sizePolicy);
        btn_eliminar->setMinimumSize(QSize(0, 0));
        btn_eliminar->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(10);
        btn_eliminar->setFont(font1);

        layout_superior->addWidget(btn_eliminar);

        btn_nueva = new QPushButton(widget_superior);
        btn_nueva->setObjectName(QStringLiteral("btn_nueva"));
        sizePolicy.setHeightForWidth(btn_nueva->sizePolicy().hasHeightForWidth());
        btn_nueva->setSizePolicy(sizePolicy);
        btn_nueva->setMinimumSize(QSize(0, 0));
        btn_nueva->setMaximumSize(QSize(16777215, 16777215));
        btn_nueva->setFont(font1);

        layout_superior->addWidget(btn_nueva);

        widget_opciones = new QWidget(widget_superior);
        widget_opciones->setObjectName(QStringLiteral("widget_opciones"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_opciones->sizePolicy().hasHeightForWidth());
        widget_opciones->setSizePolicy(sizePolicy1);
        layout_opciones = new QHBoxLayout(widget_opciones);
        layout_opciones->setSpacing(3);
        layout_opciones->setContentsMargins(11, 11, 11, 11);
        layout_opciones->setObjectName(QStringLiteral("layout_opciones"));
        layout_opciones->setContentsMargins(0, 0, 0, 0);
        line = new QFrame(widget_opciones);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        layout_opciones->addWidget(line);

        btn_guardar = new QPushButton(widget_opciones);
        btn_guardar->setObjectName(QStringLiteral("btn_guardar"));
        sizePolicy.setHeightForWidth(btn_guardar->sizePolicy().hasHeightForWidth());
        btn_guardar->setSizePolicy(sizePolicy);
        btn_guardar->setFont(font1);

        layout_opciones->addWidget(btn_guardar);

        btn_cancelar = new QPushButton(widget_opciones);
        btn_cancelar->setObjectName(QStringLiteral("btn_cancelar"));
        sizePolicy.setHeightForWidth(btn_cancelar->sizePolicy().hasHeightForWidth());
        btn_cancelar->setSizePolicy(sizePolicy);
        btn_cancelar->setFont(font1);

        layout_opciones->addWidget(btn_cancelar);


        layout_superior->addWidget(widget_opciones);


        layout_lista->addWidget(widget_superior, 0, Qt::AlignBottom);

        lista_medios_facebook = new QListWidget(widget_lista);
        lista_medios_facebook->setObjectName(QStringLiteral("lista_medios_facebook"));
        lista_medios_facebook->setFont(font1);

        layout_lista->addWidget(lista_medios_facebook);


        layout_general->addWidget(widget_lista);


        verticalLayout->addWidget(widget_general);


        retranslateUi(DialogoMediosFacebook);

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
        btn_guardar->setText(QApplication::translate("DialogoMediosFacebook", "Guardar", Q_NULLPTR));
        btn_cancelar->setText(QApplication::translate("DialogoMediosFacebook", "Cancelar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoMediosFacebook: public Ui_DialogoMediosFacebook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOMEDIOSFACEBOOK_H
