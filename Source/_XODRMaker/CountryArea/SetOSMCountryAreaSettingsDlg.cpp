#include "SetOSMCountryAreaSettingsDlg.h"
#include "ui_SetOSMCountryAreaSettingsDlg.h"
#include "OSM/CountryArea/OSMCountryAreaSettingsOnPGDatabase.h"

SetOSMCountryAreaSettingsDlg::SetOSMCountryAreaSettingsDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetOSMCountryAreaSettingsDlg)
{
    ui->setupUi(this);
    ui->getCntryAreaOnlyForAUChkBox->setChecked(OSMCountryAreaSettingsOnPGDatabase_getDefaultInstance.haveToGetCountryAreaOnlyForAU());
}

SetOSMCountryAreaSettingsDlg::~SetOSMCountryAreaSettingsDlg()
{
    delete ui;
}

void SetOSMCountryAreaSettingsDlg::accept()
{
    OSMCountryAreaSettingsOnPGDatabase_getDefaultInstance.setHaveToGetCountryAreaOnlyForAU(ui->getCntryAreaOnlyForAUChkBox->isChecked());

    QDialog::accept();
}
