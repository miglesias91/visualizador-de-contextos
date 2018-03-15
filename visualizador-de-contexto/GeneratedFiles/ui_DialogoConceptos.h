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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QAction *action_nuevo_concepto;
    QAction *action_estado_btn_eliminar;
    QAction *action_estado_btn_agregar;
    QAction *action_editar_concepto;
    QDialogButtonBox *btnbox_conceptos;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *layout_general;
    QVBoxLayout *layout_lista;
    QHBoxLayout *layout_superior;
    QLabel *label;
    QPushButton *btn_eliminar_concepto;
    QPushButton *btn_agregar_concepto;
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
        action_nuevo_concepto = new QAction(DialogoConceptos);
        action_nuevo_concepto->setObjectName(QStringLiteral("action_nuevo_concepto"));
        action_estado_btn_eliminar = new QAction(DialogoConceptos);
        action_estado_btn_eliminar->setObjectName(QStringLiteral("action_estado_btn_eliminar"));
        action_estado_btn_agregar = new QAction(DialogoConceptos);
        action_estado_btn_agregar->setObjectName(QStringLiteral("action_estado_btn_agregar"));
        action_editar_concepto = new QAction(DialogoConceptos);
        action_editar_concepto->setObjectName(QStringLiteral("action_editar_concepto"));
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
        font.setItalic(false);
        font.setWeight(50);
        btnbox_conceptos->setFont(font);
        btnbox_conceptos->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        horizontalLayoutWidget = new QWidget(DialogoConceptos);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 781, 351));
        layout_general = new QHBoxLayout(horizontalLayoutWidget);
        layout_general->setSpacing(0);
        layout_general->setContentsMargins(11, 11, 11, 11);
        layout_general->setObjectName(QStringLiteral("layout_general"));
        layout_general->setSizeConstraint(QLayout::SetNoConstraint);
        layout_general->setContentsMargins(0, 0, 0, 0);
        layout_lista = new QVBoxLayout();
        layout_lista->setSpacing(0);
        layout_lista->setObjectName(QStringLiteral("layout_lista"));
        layout_superior = new QHBoxLayout();
        layout_superior->setSpacing(6);
        layout_superior->setObjectName(QStringLiteral("layout_superior"));
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(16);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        font1.setStyleStrategy(QFont::PreferAntialias);
        label->setFont(font1);
        label->setFrameShadow(QFrame::Plain);
        label->setLineWidth(1);
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        layout_superior->addWidget(label);

        btn_eliminar_concepto = new QPushButton(horizontalLayoutWidget);
        btn_eliminar_concepto->setObjectName(QStringLiteral("btn_eliminar_concepto"));
        btn_eliminar_concepto->setMinimumSize(QSize(0, 30));
        btn_eliminar_concepto->setMaximumSize(QSize(80, 16777215));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(11);
        btn_eliminar_concepto->setFont(font2);

        layout_superior->addWidget(btn_eliminar_concepto);

        btn_agregar_concepto = new QPushButton(horizontalLayoutWidget);
        btn_agregar_concepto->setObjectName(QStringLiteral("btn_agregar_concepto"));
        btn_agregar_concepto->setMinimumSize(QSize(0, 30));
        btn_agregar_concepto->setMaximumSize(QSize(80, 16777215));
        btn_agregar_concepto->setFont(font2);

        layout_superior->addWidget(btn_agregar_concepto);


        layout_lista->addLayout(layout_superior);

        lista_conceptos = new QListWidget(horizontalLayoutWidget);
        lista_conceptos->setObjectName(QStringLiteral("lista_conceptos"));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        font3.setPointSize(10);
        lista_conceptos->setFont(font3);

        layout_lista->addWidget(lista_conceptos);


        layout_general->addLayout(layout_lista);


        retranslateUi(DialogoConceptos);
        QObject::connect(btnbox_conceptos, SIGNAL(accepted()), action_actualizar_y_cerrar, SLOT(trigger()));
        QObject::connect(btnbox_conceptos, SIGNAL(rejected()), DialogoConceptos, SLOT(close()));
        QObject::connect(btn_agregar_concepto, SIGNAL(released()), action_nuevo_concepto, SLOT(trigger()));
        QObject::connect(btn_eliminar_concepto, SIGNAL(released()), action_eliminar_concepto, SLOT(trigger()));
        QObject::connect(lista_conceptos, SIGNAL(itemSelectionChanged()), action_estado_btn_eliminar, SLOT(trigger()));
        QObject::connect(lista_conceptos, SIGNAL(itemDoubleClicked(QListWidgetItem*)), action_editar_concepto, SLOT(trigger()));

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
        action_nuevo_concepto->setText(QApplication::translate("DialogoConceptos", "nuevo_concepto", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_nuevo_concepto->setToolTip(QApplication::translate("DialogoConceptos", "nuevo concepto", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_estado_btn_eliminar->setText(QApplication::translate("DialogoConceptos", "estado_btn_eliminar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_estado_btn_eliminar->setToolTip(QApplication::translate("DialogoConceptos", "estado btn eliminar", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_estado_btn_agregar->setText(QApplication::translate("DialogoConceptos", "estado_btn_agregar", Q_NULLPTR));
        action_editar_concepto->setText(QApplication::translate("DialogoConceptos", "Editar concepto", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_editar_concepto->setToolTip(QApplication::translate("DialogoConceptos", "Editar concepto", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("DialogoConceptos", "Lista de conceptos", Q_NULLPTR));
        btn_eliminar_concepto->setText(QApplication::translate("DialogoConceptos", "Eliminar", Q_NULLPTR));
        btn_agregar_concepto->setText(QApplication::translate("DialogoConceptos", "Nuevo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoConceptos: public Ui_DialogoConceptos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOCONCEPTOS_H
