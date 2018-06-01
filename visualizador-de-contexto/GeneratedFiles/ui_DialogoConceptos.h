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
    QVBoxLayout *verticalLayout;
    QWidget *widget_general;
    QHBoxLayout *layout_general;
    QWidget *widget_lista;
    QVBoxLayout *layout_lista;
    QWidget *widget_superior;
    QHBoxLayout *layout_superior;
    QLabel *label;
    QPushButton *btn_eliminar;
    QPushButton *btn_nuevo;
    QListWidget *lista_conceptos;
    QWidget *widget_opciones;
    QHBoxLayout *layout_opciones;
    QPushButton *btn_guardar;
    QPushButton *btn_cancelar;

    void setupUi(QWidget *DialogoConceptos)
    {
        if (DialogoConceptos->objectName().isEmpty())
            DialogoConceptos->setObjectName(QStringLiteral("DialogoConceptos"));
        DialogoConceptos->resize(800, 400);
        DialogoConceptos->setAutoFillBackground(false);
        DialogoConceptos->setStyleSheet(QStringLiteral("border-color: rgb(29, 29, 29);"));
        verticalLayout = new QVBoxLayout(DialogoConceptos);
        verticalLayout->setSpacing(3);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_general = new QWidget(DialogoConceptos);
        widget_general->setObjectName(QStringLiteral("widget_general"));
        widget_general->setStyleSheet(QStringLiteral(""));
        layout_general = new QHBoxLayout(widget_general);
        layout_general->setSpacing(0);
        layout_general->setContentsMargins(11, 11, 11, 11);
        layout_general->setObjectName(QStringLiteral("layout_general"));
        layout_general->setSizeConstraint(QLayout::SetNoConstraint);
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
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        font.setStyleStrategy(QFont::PreferAntialias);
        label->setFont(font);
        label->setFrameShadow(QFrame::Plain);
        label->setLineWidth(1);
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        layout_superior->addWidget(label);

        btn_eliminar = new QPushButton(widget_superior);
        btn_eliminar->setObjectName(QStringLiteral("btn_eliminar"));
        btn_eliminar->setMinimumSize(QSize(0, 30));
        btn_eliminar->setMaximumSize(QSize(80, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(11);
        btn_eliminar->setFont(font1);

        layout_superior->addWidget(btn_eliminar);

        btn_nuevo = new QPushButton(widget_superior);
        btn_nuevo->setObjectName(QStringLiteral("btn_nuevo"));
        btn_nuevo->setMinimumSize(QSize(0, 30));
        btn_nuevo->setMaximumSize(QSize(80, 16777215));
        btn_nuevo->setFont(font1);

        layout_superior->addWidget(btn_nuevo);


        layout_lista->addWidget(widget_superior);

        lista_conceptos = new QListWidget(widget_lista);
        lista_conceptos->setObjectName(QStringLiteral("lista_conceptos"));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(10);
        lista_conceptos->setFont(font2);

        layout_lista->addWidget(lista_conceptos);

        widget_opciones = new QWidget(widget_lista);
        widget_opciones->setObjectName(QStringLiteral("widget_opciones"));
        layout_opciones = new QHBoxLayout(widget_opciones);
        layout_opciones->setSpacing(3);
        layout_opciones->setContentsMargins(11, 11, 11, 11);
        layout_opciones->setObjectName(QStringLiteral("layout_opciones"));
        layout_opciones->setContentsMargins(0, 0, 0, 0);
        btn_guardar = new QPushButton(widget_opciones);
        btn_guardar->setObjectName(QStringLiteral("btn_guardar"));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        font3.setPointSize(12);
        btn_guardar->setFont(font3);

        layout_opciones->addWidget(btn_guardar);

        btn_cancelar = new QPushButton(widget_opciones);
        btn_cancelar->setObjectName(QStringLiteral("btn_cancelar"));
        btn_cancelar->setFont(font3);

        layout_opciones->addWidget(btn_cancelar);


        layout_lista->addWidget(widget_opciones, 0, Qt::AlignHCenter);


        layout_general->addWidget(widget_lista);


        verticalLayout->addWidget(widget_general);


        retranslateUi(DialogoConceptos);

        QMetaObject::connectSlotsByName(DialogoConceptos);
    } // setupUi

    void retranslateUi(QWidget *DialogoConceptos)
    {
        DialogoConceptos->setWindowTitle(QApplication::translate("DialogoConceptos", "Conceptos", Q_NULLPTR));
        label->setText(QApplication::translate("DialogoConceptos", "Lista de conceptos", Q_NULLPTR));
        btn_eliminar->setText(QApplication::translate("DialogoConceptos", "Eliminar", Q_NULLPTR));
        btn_nuevo->setText(QApplication::translate("DialogoConceptos", "Nuevo", Q_NULLPTR));
        btn_guardar->setText(QApplication::translate("DialogoConceptos", "Guardar", Q_NULLPTR));
        btn_cancelar->setText(QApplication::translate("DialogoConceptos", "Cancelar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoConceptos: public Ui_DialogoConceptos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOCONCEPTOS_H
