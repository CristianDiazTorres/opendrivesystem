#pragma once

#include "DB/Internal/Internal.h"

namespace _NDB
{

class SettingsOnPGDatabase : public QObject, protected StringMap
{
    Q_OBJECT

protected:
    QString tableName;

public:
    SettingsOnPGDatabase(const QString& tableName = "settings_global");
    bool init();

public:
    QString getValue(const QString& key);
    QString getValue(const QString& key, int defaultValue);
    bool setValue(const QString& key, const QString& value);
    bool setValue(const QString& key, int value);

signals:
    void settingChanged(QString key, QString value);

};

}
