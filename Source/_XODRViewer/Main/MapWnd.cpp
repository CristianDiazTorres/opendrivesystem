#include "MapWnd.h"
#include "ui_MapWnd.h"
#include <QPainter>
#include "GeoCoordinate/GeoCoordinate.h"
#include <QDebug>
#include "OSM/TileImage/OSMTileImageDownloader.h"

#ifdef _WIN32
#include "OSGeo4W64/include/gdal.h"
#else
#include "gdal.h"
#endif

#define MIN_SCALE_DENOMINATOR   100
#define MAX_SCALE_DENOMINATOR   5000000

MapWnd::MapWnd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapWnd)
{
    GDALAllRegister();

    centerPos.rx() = 9.4988024437317718e+5;
    centerPos.ry() = -4.2983998316241270e+6;
    (CoordSys&)centerPos = CoordSys::getAusCoordSys();
    //centerPos.rx() = 16112886.04;
    //centerPos.ry() = -4560094.57;
    scaleDenominator = 10000;

    ui->setupUi(this);

    setMouseTracking(true);
    setFocusPolicy(Qt::ClickFocus);

    pressed = false;

    showGPSLayer = true;
    showTrajectoryLayer = true;
    showOSMWayLayer = true;
    showOpenDRIVERoadLayer = true;

    connect(OSMTileImageDownloader_getDefaultInstance, SIGNAL(tileImageDownloaded(_NOSM::OSMTileImageParam))
            , this, SLOT(onOSMTileImageDownloaded(_NOSM::OSMTileImageParam)));

    connect(&timer, SIGNAL(timeout()), this, SLOT(update()));
    timer.setInterval(1000);
    timer.start();
}

MapWnd::~MapWnd()
{
    delete ui;
}

void MapWnd::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    //QWidget::paintEvent(event);

    updateRenderGeomParams();

    QPainter painter(this);
    painter.fillRect(rect(), Qt::white);

    painter.setRenderHint(QPainter::Antialiasing);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);
    painter.setRenderHint(QPainter::HighQualityAntialiasing);

    renderOSM(painter);
}

void MapWnd::updateRenderGeomParams()
{
    // ??? !!!
    centerPos.setFromXY(centerPos, centerPos);

    dpi = logicalDpiX();
    meterToPxRatio = dpi * 100 / 2.54 / scaleDenominator;

    halfWInPx = this->width() / 2.;
    halfHInPx = this->height() / 2.;

    halfWInMeter = halfWInPx / meterToPxRatio;
    halfHInMeter = halfHInPx / meterToPxRatio;

    boundInMeter.setLeft(centerPos.rx() - halfWInMeter);
    boundInMeter.setTop(centerPos.ry() - halfHInMeter);
    boundInMeter.setRight(centerPos.rx() + halfWInMeter);
    boundInMeter.setBottom(centerPos.ry() + halfHInMeter);

    //???!!!
    // need to check min max for boundInMeter

    LLCoordSysXYCellVec corners(4);
    corners[0].setFromXY(boundInMeter.topLeft(), centerPos);
    corners[1].setFromXY(boundInMeter.topRight(), centerPos);
    corners[2].setFromXY(boundInMeter.bottomRight(), centerPos);
    corners[3].setFromXY(boundInMeter.bottomLeft(), centerPos);

    double minLon = _NGC::getMinLon(corners);
    double maxLon = _NGC::getMaxLon(corners);
    double minLat = _NGC::getMinLat(corners);
    double maxLat = _NGC::getMaxLat(corners);

    CLAMP(minLon, -180, 180);
    CLAMP(maxLon, -180, 180);
    CLAMP(minLat, -85.0511, 85.0511);
    CLAMP(maxLat, -85.0511, 85.0511);

    boundInLL.setLeft(minLon);
    boundInLL.setRight(maxLon);
    boundInLL.setTop(minLat);
    boundInLL.setBottom(maxLat);

    meterToPxMat = QMatrix().translate(- centerPos.x(), - centerPos.y());
    meterToPxMat *= QMatrix().scale(meterToPxRatio, - meterToPxRatio);
    meterToPxMat *= QMatrix().translate(halfWInPx, halfHInPx);

    pxToMeterMat = QMatrix().translate(- halfWInPx, - halfHInPx);
    pxToMeterMat *= QMatrix().scale(1 / meterToPxRatio, - 1 / meterToPxRatio);
    pxToMeterMat *= QMatrix().translate(centerPos.x(), centerPos.y());

    double osmZoomLevelTemp = log(meterToPxRatio * 156412 / 1.3) / log(2);
    osmZoomLevel = round(osmZoomLevelTemp);
    if (osmZoomLevel < 0)
        osmZoomLevel = 0;
    else if (osmZoomLevel > 19)
        osmZoomLevel = 19;

    emit updateStatus();
}

