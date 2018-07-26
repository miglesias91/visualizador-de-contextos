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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
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
    QWidget *pestania_3;
    QHBoxLayout *layout_pestania_3;
    QLabel *lbl_sin_valores_3;
    QHBoxLayout *layout_fechas;
    QDateEdit *calendario;
    QSlider *dias;
    QWidget *widget_exportar;
    QHBoxLayout *layout_exportar;
    QWidget *widget_exportar_botones;
    QHBoxLayout *layout_exportar_botones;
    QPushButton *btn_exportar_fecha_actual;
    QPushButton *btn_exportar_todo;
    QPushButton *btn_exportar_rango;
    QLabel *lbl_desde;
    QWidget *widget_desde;
    QVBoxLayout *layout_desde;
    QDateEdit *dateedit_desde;
    QLabel *lbl_hasta;
    QWidget *widget_hasta;
    QVBoxLayout *layout_hasta;
    QDateEdit *dateedit_hasta;
    QProgressBar *progressbar_exportacion;

    void setupUi(QWidget *DialogoResultadoConsulta)
    {
        if (DialogoResultadoConsulta->objectName().isEmpty())
            DialogoResultadoConsulta->setObjectName(QStringLiteral("DialogoResultadoConsulta"));
        DialogoResultadoConsulta->resize(800, 300);
        DialogoResultadoConsulta->setMinimumSize(QSize(800, 300));
        verticalLayout = new QVBoxLayout(DialogoResultadoConsulta);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        analisis = new QTabWidget(DialogoResultadoConsulta);
        analisis->setObjectName(QStringLiteral("analisis"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(10);
        analisis->setFont(font);
        analisis->setTabPosition(QTabWidget::North);
        analisis->setTabShape(QTabWidget::Rounded);
        analisis->setElideMode(Qt::ElideLeft);
        analisis->setUsesScrollButtons(true);
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
        font1.setPointSize(16);
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
        pestania_3 = new QWidget();
        pestania_3->setObjectName(QStringLiteral("pestania_3"));
        layout_pestania_3 = new QHBoxLayout(pestania_3);
        layout_pestania_3->setSpacing(0);
        layout_pestania_3->setContentsMargins(11, 11, 11, 11);
        layout_pestania_3->setObjectName(QStringLiteral("layout_pestania_3"));
        layout_pestania_3->setContentsMargins(0, 0, 0, 0);
        lbl_sin_valores_3 = new QLabel(pestania_3);
        lbl_sin_valores_3->setObjectName(QStringLiteral("lbl_sin_valores_3"));
        sizePolicy.setHeightForWidth(lbl_sin_valores_3->sizePolicy().hasHeightForWidth());
        lbl_sin_valores_3->setSizePolicy(sizePolicy);
        lbl_sin_valores_3->setFont(font1);
        lbl_sin_valores_3->setLayoutDirection(Qt::LeftToRight);
        lbl_sin_valores_3->setAutoFillBackground(false);
        lbl_sin_valores_3->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lbl_sin_valores_3->setFrameShape(QFrame::Box);
        lbl_sin_valores_3->setFrameShadow(QFrame::Plain);
        lbl_sin_valores_3->setTextFormat(Qt::PlainText);
        lbl_sin_valores_3->setScaledContents(false);
        lbl_sin_valores_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lbl_sin_valores_3->setWordWrap(false);

        layout_pestania_3->addWidget(lbl_sin_valores_3);

        analisis->addTab(pestania_3, QString());

        verticalLayout->addWidget(analisis);

        layout_fechas = new QHBoxLayout();
        layout_fechas->setSpacing(6);
        layout_fechas->setObjectName(QStringLiteral("layout_fechas"));
        calendario = new QDateEdit(DialogoResultadoConsulta);
        calendario->setObjectName(QStringLiteral("calendario"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(calendario->sizePolicy().hasHeightForWidth());
        calendario->setSizePolicy(sizePolicy1);
        calendario->setMinimumSize(QSize(91, 0));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(10);
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

        widget_exportar = new QWidget(DialogoResultadoConsulta);
        widget_exportar->setObjectName(QStringLiteral("widget_exportar"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget_exportar->sizePolicy().hasHeightForWidth());
        widget_exportar->setSizePolicy(sizePolicy2);
        widget_exportar->setLayoutDirection(Qt::LeftToRight);
        layout_exportar = new QHBoxLayout(widget_exportar);
        layout_exportar->setSpacing(5);
        layout_exportar->setContentsMargins(11, 11, 11, 11);
        layout_exportar->setObjectName(QStringLiteral("layout_exportar"));
        layout_exportar->setContentsMargins(0, 0, 0, 0);
        widget_exportar_botones = new QWidget(widget_exportar);
        widget_exportar_botones->setObjectName(QStringLiteral("widget_exportar_botones"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_exportar_botones->sizePolicy().hasHeightForWidth());
        widget_exportar_botones->setSizePolicy(sizePolicy3);
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        widget_exportar_botones->setFont(font3);
        layout_exportar_botones = new QHBoxLayout(widget_exportar_botones);
        layout_exportar_botones->setSpacing(2);
        layout_exportar_botones->setContentsMargins(11, 11, 11, 11);
        layout_exportar_botones->setObjectName(QStringLiteral("layout_exportar_botones"));
        layout_exportar_botones->setContentsMargins(0, 0, 0, 0);
        btn_exportar_fecha_actual = new QPushButton(widget_exportar_botones);
        btn_exportar_fecha_actual->setObjectName(QStringLiteral("btn_exportar_fecha_actual"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(30);
        sizePolicy4.setHeightForWidth(btn_exportar_fecha_actual->sizePolicy().hasHeightForWidth());
        btn_exportar_fecha_actual->setSizePolicy(sizePolicy4);
        btn_exportar_fecha_actual->setMinimumSize(QSize(0, 0));
        btn_exportar_fecha_actual->setMaximumSize(QSize(200, 16777215));
        btn_exportar_fecha_actual->setFont(font);

        layout_exportar_botones->addWidget(btn_exportar_fecha_actual);

        btn_exportar_todo = new QPushButton(widget_exportar_botones);
        btn_exportar_todo->setObjectName(QStringLiteral("btn_exportar_todo"));
        btn_exportar_todo->setMinimumSize(QSize(0, 0));
        btn_exportar_todo->setMaximumSize(QSize(150, 16777215));
        btn_exportar_todo->setFont(font);

        layout_exportar_botones->addWidget(btn_exportar_todo);

        btn_exportar_rango = new QPushButton(widget_exportar_botones);
        btn_exportar_rango->setObjectName(QStringLiteral("btn_exportar_rango"));
        btn_exportar_rango->setMinimumSize(QSize(0, 0));
        btn_exportar_rango->setMaximumSize(QSize(150, 16777215));
        btn_exportar_rango->setFont(font);

        layout_exportar_botones->addWidget(btn_exportar_rango);

        lbl_desde = new QLabel(widget_exportar_botones);
        lbl_desde->setObjectName(QStringLiteral("lbl_desde"));
        lbl_desde->setMaximumSize(QSize(50, 16777215));
        lbl_desde->setFont(font3);

        layout_exportar_botones->addWidget(lbl_desde);

        widget_desde = new QWidget(widget_exportar_botones);
        widget_desde->setObjectName(QStringLiteral("widget_desde"));
        sizePolicy3.setHeightForWidth(widget_desde->sizePolicy().hasHeightForWidth());
        widget_desde->setSizePolicy(sizePolicy3);
        widget_desde->setMaximumSize(QSize(90, 35));
        layout_desde = new QVBoxLayout(widget_desde);
        layout_desde->setSpacing(0);
        layout_desde->setContentsMargins(11, 11, 11, 11);
        layout_desde->setObjectName(QStringLiteral("layout_desde"));
        layout_desde->setContentsMargins(0, 0, 0, 0);
        dateedit_desde = new QDateEdit(widget_desde);
        dateedit_desde->setObjectName(QStringLiteral("dateedit_desde"));
        dateedit_desde->setMinimumSize(QSize(90, 0));
        dateedit_desde->setMaximumSize(QSize(80, 16777215));
        dateedit_desde->setFont(font);
        dateedit_desde->setCalendarPopup(true);

        layout_desde->addWidget(dateedit_desde);


        layout_exportar_botones->addWidget(widget_desde);

        lbl_hasta = new QLabel(widget_exportar_botones);
        lbl_hasta->setObjectName(QStringLiteral("lbl_hasta"));
        lbl_hasta->setMaximumSize(QSize(50, 16777215));
        lbl_hasta->setFont(font3);

        layout_exportar_botones->addWidget(lbl_hasta);

        widget_hasta = new QWidget(widget_exportar_botones);
        widget_hasta->setObjectName(QStringLiteral("widget_hasta"));
        sizePolicy3.setHeightForWidth(widget_hasta->sizePolicy().hasHeightForWidth());
        widget_hasta->setSizePolicy(sizePolicy3);
        widget_hasta->setMaximumSize(QSize(90, 35));
        layout_hasta = new QVBoxLayout(widget_hasta);
        layout_hasta->setSpacing(0);
        layout_hasta->setContentsMargins(11, 11, 11, 11);
        layout_hasta->setObjectName(QStringLiteral("layout_hasta"));
        layout_hasta->setContentsMargins(0, 0, 0, 0);
        dateedit_hasta = new QDateEdit(widget_hasta);
        dateedit_hasta->setObjectName(QStringLiteral("dateedit_hasta"));
        dateedit_hasta->setMinimumSize(QSize(90, 0));
        dateedit_hasta->setMaximumSize(QSize(80, 16777215));
        dateedit_hasta->setFont(font);
        dateedit_hasta->setCalendarPopup(true);

        layout_hasta->addWidget(dateedit_hasta);


        layout_exportar_botones->addWidget(widget_hasta);


        layout_exportar->addWidget(widget_exportar_botones);

        progressbar_exportacion = new QProgressBar(widget_exportar);
        progressbar_exportacion->setObjectName(QStringLiteral("progressbar_exportacion"));
        progressbar_exportacion->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(progressbar_exportacion->sizePolicy().hasHeightForWidth());
        progressbar_exportacion->setSizePolicy(sizePolicy5);
        progressbar_exportacion->setMinimumSize(QSize(0, 0));
        progressbar_exportacion->setValue(50);
        progressbar_exportacion->setTextVisible(false);
        progressbar_exportacion->setInvertedAppearance(false);

        layout_exportar->addWidget(progressbar_exportacion);


        verticalLayout->addWidget(widget_exportar, 0, Qt::AlignLeft);


        retranslateUi(DialogoResultadoConsulta);

        analisis->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogoResultadoConsulta);
    } // setupUi

    void retranslateUi(QWidget *DialogoResultadoConsulta)
    {
        DialogoResultadoConsulta->setWindowTitle(QApplication::translate("DialogoResultadoConsulta", "DialogoResultadoConsulta", Q_NULLPTR));
        lbl_sin_valores_1->setText(QApplication::translate("DialogoResultadoConsulta", "sin valores", Q_NULLPTR));
        analisis->setTabText(analisis->indexOf(pestania_1), QApplication::translate("DialogoResultadoConsulta", "Fuerza en noticia", Q_NULLPTR));
        lbl_sin_valores_2->setText(QApplication::translate("DialogoResultadoConsulta", "sin valores", Q_NULLPTR));
        analisis->setTabText(analisis->indexOf(pestania_2), QApplication::translate("DialogoResultadoConsulta", "Sentimiento", Q_NULLPTR));
        lbl_sin_valores_3->setText(QApplication::translate("DialogoResultadoConsulta", "sin valores", Q_NULLPTR));
        analisis->setTabText(analisis->indexOf(pestania_3), QApplication::translate("DialogoResultadoConsulta", "Tendencias", Q_NULLPTR));
        btn_exportar_fecha_actual->setText(QApplication::translate("DialogoResultadoConsulta", "Exportar fecha actual", Q_NULLPTR));
        btn_exportar_todo->setText(QApplication::translate("DialogoResultadoConsulta", "Exportar todo", Q_NULLPTR));
        btn_exportar_rango->setText(QApplication::translate("DialogoResultadoConsulta", "Exportar rango", Q_NULLPTR));
        lbl_desde->setText(QApplication::translate("DialogoResultadoConsulta", "desde", Q_NULLPTR));
        lbl_hasta->setText(QApplication::translate("DialogoResultadoConsulta", "hasta", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoResultadoConsulta: public Ui_DialogoResultadoConsulta {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGORESULTADOCONSULTA_H
