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
    QAction *action_estado_btn_agregar;
    QDialogButtonBox *btnbox_conceptos;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *layout_general;
    QFormLayout *layout_opciones;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta;
    QPushButton *btn_limpiar_concepto;
    QPushButton *btn_eliminar_concepto;
    QPushButton *btn_agregar_eliminar_terminos;
    QPushButton *btn_agregar_concepto;
    QGroupBox *groupbox_terminos;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *layout_terminos;
    QListWidget *lista_terminos;
    QVBoxLayout *layout_lista;
    QListWidget *lista_conceptos;

    void setupUi(QWidget *DialogoConceptos)
    {
        if (DialogoConceptos->objectName().isEmpty())
            DialogoConceptos->setObjectName(QStringLiteral("DialogoConceptos"));
        DialogoConceptos->resize(800, 400);
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
        action_estado_btn_agregar = new QAction(DialogoConceptos);
        action_estado_btn_agregar->setObjectName(QStringLiteral("action_estado_btn_agregar"));
        btnbox_conceptos = new QDialogButtonBox(DialogoConceptos);
        btnbox_conceptos->setObjectName(QStringLiteral("btnbox_conceptos"));
        btnbox_conceptos->setGeometry(QRect(325, 370, 156, 23));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnbox_conceptos->sizePolicy().hasHeightForWidth());
        btnbox_conceptos->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(11);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        btnbox_conceptos->setFont(font);
        btnbox_conceptos->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(DialogoConceptos);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 781, 357));
        layout_general = new QHBoxLayout(horizontalLayoutWidget);
        layout_general->setSpacing(6);
        layout_general->setContentsMargins(11, 11, 11, 11);
        layout_general->setObjectName(QStringLiteral("layout_general"));
        layout_general->setSizeConstraint(QLayout::SetNoConstraint);
        layout_general->setContentsMargins(0, 0, 0, 0);
        layout_opciones = new QFormLayout();
        layout_opciones->setSpacing(6);
        layout_opciones->setObjectName(QStringLiteral("layout_opciones"));
        lbl_etiqueta = new QLabel(horizontalLayoutWidget);
        lbl_etiqueta->setObjectName(QStringLiteral("lbl_etiqueta"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(12);
        lbl_etiqueta->setFont(font1);

        layout_opciones->setWidget(0, QFormLayout::LabelRole, lbl_etiqueta);

        lineedit_etiqueta = new QLineEdit(horizontalLayoutWidget);
        lineedit_etiqueta->setObjectName(QStringLiteral("lineedit_etiqueta"));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(10);
        font2.setItalic(true);
        lineedit_etiqueta->setFont(font2);

        layout_opciones->setWidget(0, QFormLayout::FieldRole, lineedit_etiqueta);

        btn_limpiar_concepto = new QPushButton(horizontalLayoutWidget);
        btn_limpiar_concepto->setObjectName(QStringLiteral("btn_limpiar_concepto"));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        font3.setPointSize(11);
        btn_limpiar_concepto->setFont(font3);

        layout_opciones->setWidget(3, QFormLayout::FieldRole, btn_limpiar_concepto);

        btn_eliminar_concepto = new QPushButton(horizontalLayoutWidget);
        btn_eliminar_concepto->setObjectName(QStringLiteral("btn_eliminar_concepto"));
        btn_eliminar_concepto->setFont(font3);

        layout_opciones->setWidget(4, QFormLayout::FieldRole, btn_eliminar_concepto);

        btn_agregar_eliminar_terminos = new QPushButton(horizontalLayoutWidget);
        btn_agregar_eliminar_terminos->setObjectName(QStringLiteral("btn_agregar_eliminar_terminos"));
        btn_agregar_eliminar_terminos->setEnabled(false);
        QFont font4;
        font4.setFamily(QStringLiteral("Calibri"));
        font4.setPointSize(11);
        font4.setItalic(true);
        btn_agregar_eliminar_terminos->setFont(font4);

        layout_opciones->setWidget(5, QFormLayout::FieldRole, btn_agregar_eliminar_terminos);

        btn_agregar_concepto = new QPushButton(horizontalLayoutWidget);
        btn_agregar_concepto->setObjectName(QStringLiteral("btn_agregar_concepto"));
        btn_agregar_concepto->setFont(font3);

        layout_opciones->setWidget(2, QFormLayout::FieldRole, btn_agregar_concepto);

        groupbox_terminos = new QGroupBox(horizontalLayoutWidget);
        groupbox_terminos->setObjectName(QStringLiteral("groupbox_terminos"));
        groupbox_terminos->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupbox_terminos->sizePolicy().hasHeightForWidth());
        groupbox_terminos->setSizePolicy(sizePolicy1);
        groupbox_terminos->setMinimumSize(QSize(0, 190));
        groupbox_terminos->setFont(font1);
        groupbox_terminos->setAcceptDrops(false);
        groupbox_terminos->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        verticalLayoutWidget_2 = new QWidget(groupbox_terminos);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 20, 371, 161));
        layout_terminos = new QVBoxLayout(verticalLayoutWidget_2);
        layout_terminos->setSpacing(6);
        layout_terminos->setContentsMargins(11, 11, 11, 11);
        layout_terminos->setObjectName(QStringLiteral("layout_terminos"));
        layout_terminos->setSizeConstraint(QLayout::SetDefaultConstraint);
        layout_terminos->setContentsMargins(0, 0, 0, 0);
        lista_terminos = new QListWidget(verticalLayoutWidget_2);
        lista_terminos->setObjectName(QStringLiteral("lista_terminos"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lista_terminos->sizePolicy().hasHeightForWidth());
        lista_terminos->setSizePolicy(sizePolicy2);
        lista_terminos->setMinimumSize(QSize(0, 0));
        lista_terminos->setMaximumSize(QSize(16777215, 150));
        QFont font5;
        font5.setPointSize(10);
        font5.setItalic(false);
        lista_terminos->setFont(font5);

        layout_terminos->addWidget(lista_terminos);


        layout_opciones->setWidget(1, QFormLayout::SpanningRole, groupbox_terminos);


        layout_general->addLayout(layout_opciones);

        layout_lista = new QVBoxLayout();
        layout_lista->setSpacing(6);
        layout_lista->setObjectName(QStringLiteral("layout_lista"));
        lista_conceptos = new QListWidget(horizontalLayoutWidget);
        lista_conceptos->setObjectName(QStringLiteral("lista_conceptos"));
        QFont font6;
        font6.setFamily(QStringLiteral("Calibri"));
        font6.setPointSize(10);
        lista_conceptos->setFont(font6);

        layout_lista->addWidget(lista_conceptos);


        layout_general->addLayout(layout_lista);

        btnbox_conceptos->raise();
        horizontalLayoutWidget->raise();
        lista_terminos->raise();

        retranslateUi(DialogoConceptos);
        QObject::connect(btnbox_conceptos, SIGNAL(accepted()), action_actualizar_y_cerrar, SLOT(trigger()));
        QObject::connect(btnbox_conceptos, SIGNAL(rejected()), DialogoConceptos, SLOT(close()));
        QObject::connect(btn_agregar_concepto, SIGNAL(released()), action_guardar_concepto, SLOT(trigger()));
        QObject::connect(btn_limpiar_concepto, SIGNAL(released()), action_resetear_concepto, SLOT(trigger()));
        QObject::connect(btn_eliminar_concepto, SIGNAL(released()), action_eliminar_concepto, SLOT(trigger()));
        QObject::connect(lista_conceptos, SIGNAL(itemSelectionChanged()), action_estado_btn_eliminar, SLOT(trigger()));
        QObject::connect(lista_terminos, SIGNAL(itemSelectionChanged()), action_estado_btn_agregar, SLOT(trigger()));

        QMetaObject::connectSlotsByName(DialogoConceptos);
    } // setupUi

    void retranslateUi(QWidget *DialogoConceptos)
    {
        DialogoConceptos->setWindowTitle(QApplication::translate("DialogoConceptos", "Conceptos", Q_NULLPTR));
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
        action_estado_btn_agregar->setText(QApplication::translate("DialogoConceptos", "estado_btn_agregar", Q_NULLPTR));
        lbl_etiqueta->setText(QApplication::translate("DialogoConceptos", "Etiqueta", Q_NULLPTR));
        lineedit_etiqueta->setText(QString());
        btn_limpiar_concepto->setText(QApplication::translate("DialogoConceptos", "Limpiar", Q_NULLPTR));
        btn_eliminar_concepto->setText(QApplication::translate("DialogoConceptos", "Eliminar", Q_NULLPTR));
        btn_agregar_eliminar_terminos->setText(QApplication::translate("DialogoConceptos", "Sumar/Sacar t\303\251rminos", Q_NULLPTR));
        btn_agregar_concepto->setText(QApplication::translate("DialogoConceptos", "Agregar", Q_NULLPTR));
        groupbox_terminos->setTitle(QApplication::translate("DialogoConceptos", "T\303\251rminos", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoConceptos: public Ui_DialogoConceptos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOCONCEPTOS_H
