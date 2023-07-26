/********************************************************************************
** Form generated from reading UI file 'SetPGDatabaseSettingDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPGDATABASESETTINGDLG_H
#define UI_SETPGDATABASESETTINGDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SetPGDatabaseSettingDlg
{
public:
    QLabel *label;
    QLineEdit *hostEdt;
    QLineEdit *portEdt;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *dbEdt;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *dbUserEdt;
    QLineEdit *pwdEdt;
    QPushButton *okBtn;
    QPushButton *cancelBtn;
    QLineEdit *appUserEdt;
    QLabel *label_6;
    QPushButton *clearDataBtn;
    QPushButton *clearLogBtn;
    QPushButton *clearSettingBtn;

    void setupUi(QDialog *SetPGDatabaseSettingDlg)
    {
        if (SetPGDatabaseSettingDlg->objectName().isEmpty())
            SetPGDatabaseSettingDlg->setObjectName(QStringLiteral("SetPGDatabaseSettingDlg"));
        SetPGDatabaseSettingDlg->resize(501, 368);
        label = new QLabel(SetPGDatabaseSettingDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 30, 71, 16));
        hostEdt = new QLineEdit(SetPGDatabaseSettingDlg);
        hostEdt->setObjectName(QStringLiteral("hostEdt"));
        hostEdt->setGeometry(QRect(180, 30, 281, 21));
        portEdt = new QLineEdit(SetPGDatabaseSettingDlg);
        portEdt->setObjectName(QStringLiteral("portEdt"));
        portEdt->setGeometry(QRect(180, 70, 281, 21));
        label_2 = new QLabel(SetPGDatabaseSettingDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 70, 71, 16));
        label_3 = new QLabel(SetPGDatabaseSettingDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 110, 111, 16));
        dbEdt = new QLineEdit(SetPGDatabaseSettingDlg);
        dbEdt->setObjectName(QStringLiteral("dbEdt"));
        dbEdt->setGeometry(QRect(180, 110, 281, 21));
        label_4 = new QLabel(SetPGDatabaseSettingDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 190, 71, 16));
        label_5 = new QLabel(SetPGDatabaseSettingDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 150, 131, 16));
        dbUserEdt = new QLineEdit(SetPGDatabaseSettingDlg);
        dbUserEdt->setObjectName(QStringLiteral("dbUserEdt"));
        dbUserEdt->setGeometry(QRect(180, 150, 281, 21));
        pwdEdt = new QLineEdit(SetPGDatabaseSettingDlg);
        pwdEdt->setObjectName(QStringLiteral("pwdEdt"));
        pwdEdt->setGeometry(QRect(180, 190, 281, 21));
        okBtn = new QPushButton(SetPGDatabaseSettingDlg);
        okBtn->setObjectName(QStringLiteral("okBtn"));
        okBtn->setGeometry(QRect(290, 310, 75, 23));
        cancelBtn = new QPushButton(SetPGDatabaseSettingDlg);
        cancelBtn->setObjectName(QStringLiteral("cancelBtn"));
        cancelBtn->setGeometry(QRect(390, 310, 75, 23));
        appUserEdt = new QLineEdit(SetPGDatabaseSettingDlg);
        appUserEdt->setObjectName(QStringLiteral("appUserEdt"));
        appUserEdt->setGeometry(QRect(180, 230, 281, 21));
        label_6 = new QLabel(SetPGDatabaseSettingDlg);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 230, 71, 16));
        clearDataBtn = new QPushButton(SetPGDatabaseSettingDlg);
        clearDataBtn->setObjectName(QStringLiteral("clearDataBtn"));
        clearDataBtn->setGeometry(QRect(40, 270, 111, 21));
        clearLogBtn = new QPushButton(SetPGDatabaseSettingDlg);
        clearLogBtn->setObjectName(QStringLiteral("clearLogBtn"));
        clearLogBtn->setGeometry(QRect(190, 270, 121, 21));
        clearSettingBtn = new QPushButton(SetPGDatabaseSettingDlg);
        clearSettingBtn->setObjectName(QStringLiteral("clearSettingBtn"));
        clearSettingBtn->setGeometry(QRect(350, 270, 111, 21));

        retranslateUi(SetPGDatabaseSettingDlg);

        QMetaObject::connectSlotsByName(SetPGDatabaseSettingDlg);
    } // setupUi

    void retranslateUi(QDialog *SetPGDatabaseSettingDlg)
    {
        SetPGDatabaseSettingDlg->setWindowTitle(QApplication::translate("SetPGDatabaseSettingDlg", "Database Settings", Q_NULLPTR));
        label->setText(QApplication::translate("SetPGDatabaseSettingDlg", "Host", Q_NULLPTR));
        label_2->setText(QApplication::translate("SetPGDatabaseSettingDlg", "Port", Q_NULLPTR));
        label_3->setText(QApplication::translate("SetPGDatabaseSettingDlg", "Database", Q_NULLPTR));
        label_4->setText(QApplication::translate("SetPGDatabaseSettingDlg", "Password", Q_NULLPTR));
        label_5->setText(QApplication::translate("SetPGDatabaseSettingDlg", "Database User", Q_NULLPTR));
        okBtn->setText(QApplication::translate("SetPGDatabaseSettingDlg", "OK", Q_NULLPTR));
        cancelBtn->setText(QApplication::translate("SetPGDatabaseSettingDlg", "Cancel", Q_NULLPTR));
        label_6->setText(QApplication::translate("SetPGDatabaseSettingDlg", "App User", Q_NULLPTR));
        clearDataBtn->setText(QApplication::translate("SetPGDatabaseSettingDlg", "Clear Data", Q_NULLPTR));
        clearLogBtn->setText(QApplication::translate("SetPGDatabaseSettingDlg", "Clear Log", Q_NULLPTR));
        clearSettingBtn->setText(QApplication::translate("SetPGDatabaseSettingDlg", "Clear Setting", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetPGDatabaseSettingDlg: public Ui_SetPGDatabaseSettingDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPGDATABASESETTINGDLG_H
