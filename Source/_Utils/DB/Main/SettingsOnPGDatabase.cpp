#include "SettingsOnPGDatabase.h"
#include "PGDatabaseConnector.h"

namespace _NDB
{

SettingsOnPGDatabase::SettingsOnPGDatabase(const QString& tableName)
    : tableName(tableName)
{
}

bool SettingsOnPGDatabase::init()
{
    StringVec keys, vals;
    if (!PGDatabaseConnector_getDefaultInstance.getSettings(tableName, keys, vals))
        return false;

    clear();

    for (int i = 0; i < keys.size(); i ++)
        (*this)[keys[i]] = vals[i];

    return true;
}

QString SettingsOnPGDatabase::getValue(const QString& key)
{
    if (contains(key))
        return (*this)[key];
    return "";
}

QString SettingsOnPGDatabase::getValue(const QString& key, int defaultValue)
{
    if (!contains(key))
        setValue(key, defaultValue);
    return getValue(key);
}

bool SettingsOnPGDatabase::setValue(const QString& key, const QString& value)
{
    if (!PGDatabaseConnector_getDefaultInstance.updateSetting(tableName, key, value))
        return false;

    (*this)[key] = value;

    emit settingChanged(key, value);

    return true;
}

bool SettingsOnPGDatabase::setValue(const QString& key, int value)
{
    return setValue(key, QString::number(value));
}

}
