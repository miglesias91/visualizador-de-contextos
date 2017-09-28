#pragma once

// qt
#include <QtWidgets/qdialogbuttonbox.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qcheckbox.h>
#include <QtWidgets/qlineedit.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qboxlayout.h>
#include <QtWidgets/qdialog.h>

class DialogoPrincipal : public QDialog
{

public:
	DialogoPrincipal(QWidget *parent = 0);
	~DialogoPrincipal();


private:
	QLabel *label;
	QLineEdit *lineEdit;
	QCheckBox *caseCheckBox;
	QCheckBox *fromStartCheckBox;
	QCheckBox *wholeWordsCheckBox;
	QCheckBox *searchSelectionCheckBox;
	QCheckBox *backwardCheckBox;
	QDialogButtonBox *buttonBox;
	QPushButton *findButton;
	QPushButton *moreButton;
	QWidget *extension;

	
};

