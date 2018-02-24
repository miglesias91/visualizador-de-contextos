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
    QAction *action_actualizar_y_cerrar;
    QAction *action_resetear_cuenta;
    QAction *action_guardar_cuenta;
    QAction *action_eliminar_cuenta;
    QAction *action_estado_btn_eliminar;
    QAction *action_estado_btn_agregar;
    QDialogButtonBox *btnbox_medios_twitter;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *layout_general;
    QFormLayout *layout_opciones;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta;
    QLabel *lbl_nombre_usuario;
    QPushButton *btn_agregar;
    QPushButton *btn_limpiar;
    QPushButton *btn_eliminar;
    QLineEdit *lineedit_nombre_usuario;
    QVBoxLayout *layout_lista;
    QListWidget *lista_medios_twitter;

    void setupUi(QWidget *DialogoMediosTwitter)
    {
        if (DialogoMediosTwitter->objectName().isEmpty())
            DialogoMediosTwitter->setObjectName(QStringLiteral("DialogoMediosTwitter"));
        DialogoMediosTwitter->resize(800, 400);
        action_actualizar_y_cerrar = new QAction(DialogoMediosTwitter);
        action_actualizar_y_cerrar->setObjectName(QStringLiteral("action_actualizar_y_cerrar"));
        action_actualizar_y_cerrar->setCheckable(true);
        action_resetear_cuenta = new QAction(DialogoMediosTwitter);
        action_resetear_cuenta->setObjectName(QStringLiteral("action_resetear_cuenta"));
        action_resetear_cuenta->setCheckable(true);
        action_guardar_cuenta = new QAction(DialogoMediosTwitter);
        action_guardar_cuenta->setObjectName(QStringLiteral("action_guardar_cuenta"));
        action_guardar_cuenta->setCheckable(true);
        action_eliminar_cuenta = new QAction(DialogoMediosTwitter);
        action_eliminar_cuenta->setObjectName(QStringLiteral("action_eliminar_cuenta"));
        action_eliminar_cuenta->setCheckable(true);
        action_estado_btn_eliminar = new QAction(DialogoMediosTwitter);
        action_estado_btn_eliminar->setObjectName(QStringLiteral("action_estado_btn_eliminar"));
        action_estado_btn_agregar = new QAction(DialogoMediosTwitter);
        action_estado_btn_agregar->setObjectName(QStringLiteral("action_estado_btn_agregar"));
        btnbox_medios_twitter = new QDialogButtonBox(DialogoMediosTwitter);
        btnbox_medios_twitter->setObjectName(QStringLiteral("btnbox_medios_twitter"));
        btnbox_medios_twitter->setGeometry(QRect(325, 370, 156, 23));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(11);
        font.setItalic(true);
        btnbox_medios_twitter->setFont(font);
        btnbox_medios_twitter->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        horizontalLayoutWidget = new QWidget(DialogoMediosTwitter);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 781, 351));
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
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(12);
        lbl_etiqueta->setFont(font1);

        layout_opciones->setWidget(0, QFormLayout::LabelRole, lbl_etiqueta);

        lineedit_etiqueta = new QLineEdit(horizontalLayoutWidget);
        lineedit_etiqueta->setObjectName(QStringLiteral("lineedit_etiqueta"));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(10);
        font2.setItalic(true);
        lineedit_etiqueta->setFont(font2);

        layout_opciones->setWidget(0, QFormLayout::FieldRole, lineedit_etiqueta);

        lbl_nombre_usuario = new QLabel(horizontalLayoutWidget);
        lbl_nombre_usuario->setObjectName(QStringLiteral("lbl_nombre_usuario"));
        lbl_nombre_usuario->setFont(font1);

        layout_opciones->setWidget(1, QFormLayout::LabelRole, lbl_nombre_usuario);

        btn_agregar = new QPushButton(horizontalLayoutWidget);
        btn_agregar->setObjectName(QStringLiteral("btn_agregar"));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        font3.setPointSize(11);
        btn_agregar->setFont(font3);

        layout_opciones->setWidget(2, QFormLayout::FieldRole, btn_agregar);

        btn_limpiar = new QPushButton(horizontalLayoutWidget);
        btn_limpiar->setObjectName(QStringLiteral("btn_limpiar"));
        btn_limpiar->setFont(font3);

        layout_opciones->setWidget(3, QFormLayout::FieldRole, btn_limpiar);

        btn_eliminar = new QPushButton(horizontalLayoutWidget);
        btn_eliminar->setObjectName(QStringLiteral("btn_eliminar"));
        btn_eliminar->setFont(font3);

        layout_opciones->setWidget(4, QFormLayout::FieldRole, btn_eliminar);

        lineedit_nombre_usuario = new QLineEdit(horizontalLayoutWidget);
        lineedit_nombre_usuario->setObjectName(QStringLiteral("lineedit_nombre_usuario"));
        QFont font4;
        font4.setFamily(QStringLiteral("Calibri"));
        font4.setPointSize(10);
        font4.setBold(false);
        font4.setWeight(50);
        lineedit_nombre_usuario->setFont(font4);

        layout_opciones->setWidget(1, QFormLayout::FieldRole, lineedit_nombre_usuario);


        layout_general->addLayout(layout_opciones);

        layout_lista = new QVBoxLayout();
        layout_lista->setSpacing(0);
        layout_lista->setObjectName(QStringLiteral("layout_lista"));
        lista_medios_twitter = new QListWidget(horizontalLayoutWidget);
        lista_medios_twitter->setObjectName(QStringLiteral("lista_medios_twitter"));
        QFont font5;
        font5.setFamily(QStringLiteral("Calibri"));
        font5.setPointSize(10);
        lista_medios_twitter->setFont(font5);

        layout_lista->addWidget(lista_medios_twitter);


        layout_general->addLayout(layout_lista);


        retranslateUi(DialogoMediosTwitter);
        QObject::connect(lista_medios_twitter, SIGNAL(itemSelectionChanged()), action_estado_btn_eliminar, SLOT(trigger()));
        QObject::connect(lineedit_nombre_usuario, SIGNAL(textEdited(QString)), action_estado_btn_agregar, SLOT(trigger()));
        QObject::connect(btnbox_medios_twitter, SIGNAL(accepted()), action_actualizar_y_cerrar, SLOT(trigger()));
        QObject::connect(btnbox_medios_twitter, SIGNAL(rejected()), DialogoMediosTwitter, SLOT(close()));
        QObject::connect(btn_limpiar, SIGNAL(released()), action_resetear_cuenta, SLOT(trigger()));
        QObject::connect(btn_eliminar, SIGNAL(released()), action_eliminar_cuenta, SLOT(trigger()));
        QObject::connect(btn_agregar, SIGNAL(released()), action_guardar_cuenta, SLOT(trigger()));

        QMetaObject::connectSlotsByName(DialogoMediosTwitter);
    } // setupUi

    void retranslateUi(QWidget *DialogoMediosTwitter)
    {
        DialogoMediosTwitter->setWindowTitle(QApplication::translate("DialogoMediosTwitter", "Cuentas de Twitter", Q_NULLPTR));
        action_actualizar_y_cerrar->setText(QApplication::translate("DialogoMediosTwitter", "actualiza_y_cerrar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_actualizar_y_cerrar->setToolTip(QApplication::translate("DialogoMediosTwitter", "actualizar y cerrar", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_resetear_cuenta->setText(QApplication::translate("DialogoMediosTwitter", "resetear_cuenta", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_resetear_cuenta->setToolTip(QApplication::translate("DialogoMediosTwitter", "resetear cuenta", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_resetear_cuenta->setShortcut(QApplication::translate("DialogoMediosTwitter", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_guardar_cuenta->setText(QApplication::translate("DialogoMediosTwitter", "guardar_cuenta", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_guardar_cuenta->setToolTip(QApplication::translate("DialogoMediosTwitter", "guardar cuenta", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_guardar_cuenta->setShortcut(QApplication::translate("DialogoMediosTwitter", "Ctrl+G", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_eliminar_cuenta->setText(QApplication::translate("DialogoMediosTwitter", "eliminar_cuenta", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_eliminar_cuenta->setToolTip(QApplication::translate("DialogoMediosTwitter", "eliminar cuenta", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_eliminar_cuenta->setShortcut(QApplication::translate("DialogoMediosTwitter", "Ctrl+D", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_estado_btn_eliminar->setText(QApplication::translate("DialogoMediosTwitter", "estado_btn_eliminar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_estado_btn_eliminar->setToolTip(QApplication::translate("DialogoMediosTwitter", "estado btn eliminar", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_estado_btn_agregar->setText(QApplication::translate("DialogoMediosTwitter", "estado_btn_agregar", Q_NULLPTR));
        lbl_etiqueta->setText(QApplication::translate("DialogoMediosTwitter", "Etiqueta", Q_NULLPTR));
        lbl_nombre_usuario->setText(QApplication::translate("DialogoMediosTwitter", "Nombre de usuario", Q_NULLPTR));
        btn_agregar->setText(QApplication::translate("DialogoMediosTwitter", "Agregar", Q_NULLPTR));
        btn_limpiar->setText(QApplication::translate("DialogoMediosTwitter", "Limpiar", Q_NULLPTR));
        btn_eliminar->setText(QApplication::translate("DialogoMediosTwitter", "Eliminar", Q_NULLPTR));
        lineedit_nombre_usuario->setText(QString());
        lineedit_nombre_usuario->setPlaceholderText(QString());
    } // retranslateUi

};

namespace Ui {
    class DialogoMediosTwitter: public Ui_DialogoMediosTwitter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOMEDIOSTWITTER_H
