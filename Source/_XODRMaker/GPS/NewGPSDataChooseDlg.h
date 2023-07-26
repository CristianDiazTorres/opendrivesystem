#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QDialog>

namespace Ui {
class NewGPSDataChooseDlg;
}

class NewGPSDataChooseDlg : public QDialog
{
    Q_OBJECT

public:
    explicit NewGPSDataChooseDlg(QWidget *parent = 0);
    ~NewGPSDataChooseDlg();

public:
    QString getGPSFilePath();

public Q_SLOTS:
    virtual void accept();

private slots:
    void on_browseBtn_clicked();

private:
    Ui::NewGPSDataChooseDlg *ui;
};

