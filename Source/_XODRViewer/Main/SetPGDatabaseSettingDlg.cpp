#include "SetPGDatabaseSettingDlg.h"
#include "ui_SetPGDatabaseSettingDlg.h"
#include "DB/Main/DatabaseSettingsOnLocalSystem.h"
#include "DB/Main/PGDatabaseConnector.h"
#include <QMessageBox>

SetPGDatabaseSettingDlg::SetPGDatabaseSettingDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetPGDatabaseSettingDlg)
{
    ui->setupUi(this);

    ui->hostEdt->setText(DatabaseSettingsOnLocalSystem_getDefaultInstance.getHost());
    ui->portEdt->setText(DatabaseSettingsOnLocalSystem_getDefaultInstance.getPort());
    ui->dbEdt->setText(DatabaseSettingsOnLocalSystem_getDefaultInstance.getDBName());
    ui->dbUserEdt->setText(DatabaseSettingsOnLocalSystem_getDefaultInstance.getDBUser());
    ui->pwdEdt->setText(DatabaseSettingsOnLocalSystem_getDefaultInstance.getPassword());
    ui->appUserEdt->setText(DatabaseSettingsOnLocalSystem_getDefaultInstance.getAppUser());
}

SetPGDatabaseSettingDlg::~SetPGDatabaseSettingDlg()
{
    delete ui;
}

void SetPGDatabaseSettingDlg::on_okBtn_clicked()
{
    DatabaseSettingsOnLocalSystem_getDefaultInstance.setHost(ui->hostEdt->text());
    DatabaseSettingsOnLocalSystem_getDefaultInstance.setPort(ui->portEdt->text());
    DatabaseSettingsOnLocalSystem_getDefaultInstance.setDBName(ui->dbEdt->text());
    DatabaseSettingsOnLocalSystem_getDefaultInstance.setDBUser(ui->dbUserEdt->text());
    DatabaseSettingsOnLocalSystem_getDefaultInstance.setPassword(ui->pwdEdt->text());
    DatabaseSettingsOnLocalSystem_getDefaultInstance.setAppUser(ui->appUserEdt->text());

    if (PGDatabaseConnector_getDefaultInstance.reconnect())
    {
        QMessageBox::information(NULL, "PostgreSQL Database Connection", "Connection succeeded.");
        accept();
        return;
    }

    QMessageBox::critical(NULL, "PostgreSQL Database Connection", "Connection failed. Please try again");
}

void SetPGDatabaseSettingDlg::on_cancelBtn_clicked()
{
    reject();
}

void SetPGDatabaseSettingDlg::on_clearDataBtn_clicked()
{
    PGDatabaseConnector_getDefaultInstance.clearData();
}

void SetPGDatabaseSettingDlg::on_clearLogBtn_clicked()
{
    PGDatabaseConnector_getDefaultInstance.clearLogs();
}

void SetPGDatabaseSettingDlg::on_clearSettingBtn_clicked()
{
    PGDatabaseConnector_getDefaultInstance.clearSettings();
}
