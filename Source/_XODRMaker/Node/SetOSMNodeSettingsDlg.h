#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QDialog>

namespace Ui {
class SetOSMNodeSettingsDlg;
}

class SetOSMNodeSettingsDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SetOSMNodeSettingsDlg(QWidget *parent = 0);
    ~SetOSMNodeSettingsDlg();

private slots:


public Q_SLOTS:
    virtual void accept();

private:
    Ui::SetOSMNodeSettingsDlg *ui;
};

