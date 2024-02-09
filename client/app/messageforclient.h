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

} // namespace MessageForClient

#endif // MESSAGEFORCLIENT_H
