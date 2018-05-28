/********************************************************************************
** Form generated from reading UI file 'DialogoResultadoConsulta.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGORESULTADOCONSULTA_H
#define UI_DIALOGORESULTADOCONSULTA_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoResultadoConsulta
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *analisis;
    QWidget *pestania_1;
    QVBoxLayout *layout_pestania_1;
    QLabel *lbl_sin_valores_1;
    QWidget *pestania_2;
    QVBoxLayout *layout_pestania_2;
    QLabel *lbl_sin_valores_2;
    QHBoxLayout *layout_fechas;
    QDateEdit *calendario;
    QSlider *dias;

    void setupUi(QWidget *DialogoResultadoConsulta)
    {
        if (DialogoResultadoConsulta->objectName().isEmpty())
            DialogoResultadoConsulta->setObjectName(QStringLiteral("DialogoResultadoConsulta"));
        DialogoResultadoConsulta->resize(800, 400);
        verticalLayout = new QVBoxLayout(DialogoResultadoConsulta);
        verticalLayout->setSpacing(5);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(5, 5, 5, 5);
        analisis = new QTabWidget(DialogoResultadoConsulta);
        analisis->setObjectName(QStringLiteral("analisis"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        analisis->setFont(font);
        analisis->setTabPosition(QTabWidget::North);
        analisis->setTabShape(QTabWidget::Rounded);
        analisis->setElideMode(Qt::ElideNone);
        analisis->setDocumentMode(true);
        analisis->setTabsClosable(false);
        analisis->setMovable(true);
        analisis->setTabBarAutoHide(false);
        pestania_1 = new QWidget();
        pestania_1->setObjectName(QStringLiteral("pestania_1"));
        layout_pestania_1 = new QVBoxLayout(pestania_1);
        layout_pestania_1->setSpacing(0);
        layout_pestania_1->setContentsMargins(11, 11, 11, 11);
        layout_pestania_1->setObjectName(QStringLiteral("layout_pestania_1"));
        layout_pestania_1->setContentsMargins(0, 0, 0, 0);
        lbl_sin_valores_1 = new QLabel(pestania_1);
        lbl_sin_valores_1->setObjectName(QStringLiteral("lbl_sin_valores_1"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lbl_sin_valores_1->sizePolicy().hasHeightForWidth());
        lbl_sin_valores_1->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(50);
        lbl_sin_valores_1->setFont(font1);
        lbl_sin_valores_1->setAutoFillBackground(false);
        lbl_sin_valores_1->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_sin_valores_1->setFrameShape(QFrame::Box);
        lbl_sin_valores_1->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        layout_pestania_1->addWidget(lbl_sin_valores_1);

        analisis->addTab(pestania_1, QString());
        pestania_2 = new QWidget();
        pestania_2->setObjectName(QStringLiteral("pestania_2"));
        layout_pestania_2 = new QVBoxLayout(pestania_2);
        layout_pestania_2->setSpacing(0);
        layout_pestania_2->setContentsMargins(11, 11, 11, 11);
        layout_pestania_2->setObjectName(QStringLiteral("layout_pestania_2"));
        layout_pestania_2->setContentsMargins(0, 0, 0, 0);
        lbl_sin_valores_2 = new QLabel(pestania_2);
        lbl_sin_valores_2->setObjectName(QStringLiteral("lbl_sin_valores_2"));
        sizePolicy.setHeightForWidth(lbl_sin_valores_2->sizePolicy().hasHeightForWidth());
        lbl_sin_valores_2->setSizePolicy(sizePolicy);
        lbl_sin_valores_2->setFont(font1);
        lbl_sin_valores_2->setLayoutDirection(Qt::LeftToRight);
        lbl_sin_valores_2->setAutoFillBackground(false);
        lbl_sin_valores_2->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_sin_valores_2->setFrameShape(QFrame::Box);
        lbl_sin_valores_2->setFrameShadow(QFrame::Plain);
        lbl_sin_valores_2->setTextFormat(Qt::PlainText);
        lbl_sin_valores_2->setScaledContents(false);
        lbl_sin_valores_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lbl_sin_valores_2->setWordWrap(false);

        layout_pestania_2->addWidget(lbl_sin_valores_2);

        analisis->addTab(pestania_2, QString());

        verticalLayout->addWidget(analisis);

        layout_fechas = new QHBoxLayout();
        layout_fechas->setSpacing(6);
        layout_fechas->setObjectName(QStringLiteral("layout_fechas"));
        calendario = new QDateEdit(DialogoResultadoConsulta);
        calendario->setObjectName(QStringLiteral("calendario"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(calendario->sizePolicy().hasHeightForWidth());
        calendario->setSizePolicy(sizePolicy1);
        calendario->setMinimumSize(QSize(150, 0));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(15);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setWeight(50);
        calendario->setFont(font2);
        calendario->setWrapping(false);
        calendario->setFrame(true);
        calendario->setAlignment(Qt::AlignCenter);
        calendario->setReadOnly(false);
        calendario->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        calendario->setAccelerated(true);
        calendario->setProperty("showGroupSeparator", QVariant(false));
        calendario->setCurrentSection(QDateTimeEdit::YearSection);
        calendario->setCalendarPopup(true);
        calendario->setDate(QDate(2018, 12, 12));

        layout_fechas->addWidget(calendario);

        dias = new QSlider(DialogoResultadoConsulta);
        dias->setObjectName(QStringLiteral("dias"));
        dias->setMaximum(1);
        dias->setTracking(true);
        dias->setOrientation(Qt::Horizontal);
        dias->setInvertedAppearance(false);
        dias->setInvertedControls(false);
        dias->setTickPosition(QSlider::TicksAbove);
        dias->setTickInterval(1);

        layout_fechas->addWidget(dias);


        verticalLayout->addLayout(layout_fechas);


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
