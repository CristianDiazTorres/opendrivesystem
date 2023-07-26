#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QDialog>

namespace Ui {
class SetOSMCountryAreaSettingsDlg;
}

class SetOSMCountryAreaSettingsDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SetOSMCountryAreaSettingsDlg(QWidget *parent = 0);
    ~SetOSMCountryAreaSettingsDlg();

private slots:


public Q_SLOTS:
    virtual void accept();

private:
    Ui::SetOSMCountryAreaSettingsDlg *ui;
};

