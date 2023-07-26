/********************************************************************************
** Form generated from reading UI file 'SetOSMCountryAreaSettingsDlg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETOSMCOUNTRYAREASETTINGSDLG_H
#define UI_SETOSMCOUNTRYAREASETTINGSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_SetOSMCountryAreaSettingsDlg
{
public:
    QDialogButtonBox *buttonBox;
    QCheckBox *getCntryAreaOnlyForAUChkBox;

    void setupUi(QDialog *SetOSMCountryAreaSettingsDlg)
    {
        if (SetOSMCountryAreaSettingsDlg->objectName().isEmpty())
            SetOSMCountryAreaSettingsDlg->setObjectName(QStringLiteral("SetOSMCountryAreaSettingsDlg"));
        SetOSMCountryAreaSettingsDlg->resize(520, 285);
        buttonBox = new QDialogButtonBox(SetOSMCountryAreaSettingsDlg);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(150, 230, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        getCntryAreaOnlyForAUChkBox = new QCheckBox(SetOSMCountryAreaSettingsDlg);
        getCntryAreaOnlyForAUChkBox->setObjectName(QStringLiteral("getCntryAreaOnlyForAUChkBox"));
        getCntryAreaOnlyForAUChkBox->setGeometry(QRect(30, 90, 241, 17));

        retranslateUi(SetOSMCountryAreaSettingsDlg);
        QObject::connect(buttonBox, SIGNAL(accepted()), SetOSMCountryAreaSettingsDlg, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SetOSMCountryAreaSettingsDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(SetOSMCountryAreaSettingsDlg);
    } // setupUi

    void retranslateUi(QDialog *SetOSMCountryAreaSettingsDlg)
    {
        SetOSMCountryAreaSettingsDlg->setWindowTitle(QApplication::translate("SetOSMCountryAreaSettingsDlg", "OSM Country Area Settings", Q_NULLPTR));
        getCntryAreaOnlyForAUChkBox->setText(QApplication::translate("SetOSMCountryAreaSettingsDlg", "Get area only for Australia ?", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SetOSMCountryAreaSettingsDlg: public Ui_SetOSMCountryAreaSettingsDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETOSMCOUNTRYAREASETTINGSDLG_H
