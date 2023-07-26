#include "NewCurvatureSlopeDataChooseDlg.h"
#include "ui_NewCurvatureSlopeDataChooseDlg.h"
#include <QFileDialog>
#include <QMessageBox>
//#include "_XODRMaker/Main/ODSSettingsOnPGDatabase.h"

NewCurvatureSlopeDataChooseDlg::NewCurvatureSlopeDataChooseDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewCurvatureSlopeDataChooseDlg)
{
    ui->setupUi(this);

//    ui->pathEdt->setText(DefaultODSSettingsOnPGDatabase.getValue("LastCurvatureSlopeDataPath"));
}

NewCurvatureSlopeDataChooseDlg::~NewCurvatureSlopeDataChooseDlg()
{
    delete ui;
}

QString NewCurvatureSlopeDataChooseDlg::getCurvatureSlopeDataPath()
{
    return ui->pathEdt->text();
}

void NewCurvatureSlopeDataChooseDlg::accept()
{
    if (getCurvatureSlopeDataPath().isEmpty())
    {
        QMessageBox::critical(this, "Warning", "Please choose a valid path");
        return;
    }

//    DefaultODSSettingsOnPGDatabase.setValue("LastCurvatureSlopeDataPath", ui->pathEdt->text());

    QDialog::accept();
}

void NewCurvatureSlopeDataChooseDlg::on_browseBtn_clicked()
{
    QFileDialog fileDlg;
    fileDlg.setAcceptMode(QFileDialog::AcceptOpen);
    fileDlg.setFileMode(QFileDialog::DirectoryOnly);

    if (getCurvatureSlopeDataPath().isEmpty())
    {
        fileDlg.setDirectory(QCoreApplication::applicationDirPath());
    }
    else
    {
        fileDlg.setDirectory(getCurvatureSlopeDataPath());
    }

    if (!fileDlg.exec())
        return;

    if (fileDlg.selectedFiles().isEmpty())
        return;

    ui->pathEdt->setText(fileDlg.selectedFiles().first());
}
