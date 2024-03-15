#include <QDateTime>

#include "storage.h"

Storage::~Storage() {}

QString Storage::currentDtUtcStr()
{
    return QDateTime::currentDateTimeUtc().
        toString(Qt::ISODate);
}
