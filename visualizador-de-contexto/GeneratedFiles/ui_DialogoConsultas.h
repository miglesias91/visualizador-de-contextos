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
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
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
    QTabWidget *opciones_consulta;
    QWidget *tab_consulta;
    QWidget *gridLayoutWidget;
    QGridLayout *layout_consulta;
    QGroupBox *groupbox_periodo;
    QWidget *formLayoutWidget;
    QFormLayout *layout_periodo;
    QLabel *lbl_desde;
    QDateEdit *dateedit_desde;
    QLabel *lbl_hasta;
    QDateEdit *dateedit_hastsa;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta;
    QGroupBox *groupbox_secciones;
    QListWidget *lista_secciones_en_consulta;
    QGroupBox *groupbox_conceptos;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layout_concepto_consulta;
    QListWidget *lista_conceptos_en_consulta;
    QGroupBox *groupbox_medios;
    QListWidget *lista_medios_en_consulta;
    QGroupBox *groupbox_reportes;
    QListWidget *lista_reportes_en_consulta;
    QDialogButtonBox *btnbox_consulta;
    QWidget *tab_conceptos;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *layout_conceptos;
    QListWidget *lista_conceptos;
    QVBoxLayout *layout_opciones_conceptos;
    QPushButton *btn_agregar_conceptos;
    QPushButton *btn_sacar_conceptos;
    QWidget *tab_periodo;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *layout_periodos;
    QListWidget *lista_periodos;
    QHBoxLayout *layout_opciones_periodos;
    QPushButton *btn_setear_periodo;
    QWidget *tab_medios;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *layout_medios;
    QListWidget *lista_medios;
    QVBoxLayout *layout_opciones_medios;
    QPushButton *btn_agregar_medios;
    QPushButton *btn_sacar_medios;
    QWidget *tab_secciones;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *layout_secciones;
    QListWidget *lista_secciones;
    QVBoxLayout *layout_opciones_secciones;
    QPushButton *btn_agregar_secciones;
    QPushButton *btn_sacar_secciones;
    QWidget *tab_reporte;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *layout_reportes;
    QListWidget *lista_reportes;
    QVBoxLayout *layout_opciones_reportes;
    QPushButton *btn_sacar_reportes;
    QPushButton *btn_agregar_reportes;

    void setupUi(QWidget *DialogoConsultas)
    {
        if (DialogoConsultas->objectName().isEmpty())
            DialogoConsultas->setObjectName(QStringLiteral("DialogoConsultas"));
        DialogoConsultas->resize(577, 345);
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
        opciones_consulta = new QTabWidget(DialogoConsultas);
        opciones_consulta->setObjectName(QStringLiteral("opciones_consulta"));
        opciones_consulta->setGeometry(QRect(10, 10, 561, 331));
        tab_consulta = new QWidget();
        tab_consulta->setObjectName(QStringLiteral("tab_consulta"));
        gridLayoutWidget = new QWidget(tab_consulta);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 541, 251));
        layout_consulta = new QGridLayout(gridLayoutWidget);
        layout_consulta->setSpacing(6);
        layout_consulta->setContentsMargins(11, 11, 11, 11);
        layout_consulta->setObjectName(QStringLiteral("layout_consulta"));
        layout_consulta->setContentsMargins(0, 0, 0, 0);
        groupbox_periodo = new QGroupBox(gridLayoutWidget);
        groupbox_periodo->setObjectName(QStringLiteral("groupbox_periodo"));
        formLayoutWidget = new QWidget(groupbox_periodo);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 20, 160, 91));
        layout_periodo = new QFormLayout(formLayoutWidget);
        layout_periodo->setSpacing(6);
        layout_periodo->setContentsMargins(11, 11, 11, 11);
        layout_periodo->setObjectName(QStringLiteral("layout_periodo"));
        layout_periodo->setContentsMargins(0, 0, 0, 0);
        lbl_desde = new QLabel(formLayoutWidget);
        lbl_desde->setObjectName(QStringLiteral("lbl_desde"));

        layout_periodo->setWidget(1, QFormLayout::LabelRole, lbl_desde);

        dateedit_desde = new QDateEdit(formLayoutWidget);
        dateedit_desde->setObjectName(QStringLiteral("dateedit_desde"));
        dateedit_desde->setButtonSymbols(QAbstractSpinBox::NoButtons);

        layout_periodo->setWidget(1, QFormLayout::FieldRole, dateedit_desde);

        lbl_hasta = new QLabel(formLayoutWidget);
        lbl_hasta->setObjectName(QStringLiteral("lbl_hasta"));

        layout_periodo->setWidget(2, QFormLayout::LabelRole, lbl_hasta);

        dateedit_hastsa = new QDateEdit(formLayoutWidget);
        dateedit_hastsa->setObjectName(QStringLiteral("dateedit_hastsa"));
        dateedit_hastsa->setButtonSymbols(QAbstractSpinBox::NoButtons);

        layout_periodo->setWidget(2, QFormLayout::FieldRole, dateedit_hastsa);

        lbl_etiqueta = new QLabel(formLayoutWidget);
        lbl_etiqueta->setObjectName(QStringLiteral("lbl_etiqueta"));

        layout_periodo->setWidget(0, QFormLayout::LabelRole, lbl_etiqueta);

        lineedit_etiqueta = new QLineEdit(formLayoutWidget);
        lineedit_etiqueta->setObjectName(QStringLiteral("lineedit_etiqueta"));
        lineedit_etiqueta->setDragEnabled(false);
        lineedit_etiqueta->setReadOnly(true);

        layout_periodo->setWidget(0, QFormLayout::FieldRole, lineedit_etiqueta);


        layout_consulta->addWidget(groupbox_periodo, 0, 1, 1, 1);

        groupbox_secciones = new QGroupBox(gridLayoutWidget);
        groupbox_secciones->setObjectName(QStringLiteral("groupbox_secciones"));
        lista_secciones_en_consulta = new QListWidget(groupbox_secciones);
        lista_secciones_en_consulta->setObjectName(QStringLiteral("lista_secciones_en_consulta"));
        lista_secciones_en_consulta->setGeometry(QRect(10, 20, 161, 91));

        layout_consulta->addWidget(groupbox_secciones, 1, 1, 1, 1);

        groupbox_conceptos = new QGroupBox(gridLayoutWidget);
        groupbox_conceptos->setObjectName(QStringLiteral("groupbox_conceptos"));
        verticalLayoutWidget = new QWidget(groupbox_conceptos);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 20, 161, 221));
        layout_concepto_consulta = new QVBoxLayout(verticalLayoutWidget);
        layout_concepto_consulta->setSpacing(6);
        layout_concepto_consulta->setContentsMargins(11, 11, 11, 11);
        layout_concepto_consulta->setObjectName(QStringLiteral("layout_concepto_consulta"));
        layout_concepto_consulta->setContentsMargins(0, 0, 0, 0);
        lista_conceptos_en_consulta = new QListWidget(verticalLayoutWidget);
        lista_conceptos_en_consulta->setObjectName(QStringLiteral("lista_conceptos_en_consulta"));

        layout_concepto_consulta->addWidget(lista_conceptos_en_consulta);


        layout_consulta->addWidget(groupbox_conceptos, 0, 0, 2, 1);

        groupbox_medios = new QGroupBox(gridLayoutWidget);
        groupbox_medios->setObjectName(QStringLiteral("groupbox_medios"));
        lista_medios_en_consulta = new QListWidget(groupbox_medios);
        lista_medios_en_consulta->setObjectName(QStringLiteral("lista_medios_en_consulta"));
        lista_medios_en_consulta->setGeometry(QRect(10, 20, 161, 91));

        layout_consulta->addWidget(groupbox_medios, 0, 3, 1, 1);

        groupbox_reportes = new QGroupBox(gridLayoutWidget);
        groupbox_reportes->setObjectName(QStringLiteral("groupbox_reportes"));
        lista_reportes_en_consulta = new QListWidget(groupbox_reportes);
        lista_reportes_en_consulta->setObjectName(QStringLiteral("lista_reportes_en_consulta"));
        lista_reportes_en_consulta->setGeometry(QRect(10, 20, 161, 91));

        layout_consulta->addWidget(groupbox_reportes, 1, 3, 1, 1);

        btnbox_consulta = new QDialogButtonBox(tab_consulta);
        btnbox_consulta->setObjectName(QStringLiteral("btnbox_consulta"));
        btnbox_consulta->setGeometry(QRect(200, 280, 156, 23));
        btnbox_consulta->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        opciones_consulta->addTab(tab_consulta, QString());
        tab_conceptos = new QWidget();
        tab_conceptos->setObjectName(QStringLiteral("tab_conceptos"));
        horizontalLayoutWidget = new QWidget(tab_conceptos);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 541, 291));
        layout_conceptos = new QHBoxLayout(horizontalLayoutWidget);
        layout_conceptos->setSpacing(6);
        layout_conceptos->setContentsMargins(11, 11, 11, 11);
        layout_conceptos->setObjectName(QStringLiteral("layout_conceptos"));
        layout_conceptos->setContentsMargins(0, 0, 0, 0);
        lista_conceptos = new QListWidget(horizontalLayoutWidget);
        lista_conceptos->setObjectName(QStringLiteral("lista_conceptos"));

        layout_conceptos->addWidget(lista_conceptos);

        layout_opciones_conceptos = new QVBoxLayout();
        layout_opciones_conceptos->setSpacing(6);
        layout_opciones_conceptos->setObjectName(QStringLiteral("layout_opciones_conceptos"));
        btn_agregar_conceptos = new QPushButton(horizontalLayoutWidget);
        btn_agregar_conceptos->setObjectName(QStringLiteral("btn_agregar_conceptos"));

        layout_opciones_conceptos->addWidget(btn_agregar_conceptos);

        btn_sacar_conceptos = new QPushButton(horizontalLayoutWidget);
        btn_sacar_conceptos->setObjectName(QStringLiteral("btn_sacar_conceptos"));

        layout_opciones_conceptos->addWidget(btn_sacar_conceptos);


        layout_conceptos->addLayout(layout_opciones_conceptos);

        opciones_consulta->addTab(tab_conceptos, QString());
        tab_periodo = new QWidget();
        tab_periodo->setObjectName(QStringLiteral("tab_periodo"));
        horizontalLayoutWidget_3 = new QWidget(tab_periodo);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 10, 531, 291));
        layout_periodos = new QHBoxLayout(horizontalLayoutWidget_3);
        layout_periodos->setSpacing(6);
        layout_periodos->setContentsMargins(11, 11, 11, 11);
        layout_periodos->setObjectName(QStringLiteral("layout_periodos"));
        layout_periodos->setContentsMargins(0, 0, 0, 0);
        lista_periodos = new QListWidget(horizontalLayoutWidget_3);
        lista_periodos->setObjectName(QStringLiteral("lista_periodos"));

        layout_periodos->addWidget(lista_periodos);

        layout_opciones_periodos = new QHBoxLayout();
        layout_opciones_periodos->setSpacing(6);
        layout_opciones_periodos->setObjectName(QStringLiteral("layout_opciones_periodos"));
        btn_setear_periodo = new QPushButton(horizontalLayoutWidget_3);
        btn_setear_periodo->setObjectName(QStringLiteral("btn_setear_periodo"));

        layout_opciones_periodos->addWidget(btn_setear_periodo);


        layout_periodos->addLayout(layout_opciones_periodos);

        opciones_consulta->addTab(tab_periodo, QString());
        tab_medios = new QWidget();
        tab_medios->setObjectName(QStringLiteral("tab_medios"));
        horizontalLayoutWidget_4 = new QWidget(tab_medios);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 9, 541, 291));
        layout_medios = new QHBoxLayout(horizontalLayoutWidget_4);
        layout_medios->setSpacing(6);
        layout_medios->setContentsMargins(11, 11, 11, 11);
        layout_medios->setObjectName(QStringLiteral("layout_medios"));
        layout_medios->setContentsMargins(0, 0, 0, 0);
        lista_medios = new QListWidget(horizontalLayoutWidget_4);
        lista_medios->setObjectName(QStringLiteral("lista_medios"));

        layout_medios->addWidget(lista_medios);

        layout_opciones_medios = new QVBoxLayout();
        layout_opciones_medios->setSpacing(6);
        layout_opciones_medios->setObjectName(QStringLiteral("layout_opciones_medios"));
        btn_agregar_medios = new QPushButton(horizontalLayoutWidget_4);
        btn_agregar_medios->setObjectName(QStringLiteral("btn_agregar_medios"));

        layout_opciones_medios->addWidget(btn_agregar_medios);

        btn_sacar_medios = new QPushButton(horizontalLayoutWidget_4);
        btn_sacar_medios->setObjectName(QStringLiteral("btn_sacar_medios"));

        layout_opciones_medios->addWidget(btn_sacar_medios);


        layout_medios->addLayout(layout_opciones_medios);

        opciones_consulta->addTab(tab_medios, QString());
        tab_secciones = new QWidget();
        tab_secciones->setObjectName(QStringLiteral("tab_secciones"));
        horizontalLayoutWidget_5 = new QWidget(tab_secciones);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 9, 541, 291));
        layout_secciones = new QHBoxLayout(horizontalLayoutWidget_5);
        layout_secciones->setSpacing(6);
        layout_secciones->setContentsMargins(11, 11, 11, 11);
        layout_secciones->setObjectName(QStringLiteral("layout_secciones"));
        layout_secciones->setContentsMargins(0, 0, 0, 0);
        lista_secciones = new QListWidget(horizontalLayoutWidget_5);
        lista_secciones->setObjectName(QStringLiteral("lista_secciones"));

        layout_secciones->addWidget(lista_secciones);

        layout_opciones_secciones = new QVBoxLayout();
        layout_opciones_secciones->setSpacing(6);
        layout_opciones_secciones->setObjectName(QStringLiteral("layout_opciones_secciones"));
        btn_agregar_secciones = new QPushButton(horizontalLayoutWidget_5);
        btn_agregar_secciones->setObjectName(QStringLiteral("btn_agregar_secciones"));

        layout_opciones_secciones->addWidget(btn_agregar_secciones);

        btn_sacar_secciones = new QPushButton(horizontalLayoutWidget_5);
        btn_sacar_secciones->setObjectName(QStringLiteral("btn_sacar_secciones"));

        layout_opciones_secciones->addWidget(btn_sacar_secciones);


        layout_secciones->addLayout(layout_opciones_secciones);

        opciones_consulta->addTab(tab_secciones, QString());
        tab_reporte = new QWidget();
        tab_reporte->setObjectName(QStringLiteral("tab_reporte"));
        horizontalLayoutWidget_6 = new QWidget(tab_reporte);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(10, 10, 541, 291));
        layout_reportes = new QHBoxLayout(horizontalLayoutWidget_6);
        layout_reportes->setSpacing(6);
        layout_reportes->setContentsMargins(11, 11, 11, 11);
        layout_reportes->setObjectName(QStringLiteral("layout_reportes"));
        layout_reportes->setContentsMargins(0, 0, 0, 0);
        lista_reportes = new QListWidget(horizontalLayoutWidget_6);
        lista_reportes->setObjectName(QStringLiteral("lista_reportes"));

        layout_reportes->addWidget(lista_reportes);

        layout_opciones_reportes = new QVBoxLayout();
        layout_opciones_reportes->setSpacing(6);
        layout_opciones_reportes->setObjectName(QStringLiteral("layout_opciones_reportes"));
        btn_sacar_reportes = new QPushButton(horizontalLayoutWidget_6);
        btn_sacar_reportes->setObjectName(QStringLiteral("btn_sacar_reportes"));

        layout_opciones_reportes->addWidget(btn_sacar_reportes);

        btn_agregar_reportes = new QPushButton(horizontalLayoutWidget_6);
        btn_agregar_reportes->setObjectName(QStringLiteral("btn_agregar_reportes"));

        layout_opciones_reportes->addWidget(btn_agregar_reportes);


        layout_reportes->addLayout(layout_opciones_reportes);

        opciones_consulta->addTab(tab_reporte, QString());

        retranslateUi(DialogoConsultas);
        QObject::connect(btn_agregar_conceptos, SIGNAL(released()), action_agregar_conceptos, SLOT(trigger()));
        QObject::connect(btn_sacar_conceptos, SIGNAL(released()), action_sacar_conceptos, SLOT(trigger()));
        QObject::connect(btn_setear_periodo, SIGNAL(released()), action_setear_periodo, SLOT(trigger()));
        QObject::connect(btn_agregar_medios, SIGNAL(released()), action_agregar_medios, SLOT(trigger()));
        QObject::connect(btn_sacar_medios, SIGNAL(released()), action_sacar_medios, SLOT(trigger()));
        QObject::connect(btn_agregar_secciones, SIGNAL(released()), action_agregar_secciones, SLOT(trigger()));
        QObject::connect(btn_sacar_secciones, SIGNAL(released()), action_sacar_secciones, SLOT(trigger()));
        QObject::connect(btn_agregar_reportes, SIGNAL(released()), action_agregar_reportes, SLOT(trigger()));
        QObject::connect(btn_sacar_reportes, SIGNAL(released()), action_sacar_reportes, SLOT(trigger()));
        QObject::connect(btnbox_consulta, SIGNAL(accepted()), action_realizar_consulta_y_cerrar, SLOT(trigger()));
        QObject::connect(btnbox_consulta, SIGNAL(rejected()), DialogoConsultas, SLOT(close()));

        opciones_consulta->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(DialogoConsultas);
    } // setupUi

    void retranslateUi(QWidget *DialogoConsultas)
    {
        DialogoConsultas->setWindowTitle(QApplication::translate("DialogoConsultas", "DialogoConsultas", Q_NULLPTR));
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
        groupbox_periodo->setTitle(QApplication::translate("DialogoConsultas", "Periodo", Q_NULLPTR));
        lbl_desde->setText(QApplication::translate("DialogoConsultas", "desde", Q_NULLPTR));
        lbl_hasta->setText(QApplication::translate("DialogoConsultas", "hasta", Q_NULLPTR));
        lbl_etiqueta->setText(QApplication::translate("DialogoConsultas", "etiqueta", Q_NULLPTR));
        groupbox_secciones->setTitle(QApplication::translate("DialogoConsultas", "Secciones", Q_NULLPTR));
        groupbox_conceptos->setTitle(QApplication::translate("DialogoConsultas", "Conceptos", Q_NULLPTR));
        groupbox_medios->setTitle(QApplication::translate("DialogoConsultas", "Medios", Q_NULLPTR));
        groupbox_reportes->setTitle(QApplication::translate("DialogoConsultas", "Reportes", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_consulta), QApplication::translate("DialogoConsultas", "Consulta", Q_NULLPTR));
        btn_agregar_conceptos->setText(QApplication::translate("DialogoConsultas", "agregar a consulta", Q_NULLPTR));
        btn_sacar_conceptos->setText(QApplication::translate("DialogoConsultas", "sacar de consulta", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_conceptos), QApplication::translate("DialogoConsultas", "Conceptos", Q_NULLPTR));
        btn_setear_periodo->setText(QApplication::translate("DialogoConsultas", "setear periodo", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_periodo), QApplication::translate("DialogoConsultas", "Periodo", Q_NULLPTR));
        btn_agregar_medios->setText(QApplication::translate("DialogoConsultas", "agregar a consulta", Q_NULLPTR));
        btn_sacar_medios->setText(QApplication::translate("DialogoConsultas", "sacar de consulta", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_medios), QApplication::translate("DialogoConsultas", "Medios", Q_NULLPTR));
        btn_agregar_secciones->setText(QApplication::translate("DialogoConsultas", "agregar a consulta", Q_NULLPTR));
        btn_sacar_secciones->setText(QApplication::translate("DialogoConsultas", "sacar de consulta", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_secciones), QApplication::translate("DialogoConsultas", "Secciones", Q_NULLPTR));
        btn_sacar_reportes->setText(QApplication::translate("DialogoConsultas", "agregar a consulta", Q_NULLPTR));
        btn_agregar_reportes->setText(QApplication::translate("DialogoConsultas", "sacar de consulta", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_reporte), QApplication::translate("DialogoConsultas", "Reportes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoConsultas: public Ui_DialogoConsultas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOCONSULTAS_H
