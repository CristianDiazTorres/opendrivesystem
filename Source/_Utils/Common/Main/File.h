#pragma once

#include <QFile>
#include <QFileInfo>
#include <QDir>

namespace _NCM
{

inline bool writeToFile(const QString& filePath, const QByteArray& data)
{
    QDir().mkpath(QFileInfo(filePath).absoluteDir().absolutePath());

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly))
        return false;

    return file.write(data) == data.size();
}

inline bool writeToFile(const QString& filePath, const QString& data)
{
    return writeToFile(filePath, data.toUtf8());
}

}
