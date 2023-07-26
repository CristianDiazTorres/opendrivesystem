#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QDialog>

namespace Ui {
class SetLocalFilesDatabasePathDlg;
}

class SetLocalFilesDatabasePathDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SetLocalFilesDatabasePathDlg(QWidget *parent = 0);
    ~SetLocalFilesDatabasePathDlg();

private slots:
    void on_browseBtn_clicked();

public Q_SLOTS:
    virtual void accept();

private:
    Ui::SetLocalFilesDatabasePathDlg *ui;
};

