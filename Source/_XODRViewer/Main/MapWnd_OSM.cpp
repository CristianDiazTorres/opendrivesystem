#include "MapWnd.h"
#include "ui_MapWnd.h"
#include <QPainter>
#include "GeoCoordinate/GeoCoordinate.h"
#include <QDebug>
#include "OSM/TileImage/OSMTileImageDownloader.h"
#include <QMatrix3x3>

#ifdef _WIN32
#include "OSGeo4W64/include/cpl_vsi.h"
#include "OSGeo4W64/include/gdal.h"
#include "OSGeo4W64/include/gdalwarper.h"
#include "OSGeo4W64/include/ogr_spatialref.h"
#else
#include "cpl_vsi.h"
#include "gdal.h"
#include "gdalwarper.h"
#include "ogr_spatialref.h"
#endif

CPLErr CPL_STDCALL
GDALReprojectImage1( GDALDatasetH hSrcDS, const char *pszSrcWKT,
                    GDALDatasetH hDstDS, const char *pszDstWKT,
                    GDALResampleAlg eResampleAlg,
                    CPL_UNUSED double dfWarpMemoryLimit,
                    double dfMaxError,
                    GDALProgressFunc pfnProgress, void *pProgressArg,
                    GDALWarpOptions *psOptions )

{
/* -------------------------------------------------------------------- */
/*      Setup a reprojection based transformer.                         */
/* -------------------------------------------------------------------- */
    void *hTransformArg =
        GDALCreateGenImgProjTransformer( hSrcDS, pszSrcWKT, hDstDS, pszDstWKT,
                                         TRUE, 1000.0, 0 );

    if( hTransformArg == nullptr )
        return CE_Failure;

/* -------------------------------------------------------------------- */
/*      Create a copy of the user provided options, or a defaulted      */
/*      options structure.                                              */
/* -------------------------------------------------------------------- */
    GDALWarpOptions *psWOptions =
        psOptions == nullptr
        ? GDALCreateWarpOptions()
        : GDALCloneWarpOptions( psOptions );

    psWOptions->eResampleAlg = eResampleAlg;

/* -------------------------------------------------------------------- */
/*      Set transform.                                                  */
/* -------------------------------------------------------------------- */
    if( dfMaxError > 0.0 )
    {
        psWOptions->pTransformerArg =
            GDALCreateApproxTransformer( GDALGenImgProjTransform,
                                         hTransformArg, dfMaxError );

        psWOptions->pfnTransformer = GDALApproxTransform;
    }
    else
    {
        psWOptions->pfnTransformer = GDALGenImgProjTransform;
        psWOptions->pTransformerArg = hTransformArg;
    }

/* -------------------------------------------------------------------- */
/*      Set file and band mapping.                                      */
/* -------------------------------------------------------------------- */
    psWOptions->hSrcDS = hSrcDS;
    psWOptions->hDstDS = hDstDS;

    int nSrcBands = GDALGetRasterCount(hSrcDS);
    {
        GDALRasterBandH hBand = GDALGetRasterBand( hSrcDS, nSrcBands );
        if( hBand && GDALGetRasterColorInterpretation(hBand) == GCI_AlphaBand )
        {
            psWOptions->nSrcAlphaBand = nSrcBands;
            nSrcBands --;
        }
    }

    int nDstBands = GDALGetRasterCount(hDstDS);
    {
        GDALRasterBandH hBand = GDALGetRasterBand( hDstDS, nDstBands );
        if( hBand && GDALGetRasterColorInterpretation(hBand) == GCI_AlphaBand )
        {
            psWOptions->nDstAlphaBand = nDstBands;
            nDstBands --;
        }
    }

    GDALWarpInitDefaultBandMapping(
        psWOptions, std::min(nSrcBands, nDstBands));

/* -------------------------------------------------------------------- */
/*      Set source nodata values if the source dataset seems to have    */
/*      any. Same for target nodata values                              */
/* -------------------------------------------------------------------- */
    for( int iBand = 0; iBand < psWOptions->nBandCount; iBand++ )
    {
        GDALRasterBandH hBand = GDALGetRasterBand( hSrcDS, iBand+1 );

        int bGotNoData = FALSE;
        double dfNoDataValue = GDALGetRasterNoDataValue( hBand, &bGotNoData );
        if( bGotNoData )
        {
            GDALWarpInitSrcNoDataReal(psWOptions, -1.1e20);
            psWOptions->padfSrcNoDataReal[iBand] = dfNoDataValue;
        }

        // Deal with target band.
        hBand = GDALGetRasterBand( hDstDS, iBand+1 );

        dfNoDataValue = GDALGetRasterNoDataValue( hBand, &bGotNoData );
        if( bGotNoData )
        {
            GDALWarpInitDstNoDataReal(psWOptions, -1.1e20);
            psWOptions->padfDstNoDataReal[iBand] = dfNoDataValue;
        }
    }

/* -------------------------------------------------------------------- */
/*      Set the progress function.                                      */
/* -------------------------------------------------------------------- */
    if( pfnProgress != nullptr )
    {
        psWOptions->pfnProgress = pfnProgress;
        psWOptions->pProgressArg = pProgressArg;
    }

/* -------------------------------------------------------------------- */
/*      Create a warp options based on the options.                     */
/* -------------------------------------------------------------------- */
    GDALWarpOperation oWarper;
    CPLErr eErr = oWarper.Initialize( psWOptions );

    if( eErr == CE_None )
        eErr = oWarper.ChunkAndWarpImage( 0, 0,
                                          GDALGetRasterXSize(hDstDS),
                                          GDALGetRasterYSize(hDstDS) );

/* -------------------------------------------------------------------- */
/*      Cleanup.                                                        */
/* -------------------------------------------------------------------- */
    GDALDestroyGenImgProjTransformer( hTransformArg );

    if( dfMaxError > 0.0 )
        GDALDestroyApproxTransformer( psWOptions->pTransformerArg );

    GDALDestroyWarpOptions( psWOptions );

    return eErr;
}

