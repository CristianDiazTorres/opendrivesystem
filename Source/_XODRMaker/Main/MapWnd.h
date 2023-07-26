#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QWidget>
#include <QMatrix>
#include "XODR/OpenDRIVE/core/OpenDRIVE.h"

using namespace _NOD;


namespace Ui {
class MapWnd;
}

class MapWnd : public QWidget
{
    Q_OBJECT

public:
    explicit MapWnd(QWidget *parent = 0);
    ~MapWnd();

public:

    /*****************************************************/
    // Render Pos, Zoom, Area, Matrices

    LLCoordSysXYCell centerPos;
    double scaleDenominator;

    double dpi;
    double meterToPxRatio;

    double halfWInPx;
    double halfHInPx;
    double halfWInMeter;
    double halfHInMeter;
    QRectF boundInMeter;

    QMatrix meterToPxMat;
    QMatrix pxToMeterMat;

    /*****************************************************/

    QPointF curPosInPx;
    LLCoordSysXYCell curPos;

    /*****************************************************/

protected:
    bool pressed;
    QPointF pressedInMeter;

protected:
    bool showGPSLayer;
    bool showTrajectoryLayer;
    bool showOSMWayLayer;
    bool showOpenDRIVERoadLayer;

public:
    void updateRenderGeomParams();
    void updateCenterPosFrom(const QPointF& px, const QPointF& meter);
    void updateCurPos(const QPointF& mousePos);
    QPointF pxToMeter(const QPointF& px);
    QPointF meterToPx(const QPointF& meter);

public:
    void renderGPSTrajectory(QPainter& painter, const OpenDRIVE& odContent);
    void renderOSMWay(QPainter& painter, const OpenDRIVE& odContent);
    void render(QPainter& painter, const OpenDRIVE& odContent);
    void renderGPSTrajectory(QPainter& painter, const QVector<t_road>& roads);
    void renderOSMWay(QPainter& painter, const _NOSM::Way& osmWay);
    void render(QPainter& painter, const QVector<t_road>& roads);
    void renderGPSTrajectory(QPainter& painter, const t_road& road);
    void render(QPainter& painter, const t_road& road);
    void render(QPainter& painter, const QVector<_vehiclePos>& points, const QColor& color);
    void render(QPainter& painter, const t_road_planView& planView);
    void render(QPainter& painter, const t_road_objects& objects);
    void render(QPainter& painter, const t_road_objects_object& object);
    void render(QPainter& painter, const t_road_signals& signals_);
    void render(QPainter& painter, const t_road_signals_signal& signal);
    void render(QPainter& painter, const QVector<t_junction>& junctions);
    void render(QPainter& painter, const t_junction& junction);
    void renderScaleRuler(QPainter& painter);
    void renderOutlinedText(QPainter& painter, const QRectF& rc, const QString& text);

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void wheelEvent(QWheelEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual void changeEvent(QEvent *event);

signals:
    void updateStatus();

public slots:
    void onDoNaviate(double lat, double lon);
    void onShowGPSLayer(bool show);
    void onShowTrajectoryLayer(bool show);
    void onShowOSMWayLayer(bool show);
    void onShowOpenDRIVERoadLayer(bool show);

private:
    Ui::MapWnd *ui;
};

