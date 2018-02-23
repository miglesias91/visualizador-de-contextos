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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_visualizadordecontextoClass
{
public:
    QAction *action_abrir_terminos;
    QAction *action_abrir_conceptos;
    QAction *action_abrir_fechas;
    QAction *action_abrir_periodos;
    QAction *action_abrir_consulta;
    QAction *action_abrir_medios_twitter;
    QAction *action_analizar_ctx;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layout_opciones;
    QVBoxLayout *layout_entidades;
    QLabel *lbl_titulo;
    QPushButton *btn_terminos;
    QPushButton *btn_conceptos;
    QPushButton *btn_fechas;
    QPushButton *btn_periodos;
    QPushButton *btn_medios_twitter;
    QPushButton *btn_consulta;
    QPushButton *btn_analizar_ctx;
    QProgressBar *bar_analizar_ctx;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *visualizadordecontextoClass)
    {
        if (visualizadordecontextoClass->objectName().isEmpty())
            visualizadordecontextoClass->setObjectName(QStringLiteral("visualizadordecontextoClass"));
        visualizadordecontextoClass->resize(581, 433);
        action_abrir_terminos = new QAction(visualizadordecontextoClass);
        action_abrir_terminos->setObjectName(QStringLiteral("action_abrir_terminos"));
        action_abrir_terminos->setCheckable(true);
        action_abrir_conceptos = new QAction(visualizadordecontextoClass);
        action_abrir_conceptos->setObjectName(QStringLiteral("action_abrir_conceptos"));
        action_abrir_conceptos->setCheckable(true);
        action_abrir_fechas = new QAction(visualizadordecontextoClass);
        action_abrir_fechas->setObjectName(QStringLiteral("action_abrir_fechas"));
        action_abrir_fechas->setCheckable(true);
        action_abrir_periodos = new QAction(visualizadordecontextoClass);
        action_abrir_periodos->setObjectName(QStringLiteral("action_abrir_periodos"));
        action_abrir_periodos->setCheckable(true);
        action_abrir_consulta = new QAction(visualizadordecontextoClass);
        action_abrir_consulta->setObjectName(QStringLiteral("action_abrir_consulta"));
        action_abrir_consulta->setCheckable(true);
        action_abrir_medios_twitter = new QAction(visualizadordecontextoClass);
        action_abrir_medios_twitter->setObjectName(QStringLiteral("action_abrir_medios_twitter"));
        action_abrir_medios_twitter->setCheckable(true);
        action_analizar_ctx = new QAction(visualizadordecontextoClass);
        action_analizar_ctx->setObjectName(QStringLiteral("action_analizar_ctx"));
        action_analizar_ctx->setCheckable(true);
        centralWidget = new QWidget(visualizadordecontextoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(160, 10, 281, 361));
        layout_opciones = new QVBoxLayout(verticalLayoutWidget);
        layout_opciones->setSpacing(6);
        layout_opciones->setContentsMargins(11, 11, 11, 11);
        layout_opciones->setObjectName(QStringLiteral("layout_opciones"));
        layout_opciones->setContentsMargins(0, 0, 0, 0);
        layout_entidades = new QVBoxLayout();
        layout_entidades->setSpacing(6);
        layout_entidades->setObjectName(QStringLiteral("layout_entidades"));
        lbl_titulo = new QLabel(verticalLayoutWidget);
        lbl_titulo->setObjectName(QStringLiteral("lbl_titulo"));
        QFont font;
        font.setFamily(QStringLiteral("Adobe Heiti Std R"));
        font.setPointSize(8);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        font.setStyleStrategy(QFont::PreferAntialias);
        lbl_titulo->setFont(font);
        lbl_titulo->setFrameShape(QFrame::NoFrame);
        lbl_titulo->setFrameShadow(QFrame::Plain);
        lbl_titulo->setLineWidth(2);
        lbl_titulo->setMidLineWidth(8);
        lbl_titulo->setTextFormat(Qt::RichText);
        lbl_titulo->setScaledContents(false);
        lbl_titulo->setAlignment(Qt::AlignCenter);
        lbl_titulo->setWordWrap(false);
        lbl_titulo->setMargin(0);

        layout_entidades->addWidget(lbl_titulo);

        btn_terminos = new QPushButton(verticalLayoutWidget);
        btn_terminos->setObjectName(QStringLiteral("btn_terminos"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(10);
        btn_terminos->setFont(font1);

        layout_entidades->addWidget(btn_terminos);

        btn_conceptos = new QPushButton(verticalLayoutWidget);
        btn_conceptos->setObjectName(QStringLiteral("btn_conceptos"));
        btn_conceptos->setFont(font1);

        layout_entidades->addWidget(btn_conceptos);

        btn_fechas = new QPushButton(verticalLayoutWidget);
        btn_fechas->setObjectName(QStringLiteral("btn_fechas"));
        btn_fechas->setFont(font1);

        layout_entidades->addWidget(btn_fechas);

        btn_periodos = new QPushButton(verticalLayoutWidget);
        btn_periodos->setObjectName(QStringLiteral("btn_periodos"));
        btn_periodos->setFont(font1);

        layout_entidades->addWidget(btn_periodos);

        btn_medios_twitter = new QPushButton(verticalLayoutWidget);
        btn_medios_twitter->setObjectName(QStringLiteral("btn_medios_twitter"));
        btn_medios_twitter->setFont(font1);

        layout_entidades->addWidget(btn_medios_twitter);

        btn_consulta = new QPushButton(verticalLayoutWidget);
        btn_consulta->setObjectName(QStringLiteral("btn_consulta"));
        btn_consulta->setEnabled(true);
        btn_consulta->setFont(font1);

        layout_entidades->addWidget(btn_consulta);


        layout_opciones->addLayout(layout_entidades);

        btn_analizar_ctx = new QPushButton(verticalLayoutWidget);
        btn_analizar_ctx->setObjectName(QStringLiteral("btn_analizar_ctx"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_analizar_ctx->sizePolicy().hasHeightForWidth());
        btn_analizar_ctx->setSizePolicy(sizePolicy);
        btn_analizar_ctx->setMinimumSize(QSize(0, 40));
        btn_analizar_ctx->setSizeIncrement(QSize(0, 0));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(50);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferAntialias);
        btn_analizar_ctx->setFont(font2);

        layout_opciones->addWidget(btn_analizar_ctx);

        bar_analizar_ctx = new QProgressBar(verticalLayoutWidget);
        bar_analizar_ctx->setObjectName(QStringLiteral("bar_analizar_ctx"));
        bar_analizar_ctx->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bar_analizar_ctx->sizePolicy().hasHeightForWidth());
        bar_analizar_ctx->setSizePolicy(sizePolicy1);
        bar_analizar_ctx->setMinimumSize(QSize(0, 4));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        bar_analizar_ctx->setFont(font3);
        bar_analizar_ctx->setValue(0);
        bar_analizar_ctx->setTextVisible(false);
        bar_analizar_ctx->setInvertedAppearance(false);

        layout_opciones->addWidget(bar_analizar_ctx);

        visualizadordecontextoClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(visualizadordecontextoClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 581, 21));
        visualizadordecontextoClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(visualizadordecontextoClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        visualizadordecontextoClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(visualizadordecontextoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        visualizadordecontextoClass->setStatusBar(statusBar);

        retranslateUi(visualizadordecontextoClass);
        QObject::connect(btn_terminos, SIGNAL(released()), action_abrir_terminos, SLOT(trigger()));
        QObject::connect(btn_conceptos, SIGNAL(released()), action_abrir_conceptos, SLOT(trigger()));
        QObject::connect(btn_fechas, SIGNAL(released()), action_abrir_fechas, SLOT(trigger()));
        QObject::connect(btn_periodos, SIGNAL(released()), action_abrir_periodos, SLOT(trigger()));
        QObject::connect(btn_consulta, SIGNAL(released()), action_abrir_consulta, SLOT(trigger()));
        QObject::connect(btn_medios_twitter, SIGNAL(released()), action_abrir_medios_twitter, SLOT(trigger()));
        QObject::connect(btn_analizar_ctx, SIGNAL(released()), action_analizar_ctx, SLOT(trigger()));

        QMetaObject::connectSlotsByName(visualizadordecontextoClass);
    } // setupUi

    void retranslateUi(QMainWindow *visualizadordecontextoClass)
    {
        visualizadordecontextoClass->setWindowTitle(QApplication::translate("visualizadordecontextoClass", "visualizadordecontexto", Q_NULLPTR));
        action_abrir_terminos->setText(QApplication::translate("visualizadordecontextoClass", "abrir_terminos", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_abrir_terminos->setToolTip(QApplication::translate("visualizadordecontextoClass", "abrir terminos", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_abrir_terminos->setShortcut(QApplication::translate("visualizadordecontextoClass", "Ctrl+T", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_abrir_conceptos->setText(QApplication::translate("visualizadordecontextoClass", "abrir_conceptos", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_abrir_conceptos->setToolTip(QApplication::translate("visualizadordecontextoClass", "abrir conceptos", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_abrir_conceptos->setShortcut(QApplication::translate("visualizadordecontextoClass", "Ctrl+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_abrir_fechas->setText(QApplication::translate("visualizadordecontextoClass", "abrir_fechas", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_abrir_fechas->setShortcut(QApplication::translate("visualizadordecontextoClass", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_abrir_periodos->setText(QApplication::translate("visualizadordecontextoClass", "abrir_periodos", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_abrir_periodos->setShortcut(QApplication::translate("visualizadordecontextoClass", "Ctrl+P", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_abrir_consulta->setText(QApplication::translate("visualizadordecontextoClass", "abrir_consulta", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_abrir_consulta->setShortcut(QApplication::translate("visualizadordecontextoClass", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_abrir_medios_twitter->setText(QApplication::translate("visualizadordecontextoClass", "abrir_medios_twitter", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        action_abrir_medios_twitter->setShortcut(QApplication::translate("visualizadordecontextoClass", "Ctrl+W", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_analizar_ctx->setText(QApplication::translate("visualizadordecontextoClass", "analizar_ctx", Q_NULLPTR));
        lbl_titulo->setText(QApplication::translate("visualizadordecontextoClass", "<html><head/><body><p align=\"center\"><span style=\" font-size:28pt; color:#2e3343;\">Visualizador</span></p><p align=\"center\"><span style=\" font-size:28pt; color:#2e3343;\">de contexto</span></p></body></html>", Q_NULLPTR));
        btn_terminos->setText(QApplication::translate("visualizadordecontextoClass", "terminos", Q_NULLPTR));
        btn_conceptos->setText(QApplication::translate("visualizadordecontextoClass", "conceptos", Q_NULLPTR));
        btn_fechas->setText(QApplication::translate("visualizadordecontextoClass", "fechas", Q_NULLPTR));
        btn_periodos->setText(QApplication::translate("visualizadordecontextoClass", "periodos", Q_NULLPTR));
        btn_medios_twitter->setText(QApplication::translate("visualizadordecontextoClass", "cuentas de twitter", Q_NULLPTR));
        btn_consulta->setText(QApplication::translate("visualizadordecontextoClass", "consulta", Q_NULLPTR));
        btn_analizar_ctx->setText(QApplication::translate("visualizadordecontextoClass", "analizar contexto", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class visualizadordecontextoClass: public Ui_visualizadordecontextoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZADORDECONTEXTO_H
