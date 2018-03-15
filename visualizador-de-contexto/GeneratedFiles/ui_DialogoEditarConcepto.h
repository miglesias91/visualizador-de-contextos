/********************************************************************************
** Form generated from reading UI file 'DialogoEditarConcepto.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGOEDITARCONCEPTO_H
#define UI_DIALOGOEDITARCONCEPTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogoEditarConcepto
{
public:
    QAction *action_eliminar;
    QAction *action_nuevo;
    QAction *action_ok;
    QAction *action_editar;
    QAction *action_actualizar_termino;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layout_general;
    QHBoxLayout *layout_superior;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta;
    QPushButton *btn_eliminar;
    QPushButton *btn_nuevo;
    QListWidget *lista;
    QDialogButtonBox *btnbox;

    void setupUi(QWidget *DialogoEditarConcepto)
    {
        if (DialogoEditarConcepto->objectName().isEmpty())
            DialogoEditarConcepto->setObjectName(QStringLiteral("DialogoEditarConcepto"));
        DialogoEditarConcepto->setWindowModality(Qt::NonModal);
        DialogoEditarConcepto->resize(400, 300);
        action_eliminar = new QAction(DialogoEditarConcepto);
        action_eliminar->setObjectName(QStringLiteral("action_eliminar"));
        action_nuevo = new QAction(DialogoEditarConcepto);
        action_nuevo->setObjectName(QStringLiteral("action_nuevo"));
        action_ok = new QAction(DialogoEditarConcepto);
        action_ok->setObjectName(QStringLiteral("action_ok"));
        action_editar = new QAction(DialogoEditarConcepto);
        action_editar->setObjectName(QStringLiteral("action_editar"));
        action_actualizar_termino = new QAction(DialogoEditarConcepto);
        action_actualizar_termino->setObjectName(QStringLiteral("action_actualizar_termino"));
        verticalLayoutWidget = new QWidget(DialogoEditarConcepto);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 381, 281));
        layout_general = new QVBoxLayout(verticalLayoutWidget);
        layout_general->setSpacing(6);
        layout_general->setContentsMargins(11, 11, 11, 11);
        layout_general->setObjectName(QStringLiteral("layout_general"));
        layout_general->setContentsMargins(0, 0, 0, 0);
        layout_superior = new QHBoxLayout();
        layout_superior->setSpacing(6);
        layout_superior->setObjectName(QStringLiteral("layout_superior"));
        lbl_etiqueta = new QLabel(verticalLayoutWidget);
        lbl_etiqueta->setObjectName(QStringLiteral("lbl_etiqueta"));
        QFont font;
        font.setFamily(QStringLiteral("Calibri"));
        font.setPointSize(12);
        lbl_etiqueta->setFont(font);

        layout_superior->addWidget(lbl_etiqueta);

        lineedit_etiqueta = new QLineEdit(verticalLayoutWidget);
        lineedit_etiqueta->setObjectName(QStringLiteral("lineedit_etiqueta"));

        layout_superior->addWidget(lineedit_etiqueta);

        btn_eliminar = new QPushButton(verticalLayoutWidget);
        btn_eliminar->setObjectName(QStringLiteral("btn_eliminar"));
        btn_eliminar->setMinimumSize(QSize(0, 30));
        btn_eliminar->setMaximumSize(QSize(80, 16777215));
        btn_eliminar->setFont(font);

        layout_superior->addWidget(btn_eliminar);

        btn_nuevo = new QPushButton(verticalLayoutWidget);
        btn_nuevo->setObjectName(QStringLiteral("btn_nuevo"));
        btn_nuevo->setMinimumSize(QSize(0, 30));
        btn_nuevo->setMaximumSize(QSize(80, 16777215));
        btn_nuevo->setFont(font);

        layout_superior->addWidget(btn_nuevo);


        layout_general->addLayout(layout_superior);

        lista = new QListWidget(verticalLayoutWidget);
        lista->setObjectName(QStringLiteral("lista"));

        layout_general->addWidget(lista);

        btnbox = new QDialogButtonBox(verticalLayoutWidget);
        btnbox->setObjectName(QStringLiteral("btnbox"));
        btnbox->setEnabled(true);
        btnbox->setFont(font);
        btnbox->setLayoutDirection(Qt::LeftToRight);
        btnbox->setOrientation(Qt::Horizontal);
        btnbox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Save);
        btnbox->setCenterButtons(true);

        layout_general->addWidget(btnbox);


        retranslateUi(DialogoEditarConcepto);
        QObject::connect(btn_nuevo, SIGNAL(released()), action_nuevo, SLOT(trigger()));
        QObject::connect(btn_eliminar, SIGNAL(released()), action_eliminar, SLOT(trigger()));
        QObject::connect(btnbox, SIGNAL(accepted()), action_ok, SLOT(trigger()));
        QObject::connect(btnbox, SIGNAL(rejected()), DialogoEditarConcepto, SLOT(close()));

        QMetaObject::connectSlotsByName(DialogoEditarConcepto);
    } // setupUi

    void retranslateUi(QWidget *DialogoEditarConcepto)
    {
        DialogoEditarConcepto->setWindowTitle(QApplication::translate("DialogoEditarConcepto", "Editar Concepto", Q_NULLPTR));
        action_eliminar->setText(QApplication::translate("DialogoEditarConcepto", "Eliminar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_eliminar->setToolTip(QApplication::translate("DialogoEditarConcepto", "Eliminar", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_nuevo->setText(QApplication::translate("DialogoEditarConcepto", "Nuevo", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_nuevo->setToolTip(QApplication::translate("DialogoEditarConcepto", "Nuevo", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_ok->setText(QApplication::translate("DialogoEditarConcepto", "OK", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_ok->setToolTip(QApplication::translate("DialogoEditarConcepto", "OK", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_editar->setText(QApplication::translate("DialogoEditarConcepto", "Editar", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_editar->setToolTip(QApplication::translate("DialogoEditarConcepto", "Editar", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        action_actualizar_termino->setText(QApplication::translate("DialogoEditarConcepto", "Actualizar termino", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        action_actualizar_termino->setToolTip(QApplication::translate("DialogoEditarConcepto", "Actualizar termino", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        lbl_etiqueta->setText(QApplication::translate("DialogoEditarConcepto", "Etiqueta:", Q_NULLPTR));
        btn_eliminar->setText(QApplication::translate("DialogoEditarConcepto", "Eliminar", Q_NULLPTR));
        btn_nuevo->setText(QApplication::translate("DialogoEditarConcepto", "Nuevo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoEditarConcepto: public Ui_DialogoEditarConcepto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOEDITARCONCEPTO_H
