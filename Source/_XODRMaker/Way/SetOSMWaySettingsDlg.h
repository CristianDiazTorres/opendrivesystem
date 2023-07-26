#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QDialog>

namespace Ui {
class SetOSMWaySettingsDlg;
}

class SetOSMWaySettingsDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SetOSMWaySettingsDlg(QWidget *parent = 0);
    ~SetOSMWaySettingsDlg();

private slots:


public Q_SLOTS:
    virtual void accept();

private:
    Ui::SetOSMWaySettingsDlg *ui;
};