void MapWnd::updateCenterPosFrom(const QPointF &px, const QPointF &meter)
{
    QPointF meter1 = pxToMeter(px);
    QPointF deltaInMeter = meter - meter1;
    centerPos += deltaInMeter;
}

void MapWnd::updateCurPos(const QPointF& mousePos)
{
    curPosInPx = mousePos;
    curPos.setFromXY(pxToMeter(curPosInPx), centerPos);

    emit updateStatus();
}

void MapWnd::zoomInOut(const QPointF& mousePos, double ratio)
{
    QPointF inMeter = pxToMeter(mousePos);

    scaleDenominator /= ratio;

    CLAMP(scaleDenominator, MIN_SCALE_DENOMINATOR, MAX_SCALE_DENOMINATOR);

    updateRenderGeomParams();

    updateCenterPosFrom(mousePos, inMeter);
    updateRenderGeomParams();

    update();
}

QPointF MapWnd::pxToMeter(const QPointF& px)
{
    return pxToMeterMat.map(px);
}

QPointF MapWnd::meterToPx(const QPointF& meter)
{
    return meterToPxMat.map(meter);
}

void MapWnd::mousePressEvent(QMouseEvent *event)
{
    QWidget::mousePressEvent(event);

    pressed = true;
    pressedInMeter = pxToMeter(event->localPos());
}

void MapWnd::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);

    pressed = false;
}

void MapWnd::mouseMoveEvent(QMouseEvent *event)
{
    QWidget::mouseMoveEvent(event);

    if (!pressed)
    {
        updateCurPos(event->localPos());
        return;
    }

    updateCenterPosFrom(event->localPos(), pressedInMeter);
    updateRenderGeomParams();
    updateCurPos(event->localPos());

    update();
}

void MapWnd::wheelEvent(QWheelEvent *event)
{
    QWidget::wheelEvent(event);

    zoomInOut(event->posF(), pow(1.2, event->angleDelta().y() / 120));
}

void MapWnd::keyPressEvent(QKeyEvent *event)
{
    QWidget::keyPressEvent(event);

    QPointF mousePos = mapFromGlobal(QCursor::pos());
    if (event->modifiers() & Qt::ControlModifier)
    {
        if (event->key() == Qt::Key_Plus || event->key() == Qt::Key_Equal)
            zoomInOut(mousePos, pow(1.2, 1));
        else if (event->key() == Qt::Key_Minus)
            zoomInOut(mousePos, pow(1.2, -1));
    }
}

void MapWnd::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);

    updateRenderGeomParams();
}

void MapWnd::changeEvent(QEvent *event)
{
    QWidget::changeEvent(event);

    updateRenderGeomParams();
}

void MapWnd::onDoNaviate(double lat, double lon)
{
    _NGC::LL ll(lat, lon);
    _NGC::LLCoordSysXYCell coord;
    coord.setFromLL(ll);

    centerPos = coord;
    updateRenderGeomParams();
    updateCurPos(curPosInPx);

    update();
}

void MapWnd::onShowGPSLayer(bool show)
{
    showGPSLayer = show;
    update();
}

void MapWnd::onShowTrajectoryLayer(bool show)
{
    showTrajectoryLayer = show;
    update();
}

void MapWnd::onShowOSMWayLayer(bool show)
{
    showOSMWayLayer = show;
    update();
}

void MapWnd::onShowOpenDRIVERoadLayer(bool show)
{
    showOpenDRIVERoadLayer = show;
    update();
}

