/********************************************************************************
** Form generated from reading UI file 'DialogoMediosTwitter.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOMEDIOSTWITTER_H
#define UI_DIALOGOMEDIOSTWITTER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoMediosTwitter
{
public:
    QDialogButtonBox *btnbox_medios_twitter;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *layout_general;
    QFormLayout *layout_opciones;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta;
    QLabel *lbl_nombre_usuario;
    QLineEdit *lineedit_nombre_usuario;
    QPushButton *btn_agregar;
    QPushButton *btn_limpiar;
    QPushButton *btn_eliminar;
    QVBoxLayout *layout_lista;
    QListWidget *lista_medios_twitter;

    void setupUi(QWidget *DialogoMediosTwitter)
    {
        if (DialogoMediosTwitter->objectName().isEmpty())
            DialogoMediosTwitter->setObjectName(QStringLiteral("DialogoMediosTwitter"));
        DialogoMediosTwitter->resize(577, 345);
        btnbox_medios_twitter = new QDialogButtonBox(DialogoMediosTwitter);
        btnbox_medios_twitter->setObjectName(QStringLiteral("btnbox_medios_twitter"));
        btnbox_medios_twitter->setGeometry(QRect(200, 300, 156, 23));
        btnbox_medios_twitter->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(DialogoMediosTwitter);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 0, 551, 291));
        layout_general = new QHBoxLayout(horizontalLayoutWidget);
        layout_general->setSpacing(6);
        layout_general->setContentsMargins(11, 11, 11, 11);
        layout_general->setObjectName(QStringLiteral("layout_general"));
        layout_general->setContentsMargins(0, 0, 0, 0);
        layout_opciones = new QFormLayout();
        layout_opciones->setSpacing(6);
        layout_opciones->setObjectName(QStringLiteral("layout_opciones"));
        lbl_etiqueta = new QLabel(horizontalLayoutWidget);
        lbl_etiqueta->setObjectName(QStringLiteral("lbl_etiqueta"));

        layout_opciones->setWidget(0, QFormLayout::LabelRole, lbl_etiqueta);

        lineedit_etiqueta = new QLineEdit(horizontalLayoutWidget);
        lineedit_etiqueta->setObjectName(QStringLiteral("lineedit_etiqueta"));

        layout_opciones->setWidget(0, QFormLayout::FieldRole, lineedit_etiqueta);

        lbl_nombre_usuario = new QLabel(horizontalLayoutWidget);
        lbl_nombre_usuario->setObjectName(QStringLiteral("lbl_nombre_usuario"));

        layout_opciones->setWidget(1, QFormLayout::LabelRole, lbl_nombre_usuario);

        lineedit_nombre_usuario = new QLineEdit(horizontalLayoutWidget);
        lineedit_nombre_usuario->setObjectName(QStringLiteral("lineedit_nombre_usuario"));

        layout_opciones->setWidget(1, QFormLayout::FieldRole, lineedit_nombre_usuario);

        btn_agregar = new QPushButton(horizontalLayoutWidget);
        btn_agregar->setObjectName(QStringLiteral("btn_agregar"));

        layout_opciones->setWidget(2, QFormLayout::FieldRole, btn_agregar);

        btn_limpiar = new QPushButton(horizontalLayoutWidget);
        btn_limpiar->setObjectName(QStringLiteral("btn_limpiar"));

        layout_opciones->setWidget(3, QFormLayout::FieldRole, btn_limpiar);

        btn_eliminar = new QPushButton(horizontalLayoutWidget);
        btn_eliminar->setObjectName(QStringLiteral("btn_eliminar"));

        layout_opciones->setWidget(4, QFormLayout::FieldRole, btn_eliminar);


        layout_general->addLayout(layout_opciones);

        layout_lista = new QVBoxLayout();
        layout_lista->setSpacing(0);
        layout_lista->setObjectName(QStringLiteral("layout_lista"));
        lista_medios_twitter = new QListWidget(horizontalLayoutWidget);
        lista_medios_twitter->setObjectName(QStringLiteral("lista_medios_twitter"));

        layout_lista->addWidget(lista_medios_twitter);


        layout_general->addLayout(layout_lista);


        retranslateUi(DialogoMediosTwitter);

        QMetaObject::connectSlotsByName(DialogoMediosTwitter);
    } // setupUi

    void retranslateUi(QWidget *DialogoMediosTwitter)
    {
        DialogoMediosTwitter->setWindowTitle(QApplication::translate("DialogoMediosTwitter", "DialogoMediosTwitter", Q_NULLPTR));
        lbl_etiqueta->setText(QApplication::translate("DialogoMediosTwitter", "etiqueta", Q_NULLPTR));
        lbl_nombre_usuario->setText(QApplication::translate("DialogoMediosTwitter", "nombre de usuario", Q_NULLPTR));
        lineedit_nombre_usuario->setPlaceholderText(QString());
        btn_agregar->setText(QApplication::translate("DialogoMediosTwitter", "agregar", Q_NULLPTR));
        btn_limpiar->setText(QApplication::translate("DialogoMediosTwitter", "limpiar", Q_NULLPTR));
        btn_eliminar->setText(QApplication::translate("DialogoMediosTwitter", "eliminar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoMediosTwitter: public Ui_DialogoMediosTwitter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOMEDIOSTWITTER_H
