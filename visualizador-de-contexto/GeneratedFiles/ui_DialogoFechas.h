/********************************************************************************
** Form generated from reading UI file 'DialogoFechas.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOFECHAS_H
#define UI_DIALOGOFECHAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
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

class Ui_DialogoFechas
{
public:
    QAction *action_guardar_fecha;
    QAction *action_limpiar_fecha;
    QAction *action_eliminar_fecha;
    QAction *action_actualizar_y_cerrar;
    QAction *action_estado_btn_eliminar;
    QDialogButtonBox *btnbox_fechas;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *layout_general;
    QFormLayout *layout_opciones;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta;
    QLabel *lbl_fecha;
    QDateEdit *dateedit_fecha;
    QPushButton *btn_guardar_fecha;
    QPushButton *btn_limpiar_fecha;
    QPushButton *btn_eliminar_fecha;
    QVBoxLayout *layout_lista;
    QListWidget *lista_fechas;

    void setupUi(QWidget *DialogoFechas)
    {
        if (DialogoFechas->objectName().isEmpty())
            DialogoFechas->setObjectName(QStringLiteral("DialogoFechas"));
        DialogoFechas->resize(577, 345);
        action_guardar_fecha = new QAction(DialogoFechas);
        action_guardar_fecha->setObjectName(QStringLiteral("action_guardar_fecha"));
        action_guardar_fecha->setCheckable(true);
        action_limpiar_fecha = new QAction(DialogoFechas);
        action_limpiar_fecha->setObjectName(QStringLiteral("action_limpiar_fecha"));
        action_eliminar_fecha = new QAction(DialogoFechas);
        action_eliminar_fecha->setObjectName(QStringLiteral("action_eliminar_fecha"));
        action_actualizar_y_cerrar = new QAction(DialogoFechas);
        action_actualizar_y_cerrar->setObjectName(QStringLiteral("action_actualizar_y_cerrar"));
        action_estado_btn_eliminar = new QAction(DialogoFechas);
        action_estado_btn_eliminar->setObjectName(QStringLiteral("action_estado_btn_eliminar"));
        btnbox_fechas = new QDialogButtonBox(DialogoFechas);
        btnbox_fechas->setObjectName(QStringLiteral("btnbox_fechas"));
        btnbox_fechas->setGeometry(QRect(210, 310, 156, 23));
        btnbox_fechas->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(DialogoFechas);
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

        lbl_fecha = new QLabel(horizontalLayoutWidget);
        lbl_fecha->setObjectName(QStringLiteral("lbl_fecha"));

        layout_opciones->setWidget(1, QFormLayout::LabelRole, lbl_fecha);

        dateedit_fecha = new QDateEdit(horizontalLayoutWidget);
        dateedit_fecha->setObjectName(QStringLiteral("dateedit_fecha"));
        dateedit_fecha->setWrapping(false);
        dateedit_fecha->setFrame(true);
        dateedit_fecha->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateedit_fecha->setProperty("showGroupSeparator", QVariant(false));
        dateedit_fecha->setCurrentSection(QDateTimeEdit::DaySection);
        dateedit_fecha->setCalendarPopup(true);

        layout_opciones->setWidget(1, QFormLayout::FieldRole, dateedit_fecha);

        btn_guardar_fecha = new QPushButton(horizontalLayoutWidget);
        btn_guardar_fecha->setObjectName(QStringLiteral("btn_guardar_fecha"));

        layout_opciones->setWidget(2, QFormLayout::FieldRole, btn_guardar_fecha);

        btn_limpiar_fecha = new QPushButton(horizontalLayoutWidget);
        btn_limpiar_fecha->setObjectName(QStringLiteral("btn_limpiar_fecha"));

        layout_opciones->setWidget(3, QFormLayout::FieldRole, btn_limpiar_fecha);

        btn_eliminar_fecha = new QPushButton(horizontalLayoutWidget);
        btn_eliminar_fecha->setObjectName(QStringLiteral("btn_eliminar_fecha"));

        layout_opciones->setWidget(4, QFormLayout::FieldRole, btn_eliminar_fecha);


        layout_general->addLayout(layout_opciones);

        layout_lista = new QVBoxLayout();
        layout_lista->setSpacing(6);
        layout_lista->setObjectName(QStringLiteral("layout_lista"));
        lista_fechas = new QListWidget(horizontalLayoutWidget);
        lista_fechas->setObjectName(QStringLiteral("lista_fechas"));

        layout_lista->addWidget(lista_fechas);


        layout_general->addLayout(layout_lista);


        retranslateUi(DialogoFechas);
        QObject::connect(lista_fechas, SIGNAL(itemSelectionChanged()), action_estado_btn_eliminar, SLOT(trigger()));
        QObject::connect(btnbox_fechas, SIGNAL(accepted()), action_actualizar_y_cerrar, SLOT(trigger()));
        QObject::connect(btnbox_fechas, SIGNAL(rejected()), DialogoFechas, SLOT(close()));
        QObject::connect(btn_guardar_fecha, SIGNAL(released()), action_guardar_fecha, SLOT(trigger()));
        QObject::connect(btn_eliminar_fecha, SIGNAL(released()), action_eliminar_fecha, SLOT(trigger()));
        QObject::connect(btn_limpiar_fecha, SIGNAL(released()), action_limpiar_fecha, SLOT(trigger()));

        QMetaObject::connectSlotsByName(DialogoFechas);
    } // setupUi

    void retranslateUi(QWidget *DialogoFechas)
    {
        DialogoFechas->setWindowTitle(QApplication::translate("DialogoFechas", "DialogoFechas", Q_NULLPTR));
        action_guardar_fecha->setText(QApplication::translate("DialogoFechas", "guardar_fecha", Q_NULLPTR));
        action_limpiar_fecha->setText(QApplication::translate("DialogoFechas", "limpiar_fecha", Q_NULLPTR));
        action_eliminar_fecha->setText(QApplication::translate("DialogoFechas", "eliminar_fecha", Q_NULLPTR));
        action_actualizar_y_cerrar->setText(QApplication::translate("DialogoFechas", "actualizar_y_cerrar", Q_NULLPTR));
        action_estado_btn_eliminar->setText(QApplication::translate("DialogoFechas", "estado_btn_eliminar", Q_NULLPTR));
        lbl_etiqueta->setText(QApplication::translate("DialogoFechas", "etiqueta", Q_NULLPTR));
        lbl_fecha->setText(QApplication::translate("DialogoFechas", "fecha", Q_NULLPTR));
        dateedit_fecha->setDisplayFormat(QApplication::translate("DialogoFechas", "d/M/yyyy", Q_NULLPTR));
        btn_guardar_fecha->setText(QApplication::translate("DialogoFechas", "guardar", Q_NULLPTR));
        btn_limpiar_fecha->setText(QApplication::translate("DialogoFechas", "limpiar", Q_NULLPTR));
        btn_eliminar_fecha->setText(QApplication::translate("DialogoFechas", "eliminar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoFechas: public Ui_DialogoFechas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOFECHAS_H
