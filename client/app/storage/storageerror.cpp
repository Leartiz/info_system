#include "storageerror.h"

namespace StorageError
{

Base::Base(const QString& text)
    : std::runtime_error(text.toStdString()) {}

QString Base::text() const
{
    return QString(what());
}

}
