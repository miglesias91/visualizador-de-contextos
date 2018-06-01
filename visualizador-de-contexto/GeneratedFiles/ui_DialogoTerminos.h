/********************************************************************************
** Form generated from reading UI file 'DialogoTerminos.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOTERMINOS_H
#define UI_DIALOGOTERMINOS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoTerminos
{
public:
    QAction *action_actualizar_y_cerrar;
    QAction *action_resetear_termino;
    QAction *action_guardar_termino;
    QAction *action_eliminar_termino;
    QAction *action_estado_btn_eliminar;
    QAction *action_estado_btn_agregar;
    QVBoxLayout *verticalLayout;
    QWidget *widget_general;
    QHBoxLayout *layout_general;
    QWidget *widget_lista;
    QVBoxLayout *layout_lista;
    QLabel *label;
    QListWidget *lista_terminos;
    QPushButton *btn_cerrar;

    void setupUi(QWidget *DialogoTerminos)
    {
        if (DialogoTerminos->objectName().isEmpty())
            DialogoTerminos->setObjectName(QStringLiteral("DialogoTerminos"));
        DialogoTerminos->resize(800, 400);
        action_actualizar_y_cerrar = new QAction(DialogoTerminos);
        action_actualizar_y_cerrar->setObjectName(QStringLiteral("action_actualizar_y_cerrar"));
        action_actualizar_y_cerrar->setCheckable(true);
        action_resetear_termino = new QAction(DialogoTerminos);
        action_resetear_termino->setObjectName(QStringLiteral("action_resetear_termino"));
        action_resetear_termino->setCheckable(true);
        action_guardar_termino = new QAction(DialogoTerminos);
        action_guardar_termino->setObjectName(QStringLiteral("action_guardar_termino"));
        action_guardar_termino->setCheckable(true);
        action_eliminar_termino = new QAction(DialogoTerminos);
        action_eliminar_termino->setObjectName(QStringLiteral("action_eliminar_termino"));
        action_eliminar_termino->setCheckable(true);
        action_estado_btn_eliminar = new QAction(DialogoTerminos);
        action_estado_btn_eliminar->setObjectName(QStringLiteral("action_estado_btn_eliminar"));
        action_estado_btn_agregar = new QAction(DialogoTerminos);
        action_estado_btn_agregar->setObjectName(QStringLiteral("action_estado_btn_agregar"));
        verticalLayout = new QVBoxLayout(DialogoTerminos);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_general = new QWidget(DialogoTerminos);
        widget_general->setObjectName(QStringLiteral("widget_general"));
        layout_general = new QHBoxLayout(widget_general);
        layout_general->setSpacing(5);
        layout_general->setContentsMargins(11, 11, 11, 11);
        layout_general->setObjectName(QStringLiteral("layout_general"));
        layout_general->setContentsMargins(0, 0, 0, 0);
        widget_lista = new QWidget(widget_general);
        widget_lista->setObjectName(QStringLiteral("widget_lista"));
        layout_lista = new QVBoxLayout(widget_lista);
        layout_lista->setSpacing(2);
        layout_lista->setContentsMargins(11, 11, 11, 11);
        layout_lista->setObjectName(QStringLiteral("layout_lista"));
        layout_lista->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget_lista);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(16);
        label->setFont(font);

        layout_lista->addWidget(label);

        lista_terminos = new QListWidget(widget_lista);
        lista_terminos->setObjectName(QStringLiteral("lista_terminos"));
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(10);
        font1.setItalic(false);
        lista_terminos->setFont(font1);

        layout_lista->addWidget(lista_terminos);

        btn_cerrar = new QPushButton(widget_lista);
        btn_cerrar->setObjectName(QStringLiteral("btn_cerrar"));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(12);
        btn_cerrar->setFont(font2);
        btn_cerrar->setFlat(false);

        layout_lista->addWidget(btn_cerrar, 0, Qt::AlignHCenter);


        layout_general->addWidget(widget_lista);


        verticalLayout->addWidget(widget_general);


        retranslateUi(DialogoTerminos);

        QMetaObject::connectSlotsByName(DialogoTerminos);
    } // setupUi

    void retranslateUi(QWidget *DialogoTerminos)
    {
        DialogoTerminos->setWindowTitle(QApplication::translate("DialogoTerminos", "T\303\251rminos", Q_NULLPTR));
        action_actualizar_y_cerrar->setText(QApplication::translate("DialogoTerminos", "actualiza_y_cerrar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_actualizar_y_cerrar->setToolTip(QApplication::translate("DialogoTerminos", "actualizar y cerrar", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_resetear_termino->setText(QApplication::translate("DialogoTerminos", "resetear_termino", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_resetear_termino->setToolTip(QApplication::translate("DialogoTerminos", "resetear termino", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_resetear_termino->setShortcut(QApplication::translate("DialogoTerminos", "Ctrl+A", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_guardar_termino->setText(QApplication::translate("DialogoTerminos", "guardar_termino", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_guardar_termino->setToolTip(QApplication::translate("DialogoTerminos", "guardar termino", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_guardar_termino->setShortcut(QApplication::translate("DialogoTerminos", "Ctrl+G", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_eliminar_termino->setText(QApplication::translate("DialogoTerminos", "eliminar_termino", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_eliminar_termino->setToolTip(QApplication::translate("DialogoTerminos", "eliminar termino", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        action_eliminar_termino->setShortcut(QApplication::translate("DialogoTerminos", "Ctrl+D", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        action_estado_btn_eliminar->setText(QApplication::translate("DialogoTerminos", "estado_btn_eliminar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_estado_btn_eliminar->setToolTip(QApplication::translate("DialogoTerminos", "estado btn eliminar", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_estado_btn_agregar->setText(QApplication::translate("DialogoTerminos", "estado_btn_agregar", Q_NULLPTR));
        label->setText(QApplication::translate("DialogoTerminos", "Lista de t\303\251rminos", Q_NULLPTR));
        btn_cerrar->setText(QApplication::translate("DialogoTerminos", "Cerrar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoTerminos: public Ui_DialogoTerminos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOTERMINOS_H
