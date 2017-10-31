/********************************************************************************
** Form generated from reading UI file 'DialogoConceptos.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOCONCEPTOS_H
#define UI_DIALOGOCONCEPTOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoConceptos
{
public:
    QAction *action_actualizar_y_cerrar;
    QAction *action_resetear_concepto;
    QAction *action_eliminar_concepto;
    QAction *action_guardar_concepto;
    QAction *action_estado_btn_eliminar;
    QDialogButtonBox *btnbox_conceptos;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *layout_general;
    QFormLayout *layout_opciones;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta;
    QGroupBox *groupbox_terminos;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *layout_terminos;
    QLineEdit *lineedit_terminos;
    QListWidget *lista_terminos;
    QPushButton *btn_guardar_concepto;
    QPushButton *btn_limpiar_concepto;
    QPushButton *btn_eliminar_concepto;
    QPushButton *btn_agregar_eliminar_terminos;
    QVBoxLayout *layout_lista;
    QListWidget *lista_conceptos;

    void setupUi(QWidget *DialogoConceptos)
    {
        if (DialogoConceptos->objectName().isEmpty())
            DialogoConceptos->setObjectName(QStringLiteral("DialogoConceptos"));
        DialogoConceptos->resize(577, 345);
        action_actualizar_y_cerrar = new QAction(DialogoConceptos);
        action_actualizar_y_cerrar->setObjectName(QStringLiteral("action_actualizar_y_cerrar"));
        action_resetear_concepto = new QAction(DialogoConceptos);
        action_resetear_concepto->setObjectName(QStringLiteral("action_resetear_concepto"));
        action_eliminar_concepto = new QAction(DialogoConceptos);
        action_eliminar_concepto->setObjectName(QStringLiteral("action_eliminar_concepto"));
        action_guardar_concepto = new QAction(DialogoConceptos);
        action_guardar_concepto->setObjectName(QStringLiteral("action_guardar_concepto"));
        action_estado_btn_eliminar = new QAction(DialogoConceptos);
        action_estado_btn_eliminar->setObjectName(QStringLiteral("action_estado_btn_eliminar"));
        btnbox_conceptos = new QDialogButtonBox(DialogoConceptos);
        btnbox_conceptos->setObjectName(QStringLiteral("btnbox_conceptos"));
        btnbox_conceptos->setGeometry(QRect(210, 310, 156, 23));
        btnbox_conceptos->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(DialogoConceptos);
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

        groupbox_terminos = new QGroupBox(horizontalLayoutWidget);
        groupbox_terminos->setObjectName(QStringLiteral("groupbox_terminos"));
        groupbox_terminos->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupbox_terminos->sizePolicy().hasHeightForWidth());
        groupbox_terminos->setSizePolicy(sizePolicy);
        groupbox_terminos->setMinimumSize(QSize(0, 144));
        verticalLayoutWidget_2 = new QWidget(groupbox_terminos);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 251, 111));
        layout_terminos = new QVBoxLayout(verticalLayoutWidget_2);
        layout_terminos->setSpacing(6);
        layout_terminos->setContentsMargins(11, 11, 11, 11);
        layout_terminos->setObjectName(QStringLiteral("layout_terminos"));
        layout_terminos->setContentsMargins(0, 0, 0, 0);
        lineedit_terminos = new QLineEdit(verticalLayoutWidget_2);
        lineedit_terminos->setObjectName(QStringLiteral("lineedit_terminos"));

        layout_terminos->addWidget(lineedit_terminos);

        lista_terminos = new QListWidget(verticalLayoutWidget_2);
        lista_terminos->setObjectName(QStringLiteral("lista_terminos"));

        layout_terminos->addWidget(lista_terminos);


        layout_opciones->setWidget(1, QFormLayout::SpanningRole, groupbox_terminos);

        btn_guardar_concepto = new QPushButton(horizontalLayoutWidget);
        btn_guardar_concepto->setObjectName(QStringLiteral("btn_guardar_concepto"));

        layout_opciones->setWidget(2, QFormLayout::FieldRole, btn_guardar_concepto);

        btn_limpiar_concepto = new QPushButton(horizontalLayoutWidget);
        btn_limpiar_concepto->setObjectName(QStringLiteral("btn_limpiar_concepto"));

        layout_opciones->setWidget(3, QFormLayout::FieldRole, btn_limpiar_concepto);

        btn_eliminar_concepto = new QPushButton(horizontalLayoutWidget);
        btn_eliminar_concepto->setObjectName(QStringLiteral("btn_eliminar_concepto"));

        layout_opciones->setWidget(4, QFormLayout::FieldRole, btn_eliminar_concepto);

        btn_agregar_eliminar_terminos = new QPushButton(horizontalLayoutWidget);
        btn_agregar_eliminar_terminos->setObjectName(QStringLiteral("btn_agregar_eliminar_terminos"));

        layout_opciones->setWidget(5, QFormLayout::FieldRole, btn_agregar_eliminar_terminos);


        layout_general->addLayout(layout_opciones);

        layout_lista = new QVBoxLayout();
        layout_lista->setSpacing(6);
        layout_lista->setObjectName(QStringLiteral("layout_lista"));
        lista_conceptos = new QListWidget(horizontalLayoutWidget);
        lista_conceptos->setObjectName(QStringLiteral("lista_conceptos"));

        layout_lista->addWidget(lista_conceptos);


        layout_general->addLayout(layout_lista);


        retranslateUi(DialogoConceptos);
        QObject::connect(btnbox_conceptos, SIGNAL(accepted()), action_actualizar_y_cerrar, SLOT(trigger()));
        QObject::connect(btnbox_conceptos, SIGNAL(rejected()), DialogoConceptos, SLOT(close()));
        QObject::connect(btn_guardar_concepto, SIGNAL(released()), action_guardar_concepto, SLOT(trigger()));
        QObject::connect(btn_limpiar_concepto, SIGNAL(released()), action_resetear_concepto, SLOT(trigger()));
        QObject::connect(btn_eliminar_concepto, SIGNAL(released()), action_eliminar_concepto, SLOT(trigger()));
        QObject::connect(lista_conceptos, SIGNAL(itemSelectionChanged()), action_estado_btn_eliminar, SLOT(trigger()));

        QMetaObject::connectSlotsByName(DialogoConceptos);
    } // setupUi

    void retranslateUi(QWidget *DialogoConceptos)
    {
        DialogoConceptos->setWindowTitle(QApplication::translate("DialogoConceptos", "DialogoConceptos", Q_NULLPTR));
        action_actualizar_y_cerrar->setText(QApplication::translate("DialogoConceptos", "actualizar_y_cerrar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_actualizar_y_cerrar->setToolTip(QApplication::translate("DialogoConceptos", "actualizar y cerrar", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_resetear_concepto->setText(QApplication::translate("DialogoConceptos", "resetear_concepto", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_resetear_concepto->setToolTip(QApplication::translate("DialogoConceptos", "resetear concepto", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_eliminar_concepto->setText(QApplication::translate("DialogoConceptos", "eliminar_concepto", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_eliminar_concepto->setToolTip(QApplication::translate("DialogoConceptos", "eliminar concepto", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_guardar_concepto->setText(QApplication::translate("DialogoConceptos", "guardar_concepto", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_guardar_concepto->setToolTip(QApplication::translate("DialogoConceptos", "guardar concepto", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_estado_btn_eliminar->setText(QApplication::translate("DialogoConceptos", "estado_btn_eliminar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_estado_btn_eliminar->setToolTip(QApplication::translate("DialogoConceptos", "estado btn eliminar", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lbl_etiqueta->setText(QApplication::translate("DialogoConceptos", "etiqueta", Q_NULLPTR));
        groupbox_terminos->setTitle(QApplication::translate("DialogoConceptos", "terminos", Q_NULLPTR));
        btn_guardar_concepto->setText(QApplication::translate("DialogoConceptos", "guardar", Q_NULLPTR));
        btn_limpiar_concepto->setText(QApplication::translate("DialogoConceptos", "limpiar", Q_NULLPTR));
        btn_eliminar_concepto->setText(QApplication::translate("DialogoConceptos", "eliminar", Q_NULLPTR));
        btn_agregar_eliminar_terminos->setText(QApplication::translate("DialogoConceptos", "agregar/eliminar terminos", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoConceptos: public Ui_DialogoConceptos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOCONCEPTOS_H