CPLErr CPL_STDCALL GDALCreateAndReprojectImage1(
    GDALDatasetH hSrcDS, const char *pszSrcWKT,
    const char *pszDstFilename, const char *pszDstWKT,
    GDALDriverH hDstDriver, char **papszCreateOptions,
    GDALResampleAlg eResampleAlg, double dfWarpMemoryLimit, double dfMaxError,
    GDALProgressFunc pfnProgress, void *pProgressArg,
    GDALWarpOptions *psOptions )

{
    VALIDATE_POINTER1( hSrcDS, "GDALCreateAndReprojectImage", CE_Failure );

/* -------------------------------------------------------------------- */
/*      Default a few parameters.                                       */
/* -------------------------------------------------------------------- */
    if( hDstDriver == nullptr )
    {
        hDstDriver = GDALGetDriverByName( "GTiff" );
        if (hDstDriver == nullptr)
        {
            CPLError(CE_Failure, CPLE_AppDefined,
                     "GDALCreateAndReprojectImage needs GTiff driver");
            return CE_Failure;
        }
    }

    if( pszSrcWKT == nullptr )
        pszSrcWKT = GDALGetProjectionRef( hSrcDS );

    if( pszDstWKT == nullptr )
        pszDstWKT = pszSrcWKT;

/* -------------------------------------------------------------------- */
/*      Create a transformation object from the source to               */
/*      destination coordinate system.                                  */
/* -------------------------------------------------------------------- */
    void *hTransformArg =
        GDALCreateGenImgProjTransformer( hSrcDS, pszSrcWKT, nullptr, pszDstWKT,
                                         TRUE, 1000.0, 0 );

    if( hTransformArg == nullptr )
        return CE_Failure;

/* -------------------------------------------------------------------- */
/*      Get approximate output definition.                              */
/* -------------------------------------------------------------------- */
    double adfDstGeoTransform[6] = {};
    int nPixels = 0;
    int nLines = 0;

    if( GDALSuggestedWarpOutput( hSrcDS,
                                 GDALGenImgProjTransform, hTransformArg,
                                 adfDstGeoTransform, &nPixels, &nLines )
        != CE_None )
        return CE_Failure;

    GDALDestroyGenImgProjTransformer( hTransformArg );

/* -------------------------------------------------------------------- */
/*      Create the output file.                                         */
/* -------------------------------------------------------------------- */
    GDALDatasetH hDstDS =
        GDALCreate( hDstDriver, pszDstFilename, nPixels, nLines,
                    GDALGetRasterCount(hSrcDS) + 1,
                    GDALGetRasterDataType(GDALGetRasterBand(hSrcDS,1)),
                    papszCreateOptions );

    if( hDstDS == nullptr )
        return CE_Failure;

    GDALSetRasterColorInterpretation(GDALGetRasterBand( hDstDS, GDALGetRasterCount(hDstDS)), GCI_AlphaBand);

/* -------------------------------------------------------------------- */
/*      Write out the projection definition.                            */
/* -------------------------------------------------------------------- */
    GDALSetProjection( hDstDS, pszDstWKT );
    GDALSetGeoTransform( hDstDS, adfDstGeoTransform );

/* -------------------------------------------------------------------- */
/*      Perform the reprojection.                                       */
/* -------------------------------------------------------------------- */
    CPLErr eErr =
        GDALReprojectImage1( hSrcDS, pszSrcWKT, hDstDS, pszDstWKT,
                            eResampleAlg, dfWarpMemoryLimit, dfMaxError,
                            pfnProgress, pProgressArg, psOptions );

    GDALClose( hDstDS );

    return eErr;
}

