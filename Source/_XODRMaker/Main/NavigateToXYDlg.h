#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QDialog>

namespace Ui {
class NavigateToXYDlg;
}

class NavigateToXYDlg : public QDialog
{
    Q_OBJECT

protected:
    LLCoordSysXYCell curCenterPos;

public:
    explicit NavigateToXYDlg(QWidget *parent = 0);
    ~NavigateToXYDlg();
    inline void setCurCenterPos(const LLCoordSysXYCell& curCenterPos)
    {
        this->curCenterPos = curCenterPos;
    }

signals:
    void doNavigate(double lat, double lon);

private slots:
    void on_navigateBtn_clicked();

    void on_closeBtn_clicked();

    void on_xyEdt_textChanged(const QString &arg1);

    void on_xyEdt_returnPressed();

private:
    Ui::NavigateToXYDlg *ui;
};

