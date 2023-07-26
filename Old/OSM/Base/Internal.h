#pragma once

#include "OSM/Config.h"
#include "OSM/Debug.h"

#include "Common/Internal.h"

#include "GeoCoordinate/VehiclePos.h"

namespace _NOSM
{

typedef _NCM::Exception         Exception;

typedef _NCM::Int64             Int64;

typedef _NCM::String            String;
typedef _NCM::ByteArray         ByteArray;
typedef _NCM::DateTime          DateTime;

template <typename T>
using Vector = _NCM::Vector<T>;

template <class Key, class T>
using Map = _NCM::Map<Key, T>;

typedef _NCM::File              File;

typedef _NCM::PointF            PointF;
typedef _NCM::Rect              Rect;
typedef _NCM::RectF             RectF;

typedef _NCM::DomElement        DomElement;
typedef _NCM::DomDocument       DomDocument;

typedef _NCM::JsonDocument      JsonDocument;
typedef _NCM::JsonValue         JsonValue;
typedef _NCM::JsonObject        JsonObject;
typedef _NCM::JsonArray         JsonArray;

typedef _NCM::DoubleVec         DoubleVec;
typedef _NCM::StringVec         StringVec;
typedef _NCM::Uint8Vec          Uint8Vec;

typedef _NGC::LL                LL;
typedef Vector<LL>              LLVec;
typedef Vector<LLVec>           LLVecVec;
typedef _NGC::VehiclePos        VehiclePos;
typedef Vector<VehiclePos>      VehiclePosVec;
typedef Vector<VehiclePosVec>   VehiclePosVecVec;

}
