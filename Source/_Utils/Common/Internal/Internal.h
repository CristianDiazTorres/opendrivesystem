#pragma once

#include "Common/Internal/Compile.h"
#include <QString>
#include <QVector>
#include <QList>
#include <QMap>

#define INTEGER_MAX             2147483647
#define INTEGER_INVALID_VALUE   INT64_MAX

#define DOUBLE_MAX              1e100 /*1.7976931348623158e+308*/
#define DOUBLE_EPSILON1         0.000001
#define DOUBLE_EPSILON2         0.000000001
#define DOUBLE_INVALID_VALUE    DOUBLE_MAX

#define EMPTY_COMMAND
#define TRUE_SEMICOLON          true;
#define SEMICOLON               ;
#define AMPAMP                  &&
#define ENDL                    "\n"

template <typename T>
using QVector01 = QVector<T>; // 0..1

template <typename T>
using QVector0x = QVector<T>; // 0..*

template <typename T>
using QVector1x = QVector<T>; // 1..*

template <typename T>
using QVector2x = QVector<T>; // 2..*

typedef QVector<double>             DoubleVec;
typedef QVector<QString>            StringVec;

typedef QMap<QString, QString>      StringMap;


