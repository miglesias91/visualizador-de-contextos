/********************************************************************************
** Form generated from reading UI file 'DialogoConsultas.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOCONSULTAS_H
#define UI_DIALOGOCONSULTAS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoConsultas
{
public:
    QAction *action_agregar_conceptos;
    QAction *action_sacar_conceptos;
    QAction *action_setear_periodo;
    QAction *action_agregar_medios;
    QAction *action_agregar_secciones;
    QAction *action_sacar_medios;
    QAction *action_sacar_secciones;
    QAction *action_agregar_reportes;
    QAction *action_sacar_reportes;
    QAction *action_realizar_consulta_y_cerrar;
    QAction *action_resetear_periodo;
    QAction *action_liberar_grafico;
    QVBoxLayout *verticalLayout_14;
    QTabWidget *opciones_consulta;
    QWidget *tab_consulta;
    QVBoxLayout *layout_tab_consulta;
    QWidget *widget_consulta;
    QVBoxLayout *layout_consulta;
    QWidget *widget_periodo;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *cabecera_periodo;
    QLabel *lbl_periodo;
    QWidget *widget_periodo_consulta;
    QHBoxLayout *layout_periodo_consulta;
    QLabel *lbl_desde;
    QDateEdit *dateedit_desde;
    QLabel *lbl_hasta;
    QDateEdit *dateedit_hasta;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta_periodo;
    QFrame *line;
    QWidget *widget_medios;
    QVBoxLayout *layout_medios_consulta;
    QHBoxLayout *cabecera_medios;
    QLabel *lbl_medios;
    QPushButton *btn_sacar_medios;
    QListWidget *lista_medios_en_consulta;
    QFrame *line_2;
    QWidget *widget_reportes;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *cabecera_reportes;
    QCheckBox *checkbox_tendencia;
    QLabel *lbl_mostrar_primeros;
    QSpinBox *spinbox_tendencias;
    QLabel *lbl_ordenar_por;
    QComboBox *combobox_tendencia;
    QFrame *line_3;
    QWidget *widget_conceptos;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *cabecera_conceptos;
    QCheckBox *checkbox_conceptos;
    QPushButton *btn_sacar_conceptos;
    QListWidget *lista_conceptos_en_consulta;
    QSpacerItem *espaciador_consulta;
    QWidget *widget_botones;
    QHBoxLayout *layout_botones;
    QPushButton *btn_realizar_consulta;
    QPushButton *btn_cancelar;
    QWidget *tab_medios;
    QVBoxLayout *verticalLayout_10;
    QWidget *widget_lista_medios;
    QVBoxLayout *layout_lista_medios;
    QHBoxLayout *cabecera_lista_medios;
    QLabel *lbl_lista_de_medios;
    QPushButton *btn_agregar_medios;
    QListWidget *lista_medios;
    QWidget *tab_conceptos;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_lista_conceptos;
    QVBoxLayout *layout_opciones_conceptos;
    QHBoxLayout *cabecera_lista_conceptos;
    QLabel *lbl_lista_de_conceptos;
    QPushButton *btn_agregar_conceptos;
    QListWidget *lista_conceptos;

    void setupUi(QWidget *DialogoConsultas)
    {
        if (DialogoConsultas->objectName().isEmpty())
            DialogoConsultas->setObjectName(QStringLiteral("DialogoConsultas"));
        DialogoConsultas->resize(500, 601);
        DialogoConsultas->setMinimumSize(QSize(500, 0));
        action_agregar_conceptos = new QAction(DialogoConsultas);
        action_agregar_conceptos->setObjectName(QStringLiteral("action_agregar_conceptos"));
        action_sacar_conceptos = new QAction(DialogoConsultas);
        action_sacar_conceptos->setObjectName(QStringLiteral("action_sacar_conceptos"));
        action_setear_periodo = new QAction(DialogoConsultas);
        action_setear_periodo->setObjectName(QStringLiteral("action_setear_periodo"));
        action_agregar_medios = new QAction(DialogoConsultas);
        action_agregar_medios->setObjectName(QStringLiteral("action_agregar_medios"));
        action_agregar_secciones = new QAction(DialogoConsultas);
        action_agregar_secciones->setObjectName(QStringLiteral("action_agregar_secciones"));
        action_sacar_medios = new QAction(DialogoConsultas);
        action_sacar_medios->setObjectName(QStringLiteral("action_sacar_medios"));
        action_sacar_secciones = new QAction(DialogoConsultas);
        action_sacar_secciones->setObjectName(QStringLiteral("action_sacar_secciones"));
        action_agregar_reportes = new QAction(DialogoConsultas);
        action_agregar_reportes->setObjectName(QStringLiteral("action_agregar_reportes"));
        action_sacar_reportes = new QAction(DialogoConsultas);
        action_sacar_reportes->setObjectName(QStringLiteral("action_sacar_reportes"));
        action_realizar_consulta_y_cerrar = new QAction(DialogoConsultas);
        action_realizar_consulta_y_cerrar->setObjectName(QStringLiteral("action_realizar_consulta_y_cerrar"));
        action_resetear_periodo = new QAction(DialogoConsultas);
        action_resetear_periodo->setObjectName(QStringLiteral("action_resetear_periodo"));
        action_liberar_grafico = new QAction(DialogoConsultas);
        action_liberar_grafico->setObjectName(QStringLiteral("action_liberar_grafico"));
        verticalLayout_14 = new QVBoxLayout(DialogoConsultas);
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QStringLiteral("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        opciones_consulta = new QTabWidget(DialogoConsultas);
        opciones_consulta->setObjectName(QStringLiteral("opciones_consulta"));
        opciones_consulta->setEnabled(true);
        opciones_consulta->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(10);
        font.setItalic(false);
        opciones_consulta->setFont(font);
        opciones_consulta->setDocumentMode(true);
        opciones_consulta->setTabsClosable(false);
        opciones_consulta->setMovable(false);
        opciones_consulta->setTabBarAutoHide(false);
        tab_consulta = new QWidget();
        tab_consulta->setObjectName(QStringLiteral("tab_consulta"));
        layout_tab_consulta = new QVBoxLayout(tab_consulta);
        layout_tab_consulta->setSpacing(0);
        layout_tab_consulta->setContentsMargins(11, 11, 11, 11);
        layout_tab_consulta->setObjectName(QStringLiteral("layout_tab_consulta"));
        layout_tab_consulta->setContentsMargins(0, 0, 0, 0);
        widget_consulta = new QWidget(tab_consulta);
        widget_consulta->setObjectName(QStringLiteral("widget_consulta"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget_consulta->sizePolicy().hasHeightForWidth());
        widget_consulta->setSizePolicy(sizePolicy);
        layout_consulta = new QVBoxLayout(widget_consulta);
        layout_consulta->setSpacing(5);
        layout_consulta->setContentsMargins(11, 11, 11, 11);
        layout_consulta->setObjectName(QStringLiteral("layout_consulta"));
        layout_consulta->setContentsMargins(0, 0, 0, 0);
        widget_periodo = new QWidget(widget_consulta);
        widget_periodo->setObjectName(QStringLiteral("widget_periodo"));
        widget_periodo->setMaximumSize(QSize(16777215, 60));
        verticalLayout_2 = new QVBoxLayout(widget_periodo);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        cabecera_periodo = new QHBoxLayout();
        cabecera_periodo->setSpacing(0);
        cabecera_periodo->setObjectName(QStringLiteral("cabecera_periodo"));
        lbl_periodo = new QLabel(widget_periodo);
        lbl_periodo->setObjectName(QStringLiteral("lbl_periodo"));
        QFont font1;
        font1.setPointSize(12);
        lbl_periodo->setFont(font1);
        lbl_periodo->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        cabecera_periodo->addWidget(lbl_periodo);


        verticalLayout_2->addLayout(cabecera_periodo);

        widget_periodo_consulta = new QWidget(widget_periodo);
        widget_periodo_consulta->setObjectName(QStringLiteral("widget_periodo_consulta"));
        layout_periodo_consulta = new QHBoxLayout(widget_periodo_consulta);
        layout_periodo_consulta->setSpacing(6);
        layout_periodo_consulta->setContentsMargins(11, 11, 11, 11);
        layout_periodo_consulta->setObjectName(QStringLiteral("layout_periodo_consulta"));
        layout_periodo_consulta->setSizeConstraint(QLayout::SetDefaultConstraint);
        layout_periodo_consulta->setContentsMargins(0, 0, 0, 0);
        lbl_desde = new QLabel(widget_periodo_consulta);
        lbl_desde->setObjectName(QStringLiteral("lbl_desde"));
        QFont font2;
        font2.setPointSize(10);
        lbl_desde->setFont(font2);

        layout_periodo_consulta->addWidget(lbl_desde);

        dateedit_desde = new QDateEdit(widget_periodo_consulta);
        dateedit_desde->setObjectName(QStringLiteral("dateedit_desde"));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        font3.setPointSize(10);
        font3.setItalic(true);
        dateedit_desde->setFont(font3);
        dateedit_desde->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dateedit_desde->setCurrentSection(QDateTimeEdit::DaySection);
        dateedit_desde->setCalendarPopup(true);

        layout_periodo_consulta->addWidget(dateedit_desde);

        lbl_hasta = new QLabel(widget_periodo_consulta);
        lbl_hasta->setObjectName(QStringLiteral("lbl_hasta"));
        lbl_hasta->setFont(font2);

        layout_periodo_consulta->addWidget(lbl_hasta);

        dateedit_hasta = new QDateEdit(widget_periodo_consulta);
        dateedit_hasta->setObjectName(QStringLiteral("dateedit_hasta"));
        dateedit_hasta->setFont(font3);
        dateedit_hasta->setButtonSymbols(QAbstractSpinBox::NoButtons);
        dateedit_hasta->setCalendarPopup(true);

        layout_periodo_consulta->addWidget(dateedit_hasta);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        layout_periodo_consulta->addItem(horizontalSpacer_2);

        lbl_etiqueta = new QLabel(widget_periodo_consulta);
        lbl_etiqueta->setObjectName(QStringLiteral("lbl_etiqueta"));
        lbl_etiqueta->setFont(font2);

        layout_periodo_consulta->addWidget(lbl_etiqueta);

        lineedit_etiqueta_periodo = new QLineEdit(widget_periodo_consulta);
        lineedit_etiqueta_periodo->setObjectName(QStringLiteral("lineedit_etiqueta_periodo"));
        lineedit_etiqueta_periodo->setMaximumSize(QSize(200, 16777215));
        lineedit_etiqueta_periodo->setFont(font3);
        lineedit_etiqueta_periodo->setDragEnabled(false);
        lineedit_etiqueta_periodo->setReadOnly(true);

        layout_periodo_consulta->addWidget(lineedit_etiqueta_periodo);


        verticalLayout_2->addWidget(widget_periodo_consulta, 0, Qt::AlignLeft);


        layout_consulta->addWidget(widget_periodo);

        line = new QFrame(widget_consulta);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        layout_consulta->addWidget(line);

        widget_medios = new QWidget(widget_consulta);
        widget_medios->setObjectName(QStringLiteral("widget_medios"));
        widget_medios->setMaximumSize(QSize(16777215, 16777215));
        layout_medios_consulta = new QVBoxLayout(widget_medios);
        layout_medios_consulta->setSpacing(0);
        layout_medios_consulta->setContentsMargins(11, 11, 11, 11);
        layout_medios_consulta->setObjectName(QStringLiteral("layout_medios_consulta"));
        layout_medios_consulta->setContentsMargins(0, 0, 0, 0);
        cabecera_medios = new QHBoxLayout();
        cabecera_medios->setSpacing(0);
        cabecera_medios->setObjectName(QStringLiteral("cabecera_medios"));
        lbl_medios = new QLabel(widget_medios);
        lbl_medios->setObjectName(QStringLiteral("lbl_medios"));
        lbl_medios->setFont(font1);
        lbl_medios->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        cabecera_medios->addWidget(lbl_medios);

        btn_sacar_medios = new QPushButton(widget_medios);
        btn_sacar_medios->setObjectName(QStringLiteral("btn_sacar_medios"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_sacar_medios->sizePolicy().hasHeightForWidth());
        btn_sacar_medios->setSizePolicy(sizePolicy1);
        btn_sacar_medios->setMinimumSize(QSize(0, 0));
        btn_sacar_medios->setMaximumSize(QSize(16777215, 16777215));
        btn_sacar_medios->setFont(font2);

        cabecera_medios->addWidget(btn_sacar_medios);


        layout_medios_consulta->addLayout(cabecera_medios);

        lista_medios_en_consulta = new QListWidget(widget_medios);
        lista_medios_en_consulta->setObjectName(QStringLiteral("lista_medios_en_consulta"));
        lista_medios_en_consulta->setMinimumSize(QSize(0, 100));
        lista_medios_en_consulta->setFont(font3);
        lista_medios_en_consulta->setDragEnabled(true);
        lista_medios_en_consulta->setDragDropMode(QAbstractItemView::DragOnly);
        lista_medios_en_consulta->setDefaultDropAction(Qt::IgnoreAction);
        lista_medios_en_consulta->setSelectionMode(QAbstractItemView::ExtendedSelection);
        lista_medios_en_consulta->setMovement(QListView::Free);
        lista_medios_en_consulta->setViewMode(QListView::ListMode);

        layout_medios_consulta->addWidget(lista_medios_en_consulta);


        layout_consulta->addWidget(widget_medios);

        line_2 = new QFrame(widget_consulta);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        layout_consulta->addWidget(line_2);

        widget_reportes = new QWidget(widget_consulta);
        widget_reportes->setObjectName(QStringLiteral("widget_reportes"));
        widget_reportes->setEnabled(true);
        widget_reportes->setMaximumSize(QSize(16777215, 80));
        verticalLayout = new QVBoxLayout(widget_reportes);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        cabecera_reportes = new QHBoxLayout();
        cabecera_reportes->setSpacing(3);
        cabecera_reportes->setObjectName(QStringLiteral("cabecera_reportes"));
        checkbox_tendencia = new QCheckBox(widget_reportes);
        checkbox_tendencia->setObjectName(QStringLiteral("checkbox_tendencia"));
        checkbox_tendencia->setFont(font1);
        checkbox_tendencia->setChecked(false);
        checkbox_tendencia->setAutoRepeat(false);
        checkbox_tendencia->setTristate(false);

        cabecera_reportes->addWidget(checkbox_tendencia);

        lbl_mostrar_primeros = new QLabel(widget_reportes);
        lbl_mostrar_primeros->setObjectName(QStringLiteral("lbl_mostrar_primeros"));
        lbl_mostrar_primeros->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lbl_mostrar_primeros->sizePolicy().hasHeightForWidth());
        lbl_mostrar_primeros->setSizePolicy(sizePolicy2);

        cabecera_reportes->addWidget(lbl_mostrar_primeros);

        spinbox_tendencias = new QSpinBox(widget_reportes);
        spinbox_tendencias->setObjectName(QStringLiteral("spinbox_tendencias"));
        sizePolicy1.setHeightForWidth(spinbox_tendencias->sizePolicy().hasHeightForWidth());
        spinbox_tendencias->setSizePolicy(sizePolicy1);
        spinbox_tendencias->setWrapping(false);
        spinbox_tendencias->setFrame(true);
        spinbox_tendencias->setAlignment(Qt::AlignCenter);
        spinbox_tendencias->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        spinbox_tendencias->setProperty("showGroupSeparator", QVariant(false));
        spinbox_tendencias->setMaximum(100);
        spinbox_tendencias->setValue(10);

        cabecera_reportes->addWidget(spinbox_tendencias);

        lbl_ordenar_por = new QLabel(widget_reportes);
        lbl_ordenar_por->setObjectName(QStringLiteral("lbl_ordenar_por"));
        sizePolicy2.setHeightForWidth(lbl_ordenar_por->sizePolicy().hasHeightForWidth());
        lbl_ordenar_por->setSizePolicy(sizePolicy2);

        cabecera_reportes->addWidget(lbl_ordenar_por);

        combobox_tendencia = new QComboBox(widget_reportes);
        combobox_tendencia->setObjectName(QStringLiteral("combobox_tendencia"));
        combobox_tendencia->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        combobox_tendencia->setFrame(true);
        combobox_tendencia->setModelColumn(0);

        cabecera_reportes->addWidget(combobox_tendencia);


        verticalLayout->addLayout(cabecera_reportes);


        layout_consulta->addWidget(widget_reportes);

        line_3 = new QFrame(widget_consulta);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        layout_consulta->addWidget(line_3);

        widget_conceptos = new QWidget(widget_consulta);
        widget_conceptos->setObjectName(QStringLiteral("widget_conceptos"));
        widget_conceptos->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_3 = new QVBoxLayout(widget_conceptos);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        cabecera_conceptos = new QHBoxLayout();
        cabecera_conceptos->setSpacing(0);
        cabecera_conceptos->setObjectName(QStringLiteral("cabecera_conceptos"));
        checkbox_conceptos = new QCheckBox(widget_conceptos);
        checkbox_conceptos->setObjectName(QStringLiteral("checkbox_conceptos"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(checkbox_conceptos->sizePolicy().hasHeightForWidth());
        checkbox_conceptos->setSizePolicy(sizePolicy3);
        checkbox_conceptos->setFont(font1);

        cabecera_conceptos->addWidget(checkbox_conceptos);

        btn_sacar_conceptos = new QPushButton(widget_conceptos);
        btn_sacar_conceptos->setObjectName(QStringLiteral("btn_sacar_conceptos"));
        sizePolicy1.setHeightForWidth(btn_sacar_conceptos->sizePolicy().hasHeightForWidth());
        btn_sacar_conceptos->setSizePolicy(sizePolicy1);
        btn_sacar_conceptos->setMinimumSize(QSize(0, 0));
        btn_sacar_conceptos->setMaximumSize(QSize(16777215, 16777215));
        btn_sacar_conceptos->setFont(font2);

        cabecera_conceptos->addWidget(btn_sacar_conceptos);


        verticalLayout_3->addLayout(cabecera_conceptos);

        lista_conceptos_en_consulta = new QListWidget(widget_conceptos);
        lista_conceptos_en_consulta->setObjectName(QStringLiteral("lista_conceptos_en_consulta"));
        lista_conceptos_en_consulta->setMinimumSize(QSize(0, 100));
        lista_conceptos_en_consulta->setFont(font3);
        lista_conceptos_en_consulta->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout_3->addWidget(lista_conceptos_en_consulta);


        layout_consulta->addWidget(widget_conceptos);

        espaciador_consulta = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        layout_consulta->addItem(espaciador_consulta);


        layout_tab_consulta->addWidget(widget_consulta);

        widget_botones = new QWidget(tab_consulta);
        widget_botones->setObjectName(QStringLiteral("widget_botones"));
        layout_botones = new QHBoxLayout(widget_botones);
        layout_botones->setSpacing(5);
        layout_botones->setContentsMargins(11, 11, 11, 11);
        layout_botones->setObjectName(QStringLiteral("layout_botones"));
        layout_botones->setContentsMargins(0, 0, 0, 0);
        btn_realizar_consulta = new QPushButton(widget_botones);
        btn_realizar_consulta->setObjectName(QStringLiteral("btn_realizar_consulta"));
        sizePolicy1.setHeightForWidth(btn_realizar_consulta->sizePolicy().hasHeightForWidth());
        btn_realizar_consulta->setSizePolicy(sizePolicy1);
        btn_realizar_consulta->setMinimumSize(QSize(0, 0));
        btn_realizar_consulta->setMaximumSize(QSize(16777215, 16777215));
        QFont font4;
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(50);
        btn_realizar_consulta->setFont(font4);

        layout_botones->addWidget(btn_realizar_consulta);

        btn_cancelar = new QPushButton(widget_botones);
        btn_cancelar->setObjectName(QStringLiteral("btn_cancelar"));
        sizePolicy1.setHeightForWidth(btn_cancelar->sizePolicy().hasHeightForWidth());
        btn_cancelar->setSizePolicy(sizePolicy1);
        btn_cancelar->setMinimumSize(QSize(0, 0));
        btn_cancelar->setMaximumSize(QSize(16777215, 16777215));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setWeight(50);
        btn_cancelar->setFont(font5);

        layout_botones->addWidget(btn_cancelar);


        layout_tab_consulta->addWidget(widget_botones, 0, Qt::AlignLeft);

        opciones_consulta->addTab(tab_consulta, QString());
        tab_medios = new QWidget();
        tab_medios->setObjectName(QStringLiteral("tab_medios"));
        verticalLayout_10 = new QVBoxLayout(tab_medios);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        widget_lista_medios = new QWidget(tab_medios);
        widget_lista_medios->setObjectName(QStringLiteral("widget_lista_medios"));
        layout_lista_medios = new QVBoxLayout(widget_lista_medios);
        layout_lista_medios->setSpacing(0);
        layout_lista_medios->setContentsMargins(11, 11, 11, 11);
        layout_lista_medios->setObjectName(QStringLiteral("layout_lista_medios"));
        layout_lista_medios->setContentsMargins(0, 0, 0, 0);
        cabecera_lista_medios = new QHBoxLayout();
        cabecera_lista_medios->setSpacing(6);
        cabecera_lista_medios->setObjectName(QStringLiteral("cabecera_lista_medios"));
        lbl_lista_de_medios = new QLabel(widget_lista_medios);
        lbl_lista_de_medios->setObjectName(QStringLiteral("lbl_lista_de_medios"));
        lbl_lista_de_medios->setFont(font1);
        lbl_lista_de_medios->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        cabecera_lista_medios->addWidget(lbl_lista_de_medios);

        btn_agregar_medios = new QPushButton(widget_lista_medios);
        btn_agregar_medios->setObjectName(QStringLiteral("btn_agregar_medios"));
        sizePolicy1.setHeightForWidth(btn_agregar_medios->sizePolicy().hasHeightForWidth());
        btn_agregar_medios->setSizePolicy(sizePolicy1);
        btn_agregar_medios->setMinimumSize(QSize(0, 0));
        btn_agregar_medios->setMaximumSize(QSize(16777215, 16777215));
        btn_agregar_medios->setFont(font2);

        cabecera_lista_medios->addWidget(btn_agregar_medios);


        layout_lista_medios->addLayout(cabecera_lista_medios);

        lista_medios = new QListWidget(widget_lista_medios);
        lista_medios->setObjectName(QStringLiteral("lista_medios"));
        QFont font6;
        font6.setPointSize(10);
        font6.setItalic(false);
        lista_medios->setFont(font6);
        lista_medios->setSelectionMode(QAbstractItemView::ExtendedSelection);

        layout_lista_medios->addWidget(lista_medios);


        verticalLayout_10->addWidget(widget_lista_medios);

        opciones_consulta->addTab(tab_medios, QString());
        tab_conceptos = new QWidget();
        tab_conceptos->setObjectName(QStringLiteral("tab_conceptos"));
        verticalLayout_9 = new QVBoxLayout(tab_conceptos);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        widget_lista_conceptos = new QWidget(tab_conceptos);
        widget_lista_conceptos->setObjectName(QStringLiteral("widget_lista_conceptos"));
        layout_opciones_conceptos = new QVBoxLayout(widget_lista_conceptos);
        layout_opciones_conceptos->setSpacing(0);
        layout_opciones_conceptos->setContentsMargins(11, 11, 11, 11);
        layout_opciones_conceptos->setObjectName(QStringLiteral("layout_opciones_conceptos"));
        layout_opciones_conceptos->setContentsMargins(0, 0, 0, 0);
        cabecera_lista_conceptos = new QHBoxLayout();
        cabecera_lista_conceptos->setSpacing(6);
        cabecera_lista_conceptos->setObjectName(QStringLiteral("cabecera_lista_conceptos"));
        lbl_lista_de_conceptos = new QLabel(widget_lista_conceptos);
        lbl_lista_de_conceptos->setObjectName(QStringLiteral("lbl_lista_de_conceptos"));
        lbl_lista_de_conceptos->setFont(font1);
        lbl_lista_de_conceptos->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        cabecera_lista_conceptos->addWidget(lbl_lista_de_conceptos);

        btn_agregar_conceptos = new QPushButton(widget_lista_conceptos);
        btn_agregar_conceptos->setObjectName(QStringLiteral("btn_agregar_conceptos"));
        sizePolicy1.setHeightForWidth(btn_agregar_conceptos->sizePolicy().hasHeightForWidth());
        btn_agregar_conceptos->setSizePolicy(sizePolicy1);
        btn_agregar_conceptos->setMinimumSize(QSize(0, 0));
        btn_agregar_conceptos->setMaximumSize(QSize(16777215, 16777215));
        btn_agregar_conceptos->setFont(font2);

        cabecera_lista_conceptos->addWidget(btn_agregar_conceptos);


        layout_opciones_conceptos->addLayout(cabecera_lista_conceptos);

        lista_conceptos = new QListWidget(widget_lista_conceptos);
        lista_conceptos->setObjectName(QStringLiteral("lista_conceptos"));
        lista_conceptos->setFont(font6);
        lista_conceptos->setSelectionMode(QAbstractItemView::ExtendedSelection);

        layout_opciones_conceptos->addWidget(lista_conceptos);


        verticalLayout_9->addWidget(widget_lista_conceptos);

        opciones_consulta->addTab(tab_conceptos, QString());

        verticalLayout_14->addWidget(opciones_consulta);


        retranslateUi(DialogoConsultas);

        opciones_consulta->setCurrentIndex(0);
        combobox_tendencia->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogoConsultas);
    } // setupUi

    void retranslateUi(QWidget *DialogoConsultas)
    {
        DialogoConsultas->setWindowTitle(QApplication::translate("DialogoConsultas", "Realizar consulta", Q_NULLPTR));
        action_agregar_conceptos->setText(QApplication::translate("DialogoConsultas", "agregar_conceptos", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_agregar_conceptos->setToolTip(QApplication::translate("DialogoConsultas", "agregar_conceptos", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_sacar_conceptos->setText(QApplication::translate("DialogoConsultas", "sacar_conceptos", Q_NULLPTR));
        action_setear_periodo->setText(QApplication::translate("DialogoConsultas", "setear_periodo", Q_NULLPTR));
        action_agregar_medios->setText(QApplication::translate("DialogoConsultas", "agregar_medios", Q_NULLPTR));
        action_agregar_secciones->setText(QApplication::translate("DialogoConsultas", "agregar_secciones", Q_NULLPTR));
        action_sacar_medios->setText(QApplication::translate("DialogoConsultas", "sacar_medios", Q_NULLPTR));
        action_sacar_secciones->setText(QApplication::translate("DialogoConsultas", "sacar_secciones", Q_NULLPTR));
        action_agregar_reportes->setText(QApplication::translate("DialogoConsultas", "agregar_reportes", Q_NULLPTR));
        action_sacar_reportes->setText(QApplication::translate("DialogoConsultas", "sacar_reportes", Q_NULLPTR));
        action_realizar_consulta_y_cerrar->setText(QApplication::translate("DialogoConsultas", "realizar_consulta_y_cerrar", Q_NULLPTR));
        action_resetear_periodo->setText(QApplication::translate("DialogoConsultas", "resetear_periodo", Q_NULLPTR));
        action_liberar_grafico->setText(QApplication::translate("DialogoConsultas", "liberar_grafico", Q_NULLPTR));
        lbl_periodo->setText(QApplication::translate("DialogoConsultas", "Per\303\255odo", Q_NULLPTR));
        lbl_desde->setText(QApplication::translate("DialogoConsultas", "Desde", Q_NULLPTR));
        lbl_hasta->setText(QApplication::translate("DialogoConsultas", "Hasta", Q_NULLPTR));
        lbl_etiqueta->setText(QApplication::translate("DialogoConsultas", "Etiqueta", Q_NULLPTR));
        lbl_medios->setText(QApplication::translate("DialogoConsultas", "Medios", Q_NULLPTR));
        btn_sacar_medios->setText(QApplication::translate("DialogoConsultas", "Sacar medios", Q_NULLPTR));
        checkbox_tendencia->setText(QApplication::translate("DialogoConsultas", "Tendencias", Q_NULLPTR));
        lbl_mostrar_primeros->setText(QApplication::translate("DialogoConsultas", "mostrar primeros:", Q_NULLPTR));
        spinbox_tendencias->setSuffix(QString());
        spinbox_tendencias->setPrefix(QString());
        lbl_ordenar_por->setText(QApplication::translate("DialogoConsultas", "ordendos por:", Q_NULLPTR));
        combobox_tendencia->clear();
        combobox_tendencia->insertItems(0, QStringList()
         << QApplication::translate("DialogoConsultas", "menciones", Q_NULLPTR)
         << QApplication::translate("DialogoConsultas", "fuerza en noticia", Q_NULLPTR)
        );
        combobox_tendencia->setCurrentText(QApplication::translate("DialogoConsultas", "menciones", Q_NULLPTR));
        checkbox_conceptos->setText(QApplication::translate("DialogoConsultas", "Conceptos", Q_NULLPTR));
        btn_sacar_conceptos->setText(QApplication::translate("DialogoConsultas", "Sacar conceptos", Q_NULLPTR));
        btn_realizar_consulta->setText(QApplication::translate("DialogoConsultas", "Consultar", Q_NULLPTR));
        btn_cancelar->setText(QApplication::translate("DialogoConsultas", "Cancelar", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_consulta), QApplication::translate("DialogoConsultas", "Consulta", Q_NULLPTR));
        lbl_lista_de_medios->setText(QApplication::translate("DialogoConsultas", "Lista de Medios", Q_NULLPTR));
        btn_agregar_medios->setText(QApplication::translate("DialogoConsultas", "Agregar", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_medios), QApplication::translate("DialogoConsultas", "Medios", Q_NULLPTR));
        lbl_lista_de_conceptos->setText(QApplication::translate("DialogoConsultas", "Lista de Conceptos", Q_NULLPTR));
        btn_agregar_conceptos->setText(QApplication::translate("DialogoConsultas", "Agregar", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_conceptos), QApplication::translate("DialogoConsultas", "Conceptos", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoConsultas: public Ui_DialogoConsultas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOCONSULTAS_H
