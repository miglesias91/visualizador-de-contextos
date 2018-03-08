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
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layout_general;
    QHBoxLayout *layout_superior;
    QLabel *lbl_etiqueta;
    QLineEdit *lineedit_etiqueta;
    QPushButton *btn_nuevo;
    QListWidget *lista;

    void setupUi(QWidget *DialogoEditarConcepto)
    {
        if (DialogoEditarConcepto->objectName().isEmpty())
            DialogoEditarConcepto->setObjectName(QStringLiteral("DialogoEditarConcepto"));
        DialogoEditarConcepto->setWindowModality(Qt::NonModal);
        DialogoEditarConcepto->resize(400, 300);
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

        layout_superior->addWidget(lbl_etiqueta);

        lineedit_etiqueta = new QLineEdit(verticalLayoutWidget);
        lineedit_etiqueta->setObjectName(QStringLiteral("lineedit_etiqueta"));

        layout_superior->addWidget(lineedit_etiqueta);

        btn_nuevo = new QPushButton(verticalLayoutWidget);
        btn_nuevo->setObjectName(QStringLiteral("btn_nuevo"));

        layout_superior->addWidget(btn_nuevo);


        layout_general->addLayout(layout_superior);

        lista = new QListWidget(verticalLayoutWidget);
        lista->setObjectName(QStringLiteral("lista"));

        layout_general->addWidget(lista);


        retranslateUi(DialogoEditarConcepto);

        QMetaObject::connectSlotsByName(DialogoEditarConcepto);
    } // setupUi

    void retranslateUi(QWidget *DialogoEditarConcepto)
    {
        DialogoEditarConcepto->setWindowTitle(QApplication::translate("DialogoEditarConcepto", "Editar Concepto", Q_NULLPTR));
        lbl_etiqueta->setText(QApplication::translate("DialogoEditarConcepto", "Etiqueta:", Q_NULLPTR));
        btn_nuevo->setText(QApplication::translate("DialogoEditarConcepto", "Nuevo", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogoEditarConcepto: public Ui_DialogoEditarConcepto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGOEDITARCONCEPTO_H
