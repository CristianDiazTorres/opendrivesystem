/********************************************************************************
** Form generated from reading UI file 'SetOSMWaySettingsDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETOSMWAYSETTINGSDLG_H
#define UI_SETOSMWAYSETTINGSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_SetOSMWaySettingsDlg
{
public:
    QDialogButtonBox *buttonBox;
    QCheckBox *getCntryAreaOnlyForAUChkBox;

    void setupUi(QDialog *SetOSMWaySettingsDlg)
    {
        if (SetOSMWaySettingsDlg->objectName().isEmpty())
            SetOSMWaySettingsDlg->setObjectName(QStringLiteral("SetOSMWaySettingsDlg"));
        SetOSMWaySettingsDlg->resize(520, 285);
        buttonBox = new QDialogButtonBox(SetOSMWaySettingsDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(150, 230, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        getCntryAreaOnlyForAUChkBox = new QCheckBox(SetOSMWaySettingsDlg);
        getCntryAreaOnlyForAUChkBox->setObjectName(QStringLiteral("getCntryAreaOnlyForAUChkBox"));
        getCntryAreaOnlyForAUChkBox->setGeometry(QRect(30, 90, 241, 17));

        retranslateUi(SetOSMWaySettingsDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), SetOSMWaySettingsDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SetOSMWaySettingsDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetOSMWaySettingsDlg);
    } // setupUi

    void retranslateUi(QDialog *SetOSMWaySettingsDlg)
    {
        SetOSMWaySettingsDlg->setWindowTitle(QApplication::translate("SetOSMWaySettingsDlg", "OSM Way Settings", Q_NULLPTR));
        getCntryAreaOnlyForAUChkBox->setText(QApplication::translate("SetOSMWaySettingsDlg", "Have to get country are only for Australia ?", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetOSMWaySettingsDlg: public Ui_SetOSMWaySettingsDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETOSMWAYSETTINGSDLG_H
