/********************************************************************************
** Form generated from reading UI file 'visualizadordecontexto.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISUALIZADORDECONTEXTO_H
#define UI_VISUALIZADORDECONTEXTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_visualizadordecontextoClass
{
public:
    QAction *action_abrirTerminos;
    QWidget *centralWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *btn_conceptos;
    QPushButton *btn_terminos;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *visualizadordecontextoClass)
    {
        if (visualizadordecontextoClass->objectName().isEmpty())
            visualizadordecontextoClass->setObjectName(QStringLiteral("visualizadordecontextoClass"));
        visualizadordecontextoClass->resize(600, 400);
        action_abrirTerminos = new QAction(visualizadordecontextoClass);
        action_abrirTerminos->setObjectName(QStringLiteral("action_abrirTerminos"));
        action_abrirTerminos->setCheckable(true);
        centralWidget = new QWidget(visualizadordecontextoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(120, 60, 311, 80));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        btn_conceptos = new QPushButton(gridLayoutWidget);
        btn_conceptos->setObjectName(QStringLiteral("btn_conceptos"));

        gridLayout->addWidget(btn_conceptos, 1, 0, 1, 1);

        btn_terminos = new QPushButton(gridLayoutWidget);
        btn_terminos->setObjectName(QStringLiteral("btn_terminos"));

        gridLayout->addWidget(btn_terminos, 0, 0, 1, 1);

        visualizadordecontextoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(visualizadordecontextoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        visualizadordecontextoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(visualizadordecontextoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        visualizadordecontextoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(visualizadordecontextoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        visualizadordecontextoClass->setStatusBar(statusBar);

        retranslateUi(visualizadordecontextoClass);
        QObject::connect(btn_terminos, SIGNAL(released()), action_abrirTerminos, SLOT(trigger()));

        QMetaObject::connectSlotsByName(visualizadordecontextoClass);
    } // setupUi

    void retranslateUi(QMainWindow *visualizadordecontextoClass)
    {
        visualizadordecontextoClass->setWindowTitle(QApplication::translate("visualizadordecontextoClass", "visualizadordecontexto", Q_NULLPTR));
        action_abrirTerminos->setText(QApplication::translate("visualizadordecontextoClass", "abrirTerminos", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_abrirTerminos->setShortcut(QApplication::translate("visualizadordecontextoClass", "Ctrl+T", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        btn_conceptos->setText(QApplication::translate("visualizadordecontextoClass", "conceptos", Q_NULLPTR));
        btn_terminos->setText(QApplication::translate("visualizadordecontextoClass", "terminos", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class visualizadordecontextoClass: public Ui_visualizadordecontextoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZADORDECONTEXTO_H
