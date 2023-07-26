#pragma once

#include "Common/Internal/Internal.h"
#include <QDateTime>
#include <QMutex>
#include <QMutexLocker>
#include <assert.h>

namespace _NCM
{

template <typename KeyType, typename ContentType>
class Cacher
{
protected:
    struct CacheInfo
    {
        ContentType content;
        qint64 time; // elapsed time(seconds) after starting
        int refCount;
    };

protected:
    int maxCount;
    QMap<KeyType, CacheInfo> cacheInfos;
    qint64 s_secsSinceEpochWhenStarted;
    QMutex mutex;

public:
    Cacher(int maxCount = 2000);

public:
    inline bool exists(const KeyType& key);
    ContentType getContent(const KeyType& key);
    void update(const KeyType& key, const ContentType& value);

private:
    void removeOldestContent();

};

template <typename KeyType, typename ContentType>
Cacher<KeyType, ContentType>::Cacher(int maxCount)
    : maxCount(maxCount)
{
    s_secsSinceEpochWhenStarted = QDateTime::currentSecsSinceEpoch();
}

template <typename KeyType, typename ContentType>
inline bool Cacher<KeyType, ContentType>::exists(const KeyType& key)
{
    QMutexLocker locker(&mutex);

    //qDebug() << "cacheInfos.size() : " << cacheInfos.size();
    return cacheInfos.contains(key);
}

template <typename KeyType, typename ContentType>
ContentType Cacher<KeyType, ContentType>::getContent(const KeyType& key)
{
    QMutexLocker locker(&mutex);

    assert(cacheInfos.contains(key));

    CacheInfo& cacheInfo = cacheInfos[key];
    cacheInfo.time = QDateTime::currentSecsSinceEpoch() - s_secsSinceEpochWhenStarted;
    cacheInfo.refCount ++;
    return cacheInfo.content;
}

template <typename KeyType, typename ContentType>
void Cacher<KeyType, ContentType>::update(const KeyType& key, const ContentType& content)
{
    QMutexLocker locker(&mutex);

    if (!cacheInfos.contains(key))
    {
        if (cacheInfos.size() >= maxCount)
            removeOldestContent();

        CacheInfo& cacheInfo = cacheInfos[key];
        cacheInfo.refCount = 0;
    }

    CacheInfo& cacheInfo = cacheInfos[key];
    cacheInfo.content = content;
    cacheInfo.time = QDateTime::currentSecsSinceEpoch() - s_secsSinceEpochWhenStarted;
    cacheInfo.refCount ++;
}

template <typename KeyType, typename ContentType>
void Cacher<KeyType, ContentType>::removeOldestContent()
{
    assert(!cacheInfos.empty());

    double minFreqFactor = DOUBLE_MAX;
    KeyType oldestKey;

    for (typename QMap<KeyType, CacheInfo>::iterator iter = cacheInfos.begin(); iter != cacheInfos.end(); iter ++)
    {
        CacheInfo& cacheInfo = iter.value();

        double freqFactor = cacheInfo.time + cacheInfo.refCount * 100;
        if (freqFactor < minFreqFactor)
        {
            minFreqFactor = freqFactor;
            oldestKey = iter.key();
        }
    }

    cacheInfos.remove(oldestKey);
}

}
