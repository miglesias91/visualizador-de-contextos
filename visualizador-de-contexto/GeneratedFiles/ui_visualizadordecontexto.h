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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
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
    QAction *action_deshabilitar_menu;
    QAction *action_habilitar_menu;
    QAction *action_abrir_medios_facebook;
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
    QPushButton *btn_medios_facebook;
    QFrame *linea_separadora;
    QPushButton *btn_consulta;
    QPushButton *btn_analizar_ctx;
    QProgressBar *bar_analizar_ctx;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *visualizadordecontextoClass)
    {
        if (visualizadordecontextoClass->objectName().isEmpty())
            visualizadordecontextoClass->setObjectName(QStringLiteral("visualizadordecontextoClass"));
        visualizadordecontextoClass->resize(478, 481);
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
        action_deshabilitar_menu = new QAction(visualizadordecontextoClass);
        action_deshabilitar_menu->setObjectName(QStringLiteral("action_deshabilitar_menu"));
        action_deshabilitar_menu->setCheckable(true);
        action_habilitar_menu = new QAction(visualizadordecontextoClass);
        action_habilitar_menu->setObjectName(QStringLiteral("action_habilitar_menu"));
        action_habilitar_menu->setCheckable(true);
        action_abrir_medios_facebook = new QAction(visualizadordecontextoClass);
        action_abrir_medios_facebook->setObjectName(QStringLiteral("action_abrir_medios_facebook"));
        action_abrir_medios_facebook->setCheckable(true);
        centralWidget = new QWidget(visualizadordecontextoClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(100, 10, 281, 415));
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
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(28);
        font.setBold(true);
        font.setItalic(true);
        font.setWeight(75);
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
        font1.setPointSize(12);
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

        btn_medios_facebook = new QPushButton(verticalLayoutWidget);
        btn_medios_facebook->setObjectName(QStringLiteral("btn_medios_facebook"));
        btn_medios_facebook->setFont(font1);

        layout_entidades->addWidget(btn_medios_facebook);

        linea_separadora = new QFrame(verticalLayoutWidget);
        linea_separadora->setObjectName(QStringLiteral("linea_separadora"));
        linea_separadora->setLineWidth(4);
        linea_separadora->setFrameShape(QFrame::HLine);
        linea_separadora->setFrameShadow(QFrame::Sunken);

        layout_entidades->addWidget(linea_separadora);


        layout_opciones->addLayout(layout_entidades);

        btn_consulta = new QPushButton(verticalLayoutWidget);
        btn_consulta->setObjectName(QStringLiteral("btn_consulta"));
        btn_consulta->setEnabled(true);
        btn_consulta->setMinimumSize(QSize(0, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(20);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        btn_consulta->setFont(font2);

        layout_opciones->addWidget(btn_consulta);

        btn_analizar_ctx = new QPushButton(verticalLayoutWidget);
        btn_analizar_ctx->setObjectName(QStringLiteral("btn_analizar_ctx"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_analizar_ctx->sizePolicy().hasHeightForWidth());
        btn_analizar_ctx->setSizePolicy(sizePolicy);
        btn_analizar_ctx->setMinimumSize(QSize(0, 40));
        btn_analizar_ctx->setSizeIncrement(QSize(0, 0));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        font3.setPointSize(20);
        font3.setBold(false);
        font3.setItalic(true);
        font3.setUnderline(false);
        font3.setWeight(50);
        font3.setStrikeOut(false);
        font3.setKerning(true);
        font3.setStyleStrategy(QFont::PreferAntialias);
        btn_analizar_ctx->setFont(font3);

        layout_opciones->addWidget(btn_analizar_ctx);

        bar_analizar_ctx = new QProgressBar(centralWidget);
        bar_analizar_ctx->setObjectName(QStringLiteral("bar_analizar_ctx"));
        bar_analizar_ctx->setEnabled(false);
        bar_analizar_ctx->setGeometry(QRect(100, 425, 281, 10));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(bar_analizar_ctx->sizePolicy().hasHeightForWidth());
        bar_analizar_ctx->setSizePolicy(sizePolicy1);
        bar_analizar_ctx->setMinimumSize(QSize(0, 4));
        QFont font4;
        font4.setFamily(QStringLiteral("Calibri"));
        bar_analizar_ctx->setFont(font4);
        bar_analizar_ctx->setValue(0);
        bar_analizar_ctx->setTextVisible(false);
        bar_analizar_ctx->setInvertedAppearance(false);
        visualizadordecontextoClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(visualizadordecontextoClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        statusBar->setEnabled(true);
        visualizadordecontextoClass->setStatusBar(statusBar);

        retranslateUi(visualizadordecontextoClass);
        QObject::connect(btn_terminos, SIGNAL(released()), action_abrir_terminos, SLOT(trigger()));
        QObject::connect(btn_conceptos, SIGNAL(released()), action_abrir_conceptos, SLOT(trigger()));
        QObject::connect(btn_fechas, SIGNAL(released()), action_abrir_fechas, SLOT(trigger()));
        QObject::connect(btn_periodos, SIGNAL(released()), action_abrir_periodos, SLOT(trigger()));
        QObject::connect(btn_consulta, SIGNAL(released()), action_abrir_consulta, SLOT(trigger()));
        QObject::connect(btn_medios_twitter, SIGNAL(released()), action_abrir_medios_twitter, SLOT(trigger()));
        QObject::connect(btn_analizar_ctx, SIGNAL(released()), action_analizar_ctx, SLOT(trigger()));
        QObject::connect(btn_medios_facebook, SIGNAL(released()), action_abrir_medios_facebook, SLOT(trigger()));

        QMetaObject::connectSlotsByName(visualizadordecontextoClass);
    } // setupUi

    void retranslateUi(QMainWindow *visualizadordecontextoClass)
    {
        visualizadordecontextoClass->setWindowTitle(QApplication::translate("visualizadordecontextoClass", "Visualizador de contexto", Q_NULLPTR));
        action_abrir_terminos->setText(QApplication::translate("visualizadordecontextoClass", "T\303\251rminos", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_abrir_terminos->setToolTip(QApplication::translate("visualizadordecontextoClass", "Abrir terminos", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_abrir_terminos->setShortcut(QApplication::translate("visualizadordecontextoClass", "Ctrl+T", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_abrir_conceptos->setText(QApplication::translate("visualizadordecontextoClass", "Conceptos", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_abrir_conceptos->setToolTip(QApplication::translate("visualizadordecontextoClass", "Abrir conceptos", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_abrir_conceptos->setShortcut(QApplication::translate("visualizadordecontextoClass", "Ctrl+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_abrir_fechas->setText(QApplication::translate("visualizadordecontextoClass", "Fechas", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_abrir_fechas->setToolTip(QApplication::translate("visualizadordecontextoClass", "Abrir fechas", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_abrir_fechas->setShortcut(QApplication::translate("visualizadordecontextoClass", "Ctrl+F", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_abrir_periodos->setText(QApplication::translate("visualizadordecontextoClass", "Peri\303\255odos", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_abrir_periodos->setToolTip(QApplication::translate("visualizadordecontextoClass", "Abrir periodos", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_abrir_periodos->setShortcut(QApplication::translate("visualizadordecontextoClass", "Ctrl+P", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_abrir_consulta->setText(QApplication::translate("visualizadordecontextoClass", "Consulta", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_abrir_consulta->setToolTip(QApplication::translate("visualizadordecontextoClass", "Realizar consulta", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_abrir_consulta->setShortcut(QApplication::translate("visualizadordecontextoClass", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_abrir_medios_twitter->setText(QApplication::translate("visualizadordecontextoClass", "Cuentas de Twitter", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_abrir_medios_twitter->setToolTip(QApplication::translate("visualizadordecontextoClass", "Abrir cuentas de Twitter", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_abrir_medios_twitter->setShortcut(QApplication::translate("visualizadordecontextoClass", "Ctrl+W", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_analizar_ctx->setText(QApplication::translate("visualizadordecontextoClass", "Analizar contexto", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_analizar_ctx->setToolTip(QApplication::translate("visualizadordecontextoClass", "Iniciar an\303\241lisis de contexto", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_deshabilitar_menu->setText(QApplication::translate("visualizadordecontextoClass", "deshabilitar menu", Q_NULLPTR));
        action_habilitar_menu->setText(QApplication::translate("visualizadordecontextoClass", "habilitar menu", Q_NULLPTR));
        action_abrir_medios_facebook->setText(QApplication::translate("visualizadordecontextoClass", "P\303\241ginas de Facebook", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_abrir_medios_facebook->setToolTip(QApplication::translate("visualizadordecontextoClass", "Abrir paginas de Facebook", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lbl_titulo->setText(QApplication::translate("visualizadordecontextoClass", "<html><head/><body><p align=\"center\"><span style=\" color:#2e3343;\">Visualizador</span></p><p align=\"center\"><span style=\" color:#2e3343;\">de contexto</span></p></body></html>", Q_NULLPTR));
        btn_terminos->setText(QApplication::translate("visualizadordecontextoClass", "T\303\251rminos", Q_NULLPTR));
        btn_conceptos->setText(QApplication::translate("visualizadordecontextoClass", "Conceptos", Q_NULLPTR));
        btn_fechas->setText(QApplication::translate("visualizadordecontextoClass", "Fechas", Q_NULLPTR));
        btn_periodos->setText(QApplication::translate("visualizadordecontextoClass", "Per\303\255odos", Q_NULLPTR));
        btn_medios_twitter->setText(QApplication::translate("visualizadordecontextoClass", "Cuentas de Twitter", Q_NULLPTR));
        btn_medios_facebook->setText(QApplication::translate("visualizadordecontextoClass", "P\303\241ginas de Facebook", Q_NULLPTR));
        btn_consulta->setText(QApplication::translate("visualizadordecontextoClass", "Realizar consulta", Q_NULLPTR));
        btn_analizar_ctx->setText(QApplication::translate("visualizadordecontextoClass", "Analizar contexto", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class visualizadordecontextoClass: public Ui_visualizadordecontextoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZADORDECONTEXTO_H
