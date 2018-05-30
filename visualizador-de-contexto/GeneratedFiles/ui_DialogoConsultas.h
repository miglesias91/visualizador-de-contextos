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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QVBoxLayout *verticalLayout_8;
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
    QWidget *widget_conceptos;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *cabecera_conceptos;
    QLabel *lbl_conceptos;
    QPushButton *btn_sacar_conceptos;
    QListWidget *lista_conceptos_en_consulta;
    QFrame *line_3;
    QWidget *widget_reportes;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *cabecera_reportes;
    QLabel *lbl_reportes;
    QPushButton *btn_agregar_reportes;
    QListWidget *lista_reportes_en_consulta;
    QFrame *line_4;
    QWidget *widget_secciones;
    QVBoxLayout *layout_secciones_consulta;
    QHBoxLayout *cabecera_secciones;
    QLabel *lbl_secciones;
    QPushButton *btn_sacar_secciones;
    QListWidget *lista_secciones_en_consulta;
    QSpacerItem *espaciador_consulta;
    QHBoxLayout *layout_botones;
    QPushButton *btn_realizar_consulta;
    QProgressBar *progressbar_realizar_consulta;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_cancelar;
    QWidget *tab_conceptos;
    QVBoxLayout *verticalLayout_9;
    QWidget *widget_lista_conceptos;
    QVBoxLayout *layout_opciones_conceptos;
    QHBoxLayout *cabecera_lista_conceptos;
    QLabel *lbl_lista_de_conceptos;
    QPushButton *btn_agregar_conceptos;
    QListWidget *lista_conceptos;
    QWidget *tab_medios;
    QVBoxLayout *verticalLayout_10;
    QWidget *widget_lista_medios;
    QVBoxLayout *layout_lista_medios;
    QHBoxLayout *cabecera_lista_medios;
    QLabel *lbl_lista_de_medios;
    QPushButton *btn_agregar_medios;
    QListWidget *lista_medios;
    QWidget *tab_periodo;
    QVBoxLayout *verticalLayout_11;
    QWidget *widget_lista_periodos;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *cabecera_lista_periodos;
    QLabel *lbl_lista_de_periodos;
    QPushButton *btn_setear_periodo;
    QListWidget *lista_periodos;
    QWidget *tab_secciones;
    QVBoxLayout *verticalLayout_12;
    QWidget *widget_lista_secciones;
    QVBoxLayout *layout_lista_secciones;
    QHBoxLayout *cabecera_lista_secciones;
    QLabel *lbl_lista_de_secciones;
    QPushButton *btn_agregar_secciones;
    QListWidget *lista_secciones;
    QWidget *tab_reporte;
    QVBoxLayout *verticalLayout_13;
    QWidget *widget_lista_reportes;
    QVBoxLayout *layout_lista_reportes;
    QHBoxLayout *cabecera_lista_reportes;
    QLabel *label_2;
    QPushButton *btn_sacar_reportes;
    QListWidget *lista_reportes;

    void setupUi(QWidget *DialogoConsultas)
    {
        if (DialogoConsultas->objectName().isEmpty())
            DialogoConsultas->setObjectName(QStringLiteral("DialogoConsultas"));
        DialogoConsultas->resize(500, 672);
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
        font.setPointSize(12);
        font.setItalic(false);
        opciones_consulta->setFont(font);
        opciones_consulta->setDocumentMode(true);
        opciones_consulta->setTabsClosable(false);
        opciones_consulta->setMovable(false);
        opciones_consulta->setTabBarAutoHide(false);
        tab_consulta = new QWidget();
        tab_consulta->setObjectName(QStringLiteral("tab_consulta"));
        verticalLayout_8 = new QVBoxLayout(tab_consulta);
        verticalLayout_8->setSpacing(5);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(5, 5, 5, 5);
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
        font1.setPointSize(16);
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

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

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


        verticalLayout_2->addWidget(widget_periodo_consulta);


        layout_consulta->addWidget(widget_periodo);

        line = new QFrame(widget_consulta);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        layout_consulta->addWidget(line);

        widget_medios = new QWidget(widget_consulta);
        widget_medios->setObjectName(QStringLiteral("widget_medios"));
        widget_medios->setMaximumSize(QSize(16777215, 200));
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
        btn_sacar_medios->setMinimumSize(QSize(0, 30));
        btn_sacar_medios->setMaximumSize(QSize(150, 16777215));
        QFont font4;
        font4.setPointSize(11);
        btn_sacar_medios->setFont(font4);

        cabecera_medios->addWidget(btn_sacar_medios);


        layout_medios_consulta->addLayout(cabecera_medios);

        lista_medios_en_consulta = new QListWidget(widget_medios);
        lista_medios_en_consulta->setObjectName(QStringLiteral("lista_medios_en_consulta"));
        lista_medios_en_consulta->setMinimumSize(QSize(0, 100));
        lista_medios_en_consulta->setFont(font3);

        layout_medios_consulta->addWidget(lista_medios_en_consulta);


        layout_consulta->addWidget(widget_medios);

        line_2 = new QFrame(widget_consulta);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        layout_consulta->addWidget(line_2);

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
        lbl_conceptos = new QLabel(widget_conceptos);
        lbl_conceptos->setObjectName(QStringLiteral("lbl_conceptos"));
        lbl_conceptos->setFont(font1);
        lbl_conceptos->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        cabecera_conceptos->addWidget(lbl_conceptos);

        btn_sacar_conceptos = new QPushButton(widget_conceptos);
        btn_sacar_conceptos->setObjectName(QStringLiteral("btn_sacar_conceptos"));
        btn_sacar_conceptos->setMinimumSize(QSize(0, 30));
        btn_sacar_conceptos->setMaximumSize(QSize(150, 16777215));
        btn_sacar_conceptos->setFont(font4);

        cabecera_conceptos->addWidget(btn_sacar_conceptos);


        verticalLayout_3->addLayout(cabecera_conceptos);

        lista_conceptos_en_consulta = new QListWidget(widget_conceptos);
        lista_conceptos_en_consulta->setObjectName(QStringLiteral("lista_conceptos_en_consulta"));
        lista_conceptos_en_consulta->setMinimumSize(QSize(0, 100));
        lista_conceptos_en_consulta->setFont(font3);

        verticalLayout_3->addWidget(lista_conceptos_en_consulta);


        layout_consulta->addWidget(widget_conceptos);

        line_3 = new QFrame(widget_consulta);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        layout_consulta->addWidget(line_3);

        widget_reportes = new QWidget(widget_consulta);
        widget_reportes->setObjectName(QStringLiteral("widget_reportes"));
        widget_reportes->setEnabled(false);
        widget_reportes->setMaximumSize(QSize(16777215, 80));
        verticalLayout = new QVBoxLayout(widget_reportes);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        cabecera_reportes = new QHBoxLayout();
        cabecera_reportes->setSpacing(0);
        cabecera_reportes->setObjectName(QStringLiteral("cabecera_reportes"));
        lbl_reportes = new QLabel(widget_reportes);
        lbl_reportes->setObjectName(QStringLiteral("lbl_reportes"));
        lbl_reportes->setFont(font1);
        lbl_reportes->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        cabecera_reportes->addWidget(lbl_reportes);

        btn_agregar_reportes = new QPushButton(widget_reportes);
        btn_agregar_reportes->setObjectName(QStringLiteral("btn_agregar_reportes"));
        btn_agregar_reportes->setMinimumSize(QSize(0, 30));
        btn_agregar_reportes->setMaximumSize(QSize(150, 16777215));
        btn_agregar_reportes->setFont(font4);

        cabecera_reportes->addWidget(btn_agregar_reportes);


        verticalLayout->addLayout(cabecera_reportes);

        lista_reportes_en_consulta = new QListWidget(widget_reportes);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(lista_reportes_en_consulta);
        __qlistwidgetitem->setFont(font3);
        QFont font5;
        font5.setItalic(true);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(lista_reportes_en_consulta);
        __qlistwidgetitem1->setFont(font5);
        lista_reportes_en_consulta->setObjectName(QStringLiteral("lista_reportes_en_consulta"));
        lista_reportes_en_consulta->setEnabled(false);
        lista_reportes_en_consulta->setMaximumSize(QSize(16777215, 16777215));
        lista_reportes_en_consulta->setFont(font2);

        verticalLayout->addWidget(lista_reportes_en_consulta);


        layout_consulta->addWidget(widget_reportes);

        line_4 = new QFrame(widget_consulta);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        layout_consulta->addWidget(line_4);

        widget_secciones = new QWidget(widget_consulta);
        widget_secciones->setObjectName(QStringLiteral("widget_secciones"));
        widget_secciones->setEnabled(false);
        widget_secciones->setMaximumSize(QSize(16777215, 80));
        layout_secciones_consulta = new QVBoxLayout(widget_secciones);
        layout_secciones_consulta->setSpacing(0);
        layout_secciones_consulta->setContentsMargins(11, 11, 11, 11);
        layout_secciones_consulta->setObjectName(QStringLiteral("layout_secciones_consulta"));
        layout_secciones_consulta->setContentsMargins(0, 0, 0, 0);
        cabecera_secciones = new QHBoxLayout();
        cabecera_secciones->setSpacing(0);
        cabecera_secciones->setObjectName(QStringLiteral("cabecera_secciones"));
        lbl_secciones = new QLabel(widget_secciones);
        lbl_secciones->setObjectName(QStringLiteral("lbl_secciones"));
        lbl_secciones->setFont(font1);
        lbl_secciones->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        cabecera_secciones->addWidget(lbl_secciones);

        btn_sacar_secciones = new QPushButton(widget_secciones);
        btn_sacar_secciones->setObjectName(QStringLiteral("btn_sacar_secciones"));
        btn_sacar_secciones->setMinimumSize(QSize(0, 30));
        btn_sacar_secciones->setMaximumSize(QSize(150, 16777215));
        btn_sacar_secciones->setFont(font4);

        cabecera_secciones->addWidget(btn_sacar_secciones);


        layout_secciones_consulta->addLayout(cabecera_secciones);

        lista_secciones_en_consulta = new QListWidget(widget_secciones);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(lista_secciones_en_consulta);
        __qlistwidgetitem2->setFont(font3);
        lista_secciones_en_consulta->setObjectName(QStringLiteral("lista_secciones_en_consulta"));
        lista_secciones_en_consulta->setEnabled(false);
        lista_secciones_en_consulta->setFont(font2);

        layout_secciones_consulta->addWidget(lista_secciones_en_consulta);


        layout_consulta->addWidget(widget_secciones);

        espaciador_consulta = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        layout_consulta->addItem(espaciador_consulta);


        verticalLayout_8->addWidget(widget_consulta);

        layout_botones = new QHBoxLayout();
        layout_botones->setSpacing(5);
        layout_botones->setObjectName(QStringLiteral("layout_botones"));
        btn_realizar_consulta = new QPushButton(tab_consulta);
        btn_realizar_consulta->setObjectName(QStringLiteral("btn_realizar_consulta"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(btn_realizar_consulta->sizePolicy().hasHeightForWidth());
        btn_realizar_consulta->setSizePolicy(sizePolicy1);
        btn_realizar_consulta->setMinimumSize(QSize(120, 30));
        btn_realizar_consulta->setMaximumSize(QSize(150, 16777215));
        QFont font6;
        font6.setPointSize(16);
        font6.setBold(true);
        font6.setItalic(false);
        font6.setWeight(75);
        btn_realizar_consulta->setFont(font6);

        layout_botones->addWidget(btn_realizar_consulta);

        progressbar_realizar_consulta = new QProgressBar(tab_consulta);
        progressbar_realizar_consulta->setObjectName(QStringLiteral("progressbar_realizar_consulta"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(progressbar_realizar_consulta->sizePolicy().hasHeightForWidth());
        progressbar_realizar_consulta->setSizePolicy(sizePolicy2);
        progressbar_realizar_consulta->setMinimumSize(QSize(0, 30));
        progressbar_realizar_consulta->setValue(24);
        progressbar_realizar_consulta->setTextVisible(false);

        layout_botones->addWidget(progressbar_realizar_consulta);

        horizontalSpacer = new QSpacerItem(10, 27, QSizePolicy::Maximum, QSizePolicy::Minimum);

        layout_botones->addItem(horizontalSpacer);

        btn_cancelar = new QPushButton(tab_consulta);
        btn_cancelar->setObjectName(QStringLiteral("btn_cancelar"));
        sizePolicy1.setHeightForWidth(btn_cancelar->sizePolicy().hasHeightForWidth());
        btn_cancelar->setSizePolicy(sizePolicy1);
        btn_cancelar->setMinimumSize(QSize(100, 30));
        btn_cancelar->setMaximumSize(QSize(150, 16777215));
        QFont font7;
        font7.setPointSize(16);
        font7.setBold(true);
        font7.setWeight(75);
        btn_cancelar->setFont(font7);

        layout_botones->addWidget(btn_cancelar);


        verticalLayout_8->addLayout(layout_botones);

        opciones_consulta->addTab(tab_consulta, QString());
        tab_conceptos = new QWidget();
        tab_conceptos->setObjectName(QStringLiteral("tab_conceptos"));
        verticalLayout_9 = new QVBoxLayout(tab_conceptos);
        verticalLayout_9->setSpacing(5);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(5, 5, 5, 5);
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
        btn_agregar_conceptos->setMinimumSize(QSize(0, 30));
        btn_agregar_conceptos->setMaximumSize(QSize(150, 16777215));
        btn_agregar_conceptos->setFont(font4);

        cabecera_lista_conceptos->addWidget(btn_agregar_conceptos);


        layout_opciones_conceptos->addLayout(cabecera_lista_conceptos);

        lista_conceptos = new QListWidget(widget_lista_conceptos);
        lista_conceptos->setObjectName(QStringLiteral("lista_conceptos"));
        QFont font8;
        font8.setPointSize(10);
        font8.setItalic(false);
        lista_conceptos->setFont(font8);

        layout_opciones_conceptos->addWidget(lista_conceptos);


        verticalLayout_9->addWidget(widget_lista_conceptos);

        opciones_consulta->addTab(tab_conceptos, QString());
        tab_medios = new QWidget();
        tab_medios->setObjectName(QStringLiteral("tab_medios"));
        verticalLayout_10 = new QVBoxLayout(tab_medios);
        verticalLayout_10->setSpacing(5);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(5, 5, 5, 5);
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
        btn_agregar_medios->setMinimumSize(QSize(0, 30));
        btn_agregar_medios->setMaximumSize(QSize(150, 16777215));
        btn_agregar_medios->setFont(font4);

        cabecera_lista_medios->addWidget(btn_agregar_medios);


        layout_lista_medios->addLayout(cabecera_lista_medios);

        lista_medios = new QListWidget(widget_lista_medios);
        lista_medios->setObjectName(QStringLiteral("lista_medios"));
        lista_medios->setFont(font8);

        layout_lista_medios->addWidget(lista_medios);


        verticalLayout_10->addWidget(widget_lista_medios);

        opciones_consulta->addTab(tab_medios, QString());
        tab_periodo = new QWidget();
        tab_periodo->setObjectName(QStringLiteral("tab_periodo"));
        tab_periodo->setEnabled(false);
        verticalLayout_11 = new QVBoxLayout(tab_periodo);
        verticalLayout_11->setSpacing(5);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(5, 5, 5, 5);
        widget_lista_periodos = new QWidget(tab_periodo);
        widget_lista_periodos->setObjectName(QStringLiteral("widget_lista_periodos"));
        verticalLayout_4 = new QVBoxLayout(widget_lista_periodos);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        cabecera_lista_periodos = new QHBoxLayout();
        cabecera_lista_periodos->setSpacing(6);
        cabecera_lista_periodos->setObjectName(QStringLiteral("cabecera_lista_periodos"));
        lbl_lista_de_periodos = new QLabel(widget_lista_periodos);
        lbl_lista_de_periodos->setObjectName(QStringLiteral("lbl_lista_de_periodos"));
        lbl_lista_de_periodos->setFont(font1);
        lbl_lista_de_periodos->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        cabecera_lista_periodos->addWidget(lbl_lista_de_periodos);

        btn_setear_periodo = new QPushButton(widget_lista_periodos);
        btn_setear_periodo->setObjectName(QStringLiteral("btn_setear_periodo"));
        btn_setear_periodo->setMinimumSize(QSize(0, 30));
        btn_setear_periodo->setMaximumSize(QSize(150, 16777215));
        btn_setear_periodo->setFont(font4);

        cabecera_lista_periodos->addWidget(btn_setear_periodo);


        verticalLayout_4->addLayout(cabecera_lista_periodos);

        lista_periodos = new QListWidget(widget_lista_periodos);
        lista_periodos->setObjectName(QStringLiteral("lista_periodos"));
        lista_periodos->setFont(font8);

        verticalLayout_4->addWidget(lista_periodos);


        verticalLayout_11->addWidget(widget_lista_periodos);

        opciones_consulta->addTab(tab_periodo, QString());
        tab_secciones = new QWidget();
        tab_secciones->setObjectName(QStringLiteral("tab_secciones"));
        tab_secciones->setEnabled(false);
        QFont font9;
        font9.setItalic(false);
        tab_secciones->setFont(font9);
        verticalLayout_12 = new QVBoxLayout(tab_secciones);
        verticalLayout_12->setSpacing(5);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(5, 5, 5, 5);
        widget_lista_secciones = new QWidget(tab_secciones);
        widget_lista_secciones->setObjectName(QStringLiteral("widget_lista_secciones"));
        layout_lista_secciones = new QVBoxLayout(widget_lista_secciones);
        layout_lista_secciones->setSpacing(0);
        layout_lista_secciones->setContentsMargins(11, 11, 11, 11);
        layout_lista_secciones->setObjectName(QStringLiteral("layout_lista_secciones"));
        layout_lista_secciones->setContentsMargins(0, 0, 0, 0);
        cabecera_lista_secciones = new QHBoxLayout();
        cabecera_lista_secciones->setSpacing(6);
        cabecera_lista_secciones->setObjectName(QStringLiteral("cabecera_lista_secciones"));
        lbl_lista_de_secciones = new QLabel(widget_lista_secciones);
        lbl_lista_de_secciones->setObjectName(QStringLiteral("lbl_lista_de_secciones"));
        lbl_lista_de_secciones->setFont(font1);
        lbl_lista_de_secciones->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        cabecera_lista_secciones->addWidget(lbl_lista_de_secciones);

        btn_agregar_secciones = new QPushButton(widget_lista_secciones);
        btn_agregar_secciones->setObjectName(QStringLiteral("btn_agregar_secciones"));
        btn_agregar_secciones->setMinimumSize(QSize(0, 30));
        btn_agregar_secciones->setMaximumSize(QSize(150, 16777215));
        QFont font10;
        font10.setPointSize(11);
        font10.setItalic(true);
        btn_agregar_secciones->setFont(font10);

        cabecera_lista_secciones->addWidget(btn_agregar_secciones);


        layout_lista_secciones->addLayout(cabecera_lista_secciones);

        lista_secciones = new QListWidget(widget_lista_secciones);
        lista_secciones->setObjectName(QStringLiteral("lista_secciones"));

        layout_lista_secciones->addWidget(lista_secciones);


        verticalLayout_12->addWidget(widget_lista_secciones);

        opciones_consulta->addTab(tab_secciones, QString());
        tab_reporte = new QWidget();
        tab_reporte->setObjectName(QStringLiteral("tab_reporte"));
        tab_reporte->setEnabled(false);
        verticalLayout_13 = new QVBoxLayout(tab_reporte);
        verticalLayout_13->setSpacing(5);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QStringLiteral("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(5, 5, 5, 5);
        widget_lista_reportes = new QWidget(tab_reporte);
        widget_lista_reportes->setObjectName(QStringLiteral("widget_lista_reportes"));
        layout_lista_reportes = new QVBoxLayout(widget_lista_reportes);
        layout_lista_reportes->setSpacing(0);
        layout_lista_reportes->setContentsMargins(11, 11, 11, 11);
        layout_lista_reportes->setObjectName(QStringLiteral("layout_lista_reportes"));
        layout_lista_reportes->setContentsMargins(0, 0, 0, 0);
        cabecera_lista_reportes = new QHBoxLayout();
        cabecera_lista_reportes->setSpacing(6);
        cabecera_lista_reportes->setObjectName(QStringLiteral("cabecera_lista_reportes"));
        label_2 = new QLabel(widget_lista_reportes);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        cabecera_lista_reportes->addWidget(label_2);

        btn_sacar_reportes = new QPushButton(widget_lista_reportes);
        btn_sacar_reportes->setObjectName(QStringLiteral("btn_sacar_reportes"));
        btn_sacar_reportes->setMinimumSize(QSize(0, 30));
        btn_sacar_reportes->setMaximumSize(QSize(150, 16777215));
        btn_sacar_reportes->setFont(font10);

        cabecera_lista_reportes->addWidget(btn_sacar_reportes);


        layout_lista_reportes->addLayout(cabecera_lista_reportes);

        lista_reportes = new QListWidget(widget_lista_reportes);
        lista_reportes->setObjectName(QStringLiteral("lista_reportes"));

        layout_lista_reportes->addWidget(lista_reportes);


        verticalLayout_13->addWidget(widget_lista_reportes);

        opciones_consulta->addTab(tab_reporte, QString());

        verticalLayout_14->addWidget(opciones_consulta);


        retranslateUi(DialogoConsultas);

        opciones_consulta->setCurrentIndex(0);


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
        lbl_conceptos->setText(QApplication::translate("DialogoConsultas", "Conceptos", Q_NULLPTR));
        btn_sacar_conceptos->setText(QApplication::translate("DialogoConsultas", "Sacar conceptos", Q_NULLPTR));
        lbl_reportes->setText(QApplication::translate("DialogoConsultas", "Reportes", Q_NULLPTR));
        btn_agregar_reportes->setText(QApplication::translate("DialogoConsultas", "Sacar reportes", Q_NULLPTR));

        const bool __sortingEnabled = lista_reportes_en_consulta->isSortingEnabled();
        lista_reportes_en_consulta->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = lista_reportes_en_consulta->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("DialogoConsultas", "Fuerza de concepto en medio", Q_NULLPTR));
        QListWidgetItem *___qlistwidgetitem1 = lista_reportes_en_consulta->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("DialogoConsultas", "Sentimiento", Q_NULLPTR));
        lista_reportes_en_consulta->setSortingEnabled(__sortingEnabled);

        lbl_secciones->setText(QApplication::translate("DialogoConsultas", "Secciones", Q_NULLPTR));
        btn_sacar_secciones->setText(QApplication::translate("DialogoConsultas", "Sacar secciones", Q_NULLPTR));

        const bool __sortingEnabled1 = lista_secciones_en_consulta->isSortingEnabled();
        lista_secciones_en_consulta->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem2 = lista_secciones_en_consulta->item(0);
        ___qlistwidgetitem2->setText(QApplication::translate("DialogoConsultas", "Todas", Q_NULLPTR));
        lista_secciones_en_consulta->setSortingEnabled(__sortingEnabled1);

        btn_realizar_consulta->setText(QApplication::translate("DialogoConsultas", "Consultar", Q_NULLPTR));
        btn_cancelar->setText(QApplication::translate("DialogoConsultas", "Cancelar", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_consulta), QApplication::translate("DialogoConsultas", "Consulta", Q_NULLPTR));
        lbl_lista_de_conceptos->setText(QApplication::translate("DialogoConsultas", "Lista de Conceptos", Q_NULLPTR));
        btn_agregar_conceptos->setText(QApplication::translate("DialogoConsultas", "Agregar", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_conceptos), QApplication::translate("DialogoConsultas", "Conceptos", Q_NULLPTR));
        lbl_lista_de_medios->setText(QApplication::translate("DialogoConsultas", "Lista de Medios", Q_NULLPTR));
        btn_agregar_medios->setText(QApplication::translate("DialogoConsultas", "Agregar", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_medios), QApplication::translate("DialogoConsultas", "Medios", Q_NULLPTR));
        lbl_lista_de_periodos->setText(QApplication::translate("DialogoConsultas", "Lista de Per\303\255odos", Q_NULLPTR));
        btn_setear_periodo->setText(QApplication::translate("DialogoConsultas", "Setear", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_periodo), QApplication::translate("DialogoConsultas", "Per\303\255odo", Q_NULLPTR));
        lbl_lista_de_secciones->setText(QApplication::translate("DialogoConsultas", "Lista de Secciones", Q_NULLPTR));
        btn_agregar_secciones->setText(QApplication::translate("DialogoConsultas", "Agregar", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_secciones), QApplication::translate("DialogoConsultas", "Secciones", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogoConsultas", "Lista de Reportes", Q_NULLPTR));
        btn_sacar_reportes->setText(QApplication::translate("DialogoConsultas", "Agregar", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_reporte), QApplication::translate("DialogoConsultas", "Reportes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoConsultas: public Ui_DialogoConsultas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOCONSULTAS_H
