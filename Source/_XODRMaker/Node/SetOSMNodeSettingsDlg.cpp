#include "SetOSMNodeSettingsDlg.h"
#include "ui_SetOSMNodeSettingsDlg.h"
#include "OSM/Node/OSMNodeSettingsOnPGDatabase.h"

SetOSMNodeSettingsDlg::SetOSMNodeSettingsDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetOSMNodeSettingsDlg)
{
    ui->setupUi(this);

}

SetOSMNodeSettingsDlg::~SetOSMNodeSettingsDlg()
{
    delete ui;
}

void SetOSMNodeSettingsDlg::accept()
{
    QDialog::accept();
}
