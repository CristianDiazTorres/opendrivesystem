#include "MapWnd.h"
#include "ui_MapWnd.h"
#include <QPainter>
#include "GeoCoordinate/GeoCoordinate.h"
#include "DB/Main/LocalFilesDatabaseConnector.h"
#include <QDebug>

MapWnd::MapWnd(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MapWnd)
{
    ui->setupUi(this);

    setMouseTracking(true);

    centerPos.rx() = 9.4988024437317718e+5;
    centerPos.ry() = -4.2983998316241270e+6;
    scaleDenominator = 10000;
    updateRenderGeomParams();

    pressed = false;

    showGPSLayer = true;
    showTrajectoryLayer = true;
    showOSMWayLayer = true;
    showOpenDRIVERoadLayer = true;
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

    return;

    //painter.setMatrix(meterToPxMat);
    /*
    QVector<_NGC::Cell> cells = _NGC::Cell::getCells(boundInMeter);

    //qDebug() << "**********:" << cells.size();

    LocalFilesDatabaseConnector db;
    for (_NGC::Cell cell : cells)
    {
        //qDebug() << "Rendering cell : " << cell.cellRow << " , " << cell.cellCol;

        _NOD::OpenDRIVE odContent = db.getXODRContent(cell);
        odContent.setParent();
        renderGPSTrajectory(painter, odContent);

        if (showOSMWayLayer)
            renderOSMWay(painter, odContent);

        render(painter, odContent);
    }

    renderScaleRuler(painter);
    */
}

void MapWnd::updateRenderGeomParams()
{
    return;

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

    meterToPxMat = QMatrix().translate(- centerPos.x(), - centerPos.y());
    meterToPxMat *= QMatrix().scale(meterToPxRatio, - meterToPxRatio);
    meterToPxMat *= QMatrix().translate(halfWInPx, halfHInPx);

    pxToMeterMat = QMatrix().translate(- halfWInPx, - halfHInPx);
    pxToMeterMat *= QMatrix().scale(1 / meterToPxRatio, - 1 / meterToPxRatio);
    pxToMeterMat *= QMatrix().translate(centerPos.x(), centerPos.y());

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
    return;

    curPosInPx = mousePos;
    curPos.setFromXY(pxToMeter(curPosInPx), centerPos);

    emit updateStatus();
}

QPointF MapWnd::pxToMeter(const QPointF& px)
{
    return pxToMeterMat.map(px);
}

QPointF MapWnd::meterToPx(const QPointF& meter)
{
    return meterToPxMat.map(meter);
}

void MapWnd::renderGPSTrajectory(QPainter& painter, const _NOD::OpenDRIVE& odContent)
{
    renderGPSTrajectory(painter, odContent.road_sequence);
}

void MapWnd::renderOSMWay(QPainter& painter, const _NOD::OpenDRIVE& odContent)
{
    for (const _NOSM::Way& osmWay : odContent.additionalData.getOSMWayDataOnCell())
        renderOSMWay(painter, osmWay);
}

void MapWnd::render(QPainter& painter, const _NOD::OpenDRIVE& odContent)
{
    render(painter, odContent.road_sequence);
    render(painter, odContent.junction_sequence);
}

void MapWnd::renderGPSTrajectory(QPainter& painter, const QVector<t_road>& roads)
{
    for (const t_road& road : roads)
        renderGPSTrajectory(painter, road);
}

void MapWnd::renderOSMWay(QPainter& painter, const _NOSM::Way& osmWay)
{
    QPolygonF polyline;
    //qDebug() << "******* osmWay.chord_coords_sequence.size() : " << osmWay.chord_coords_sequence.size();
    polyline.reserve(osmWay.chord_coords_sequence.size());
    for (const _vehiclePos& point : osmWay.chord_coords_sequence)
        polyline.append(meterToPx(point));

    painter.setPen(Qt::green);
    painter.drawPolyline(polyline);
}

void MapWnd::render(QPainter& painter, const QVector<t_road>& roads)
{
    for (const t_road& road : roads)
        render(painter, road);
}

void MapWnd::renderGPSTrajectory(QPainter& painter, const t_road& road)
{
    if (showGPSLayer)
        render(painter, road.additionalData.getGPSData(), Qt::red);

    if (showTrajectoryLayer)
        render(painter, road.additionalData.getTrajectoryData(), Qt::blue);
}

void MapWnd::render(QPainter& painter, const t_road& road)
{
    if (showOpenDRIVERoadLayer)
        render(painter, road.planView);

    if (!road.objects_sequence.isEmpty())
        render(painter, road.objects_sequence.first());

    if (!road.signals_sequence.isEmpty())
        render(painter, road.signals_sequence.first());
}

