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
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QAction *action_estado_btn_agregar;
    QDialogButtonBox *btnbox_periodos;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *layout_lista;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPushButton *btn_eliminar_periodo;
    QPushButton *btn_agregar_periodo;
    QListWidget *lista_periodos;

    void setupUi(QWidget *DialogoPeriodos)
    {
        if (DialogoPeriodos->objectName().isEmpty())
            DialogoPeriodos->setObjectName(QStringLiteral("DialogoPeriodos"));
        DialogoPeriodos->resize(800, 400);
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
        action_estado_btn_agregar = new QAction(DialogoPeriodos);
        action_estado_btn_agregar->setObjectName(QStringLiteral("action_estado_btn_agregar"));
        btnbox_periodos = new QDialogButtonBox(DialogoPeriodos);
        btnbox_periodos->setObjectName(QStringLiteral("btnbox_periodos"));
        btnbox_periodos->setGeometry(QRect(325, 370, 156, 23));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(11);
        font.setItalic(false);
        btnbox_periodos->setFont(font);
        btnbox_periodos->setOrientation(Qt::Horizontal);
        btnbox_periodos->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        btnbox_periodos->setCenterButtons(false);
        horizontalLayoutWidget = new QWidget(DialogoPeriodos);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 781, 351));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        layout_lista = new QVBoxLayout();
        layout_lista->setSpacing(0);
        layout_lista->setObjectName(QStringLiteral("layout_lista"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(16);
        label->setFont(font1);
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_2->addWidget(label);

        btn_eliminar_periodo = new QPushButton(horizontalLayoutWidget);
        btn_eliminar_periodo->setObjectName(QStringLiteral("btn_eliminar_periodo"));
        btn_eliminar_periodo->setMinimumSize(QSize(0, 30));
        btn_eliminar_periodo->setMaximumSize(QSize(80, 16777215));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(11);
        btn_eliminar_periodo->setFont(font2);

        horizontalLayout_2->addWidget(btn_eliminar_periodo);

        btn_agregar_periodo = new QPushButton(horizontalLayoutWidget);
        btn_agregar_periodo->setObjectName(QStringLiteral("btn_agregar_periodo"));
        btn_agregar_periodo->setMinimumSize(QSize(0, 30));
        btn_agregar_periodo->setMaximumSize(QSize(80, 16777215));
        btn_agregar_periodo->setFont(font2);

        horizontalLayout_2->addWidget(btn_agregar_periodo);


        layout_lista->addLayout(horizontalLayout_2);

        lista_periodos = new QListWidget(horizontalLayoutWidget);
        lista_periodos->setObjectName(QStringLiteral("lista_periodos"));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        font3.setPointSize(10);
        lista_periodos->setFont(font3);

        layout_lista->addWidget(lista_periodos);


        horizontalLayout->addLayout(layout_lista);


        retranslateUi(DialogoPeriodos);
        QObject::connect(btnbox_periodos, SIGNAL(accepted()), action_actualizar_y_cerrar, SLOT(trigger()));
        QObject::connect(btnbox_periodos, SIGNAL(rejected()), DialogoPeriodos, SLOT(close()));
        QObject::connect(btn_agregar_periodo, SIGNAL(released()), action_guardar_periodo, SLOT(trigger()));
        QObject::connect(btn_eliminar_periodo, SIGNAL(released()), action_eliminar_periodo, SLOT(trigger()));
        QObject::connect(lista_periodos, SIGNAL(itemSelectionChanged()), action_estado_btn_eliminar, SLOT(trigger()));

        QMetaObject::connectSlotsByName(DialogoPeriodos);
    } // setupUi

    void retranslateUi(QWidget *DialogoPeriodos)
    {
        DialogoPeriodos->setWindowTitle(QApplication::translate("DialogoPeriodos", "Per\303\255odos", Q_NULLPTR));
        action_guardar_periodo->setText(QApplication::translate("DialogoPeriodos", "guardar_periodo", Q_NULLPTR));
        action_limpiar_periodo->setText(QApplication::translate("DialogoPeriodos", "limpiar_periodo", Q_NULLPTR));
        action_eliminar_periodo->setText(QApplication::translate("DialogoPeriodos", "eliminar_periodo", Q_NULLPTR));
        action_actualizar_y_cerrar->setText(QApplication::translate("DialogoPeriodos", "actualizar_y_cerrar", Q_NULLPTR));
        action_estado_btn_eliminar->setText(QApplication::translate("DialogoPeriodos", "estado_btn_eliminar", Q_NULLPTR));
        action_estado_btn_agregar->setText(QApplication::translate("DialogoPeriodos", "estado_btn_agregar", Q_NULLPTR));
        label->setText(QApplication::translate("DialogoPeriodos", "Lista de per\303\255odos", Q_NULLPTR));
        btn_eliminar_periodo->setText(QApplication::translate("DialogoPeriodos", "Eliminar", Q_NULLPTR));
        btn_agregar_periodo->setText(QApplication::translate("DialogoPeriodos", "Nuevo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoPeriodos: public Ui_DialogoPeriodos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOPERIODOS_H
