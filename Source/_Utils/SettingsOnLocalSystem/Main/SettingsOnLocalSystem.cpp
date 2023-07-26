#include "SettingsOnLocalSystem.h"
#include <QSettings>

namespace _NSettingsOnLocalSystem
{

SettingsOnLocalSystem::SettingsOnLocalSystem(const QString& section)
    : section(section)
    , settings(0)
{
}

void SettingsOnLocalSystem::init()
{
    if (settings)
    {
        delete settings;
        settings = 0;
    }

    settings = new QSettings("OpenDRIVE System", "OpenDRIVE System / " + section);
    settings->sync();
}

QString SettingsOnLocalSystem::getValue(const QString& key)
{
    if (settings == 0)
        return "";

    if (settings->contains(key))
        return settings->value(key).toString();
    return "";
}

QString SettingsOnLocalSystem::getValue(const QString& key, int defaultValue)
{
    if (settings == 0)
        return "";

    if (!settings->contains(key))
        setValue(key, defaultValue);
    return getValue(key);
}

void SettingsOnLocalSystem::setValue(const QString& key, const QString& value)
{
    if (settings == 0)
        return;

    settings->setValue(key, value);
    settings->sync();
    emit settingChanged(key, value);
}

void SettingsOnLocalSystem::setValue(const QString& key, int value)
{
    if (settings == 0)
        return;

    setValue(key, QString::number(value));
}

}
