#pragma once

#include "SettingsOnLocalSystem/Internal/Internal.h"
#include <QObject>
#include "Common/Main/DefaultInstance.h"

class QSettings;

namespace _NSettingsOnLocalSystem
{

class SettingsOnLocalSystem : public QObject
{
    Q_OBJECT

protected:
    QString section;
    QSettings* settings;

public:
    SettingsOnLocalSystem(const QString& section = "");
    void init();

public:
    QString getValue(const QString& key);
    QString getValue(const QString& key, int defaultValue);
    void setValue(const QString& key, const QString& value);
    void setValue(const QString& key, int value);

signals:
    void settingChanged(QString key, QString value);
};

}