void MapWnd::renderOSM(QPainter& painter)
{
    int maxTileIndex = (1 << osmZoomLevel) - 1;

    QMap<_NOSM::OSMTileImageParam, _NOSM::OSMTileImageParam> osmTiles;
    int gridSize = 50;
    for (int x = - gridSize; x <= width() + gridSize; x += gridSize)
    {
        for (int y = - gridSize; y <= height() + gridSize; y += gridSize)
        {
            QPointF meter = pxToMeter(QPointF(x, y));
            LLCoordSysXYCell pos;
            pos.setFromXY(meter, centerPos);

            _NOSM::OSMTileImageParam tileImgParam(osmZoomLevel
                                                  , _NOSM::lat2tiley(pos.lat, osmZoomLevel)
                                                  , _NOSM::long2tilex(pos.lon, osmZoomLevel));
            CLAMP(tileImgParam.row, 0, maxTileIndex);
            CLAMP(tileImgParam.col, 0, maxTileIndex);
            osmTiles[tileImgParam] = tileImgParam;
        }
    }

    for (const _NOSM::OSMTileImageParam& tileImgParam : osmTiles)
    {
        renderOSMTile(painter, tileImgParam);
    }
}

void MapWnd::renderOSMTile(QPainter& painter, const _NOSM::OSMTileImageParam &tileImgParam)
{
    QByteArray tileData;
    if (!OSMTileImageDownloader_getDefaultInstance->getTileImage(tileImgParam, tileData))
        return;

    double left = _NOSM::tilex2long(tileImgParam.col, tileImgParam.zoom);
    double right = _NOSM::tilex2long(tileImgParam.col + 1, tileImgParam.zoom);
    double top = _NOSM::tiley2lat(tileImgParam.row, tileImgParam.zoom);
    double bottom = _NOSM::tiley2lat(tileImgParam.row + 1, tileImgParam.zoom);

    LLCoordSysXYCellVec cornersIn3857(4);
    cornersIn3857[0].setFromLLCoordSys(LL(top, left), _NGC::CoordSys::get3857());
    cornersIn3857[1].setFromLLCoordSys(LL(top, right), _NGC::CoordSys::get3857());
    cornersIn3857[2].setFromLLCoordSys(LL(bottom, right), _NGC::CoordSys::get3857());
    cornersIn3857[3].setFromLLCoordSys(LL(bottom, left), _NGC::CoordSys::get3857());

    if (false)
    {
        double srcTransform[6] =
        {
            cornersIn3857[0].x()
            , (cornersIn3857[1].x() - cornersIn3857[0].x()) / 256
            , (cornersIn3857[3].x() - cornersIn3857[0].x()) / 256
            , cornersIn3857[0].y()
            , (cornersIn3857[1].y() - cornersIn3857[0].y()) / 256
            , (cornersIn3857[3].y() - cornersIn3857[0].y()) / 256
        };

        VSILFILE* srcFile = VSIFileFromMemBuffer ("/vsimem/src.png", (GByte*) tileData.data(), (vsi_l_offset) tileData.size(), FALSE );
        VSIFCloseL(srcFile);

        GDALDatasetH srcDataset = GDALOpen( "/vsimem/src.png", GA_ReadOnly );
        GDALSetGeoTransform(srcDataset, srcTransform);

        /*
        OGRSpatialReference srcSrs;
        char* srcWKT = NULL;
        srcSrs.importFromEPSG(3857);
        srcSrs.exportToWkt(&srcWKT);

        OGRSpatialReference dstSrs;
        char* dstWKT = NULL;
        dstSrs.importFromEPSG(3112);
        dstSrs.exportToWkt(&dstWKT);
        */

        const char* srcWKT = _NGC::getWKT("EPSG:3857");
        const char* dstWKT = _NGC::getWKT("EPSG:3112");

        GDALCreateAndReprojectImage(srcDataset, srcWKT, "/vsimem/dst.bmp", dstWKT, GDALGetDriverByName("BMP"), 0, GRA_Cubic, 0, 0.125, 0, 0, 0);

        GDALClose(srcDataset);
        VSIUnlink("/vsimem/src.png");

        //CPLFree(srcWKT);
        //CPLFree(dstWKT);

        GDALDatasetH dstDataset = GDALOpen( "/vsimem/dst.bmp", GA_ReadOnly );

        int width = GDALGetRasterXSize(dstDataset);
        int height = GDALGetRasterYSize(dstDataset);

        double dstTransform[6];
        GDALGetGeoTransform(dstDataset, dstTransform);

        GDALClose(dstDataset);

        QVector<QPointF> ltrb(2);
        GDALApplyGeoTransform(dstTransform, 0, 0, &ltrb[0].rx(), &ltrb[0].ry());
        GDALApplyGeoTransform(dstTransform, width, height, &ltrb[1].rx(), &ltrb[1].ry());

        vsi_l_offset warpedDataSize = 0;
        GByte* warpedDataBuffer = VSIGetMemFileBuffer("/vsimem/dst.bmp", &warpedDataSize, TRUE);

        QImage tileImg;
        //tileImg.loadFromData(warpedDataBuffer, warpedDataSize);
        tileImg.loadFromData(tileData);

        VSIFree(warpedDataBuffer);

        QRectF bound = _NMath::calcBoundInXY(ltrb);
        bound = meterToPxMat.mapRect(bound);

        painter.drawImage(bound, tileImg);
    }

    LLCoordSysXYCellVec cornersInScreenCS(4);
    cornersInScreenCS[0].setFromLLCoordSys(LL(top, left), centerPos);
    cornersInScreenCS[1].setFromLLCoordSys(LL(top, right), centerPos);
    cornersInScreenCS[2].setFromLLCoordSys(LL(bottom, right), centerPos);
    cornersInScreenCS[3].setFromLLCoordSys(LL(bottom, left), centerPos);

    QPolygonF cornersInPx(4);
    cornersInPx[0] = meterToPxMat.map((QPointF&)cornersInScreenCS[0]);
    cornersInPx[1] = meterToPxMat.map((QPointF&)cornersInScreenCS[1]);
    cornersInPx[2] = meterToPxMat.map((QPointF&)cornersInScreenCS[2]);
    cornersInPx[3] = meterToPxMat.map((QPointF&)cornersInScreenCS[3]);

    {
        QPainterPath path;
        path.addPolygon(cornersInPx);
        path.closeSubpath();

        if (!path.intersects(this->rect()))
            return;
    }

    if (true)
    {
        QImage tileImg;
        tileImg.loadFromData(tileData);

        {
            QPainterPath path;
            path.moveTo(0, 0);
            path.lineTo(256, 0);
            path.lineTo(256, 256);
            path.closeSubpath();

            QTransform t1(cornersInPx[0].x(), cornersInPx[1].x(), cornersInPx[2].x()
                    , cornersInPx[0].y(), cornersInPx[1].y(), cornersInPx[2].y()
                    , 1, 1, 1);
            QTransform t2(0, 256, 256
                        , 0, 0, 256
                        , 1, 1, 1);
            QTransform t = (t2.inverted().transposed() * t1.transposed());

            painter.setTransform(t);
            painter.setClipPath(path);
            painter.drawImage(0, 0, tileImg);
            painter.resetTransform();
            painter.setClipping(false);
        }

        if (true)
        {
            QPainterPath path;
            path.moveTo(0, 0);
            path.lineTo(256, 256);
            path.lineTo(0, 256);
            path.closeSubpath();

            QTransform t1(cornersInPx[0].x(), cornersInPx[2].x(), cornersInPx[3].x()
                    , cornersInPx[0].y(), cornersInPx[2].y(), cornersInPx[3].y()
                    , 1, 1, 1);
            QTransform t2(0, 256, 0
                        , 0, 256, 256
                        , 1, 1, 1);
            QTransform t = (t2.inverted().transposed() * t1.transposed());

            painter.setTransform(t);
            painter.setClipPath(path);
            painter.drawImage(0, 0, tileImg);
            painter.resetTransform();
            painter.setClipping(false);
        }
    }

    if (false)
    {
        painter.setPen(QColor(60, 60, 60, 40));
        painter.drawPolygon(cornersInPx);

        QRectF boundText = _NMath::calcBoundInXY(cornersInPx);

        painter.setPen(QColor(60, 60, 60, 200));
        painter.drawText(boundText, QString::number(tileImgParam.row) + ":" + QString::number(tileImgParam.col), QTextOption(Qt::AlignCenter));
    }
}

void MapWnd::onOSMTileImageDownloaded(_NOSM::OSMTileImageParam tileImgParam)
{
    Q_UNUSED(tileImgParam);
    //????????????!!!!!!!!!!!!
    this->update();
}
