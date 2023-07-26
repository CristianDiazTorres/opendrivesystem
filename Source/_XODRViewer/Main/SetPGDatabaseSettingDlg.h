#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QDialog>

namespace Ui {
class SetPGDatabaseSettingDlg;
}

class SetPGDatabaseSettingDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SetPGDatabaseSettingDlg(QWidget *parent = 0);
    ~SetPGDatabaseSettingDlg();

private slots:
    void on_okBtn_clicked();
    void on_cancelBtn_clicked();

    void on_clearDataBtn_clicked();
    void on_clearLogBtn_clicked();
    void on_clearSettingBtn_clicked();

private:
    Ui::SetPGDatabaseSettingDlg *ui;
};
