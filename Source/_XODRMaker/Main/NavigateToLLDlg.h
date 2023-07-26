#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QDialog>

namespace Ui {
class NavigateToLLDlg;
}

class NavigateToLLDlg : public QDialog
{
    Q_OBJECT

public:
    explicit NavigateToLLDlg(QWidget *parent = 0);
    ~NavigateToLLDlg();

signals:
    void doNavigate(double lat, double lon);

private slots:
    void on_navigateBtn_clicked();

    void on_closeBtn_clicked();

    void on_llEdt_textChanged(const QString &arg1);

    void on_llEdt_returnPressed();

private:
    Ui::NavigateToLLDlg *ui;
};

