/********************************************************************************
** Form generated from reading UI file 'ventanaprincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VENTANAPRINCIPAL_H
#define UI_VENTANAPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VentanaPrincipal
{
public:
    QWidget *centralWidget;
    QPushButton *btn_termino;
    QPushButton *btn_conceptos;
    QPushButton *btn_fechas;
    QPushButton *btn_periodos;
    QPushButton *btn_secciones;
    QPushButton *btn_medios;
    QPushButton *btn_consulta;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VentanaPrincipal)
    {
        if (VentanaPrincipal->objectName().isEmpty())
            VentanaPrincipal->setObjectName(QStringLiteral("VentanaPrincipal"));
        VentanaPrincipal->resize(400, 300);
        centralWidget = new QWidget(VentanaPrincipal);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        btn_termino = new QPushButton(centralWidget);
        btn_termino->setObjectName(QStringLiteral("btn_termino"));
        btn_termino->setGeometry(QRect(50, 80, 75, 23));
        btn_conceptos = new QPushButton(centralWidget);
        btn_conceptos->setObjectName(QStringLiteral("btn_conceptos"));
        btn_conceptos->setGeometry(QRect(50, 110, 75, 23));
        btn_fechas = new QPushButton(centralWidget);
        btn_fechas->setObjectName(QStringLiteral("btn_fechas"));
        btn_fechas->setGeometry(QRect(50, 140, 75, 23));
        btn_periodos = new QPushButton(centralWidget);
        btn_periodos->setObjectName(QStringLiteral("btn_periodos"));
        btn_periodos->setGeometry(QRect(50, 170, 75, 23));
        btn_secciones = new QPushButton(centralWidget);
        btn_secciones->setObjectName(QStringLiteral("btn_secciones"));
        btn_secciones->setGeometry(QRect(50, 200, 71, 23));
        btn_medios = new QPushButton(centralWidget);
        btn_medios->setObjectName(QStringLiteral("btn_medios"));
        btn_medios->setGeometry(QRect(170, 80, 75, 23));
        btn_consulta = new QPushButton(centralWidget);
        btn_consulta->setObjectName(QStringLiteral("btn_consulta"));
        btn_consulta->setGeometry(QRect(170, 110, 75, 23));
        VentanaPrincipal->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VentanaPrincipal);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 21));
        VentanaPrincipal->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VentanaPrincipal);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        VentanaPrincipal->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VentanaPrincipal);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        VentanaPrincipal->setStatusBar(statusBar);

        retranslateUi(VentanaPrincipal);

        QMetaObject::connectSlotsByName(VentanaPrincipal);
    } // setupUi

    void retranslateUi(QMainWindow *VentanaPrincipal)
    {
        VentanaPrincipal->setWindowTitle(QApplication::translate("VentanaPrincipal", "VentanaPrincipal", Q_NULLPTR));
        btn_termino->setText(QApplication::translate("VentanaPrincipal", "termino", Q_NULLPTR));
        btn_conceptos->setText(QApplication::translate("VentanaPrincipal", "conceptos", Q_NULLPTR));
        btn_fechas->setText(QApplication::translate("VentanaPrincipal", "fechas", Q_NULLPTR));
        btn_periodos->setText(QApplication::translate("VentanaPrincipal", "periodos", Q_NULLPTR));
        btn_secciones->setText(QApplication::translate("VentanaPrincipal", "secciones", Q_NULLPTR));
        btn_medios->setText(QApplication::translate("VentanaPrincipal", "medios", Q_NULLPTR));
        btn_consulta->setText(QApplication::translate("VentanaPrincipal", "consulta", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class VentanaPrincipal: public Ui_VentanaPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VENTANAPRINCIPAL_H
