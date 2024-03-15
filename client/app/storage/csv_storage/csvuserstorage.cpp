#include "csvuserstorage.h"
#include "storage/storageerror.h"

#include "subject_area/validators/uservalidatorfactory.h"

const QString CsvUserStorage::fileName{ "users.csv" };

using StorageError::NotFound;
using StorageError::Unexpected;
using StorageError::Initialization;

namespace
{

User userFromStrs(const QStringList& strs)
{
    bool converted = false;
    const auto id = strs[0].toInt(&converted);
    if (!converted) {
        throw Unexpected("Failed to convert ID");
    }
    const auto roleNumber = strs[3].toInt(&converted);
    if (!converted) {
        throw Unexpected("Failed to convert role");
    }

    // ***

    auto user = User::create(
        UserValidatorFactory::trueInstance,
        strs[1], strs[2], makeRole(roleNumber), strs[5], strs[6],
        id, QDateTime::fromString(strs[4], Qt::ISODate)
        );
    user.setValidator(
        UserValidatorFactory::regexInstance);

    return user;
}

}

// -----------------------------------------------------------------------

CsvUserStorage::CsvUserStorage()
    : CsvStorage{ fileName }
{
    if (!filePreviouslyExisted)
        inflateFileIfNeeded();

    initializeNextId();
}

void CsvUserStorage::inflateFileIfNeeded() const
{
    QFile f; openedFileFor(f, wholeFn, QFile::WriteOnly);
    const QString currentDtStr = currentDtUtcStr();

    int id = 0;
    const QList<QStringList> userLines = {
        {
            QString::number(id++), QString("admin"), QString("admin"),
            QString::number(static_cast<int>(Role::Admin)),
            currentDtStr, QString(""), QString("")
        },
        {
            QString::number(id++), QString("worker"), QString("worker"),
            QString::number(static_cast<int>(Role::Worker)),
            currentDtStr, QString(""), QString("")
        },
        {
            QString::number(id++), QString("client"), QString("client"),
            QString::number(static_cast<int>(Role::Client)),
            currentDtStr, QString(""), QString("")
        },
        //...
    };

    for (const auto& userLine : userLines) {
        writeLine(f, userLine);
    }
}

// -----------------------------------------------------------------------

User CsvUserStorage::getUserById(const int value)
{
    QFile f;
    openedFileFor(f, fileName, QFile::ReadOnly);

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
    openedFileFor(f, fileNameForUsers);

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
