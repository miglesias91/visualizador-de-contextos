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
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoResultadoConsulta
{
public:
    QTabWidget *analisis;
    QWidget *pestania_1;
    QWidget *fuerza_en_noticia_vacio;
    QLabel *lbl_sin_valores_1;
    QWidget *pestania_2;
    QWidget *sentimiento_vacio;
    QLabel *lbl_sin_valores_2;
    QSlider *fechas;
    QDateEdit *calendario;

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
        fuerza_en_noticia_vacio = new QWidget(pestania_1);
        fuerza_en_noticia_vacio->setObjectName(QStringLiteral("fuerza_en_noticia_vacio"));
        fuerza_en_noticia_vacio->setGeometry(QRect(0, 0, 611, 391));
        fuerza_en_noticia_vacio->setAutoFillBackground(true);
        lbl_sin_valores_1 = new QLabel(fuerza_en_noticia_vacio);
        lbl_sin_valores_1->setObjectName(QStringLiteral("lbl_sin_valores_1"));
        lbl_sin_valores_1->setGeometry(QRect(160, 70, 291, 201));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(50);
        lbl_sin_valores_1->setFont(font);
        analisis->addTab(pestania_1, QString());
        pestania_2 = new QWidget();
        pestania_2->setObjectName(QStringLiteral("pestania_2"));
        sentimiento_vacio = new QWidget(pestania_2);
        sentimiento_vacio->setObjectName(QStringLiteral("sentimiento_vacio"));
        sentimiento_vacio->setGeometry(QRect(0, 0, 611, 391));
        sentimiento_vacio->setAutoFillBackground(true);
        lbl_sin_valores_2 = new QLabel(sentimiento_vacio);
        lbl_sin_valores_2->setObjectName(QStringLiteral("lbl_sin_valores_2"));
        lbl_sin_valores_2->setGeometry(QRect(160, 70, 291, 201));
        lbl_sin_valores_2->setFont(font);
        analisis->addTab(pestania_2, QString());
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
        calendario = new QDateEdit(DialogoResultadoConsulta);
        calendario->setObjectName(QStringLiteral("calendario"));
        calendario->setGeometry(QRect(260, 460, 110, 22));

        retranslateUi(DialogoResultadoConsulta);

        analisis->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(DialogoResultadoConsulta);
    } // setupUi

    void retranslateUi(QWidget *DialogoResultadoConsulta)
    {
        DialogoResultadoConsulta->setWindowTitle(QApplication::translate("DialogoResultadoConsulta", "DialogoResultadoConsulta", Q_NULLPTR));
        lbl_sin_valores_1->setText(QApplication::translate("DialogoResultadoConsulta", "sin valores", Q_NULLPTR));
        analisis->setTabText(analisis->indexOf(pestania_1), QApplication::translate("DialogoResultadoConsulta", "Fuerza en noticia", Q_NULLPTR));
        lbl_sin_valores_2->setText(QApplication::translate("DialogoResultadoConsulta", "sin valores", Q_NULLPTR));
        analisis->setTabText(analisis->indexOf(pestania_2), QApplication::translate("DialogoResultadoConsulta", "Sentimiento", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoResultadoConsulta: public Ui_DialogoResultadoConsulta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGORESULTADOCONSULTA_H
