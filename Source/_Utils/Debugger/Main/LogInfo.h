#pragma once

#include "Debugger/Internal/Internal.h"
#include "Debugger/Main/LoggingTarget.h"

namespace _NDebug
{

struct LogInfo
{
    LoggingTarget loggingTarget;
    QString dateTime;
    QThread* thread;
    QString threadId;
    QString loggerId;
    QString content;
    QString fullMessage;
};

}

Q_DECLARE_METATYPE(_NDebug::LogInfo)
