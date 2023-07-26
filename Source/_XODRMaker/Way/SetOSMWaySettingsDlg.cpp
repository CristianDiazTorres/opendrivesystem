#include "SetOSMWaySettingsDlg.h"
#include "ui_SetOSMWaySettingsDlg.h"
#include "OSM/Way/OSMWaySettingsOnPGDatabase.h"

SetOSMWaySettingsDlg::SetOSMWaySettingsDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetOSMWaySettingsDlg)
{
    ui->setupUi(this);

}

SetOSMWaySettingsDlg::~SetOSMWaySettingsDlg()
{
    delete ui;
}

void SetOSMWaySettingsDlg::accept()
{
    QDialog::accept();
}
