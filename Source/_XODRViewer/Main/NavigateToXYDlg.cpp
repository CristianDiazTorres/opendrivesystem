#include "NavigateToXYDlg.h"
#include "ui_NavigateToXYDlg.h"
#include "Math/Math.h"
#include "GeoCoordinate/GeoCoordinate.h"
#include "GeoCoordinate/Main/LLCoordSysXYCell.h"

NavigateToXYDlg::NavigateToXYDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NavigateToXYDlg)
{
    ui->setupUi(this);
    setWindowFlag(Qt::WindowStaysOnTopHint);
}

NavigateToXYDlg::~NavigateToXYDlg()
{
    delete ui;
}

void NavigateToXYDlg::on_navigateBtn_clicked()
{
    _NMath::XY xy;
    xy.parseString(ui->xyEdt->text());

    _NGC::LLCoordSysXYCell coord;
    coord.setFromXY(xy, curCenterPos);

    emit doNavigate(coord.lat, coord.lon);
}

void NavigateToXYDlg::on_closeBtn_clicked()
{
    hide();
}

void NavigateToXYDlg::on_xyEdt_textChanged(const QString &text)
{
    _NMath::XY xy;
    xy.parseString(text);

    _NGC::LLCoordSysXYCell coord;
    coord.setFromXY(xy, curCenterPos);

    ui->llEdt->setText(QString::number(coord.lat, 'f') + ", " + QString::number(coord.lon, 'f'));
}

void NavigateToXYDlg::on_xyEdt_returnPressed()
{
    on_navigateBtn_clicked();
}
