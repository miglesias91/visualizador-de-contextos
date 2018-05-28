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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QAction *action_nueva_cuenta;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *layout_general;
    QVBoxLayout *layout_lista;
    QHBoxLayout *layout_superior;
    QLabel *label;
    QPushButton *btn_eliminar;
    QPushButton *btn_nueva;
    QListWidget *lista_medios_twitter;
    QDialogButtonBox *btnbox_medios_twitter;

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
        action_nueva_cuenta = new QAction(DialogoMediosTwitter);
        action_nueva_cuenta->setObjectName(QStringLiteral("action_nueva_cuenta"));
        verticalLayout = new QVBoxLayout(DialogoMediosTwitter);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        layout_general = new QHBoxLayout();
        layout_general->setSpacing(6);
        layout_general->setObjectName(QStringLiteral("layout_general"));
        layout_lista = new QVBoxLayout();
        layout_lista->setSpacing(0);
        layout_lista->setObjectName(QStringLiteral("layout_lista"));
        layout_superior = new QHBoxLayout();
        layout_superior->setSpacing(6);
        layout_superior->setObjectName(QStringLiteral("layout_superior"));
        label = new QLabel(DialogoMediosTwitter);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(16);
        label->setFont(font);
        label->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        layout_superior->addWidget(label);

        btn_eliminar = new QPushButton(DialogoMediosTwitter);
        btn_eliminar->setObjectName(QStringLiteral("btn_eliminar"));
        btn_eliminar->setMinimumSize(QSize(0, 30));
        btn_eliminar->setMaximumSize(QSize(80, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(11);
        btn_eliminar->setFont(font1);

        layout_superior->addWidget(btn_eliminar);

        btn_nueva = new QPushButton(DialogoMediosTwitter);
        btn_nueva->setObjectName(QStringLiteral("btn_nueva"));
        btn_nueva->setMinimumSize(QSize(0, 30));
        btn_nueva->setMaximumSize(QSize(80, 16777215));
        btn_nueva->setFont(font1);

        layout_superior->addWidget(btn_nueva);


        layout_lista->addLayout(layout_superior);

        lista_medios_twitter = new QListWidget(DialogoMediosTwitter);
        lista_medios_twitter->setObjectName(QStringLiteral("lista_medios_twitter"));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(10);
        lista_medios_twitter->setFont(font2);

        layout_lista->addWidget(lista_medios_twitter);


        layout_general->addLayout(layout_lista);


        verticalLayout->addLayout(layout_general);

        btnbox_medios_twitter = new QDialogButtonBox(DialogoMediosTwitter);
        btnbox_medios_twitter->setObjectName(QStringLiteral("btnbox_medios_twitter"));
        QFont font3;
        font3.setFamily(QStringLiteral("Calibri"));
        font3.setPointSize(11);
        font3.setItalic(false);
        btnbox_medios_twitter->setFont(font3);
        btnbox_medios_twitter->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        btnbox_medios_twitter->setCenterButtons(true);

        verticalLayout->addWidget(btnbox_medios_twitter);


        retranslateUi(DialogoMediosTwitter);
        QObject::connect(lista_medios_twitter, SIGNAL(itemSelectionChanged()), action_estado_btn_eliminar, SLOT(trigger()));
        QObject::connect(btnbox_medios_twitter, SIGNAL(accepted()), action_actualizar_y_cerrar, SLOT(trigger()));
        QObject::connect(btnbox_medios_twitter, SIGNAL(rejected()), DialogoMediosTwitter, SLOT(close()));
        QObject::connect(btn_eliminar, SIGNAL(released()), action_eliminar_cuenta, SLOT(trigger()));
        QObject::connect(btn_nueva, SIGNAL(released()), action_nueva_cuenta, SLOT(trigger()));

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
        action_nueva_cuenta->setText(QApplication::translate("DialogoMediosTwitter", "Nueva cuenta", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_nueva_cuenta->setToolTip(QApplication::translate("DialogoMediosTwitter", "Nueva cuenta", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("DialogoMediosTwitter", "Lista de cuentas de Twitter", Q_NULLPTR));
        btn_eliminar->setText(QApplication::translate("DialogoMediosTwitter", "Eliminar", Q_NULLPTR));
        btn_nueva->setText(QApplication::translate("DialogoMediosTwitter", "Nueva", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoMediosTwitter: public Ui_DialogoMediosTwitter {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOMEDIOSTWITTER_H
