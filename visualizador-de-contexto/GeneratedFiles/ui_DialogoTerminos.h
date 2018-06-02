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
    QWidget *widget_superior;
    QHBoxLayout *layout_superior;
    QLabel *lbl_lista_de_terminos;
    QPushButton *btn_cerrar;
    QListWidget *lista_terminos;

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
        layout_general->setSpacing(0);
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
        widget_superior = new QWidget(widget_lista);
        widget_superior->setObjectName(QStringLiteral("widget_superior"));
        layout_superior = new QHBoxLayout(widget_superior);
        layout_superior->setSpacing(0);
        layout_superior->setContentsMargins(11, 11, 11, 11);
        layout_superior->setObjectName(QStringLiteral("layout_superior"));
        layout_superior->setContentsMargins(0, 0, 0, 0);
        lbl_lista_de_terminos = new QLabel(widget_superior);
        lbl_lista_de_terminos->setObjectName(QStringLiteral("lbl_lista_de_terminos"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        lbl_lista_de_terminos->setFont(font);

        layout_superior->addWidget(lbl_lista_de_terminos);

        btn_cerrar = new QPushButton(widget_superior);
        btn_cerrar->setObjectName(QStringLiteral("btn_cerrar"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btn_cerrar->sizePolicy().hasHeightForWidth());
        btn_cerrar->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QStringLiteral("Calibri"));
        font1.setPointSize(10);
        btn_cerrar->setFont(font1);
        btn_cerrar->setFlat(false);

        layout_superior->addWidget(btn_cerrar);


        layout_lista->addWidget(widget_superior);

        lista_terminos = new QListWidget(widget_lista);
        lista_terminos->setObjectName(QStringLiteral("lista_terminos"));
        QFont font2;
        font2.setFamily(QStringLiteral("Calibri"));
        font2.setPointSize(10);
        font2.setItalic(false);
        lista_terminos->setFont(font2);

        layout_lista->addWidget(lista_terminos);


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
        lbl_lista_de_terminos->setText(QApplication::translate("DialogoTerminos", "Lista de t\303\251rminos", Q_NULLPTR));
        btn_cerrar->setText(QApplication::translate("DialogoTerminos", "Cerrar", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoTerminos: public Ui_DialogoTerminos {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOTERMINOS_H
