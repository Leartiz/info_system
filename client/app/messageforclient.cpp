#include <QObject>

#include "messageforclient.h"

namespace MessageForClient
{

QString Warning::userByCredentialsNotFound()
{
    return QObject::tr("Пользователь с такими реквизитами не найден");
}

QString Critical::unexpectedError()
{
    return QObject::tr("Неожиданная ошибка");
}

QString withArg(const QString& text, const QString& arg)
{
    return text + ": " + arg;
}

} // namespace MessageForClient
