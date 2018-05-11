/********************************************************************************
** Form generated from reading UI file 'DialogoResultadoConsulta.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGORESULTADOCONSULTA_H
#define UI_DIALOGORESULTADOCONSULTA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoResultadoConsulta
{
public:
    QTabWidget *analisis;
    QWidget *pestania_1;
    QTableWidget *fuerza_en_noticia;
    QWidget *pestania_2;
    QTableWidget *sentimiento;
    QSlider *fechas;
    QDateEdit *dateEdit;

    void setupUi(QWidget *DialogoResultadoConsulta)
    {
        if (DialogoResultadoConsulta->objectName().isEmpty())
            DialogoResultadoConsulta->setObjectName(QStringLiteral("DialogoResultadoConsulta"));
        DialogoResultadoConsulta->resize(633, 489);
        analisis = new QTabWidget(DialogoResultadoConsulta);
        analisis->setObjectName(QStringLiteral("analisis"));
        analisis->setGeometry(QRect(10, 10, 611, 421));
        analisis->setTabPosition(QTabWidget::North);
        analisis->setTabShape(QTabWidget::Rounded);
        analisis->setElideMode(Qt::ElideNone);
        analisis->setDocumentMode(true);
        analisis->setTabsClosable(false);
        analisis->setMovable(true);
        analisis->setTabBarAutoHide(false);
        pestania_1 = new QWidget();
        pestania_1->setObjectName(QStringLiteral("pestania_1"));
        fuerza_en_noticia = new QTableWidget(pestania_1);
        fuerza_en_noticia->setObjectName(QStringLiteral("fuerza_en_noticia"));
        fuerza_en_noticia->setGeometry(QRect(0, 0, 611, 391));
        fuerza_en_noticia->setShowGrid(true);
        analisis->addTab(pestania_1, QString());
        pestania_2 = new QWidget();
        pestania_2->setObjectName(QStringLiteral("pestania_2"));
        sentimiento = new QTableWidget(pestania_2);
        sentimiento->setObjectName(QStringLiteral("sentimiento"));
        sentimiento->setGeometry(QRect(0, 0, 611, 391));
        analisis->addTab(pestania_2, QString());
        sentimiento->raise();
        fechas = new QSlider(DialogoResultadoConsulta);
        fechas->setObjectName(QStringLiteral("fechas"));
        fechas->setGeometry(QRect(10, 430, 611, 22));
        fechas->setMaximum(99);
        fechas->setTracking(true);
        fechas->setOrientation(Qt::Horizontal);
        fechas->setInvertedAppearance(false);
        fechas->setInvertedControls(false);
        fechas->setTickPosition(QSlider::TicksAbove);
        fechas->setTickInterval(1);
        dateEdit = new QDateEdit(DialogoResultadoConsulta);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(260, 460, 110, 22));

        retranslateUi(DialogoResultadoConsulta);

        analisis->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogoResultadoConsulta);
    } // setupUi

    void retranslateUi(QWidget *DialogoResultadoConsulta)
    {
        DialogoResultadoConsulta->setWindowTitle(QApplication::translate("DialogoResultadoConsulta", "DialogoResultadoConsulta", Q_NULLPTR));
        analisis->setTabText(analisis->indexOf(pestania_1), QApplication::translate("DialogoResultadoConsulta", "Fuerza en noticia", Q_NULLPTR));
        analisis->setTabText(analisis->indexOf(pestania_2), QApplication::translate("DialogoResultadoConsulta", "Sentimiento", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoResultadoConsulta: public Ui_DialogoResultadoConsulta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGORESULTADOCONSULTA_H
