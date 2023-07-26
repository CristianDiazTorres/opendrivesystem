#pragma once

#include "UniversialType/UniversialType.h"
#include "GeoCoordinate/GeoCoordinate.h"
#include "OSM/OSM.h"

using namespace _NUniversialType;

namespace _NOD
{

typedef qint64                   integer;
typedef QString                  string;
typedef QByteArray               _byteArray;

template <class T>
using _vector = QVector<T>;

template <class Key, class T>
using _map = QMap<Key, T>;

typedef _map<string, string>    _stringMap;

typedef QIODevice                _ioDevice;
typedef QFile                    _file;

typedef QDomDocument             _xodrDocument;
typedef QDomNode                 _xodrNode;
typedef QDomCDATASection         _xodrCDATASection;

typedef _NXML::XmlStatus        _xodrStatus;
typedef _NXML::XmlElement       _xodrElement;

typedef _NUniversialType::StringPairs   _xodrStringPairs;
struct _OpenDriveElement;
struct _GeoJSONData;

typedef DoubleVec               _doubleVec;
typedef StringVec               _stringVec;

typedef _NMath::XY              XY;

typedef _NGC::VehiclePos        _vehiclePos;

struct a_ds_polynom;
struct a_s;
struct a_s_polynom;
struct a_s_t;
struct a_sOffset_polynom;
struct a_sOffset_tOffset;

struct OpenDRIVE;
struct t_road;
struct t_junction;

}
