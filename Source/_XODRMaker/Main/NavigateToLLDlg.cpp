#include "NavigateToLLDlg.h"
#include "ui_NavigateToLLDlg.h"
#include "Math/Math.h"
#include "GeoCoordinate/GeoCoordinate.h"
#include "GeoCoordinate/Main/LLCoordSysXYCell.h"

NavigateToLLDlg::NavigateToLLDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NavigateToLLDlg)
{
    ui->setupUi(this);
    setWindowFlag(Qt::WindowStaysOnTopHint);
}

NavigateToLLDlg::~NavigateToLLDlg()
{
    delete ui;
}

void NavigateToLLDlg::on_navigateBtn_clicked()
{
    _NGC::LL ll;
    ll.parseString(ui->llEdt->text());

    emit doNavigate(ll.lat, ll.lon);
}

void NavigateToLLDlg::on_closeBtn_clicked()
{
    hide();
}

void NavigateToLLDlg::on_llEdt_textChanged(const QString &text)
{
    _NGC::LL ll;
    ll.parseString(text);

    _NGC::LLCoordSysXYCell coord;
    coord.setFromLL(ll);

    ui->xyEdt->setText(QString::number(coord.x(), 'f') + ", " + QString::number(coord.y(), 'f'));
}

void NavigateToLLDlg::on_llEdt_returnPressed()
{
    on_navigateBtn_clicked();
}
