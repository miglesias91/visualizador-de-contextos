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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_visualizadordecontextoClass
{
public:
    QWidget *widget_central;
    QVBoxLayout *verticalLayout;
    QWidget *widget_opciones;
    QHBoxLayout *layout_opciones;
    QWidget *widget_entidades;
    QHBoxLayout *layout_fila_entidades;
    QPushButton *btn_medios_facebook;
    QPushButton *btn_medios_twitter;
    QPushButton *btn_periodos;
    QPushButton *btn_fechas;
    QPushButton *btn_conceptos;
    QPushButton *btn_terminos;
    QFrame *linea_divisora_opciones;
    QWidget *widget_acciones;
    QHBoxLayout *layout_acciones;
    QPushButton *btn_consulta;
    QFrame *line_2;
    QPushButton *btn_analizar_ctx;
    QProgressBar *bar_analizar_ctx;
    QFrame *line;
    QWidget *widget_area_trabajo;
    QVBoxLayout *layout_area_trabajo;
    QVBoxLayout *layout_ventana_abierta;

    void setupUi(QMainWindow *visualizadordecontextoClass)
    {
        if (visualizadordecontextoClass->objectName().isEmpty())
            visualizadordecontextoClass->setObjectName(QStringLiteral("visualizadordecontextoClass"));
        visualizadordecontextoClass->resize(952, 400);
        visualizadordecontextoClass->setStyleSheet(QStringLiteral(""));
        visualizadordecontextoClass->setDocumentMode(false);
        visualizadordecontextoClass->setUnifiedTitleAndToolBarOnMac(false);
        widget_central = new QWidget(visualizadordecontextoClass);
        widget_central->setObjectName(QStringLiteral("widget_central"));
        verticalLayout = new QVBoxLayout(widget_central);
        verticalLayout->setSpacing(1);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(5, 0, 5, 0);
        widget_opciones = new QWidget(widget_central);
        widget_opciones->setObjectName(QStringLiteral("widget_opciones"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_opciones->sizePolicy().hasHeightForWidth());
        widget_opciones->setSizePolicy(sizePolicy);
        widget_opciones->setStyleSheet(QLatin1String("QPushButton {\n"
"	background-color: rgba(255, 255, 255, 0);\n"
"	border: 3px solid transparent;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: rgb(247, 247, 247);\n"
"}"));
        layout_opciones = new QHBoxLayout(widget_opciones);
        layout_opciones->setSpacing(3);
        layout_opciones->setContentsMargins(11, 11, 11, 11);
        layout_opciones->setObjectName(QStringLiteral("layout_opciones"));
        layout_opciones->setContentsMargins(0, 0, 0, 0);
        widget_entidades = new QWidget(widget_opciones);
        widget_entidades->setObjectName(QStringLiteral("widget_entidades"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget_entidades->sizePolicy().hasHeightForWidth());
        widget_entidades->setSizePolicy(sizePolicy1);
        layout_fila_entidades = new QHBoxLayout(widget_entidades);
        layout_fila_entidades->setSpacing(5);
        layout_fila_entidades->setContentsMargins(11, 11, 11, 11);
        layout_fila_entidades->setObjectName(QStringLiteral("layout_fila_entidades"));
        layout_fila_entidades->setContentsMargins(0, 0, 0, 0);
        btn_medios_facebook = new QPushButton(widget_entidades);
        btn_medios_facebook->setObjectName(QStringLiteral("btn_medios_facebook"));
        btn_medios_facebook->setMinimumSize(QSize(80, 0));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(10);
        btn_medios_facebook->setFont(font);
        btn_medios_facebook->setAutoFillBackground(false);
        btn_medios_facebook->setStyleSheet(QStringLiteral(""));
        btn_medios_facebook->setCheckable(false);
        btn_medios_facebook->setChecked(false);
        btn_medios_facebook->setAutoRepeat(false);
        btn_medios_facebook->setAutoExclusive(false);
        btn_medios_facebook->setAutoDefault(false);
        btn_medios_facebook->setFlat(false);

        layout_fila_entidades->addWidget(btn_medios_facebook);

        btn_medios_twitter = new QPushButton(widget_entidades);
        btn_medios_twitter->setObjectName(QStringLiteral("btn_medios_twitter"));
        btn_medios_twitter->setMinimumSize(QSize(0, 0));
        btn_medios_twitter->setFont(font);
        btn_medios_twitter->setStyleSheet(QStringLiteral(""));
        btn_medios_twitter->setAutoDefault(false);
        btn_medios_twitter->setFlat(false);

        layout_fila_entidades->addWidget(btn_medios_twitter);

        btn_periodos = new QPushButton(widget_entidades);
        btn_periodos->setObjectName(QStringLiteral("btn_periodos"));
        btn_periodos->setFont(font);
        btn_periodos->setStyleSheet(QStringLiteral(""));
        btn_periodos->setFlat(true);

        layout_fila_entidades->addWidget(btn_periodos);

        btn_fechas = new QPushButton(widget_entidades);
        btn_fechas->setObjectName(QStringLiteral("btn_fechas"));
        btn_fechas->setFont(font);
        btn_fechas->setStyleSheet(QStringLiteral(""));
        btn_fechas->setFlat(true);

        layout_fila_entidades->addWidget(btn_fechas);

        btn_conceptos = new QPushButton(widget_entidades);
        btn_conceptos->setObjectName(QStringLiteral("btn_conceptos"));
        btn_conceptos->setFont(font);
        btn_conceptos->setStyleSheet(QStringLiteral(""));
        btn_conceptos->setFlat(true);

        layout_fila_entidades->addWidget(btn_conceptos);

        btn_terminos = new QPushButton(widget_entidades);
        btn_terminos->setObjectName(QStringLiteral("btn_terminos"));
        btn_terminos->setFont(font);
        btn_terminos->setStyleSheet(QStringLiteral(""));
        btn_terminos->setFlat(true);

        layout_fila_entidades->addWidget(btn_terminos);


        layout_opciones->addWidget(widget_entidades);

        linea_divisora_opciones = new QFrame(widget_opciones);
        linea_divisora_opciones->setObjectName(QStringLiteral("linea_divisora_opciones"));
        linea_divisora_opciones->setFrameShape(QFrame::VLine);
        linea_divisora_opciones->setFrameShadow(QFrame::Sunken);

        layout_opciones->addWidget(linea_divisora_opciones);

        widget_acciones = new QWidget(widget_opciones);
        widget_acciones->setObjectName(QStringLiteral("widget_acciones"));
        layout_acciones = new QHBoxLayout(widget_acciones);
        layout_acciones->setSpacing(2);
        layout_acciones->setContentsMargins(11, 11, 11, 11);
        layout_acciones->setObjectName(QStringLiteral("layout_acciones"));
        layout_acciones->setContentsMargins(0, 0, 0, 0);
        btn_consulta = new QPushButton(widget_acciones);
        btn_consulta->setObjectName(QStringLiteral("btn_consulta"));
        btn_consulta->setEnabled(true);
        btn_consulta->setMinimumSize(QSize(130, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setWeight(50);
        btn_consulta->setFont(font1);
        btn_consulta->setStyleSheet(QStringLiteral(""));
        btn_consulta->setFlat(true);

        layout_acciones->addWidget(btn_consulta);

        line_2 = new QFrame(widget_acciones);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);

        layout_acciones->addWidget(line_2);

        btn_analizar_ctx = new QPushButton(widget_acciones);
        btn_analizar_ctx->setObjectName(QStringLiteral("btn_analizar_ctx"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_analizar_ctx->sizePolicy().hasHeightForWidth());
        btn_analizar_ctx->setSizePolicy(sizePolicy2);
        btn_analizar_ctx->setMinimumSize(QSize(130, 0));
        btn_analizar_ctx->setSizeIncrement(QSize(0, 0));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setItalic(false);
        font2.setUnderline(false);
        font2.setWeight(50);
        font2.setStrikeOut(false);
        font2.setKerning(true);
        font2.setStyleStrategy(QFont::PreferAntialias);
        btn_analizar_ctx->setFont(font2);
        btn_analizar_ctx->setStyleSheet(QStringLiteral(""));
        btn_analizar_ctx->setAutoExclusive(false);
        btn_analizar_ctx->setFlat(true);

        layout_acciones->addWidget(btn_analizar_ctx);

        bar_analizar_ctx = new QProgressBar(widget_acciones);
        bar_analizar_ctx->setObjectName(QStringLiteral("bar_analizar_ctx"));
        bar_analizar_ctx->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(bar_analizar_ctx->sizePolicy().hasHeightForWidth());
        bar_analizar_ctx->setSizePolicy(sizePolicy3);
        bar_analizar_ctx->setMinimumSize(QSize(0, 0));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        bar_analizar_ctx->setFont(font3);
        bar_analizar_ctx->setValue(0);
        bar_analizar_ctx->setTextVisible(false);
        bar_analizar_ctx->setInvertedAppearance(false);

        layout_acciones->addWidget(bar_analizar_ctx);


        layout_opciones->addWidget(widget_acciones);


        verticalLayout->addWidget(widget_opciones, 0, Qt::AlignLeft);

        line = new QFrame(widget_central);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        widget_area_trabajo = new QWidget(widget_central);
        widget_area_trabajo->setObjectName(QStringLiteral("widget_area_trabajo"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget_area_trabajo->sizePolicy().hasHeightForWidth());
        widget_area_trabajo->setSizePolicy(sizePolicy4);
        widget_area_trabajo->setAutoFillBackground(false);
        layout_area_trabajo = new QVBoxLayout(widget_area_trabajo);
        layout_area_trabajo->setSpacing(0);
        layout_area_trabajo->setContentsMargins(11, 11, 11, 11);
        layout_area_trabajo->setObjectName(QStringLiteral("layout_area_trabajo"));
        layout_area_trabajo->setContentsMargins(2, 2, 2, 2);
        layout_ventana_abierta = new QVBoxLayout();
        layout_ventana_abierta->setSpacing(6);
        layout_ventana_abierta->setObjectName(QStringLiteral("layout_ventana_abierta"));

        layout_area_trabajo->addLayout(layout_ventana_abierta);


        verticalLayout->addWidget(widget_area_trabajo);

        visualizadordecontextoClass->setCentralWidget(widget_central);

        retranslateUi(visualizadordecontextoClass);

        btn_medios_facebook->setDefault(false);
        btn_medios_twitter->setDefault(false);
        btn_periodos->setDefault(true);


        QMetaObject::connectSlotsByName(visualizadordecontextoClass);
    } // setupUi

    void retranslateUi(QMainWindow *visualizadordecontextoClass)
    {
        visualizadordecontextoClass->setWindowTitle(QApplication::translate("visualizadordecontextoClass", "Visualizador de contexto", Q_NULLPTR));
        btn_medios_facebook->setText(QApplication::translate("visualizadordecontextoClass", "P\303\241ginas de Facebook", Q_NULLPTR));
        btn_medios_twitter->setText(QApplication::translate("visualizadordecontextoClass", "Cuentas de Twitter", Q_NULLPTR));
        btn_periodos->setText(QApplication::translate("visualizadordecontextoClass", "Per\303\255odos", Q_NULLPTR));
        btn_fechas->setText(QApplication::translate("visualizadordecontextoClass", "Fechas", Q_NULLPTR));
        btn_conceptos->setText(QApplication::translate("visualizadordecontextoClass", "Conceptos", Q_NULLPTR));
        btn_terminos->setText(QApplication::translate("visualizadordecontextoClass", "T\303\251rminos", Q_NULLPTR));
        btn_consulta->setText(QApplication::translate("visualizadordecontextoClass", "Realizar consulta", Q_NULLPTR));
        btn_analizar_ctx->setText(QApplication::translate("visualizadordecontextoClass", "Analizar contexto", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class visualizadordecontextoClass: public Ui_visualizadordecontextoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZADORDECONTEXTO_H