void MapWnd::render(QPainter& painter, const QVector<_vehiclePos>& points, const QColor& color)
{
    QPolygonF polyline;
    polyline.reserve(points.size());
    for (const _vehiclePos& point : points)
        polyline.append(meterToPx(point));

    painter.setPen(color);
    painter.drawPolyline(polyline);
}

void MapWnd::render(QPainter& painter, const t_road_planView& planView)
{
    QPolygonF polyline;
    polyline.reserve(planView.geometry_sequence.size());
    for (const t_road_planView_geometry& geom : planView.geometry_sequence)
        polyline.append(meterToPx(geom));

    //qDebug() << "Pre render planView";

    painter.setPen(Qt::black);
    painter.drawPolyline(polyline);

    //qDebug() << "Post render planView";
}

void MapWnd::render(QPainter& painter, const t_road_objects& objects)
{
    for (const t_road_objects_object& object : objects.object_sequence)
        render(painter, object);
}

void MapWnd::render(QPainter& painter, const t_road_objects_object& object)
{
    Q_UNUSED(painter);
    Q_UNUSED(object);
}

void MapWnd::render(QPainter& painter, const t_road_signals& signals_)
{
    for (const t_road_signals_signal& signal : signals_.signal_sequence)
        render(painter, signal);
}

void MapWnd::render(QPainter& painter, const t_road_signals_signal& signal)
{
    Q_UNUSED(painter);
    Q_UNUSED(signal);
}

void MapWnd::render(QPainter& painter, const QVector<t_junction>& junctions)
{
    for (const t_junction& junction : junctions)
        render(painter, junction);
}

void MapWnd::render(QPainter& painter, const t_junction& junction)
{
    Q_UNUSED(painter);
    Q_UNUSED(junction);
}

void MapWnd::renderScaleRuler(QPainter& painter)
{
    painter.setMatrix(QMatrix());

    int bottomLine = height() - 10;
    int charH = 20;
    int charY = bottomLine - charH;

    int scaleW = 80;
    renderOutlinedText(painter, QRectF(0, charY, scaleW, charH), QString("1:") + QString::number(scaleDenominator, 'f', 1));

    QVector<int> meters;
    meters << 1 << 2 << 5
           << 10 << 20 << 50
           << 100 << 200 << 500
           << 1000 << 2000 << 5000
           << 10000 << 20000 << 50000
           << 100000 << 200000 << 500000;

    int bestMeter = 1;
    double minDelta = 1e100;
    for (int meter : meters)
    {
        double px = meter * meterToPxRatio;
        double delta = fabs(px - 100);
        if (delta < minDelta)
        {
            bestMeter = meter;
            minDelta = delta;
        }
    }

    QString rulerValue = bestMeter < 1000 ? QString::number(bestMeter) + "m" : QString::number(bestMeter / 1000) + "km";
    double px = bestMeter * meterToPxRatio;
    int rulerX = scaleW;
    renderOutlinedText(painter, QRectF(rulerX, charY, px, charH), rulerValue);

    double penWidths[] = { 3, 1 };
    QColor colors[] = { QColor(Qt::white), QColor(Qt::black) };
    for (int i = 0; i < 2; i ++)
    {
        painter.setPen(QPen(colors[i], penWidths[i]));
        painter.drawLine(QPointF(rulerX, charY), QPointF(rulerX, bottomLine));
        painter.drawLine(QPointF(rulerX, bottomLine), QPointF(rulerX + px, bottomLine));
        painter.drawLine(QPointF(rulerX + px, charY), QPointF(rulerX + px, bottomLine));
    }
}

void MapWnd::renderOutlinedText(QPainter& painter, const QRectF& rc, const QString& text)
{
    //QFont font = painter.font();
    //font.setBold(true);
    //painter.setFont(font);
    painter.setRenderHint(QPainter::Antialiasing);

    QPainterPath path;
    path.addText(painter.boundingRect(rc, Qt::AlignCenter, text).bottomLeft(), painter.font(), text);
    painter.strokePath(path, QPen(Qt::white, 2));
    painter.fillPath(path, Qt::black);
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

    QPointF inMeter = pxToMeter(event->posF());

    double delta = pow(1.2, event->angleDelta().y() / 120);
    scaleDenominator /= delta;

    if (scaleDenominator < 1)
        scaleDenominator = 1;
    else if (scaleDenominator > 30000)
        scaleDenominator = 30000;

    updateRenderGeomParams();

    updateCenterPosFrom(event->posF(), inMeter);
    updateRenderGeomParams();

    update();
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

