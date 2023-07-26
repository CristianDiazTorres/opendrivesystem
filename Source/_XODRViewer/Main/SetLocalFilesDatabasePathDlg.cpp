#include "SetLocalFilesDatabasePathDlg.h"
#include "ui_SetLocalFilesDatabasePathDlg.h"
#include "DB/Main/UserSettingsOnPGDatabase.h"
#include "DB/Main/LocalFilesDatabaseSettings.h"
#include <QFileDialog>

SetLocalFilesDatabasePathDlg::SetLocalFilesDatabasePathDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetLocalFilesDatabasePathDlg)
{
    ui->setupUi(this);
    ui->pathEdt->setText(UserSettingsOnPGDatabase_getDefaultInstance.getLocalFilesDatabasePath());
}

SetLocalFilesDatabasePathDlg::~SetLocalFilesDatabasePathDlg()
{
    delete ui;
}

void SetLocalFilesDatabasePathDlg::on_browseBtn_clicked()
{
    QFileDialog fileDlg;
    fileDlg.setAcceptMode(QFileDialog::AcceptOpen);
    fileDlg.setFileMode(QFileDialog::DirectoryOnly);
    fileDlg.setOption(QFileDialog::ShowDirsOnly);
    fileDlg.setDirectory(ui->pathEdt->text());
    if (!fileDlg.exec())
        return;

    if (fileDlg.selectedFiles().isEmpty())
        return;

    ui->pathEdt->setText(fileDlg.selectedFiles().first());
}

void SetLocalFilesDatabasePathDlg::accept()
{
    UserSettingsOnPGDatabase_getDefaultInstance.setLocalFilesDatabasePath(ui->pathEdt->text());
    LocalFilesDatabaseSettings_initDefaultInstance;

    QDialog::accept();
}
