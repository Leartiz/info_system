#ifndef MESSAGEFORCLIENT_H
#define MESSAGEFORCLIENT_H

#include <QString>

namespace MessageForClient
{

struct Warning
{
    static QString userByCredentialsNotFound();
};

struct Critical
{
    static QString unexpectedError();
};

QString withArg(const QString& text, const QString& arg);

} // namespace MessageForClient

#endif // MESSAGEFORCLIENT_H
