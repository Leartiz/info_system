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

} // namespace MessageForClient
