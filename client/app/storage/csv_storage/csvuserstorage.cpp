#include "csvuserstorage.h"
#include "storage/storageerror.h"

const QString CsvUserStorage::fileName{ "users.csv" };

using StorageError::NotFound;
using StorageError::Unexpected;
using StorageError::Initialization;

CsvUserStorage::CsvUserStorage()
    : CsvStorage{ fileName }
{

}

User CsvUserStorage::getUserById(const int value)
{
    QFile f;
    openedFileForRead(f, fileName);

    const auto strId = QString::number(value);
    while (!f.atEnd()) {
        const auto parts = readStrs(f);
        if (parts[0] == strId) {
            return userFromStrs(parts);
        }
    }
    f.close();
    throw NotFound("User");
}

User CsvUserStorage::getUserByLogin(const QString& value)
{
    QFile f;
    openedFileForRead(f, fileNameForUsers);

    while (!f.atEnd()) {
        const auto parts = readStrs(f);
        if (parts[1] == value) { // case sensitive!
            return userFromStrs(parts);
        }
    }
    f.close();
    throw NotFound("User");
}

User CsvUserStorage::getUserByCredentials(
    const QString& username, const QString& password)
{
    QFile f;
    openedFileForRead(f, fileNameForUsers);

    // ***

    while (!f.atEnd()) {
        const auto parts = readStrs(f);
        if (parts[1] == username && parts[2] == password) {
            return userFromStrs(parts);
        }
    }
    f.close();
    throw NotFound("User");
}

int CsvUserStorage::insertUser(const User& user)
{
    QFile f;
    openedFileForAppend(f, fileNameForUsers);

    QStringList userLine = {
        QString::number(nextUserId),
        user.getUsername(), user.getPassword(),
        QString::number(static_cast<int>(user.getRole())),
        currentDtUtcStr(), user.getFullName(), user.getPassport()
    };

    writeLine(f, userLine);
    f.close();

    return nextUserId++;
}
