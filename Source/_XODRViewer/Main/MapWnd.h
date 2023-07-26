#pragma once

#include "_XODRMaker/Internal/Internal.h"
#include <QWidget>
#include <QMatrix>
#include "XODR/OpenDRIVE/core/OpenDRIVE.h"
#include "OSM/TileImage/OSMTileImageParam.h"
#include <QTimer>

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
    QTimer timer;

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
    QRectF boundInLL;

    QMatrix meterToPxMat;
    QMatrix pxToMeterMat;

    int osmZoomLevel;

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
    void zoomInOut(const QPointF& mousePos, double ratio);
    QPointF pxToMeter(const QPointF& px);
    QPointF meterToPx(const QPointF& meter);

public:
    void renderOSM(QPainter& painter);
    void renderOSMTile(QPainter& painter, const _NOSM::OSMTileImageParam& tileImgParam);

protected:
    virtual void paintEvent(QPaintEvent *event);
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void wheelEvent(QWheelEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void resizeEvent(QResizeEvent *event);
    virtual void changeEvent(QEvent *event);

signals:
    void updateStatus();

public Q_SLOTS:
    void onDoNaviate(double lat, double lon);
    void onShowGPSLayer(bool show);
    void onShowTrajectoryLayer(bool show);
    void onShowOSMWayLayer(bool show);
    void onShowOpenDRIVERoadLayer(bool show);
    void onOSMTileImageDownloaded(_NOSM::OSMTileImageParam tileImgParam);

private:
    Ui::MapWnd *ui;
};

