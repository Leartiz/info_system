#include <QDir>
#include <QFile>
#include <QTextStream>

#include <QList>
#include <QStringList>

#include "subject_area/validators/uservalidatorfactory.h"

#include "csvstorage.h"
#include "storageerror.h"

using StorageError::NotFound;
using StorageError::Unexpected;
using StorageError::Initialization;

namespace
{

QStringList readStrs(QFile& f)
{
    const QString line{ f.readLine() };
    return line.split(CsvStorage::sep);
}

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

} // namespace

// -----------------------------------------------------------------------

const QString CsvStorage::sep = ";";
const QString CsvStorage::rootDir{ "csv_storage" };

const QString CsvStorage::fileNameForUsers{ "users.csv" };
const QString CsvStorage::fileNameForProducts{ "products.csv" };
const QString CsvStorage::fileNameForPurchases{ "purchases.csv" };
const QString CsvStorage::fileNameForCosts{ "costs.csv" };

QString CsvStorage::wholeFn(const QString& fn)
{
    return rootDir + "/" + fn;
}

// ctor
// -----------------------------------------------------------------------

CsvStorage& CsvStorage::instance()
{
    static CsvStorage storage;
    return storage;
}

CsvStorage::CsvStorage()
{
    initializeFilesIfNeeded();
}

void CsvStorage::initializeFilesIfNeeded()
{
    auto currentDir = QDir::current();
    if (!currentDir.exists(rootDir)) {
        if (currentDir.mkdir(rootDir)) {
            throw Initialization("Mkdir failed");
        }
    }

    // ***

    auto fn = wholeFn(fileNameForUsers);
    if (!QFile::exists(fn)) {
        QFile f(fn);
        if (!f.open(QFile::WriteOnly)) {
            throw Initialization("Create file for users failed");
        }
        inflateFileForUsers(f);
    }

    fn = wholeFn(fileNameForProducts);
    if (!QFile::exists(fn)) {
        QFile f(fn);
        if (!f.open(QFile::WriteOnly)) {
            throw Initialization("Create file for products failed");
        }
    }

    fn = wholeFn(fileNameForPurchases);
    if (!QFile::exists(fn)) {
        QFile f(fn);
        if (!f.open(QFile::WriteOnly)) {
            throw Initialization("Create file for purchases failed");
        }
    }

    fn = wholeFn(fileNameForCosts);
    if (!QFile::exists(fn)) {
        QFile f(fn);
        if (!f.open(QFile::WriteOnly)) {
            throw Initialization("Create file for costs failed");
        }
    }
}

void CsvStorage::inflateFileForUsers(QFile& f)
{
    const QString currentDtStr =
        QDateTime::currentDateTimeUtc().
            toString(Qt::ISODate);

    int id = 0;
    QList<QStringList> users = {
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

    for (const auto& user : users) {
        f.write(user.join(sep).toUtf8());
        f.write("\r\n");
    }
}

// public interface
// -----------------------------------------------------------------------

User CsvStorage::getUserByLogin(const QString& value)
{
    QFile f(wholeFn(fileNameForUsers));
    if (!f.open(QFile::ReadOnly)) {
        throw Unexpected("Open file for users failed");
    }

    // ***

    while (!f.atEnd()) {
        const auto parts = readStrs(f);
        if (parts[1] == value) { // case sensitive!
            return userFromStrs(parts);
        }
    }
    f.close();

    throw NotFound("User not found");
}

User CsvStorage::getUserByCredentials(
    const QString& username, const QString& password)
{
    QFile f(wholeFn(fileNameForUsers));
    if (!f.open(QFile::ReadOnly)) {
        throw Unexpected("Open file for users failed");
    }

    // ***

    while (!f.atEnd()) {
        const auto parts = readStrs(f);
        if (parts[1] == username && parts[2] == password) {
            return userFromStrs(parts);
        }
    }
    f.close();

    throw NotFound("User not found");
}

int CsvStorage::insertUser(const User& user)
{
    return 0;
}
