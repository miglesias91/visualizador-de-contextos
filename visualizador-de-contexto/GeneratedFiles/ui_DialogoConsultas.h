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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoConsultas
{
public:
    QDialogButtonBox *btnbox_consulta;
    QTabWidget *opciones_consulta;
    QWidget *tab_consulta;
    QWidget *gridLayoutWidget;
    QGridLayout *layout_consulta;
    QGroupBox *groupbox_periodo;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *lbl_desde;
    QDateEdit *dateedit_desde;
    QLabel *lbl_hasta;
    QDateEdit *dateedit_hastsa;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta;
    QGroupBox *groupbox_secciones;
    QListWidget *lista_secciones_en_consulta;
    QGroupBox *groupbox_conceptos;
    QListWidget *lista_conceptos_en_consulta;
    QGroupBox *groupbox_medios;
    QListWidget *lista_medios_en_consulta;
    QGroupBox *groupbox_reportes;
    QListWidget *lista_reportes_en_consulta;
    QWidget *tab_conceptos;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *layout_conceptos;
    QListWidget *lista_conceptos;
    QPushButton *btn_agregar_conceptos;
    QWidget *tab_periodo;
    QWidget *tab_medios;
    QWidget *tab_secciones;
    QWidget *tab_reporte;

    void setupUi(QWidget *DialogoConsultas)
    {
        if (DialogoConsultas->objectName().isEmpty())
            DialogoConsultas->setObjectName(QStringLiteral("DialogoConsultas"));
        DialogoConsultas->resize(577, 345);
        btnbox_consulta = new QDialogButtonBox(DialogoConsultas);
        btnbox_consulta->setObjectName(QStringLiteral("btnbox_consulta"));
        btnbox_consulta->setGeometry(QRect(210, 310, 156, 23));
        btnbox_consulta->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        opciones_consulta = new QTabWidget(DialogoConsultas);
        opciones_consulta->setObjectName(QStringLiteral("opciones_consulta"));
        opciones_consulta->setGeometry(QRect(10, 10, 561, 291));
        tab_consulta = new QWidget();
        tab_consulta->setObjectName(QStringLiteral("tab_consulta"));
        gridLayoutWidget = new QWidget(tab_consulta);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 541, 241));
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
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        lbl_desde = new QLabel(formLayoutWidget);
        lbl_desde->setObjectName(QStringLiteral("lbl_desde"));

        formLayout->setWidget(1, QFormLayout::LabelRole, lbl_desde);

        dateedit_desde = new QDateEdit(formLayoutWidget);
        dateedit_desde->setObjectName(QStringLiteral("dateedit_desde"));
        dateedit_desde->setButtonSymbols(QAbstractSpinBox::NoButtons);

        formLayout->setWidget(1, QFormLayout::FieldRole, dateedit_desde);

        lbl_hasta = new QLabel(formLayoutWidget);
        lbl_hasta->setObjectName(QStringLiteral("lbl_hasta"));

        formLayout->setWidget(2, QFormLayout::LabelRole, lbl_hasta);

        dateedit_hastsa = new QDateEdit(formLayoutWidget);
        dateedit_hastsa->setObjectName(QStringLiteral("dateedit_hastsa"));
        dateedit_hastsa->setButtonSymbols(QAbstractSpinBox::NoButtons);

        formLayout->setWidget(2, QFormLayout::FieldRole, dateedit_hastsa);

        lbl_etiqueta = new QLabel(formLayoutWidget);
        lbl_etiqueta->setObjectName(QStringLiteral("lbl_etiqueta"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lbl_etiqueta);

        lineedit_etiqueta = new QLineEdit(formLayoutWidget);
        lineedit_etiqueta->setObjectName(QStringLiteral("lineedit_etiqueta"));
        lineedit_etiqueta->setDragEnabled(false);
        lineedit_etiqueta->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineedit_etiqueta);


        layout_consulta->addWidget(groupbox_periodo, 0, 1, 1, 1);

        groupbox_secciones = new QGroupBox(gridLayoutWidget);
        groupbox_secciones->setObjectName(QStringLiteral("groupbox_secciones"));
        lista_secciones_en_consulta = new QListWidget(groupbox_secciones);
        lista_secciones_en_consulta->setObjectName(QStringLiteral("lista_secciones_en_consulta"));
        lista_secciones_en_consulta->setGeometry(QRect(10, 20, 161, 91));

        layout_consulta->addWidget(groupbox_secciones, 1, 1, 1, 1);

        groupbox_conceptos = new QGroupBox(gridLayoutWidget);
        groupbox_conceptos->setObjectName(QStringLiteral("groupbox_conceptos"));
        lista_conceptos_en_consulta = new QListWidget(groupbox_conceptos);
        lista_conceptos_en_consulta->setObjectName(QStringLiteral("lista_conceptos_en_consulta"));
        lista_conceptos_en_consulta->setGeometry(QRect(10, 20, 161, 211));

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

        opciones_consulta->addTab(tab_consulta, QString());
        tab_conceptos = new QWidget();
        tab_conceptos->setObjectName(QStringLiteral("tab_conceptos"));
        horizontalLayoutWidget = new QWidget(tab_conceptos);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 531, 251));
        layout_conceptos = new QHBoxLayout(horizontalLayoutWidget);
        layout_conceptos->setSpacing(6);
        layout_conceptos->setContentsMargins(11, 11, 11, 11);
        layout_conceptos->setObjectName(QStringLiteral("layout_conceptos"));
        layout_conceptos->setContentsMargins(0, 0, 0, 0);
        lista_conceptos = new QListWidget(horizontalLayoutWidget);
        lista_conceptos->setObjectName(QStringLiteral("lista_conceptos"));

        layout_conceptos->addWidget(lista_conceptos);

        btn_agregar_conceptos = new QPushButton(horizontalLayoutWidget);
        btn_agregar_conceptos->setObjectName(QStringLiteral("btn_agregar_conceptos"));

        layout_conceptos->addWidget(btn_agregar_conceptos);

        opciones_consulta->addTab(tab_conceptos, QString());
        horizontalLayoutWidget->raise();
        lista_conceptos->raise();
        tab_periodo = new QWidget();
        tab_periodo->setObjectName(QStringLiteral("tab_periodo"));
        opciones_consulta->addTab(tab_periodo, QString());
        tab_medios = new QWidget();
        tab_medios->setObjectName(QStringLiteral("tab_medios"));
        opciones_consulta->addTab(tab_medios, QString());
        tab_secciones = new QWidget();
        tab_secciones->setObjectName(QStringLiteral("tab_secciones"));
        opciones_consulta->addTab(tab_secciones, QString());
        tab_reporte = new QWidget();
        tab_reporte->setObjectName(QStringLiteral("tab_reporte"));
        opciones_consulta->addTab(tab_reporte, QString());

        retranslateUi(DialogoConsultas);

        opciones_consulta->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(DialogoConsultas);
    } // setupUi

    void retranslateUi(QWidget *DialogoConsultas)
    {
        DialogoConsultas->setWindowTitle(QApplication::translate("DialogoConsultas", "DialogoConsultas", Q_NULLPTR));
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
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_conceptos), QApplication::translate("DialogoConsultas", "Conceptos", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_periodo), QApplication::translate("DialogoConsultas", "Periodo", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_medios), QApplication::translate("DialogoConsultas", "Medios", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_secciones), QApplication::translate("DialogoConsultas", "Secciones", Q_NULLPTR));
        opciones_consulta->setTabText(opciones_consulta->indexOf(tab_reporte), QApplication::translate("DialogoConsultas", "Reportes", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoConsultas: public Ui_DialogoConsultas {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOCONSULTAS_H
