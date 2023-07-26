#include "NewGPSDataChooseDlg.h"
#include "ui_NewGPSDataChooseDlg.h"
#include <QFileDialog>
#include <QMessageBox>
#include "GPS/GPSSettingsOnPGDatabase.h"

NewGPSDataChooseDlg::NewGPSDataChooseDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewGPSDataChooseDlg)
{
    ui->setupUi(this);

    ui->gpsPathEdt->setText(GPSSettingsOnPGDatabase_getDefaultInstance.getValue("LastGPSFilePath"));
//    ui->continueChkBox->setChecked(GPSSettingsOnPGDatabase_getDefaultInstance.getValue("LastGPSFileContinue") == "yes");
//    ui->countEdt->setText(GPSSettingsOnPGDatabase_getDefaultInstance.getValue("LastGPSFileLineCount"));
}

NewGPSDataChooseDlg::~NewGPSDataChooseDlg()
{
    delete ui;
}

QString NewGPSDataChooseDlg::getGPSFilePath()
{
    return ui->gpsPathEdt->text();
}

void NewGPSDataChooseDlg::accept()
{
    if (getGPSFilePath().isEmpty())
    {
        QMessageBox::critical(this, "Warning", "Please choose a valid file");
        return;
    }

    GPSSettingsOnPGDatabase_getDefaultInstance.setValue("LastGPSFilePath", ui->gpsPathEdt->text());
//    GPSSettingsOnPGDatabase_getDefaultInstance.setValue("LastGPSFileContinue", ui->continueChkBox->isChecked() ? "yes" : "no");
//    GPSSettingsOnPGDatabase_getDefaultInstance.setValue("LastGPSFileLineCount", ui->countEdt->text());

    QDialog::accept();
}

void NewGPSDataChooseDlg::on_browseBtn_clicked()
{
    QFileDialog fileDlg;
    fileDlg.setAcceptMode(QFileDialog::AcceptOpen);
    fileDlg.setFileMode(QFileDialog::ExistingFile);

    if (getGPSFilePath().isEmpty())
    {
        fileDlg.setDirectory(QCoreApplication::applicationDirPath());
    }
    else
    {
        fileDlg.setDirectory(QFileInfo(getGPSFilePath()).absoluteDir());
    }

    if (!fileDlg.exec())
        return;

    if (fileDlg.selectedFiles().isEmpty())
        return;

    ui->gpsPathEdt->setText(fileDlg.selectedFiles().first());
}
