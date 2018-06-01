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
    QPushButton *btn_analizar_ctx;
    QPushButton *btn_consulta;
    QFrame *line;
    QWidget *widget_area_trabajo;
    QVBoxLayout *layout_area_trabajo;
    QVBoxLayout *layout_ventana_abierta;
    QProgressBar *bar_analizar_ctx;

    void setupUi(QMainWindow *visualizadordecontextoClass)
    {
        if (visualizadordecontextoClass->objectName().isEmpty())
            visualizadordecontextoClass->setObjectName(QStringLiteral("visualizadordecontextoClass"));
        visualizadordecontextoClass->resize(882, 449);
        visualizadordecontextoClass->setDocumentMode(false);
        visualizadordecontextoClass->setUnifiedTitleAndToolBarOnMac(false);
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
        layout_fila_entidades->setSpacing(2);
        layout_fila_entidades->setContentsMargins(11, 11, 11, 11);
        layout_fila_entidades->setObjectName(QStringLiteral("layout_fila_entidades"));
        layout_fila_entidades->setContentsMargins(0, 0, 0, 0);
        btn_medios_facebook = new QPushButton(widget_entidades);
        btn_medios_facebook->setObjectName(QStringLiteral("btn_medios_facebook"));
        btn_medios_facebook->setMinimumSize(QSize(150, 0));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        btn_medios_facebook->setFont(font);
        btn_medios_facebook->setFlat(false);

        layout_fila_entidades->addWidget(btn_medios_facebook);

        btn_medios_twitter = new QPushButton(widget_entidades);
        btn_medios_twitter->setObjectName(QStringLiteral("btn_medios_twitter"));
        btn_medios_twitter->setMinimumSize(QSize(140, 0));
        btn_medios_twitter->setFont(font);

        layout_fila_entidades->addWidget(btn_medios_twitter);

        btn_periodos = new QPushButton(widget_entidades);
        btn_periodos->setObjectName(QStringLiteral("btn_periodos"));
        btn_periodos->setFont(font);

        layout_fila_entidades->addWidget(btn_periodos);

        btn_fechas = new QPushButton(widget_entidades);
        btn_fechas->setObjectName(QStringLiteral("btn_fechas"));
        btn_fechas->setFont(font);

        layout_fila_entidades->addWidget(btn_fechas);

        btn_conceptos = new QPushButton(widget_entidades);
        btn_conceptos->setObjectName(QStringLiteral("btn_conceptos"));
        btn_conceptos->setFont(font);

        layout_fila_entidades->addWidget(btn_conceptos);

        btn_terminos = new QPushButton(widget_entidades);
        btn_terminos->setObjectName(QStringLiteral("btn_terminos"));
        btn_terminos->setFont(font);

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
        btn_analizar_ctx = new QPushButton(widget_acciones);
        btn_analizar_ctx->setObjectName(QStringLiteral("btn_analizar_ctx"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(btn_analizar_ctx->sizePolicy().hasHeightForWidth());
        btn_analizar_ctx->setSizePolicy(sizePolicy2);
        btn_analizar_ctx->setMinimumSize(QSize(130, 30));
        btn_analizar_ctx->setSizeIncrement(QSize(0, 0));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(12);
        font1.setBold(false);
        font1.setItalic(true);
        font1.setUnderline(false);
        font1.setWeight(50);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        font1.setStyleStrategy(QFont::PreferAntialias);
        btn_analizar_ctx->setFont(font1);

        layout_acciones->addWidget(btn_analizar_ctx);

        btn_consulta = new QPushButton(widget_acciones);
        btn_consulta->setObjectName(QStringLiteral("btn_consulta"));
        btn_consulta->setEnabled(true);
        btn_consulta->setMinimumSize(QSize(130, 30));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setItalic(true);
        font2.setWeight(50);
        btn_consulta->setFont(font2);

        layout_acciones->addWidget(btn_consulta);


        layout_opciones->addWidget(widget_acciones);


        verticalLayout->addWidget(widget_opciones, 0, Qt::AlignLeft);

        line = new QFrame(widget_central);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        widget_area_trabajo = new QWidget(widget_central);
        widget_area_trabajo->setObjectName(QStringLiteral("widget_area_trabajo"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget_area_trabajo->sizePolicy().hasHeightForWidth());
        widget_area_trabajo->setSizePolicy(sizePolicy3);
        layout_area_trabajo = new QVBoxLayout(widget_area_trabajo);
        layout_area_trabajo->setSpacing(0);
        layout_area_trabajo->setContentsMargins(11, 11, 11, 11);
        layout_area_trabajo->setObjectName(QStringLiteral("layout_area_trabajo"));
        layout_ventana_abierta = new QVBoxLayout();
        layout_ventana_abierta->setSpacing(6);
        layout_ventana_abierta->setObjectName(QStringLiteral("layout_ventana_abierta"));

        layout_area_trabajo->addLayout(layout_ventana_abierta);


        verticalLayout->addWidget(widget_area_trabajo);

        bar_analizar_ctx = new QProgressBar(widget_central);
        bar_analizar_ctx->setObjectName(QStringLiteral("bar_analizar_ctx"));
        bar_analizar_ctx->setEnabled(false);
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(bar_analizar_ctx->sizePolicy().hasHeightForWidth());
        bar_analizar_ctx->setSizePolicy(sizePolicy4);
        bar_analizar_ctx->setMinimumSize(QSize(300, 20));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        bar_analizar_ctx->setFont(font3);
        bar_analizar_ctx->setValue(0);
        bar_analizar_ctx->setTextVisible(false);
        bar_analizar_ctx->setInvertedAppearance(false);

        verticalLayout->addWidget(bar_analizar_ctx);

        visualizadordecontextoClass->setCentralWidget(widget_central);

        retranslateUi(visualizadordecontextoClass);

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
        btn_medios_facebook->setText(QApplication::translate("visualizadordecontextoClass", "P\303\241ginas de Facebook", Q_NULLPTR));
        btn_medios_twitter->setText(QApplication::translate("visualizadordecontextoClass", "Cuentas de Twitter", Q_NULLPTR));
        btn_periodos->setText(QApplication::translate("visualizadordecontextoClass", "Per\303\255odos", Q_NULLPTR));
        btn_fechas->setText(QApplication::translate("visualizadordecontextoClass", "Fechas", Q_NULLPTR));
        btn_conceptos->setText(QApplication::translate("visualizadordecontextoClass", "Conceptos", Q_NULLPTR));
        btn_terminos->setText(QApplication::translate("visualizadordecontextoClass", "T\303\251rminos", Q_NULLPTR));
        btn_analizar_ctx->setText(QApplication::translate("visualizadordecontextoClass", "Analizar contexto", Q_NULLPTR));
        btn_consulta->setText(QApplication::translate("visualizadordecontextoClass", "Realizar consulta", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class visualizadordecontextoClass: public Ui_visualizadordecontextoClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISUALIZADORDECONTEXTO_H
