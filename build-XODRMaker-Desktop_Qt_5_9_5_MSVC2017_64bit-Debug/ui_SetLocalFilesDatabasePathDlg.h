/********************************************************************************
** Form generated from reading UI file 'SetLocalFilesDatabasePathDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETLOCALFILESDATABASEPATHDLG_H
#define UI_SETLOCALFILESDATABASEPATHDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SetLocalFilesDatabasePathDlg
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *pathEdt;
    QLabel *label;
    QPushButton *browseBtn;

    void setupUi(QDialog *SetLocalFilesDatabasePathDlg)
    {
        if (SetLocalFilesDatabasePathDlg->objectName().isEmpty())
            SetLocalFilesDatabasePathDlg->setObjectName(QStringLiteral("SetLocalFilesDatabasePathDlg"));
        SetLocalFilesDatabasePathDlg->resize(736, 175);
        buttonBox = new QDialogButtonBox(SetLocalFilesDatabasePathDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(370, 120, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        pathEdt = new QLineEdit(SetLocalFilesDatabasePathDlg);
        pathEdt->setObjectName(QStringLiteral("pathEdt"));
        pathEdt->setGeometry(QRect(30, 70, 631, 31));
        label = new QLabel(SetLocalFilesDatabasePathDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 241, 31));
        browseBtn = new QPushButton(SetLocalFilesDatabasePathDlg);
        browseBtn->setObjectName(QStringLiteral("browseBtn"));
        browseBtn->setGeometry(QRect(670, 70, 41, 31));

        retranslateUi(SetLocalFilesDatabasePathDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), SetLocalFilesDatabasePathDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SetLocalFilesDatabasePathDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetLocalFilesDatabasePathDlg);
    } // setupUi

    void retranslateUi(QDialog *SetLocalFilesDatabasePathDlg)
    {
        SetLocalFilesDatabasePathDlg->setWindowTitle(QApplication::translate("SetLocalFilesDatabasePathDlg", "Set Local Files Database Path", Q_NULLPTR));
        label->setText(QApplication::translate("SetLocalFilesDatabasePathDlg", "Please input Local Files Database Path", Q_NULLPTR));
        browseBtn->setText(QApplication::translate("SetLocalFilesDatabasePathDlg", "...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetLocalFilesDatabasePathDlg: public Ui_SetLocalFilesDatabasePathDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETLOCALFILESDATABASEPATHDLG_H
