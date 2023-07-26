/********************************************************************************
** Form generated from reading UI file 'SetOSMNodeSettingsDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETOSMNODESETTINGSDLG_H
#define UI_SETOSMNODESETTINGSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_SetOSMNodeSettingsDlg
{
public:
    QDialogButtonBox *buttonBox;
    QCheckBox *getCntryAreaOnlyForAUChkBox;

    void setupUi(QDialog *SetOSMNodeSettingsDlg)
    {
        if (SetOSMNodeSettingsDlg->objectName().isEmpty())
            SetOSMNodeSettingsDlg->setObjectName(QStringLiteral("SetOSMNodeSettingsDlg"));
        SetOSMNodeSettingsDlg->resize(520, 285);
        buttonBox = new QDialogButtonBox(SetOSMNodeSettingsDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(150, 230, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        getCntryAreaOnlyForAUChkBox = new QCheckBox(SetOSMNodeSettingsDlg);
        getCntryAreaOnlyForAUChkBox->setObjectName(QStringLiteral("getCntryAreaOnlyForAUChkBox"));
        getCntryAreaOnlyForAUChkBox->setGeometry(QRect(30, 90, 241, 17));

        retranslateUi(SetOSMNodeSettingsDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), SetOSMNodeSettingsDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SetOSMNodeSettingsDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetOSMNodeSettingsDlg);
    } // setupUi

    void retranslateUi(QDialog *SetOSMNodeSettingsDlg)
    {
        SetOSMNodeSettingsDlg->setWindowTitle(QApplication::translate("SetOSMNodeSettingsDlg", "OSM Node Settings", Q_NULLPTR));
        getCntryAreaOnlyForAUChkBox->setText(QApplication::translate("SetOSMNodeSettingsDlg", "Have to get country are only for Australia ?", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetOSMNodeSettingsDlg: public Ui_SetOSMNodeSettingsDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETOSMNODESETTINGSDLG_H
