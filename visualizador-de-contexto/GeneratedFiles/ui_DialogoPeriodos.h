/********************************************************************************
** Form generated from reading UI file 'DialogoPeriodos.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOPERIODOS_H
#define UI_DIALOGOPERIODOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
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

class Ui_DialogoPeriodos
{
public:
    QAction *action_guardar_periodo;
    QAction *action_limpiar_periodo;
    QAction *action_eliminar_periodo;
    QAction *action_actualizar_y_cerrar;
    QAction *action_estado_btn_eliminar;
    QDialogButtonBox *btnbox_periodos;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QFormLayout *layout_opciones;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta;
    QLabel *lbl_desde;
    QComboBox *combobox_desde;
    QLabel *lbl_hasta;
    QComboBox *combobox_hasta;
    QPushButton *btn_guardar_periodo;
    QPushButton *btn_limpiar_periodo;
    QPushButton *btn_eliminar_periodo;
    QVBoxLayout *layout_lista;
    QListWidget *lista_periodos;

    void setupUi(QWidget *DialogoPeriodos)
    {
        if (DialogoPeriodos->objectName().isEmpty())
            DialogoPeriodos->setObjectName(QStringLiteral("DialogoPeriodos"));
        DialogoPeriodos->resize(577, 345);
        action_guardar_periodo = new QAction(DialogoPeriodos);
        action_guardar_periodo->setObjectName(QStringLiteral("action_guardar_periodo"));
        action_limpiar_periodo = new QAction(DialogoPeriodos);
        action_limpiar_periodo->setObjectName(QStringLiteral("action_limpiar_periodo"));
        action_eliminar_periodo = new QAction(DialogoPeriodos);
        action_eliminar_periodo->setObjectName(QStringLiteral("action_eliminar_periodo"));
        action_actualizar_y_cerrar = new QAction(DialogoPeriodos);
        action_actualizar_y_cerrar->setObjectName(QStringLiteral("action_actualizar_y_cerrar"));
        action_estado_btn_eliminar = new QAction(DialogoPeriodos);
        action_estado_btn_eliminar->setObjectName(QStringLiteral("action_estado_btn_eliminar"));
        btnbox_periodos = new QDialogButtonBox(DialogoPeriodos);
        btnbox_periodos->setObjectName(QStringLiteral("btnbox_periodos"));
        btnbox_periodos->setGeometry(QRect(210, 310, 156, 23));
        btnbox_periodos->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(DialogoPeriodos);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 551, 291));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        layout_opciones = new QFormLayout();
        layout_opciones->setSpacing(6);
        layout_opciones->setObjectName(QStringLiteral("layout_opciones"));
        lbl_etiqueta = new QLabel(horizontalLayoutWidget);
        lbl_etiqueta->setObjectName(QStringLiteral("lbl_etiqueta"));

        layout_opciones->setWidget(0, QFormLayout::LabelRole, lbl_etiqueta);

        lineedit_etiqueta = new QLineEdit(horizontalLayoutWidget);
        lineedit_etiqueta->setObjectName(QStringLiteral("lineedit_etiqueta"));

        layout_opciones->setWidget(0, QFormLayout::FieldRole, lineedit_etiqueta);

        lbl_desde = new QLabel(horizontalLayoutWidget);
        lbl_desde->setObjectName(QStringLiteral("lbl_desde"));

        layout_opciones->setWidget(1, QFormLayout::LabelRole, lbl_desde);

        combobox_desde = new QComboBox(horizontalLayoutWidget);
        combobox_desde->setObjectName(QStringLiteral("combobox_desde"));

        layout_opciones->setWidget(1, QFormLayout::FieldRole, combobox_desde);

        lbl_hasta = new QLabel(horizontalLayoutWidget);
        lbl_hasta->setObjectName(QStringLiteral("lbl_hasta"));

        layout_opciones->setWidget(2, QFormLayout::LabelRole, lbl_hasta);

        combobox_hasta = new QComboBox(horizontalLayoutWidget);
        combobox_hasta->setObjectName(QStringLiteral("combobox_hasta"));

        layout_opciones->setWidget(2, QFormLayout::FieldRole, combobox_hasta);

        btn_guardar_periodo = new QPushButton(horizontalLayoutWidget);
        btn_guardar_periodo->setObjectName(QStringLiteral("btn_guardar_periodo"));

        layout_opciones->setWidget(3, QFormLayout::FieldRole, btn_guardar_periodo);

        btn_limpiar_periodo = new QPushButton(horizontalLayoutWidget);
        btn_limpiar_periodo->setObjectName(QStringLiteral("btn_limpiar_periodo"));

        layout_opciones->setWidget(4, QFormLayout::FieldRole, btn_limpiar_periodo);

        btn_eliminar_periodo = new QPushButton(horizontalLayoutWidget);
        btn_eliminar_periodo->setObjectName(QStringLiteral("btn_eliminar_periodo"));

        layout_opciones->setWidget(5, QFormLayout::FieldRole, btn_eliminar_periodo);


        horizontalLayout->addLayout(layout_opciones);

        layout_lista = new QVBoxLayout();
        layout_lista->setSpacing(6);
        layout_lista->setObjectName(QStringLiteral("layout_lista"));
        lista_periodos = new QListWidget(horizontalLayoutWidget);
        lista_periodos->setObjectName(QStringLiteral("lista_periodos"));

        layout_lista->addWidget(lista_periodos);


        horizontalLayout->addLayout(layout_lista);


        retranslateUi(DialogoPeriodos);
        QObject::connect(btnbox_periodos, SIGNAL(accepted()), action_actualizar_y_cerrar, SLOT(trigger()));
        QObject::connect(btnbox_periodos, SIGNAL(rejected()), DialogoPeriodos, SLOT(close()));
        QObject::connect(btn_guardar_periodo, SIGNAL(released()), action_guardar_periodo, SLOT(trigger()));
        QObject::connect(btn_eliminar_periodo, SIGNAL(released()), action_eliminar_periodo, SLOT(trigger()));
        QObject::connect(btn_limpiar_periodo, SIGNAL(released()), action_limpiar_periodo, SLOT(trigger()));
        QObject::connect(lista_periodos, SIGNAL(itemSelectionChanged()), action_estado_btn_eliminar, SLOT(trigger()));

        QMetaObject::connectSlotsByName(DialogoPeriodos);
    } // setupUi

    void retranslateUi(QWidget *DialogoPeriodos)
    {
        DialogoPeriodos->setWindowTitle(QApplication::translate("DialogoPeriodos", "DialogoPeriodos", Q_NULLPTR));
        action_guardar_periodo->setText(QApplication::translate("DialogoPeriodos", "guardar_periodo", Q_NULLPTR));
        action_limpiar_periodo->setText(QApplication::translate("DialogoPeriodos", "limpiar_periodo", Q_NULLPTR));
        action_eliminar_periodo->setText(QApplication::translate("DialogoPeriodos", "eliminar_periodo", Q_NULLPTR));
        action_actualizar_y_cerrar->setText(QApplication::translate("DialogoPeriodos", "actualizar_y_cerrar", Q_NULLPTR));
        action_estado_btn_eliminar->setText(QApplication::translate("DialogoPeriodos", "estado_btn_eliminar", Q_NULLPTR));
        lbl_etiqueta->setText(QApplication::translate("DialogoPeriodos", "etiqueta", Q_NULLPTR));
        lbl_desde->setText(QApplication::translate("DialogoPeriodos", "desde", Q_NULLPTR));
        lbl_hasta->setText(QApplication::translate("DialogoPeriodos", "hasta", Q_NULLPTR));
        btn_guardar_periodo->setText(QApplication::translate("DialogoPeriodos", "guardar", Q_NULLPTR));
        btn_limpiar_periodo->setText(QApplication::translate("DialogoPeriodos", "limpiar", Q_NULLPTR));
        btn_eliminar_periodo->setText(QApplication::translate("DialogoPeriodos", "eliminar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoPeriodos: public Ui_DialogoPeriodos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOPERIODOS_H
