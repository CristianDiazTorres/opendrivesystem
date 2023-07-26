#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QDialog>

namespace Ui {
class NewCurvatureSlopeDataChooseDlg;
}

class NewCurvatureSlopeDataChooseDlg : public QDialog
{
    Q_OBJECT

public:
    explicit NewCurvatureSlopeDataChooseDlg(QWidget *parent = 0);
    ~NewCurvatureSlopeDataChooseDlg();

public:
    QString getCurvatureSlopeDataPath();

public Q_SLOTS:
    virtual void accept();

private slots:
    void on_browseBtn_clicked();

private:
    Ui::NewCurvatureSlopeDataChooseDlg *ui;
};

