/********************************************************************************
** Form generated from reading UI file 'DialogoMediosPortales.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOMEDIOSPORTALES_H
#define UI_DIALOGOMEDIOSPORTALES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoMediosPortales
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
    QWidget *widget_opciones;
    QHBoxLayout *layout_opciones;
    QFrame *line;
    QPushButton *btn_cerrar;
    QTreeWidget *arbol_medios_portales;

    void setupUi(QWidget *DialogoMediosPortales)
    {
        if (DialogoMediosPortales->objectName().isEmpty())
            DialogoMediosPortales->setObjectName(QStringLiteral("DialogoMediosPortales"));
        DialogoMediosPortales->resize(800, 400);
        verticalLayout = new QVBoxLayout(DialogoMediosPortales);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_general = new QWidget(DialogoMediosPortales);
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

        widget_opciones = new QWidget(widget_superior);
        widget_opciones->setObjectName(QStringLiteral("widget_opciones"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_opciones->sizePolicy().hasHeightForWidth());
        widget_opciones->setSizePolicy(sizePolicy);
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

        btn_cerrar = new QPushButton(widget_opciones);
        btn_cerrar->setObjectName(QStringLiteral("btn_cerrar"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_cerrar->sizePolicy().hasHeightForWidth());
        btn_cerrar->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(10);
        btn_cerrar->setFont(font1);

        layout_opciones->addWidget(btn_cerrar);


        layout_superior->addWidget(widget_opciones);


        layout_lista->addWidget(widget_superior, 0, Qt::AlignBottom);

        arbol_medios_portales = new QTreeWidget(widget_lista);
        arbol_medios_portales->setObjectName(QStringLiteral("arbol_medios_portales"));
        arbol_medios_portales->setFont(font1);

        layout_lista->addWidget(arbol_medios_portales);


        layout_general->addWidget(widget_lista);


        verticalLayout->addWidget(widget_general);


        retranslateUi(DialogoMediosPortales);

        QMetaObject::connectSlotsByName(DialogoMediosPortales);
    } // setupUi

    void retranslateUi(QWidget *DialogoMediosPortales)
    {
        DialogoMediosPortales->setWindowTitle(QApplication::translate("DialogoMediosPortales", "DialogoMediosPortales", Q_NULLPTR));
        label->setText(QApplication::translate("DialogoMediosPortales", "Lista de portales de noticias", Q_NULLPTR));
        btn_cerrar->setText(QApplication::translate("DialogoMediosPortales", "Cerrar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoMediosPortales: public Ui_DialogoMediosPortales {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOMEDIOSPORTALES_H
