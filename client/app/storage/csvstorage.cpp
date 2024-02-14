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

void openedFileForRead(QFile& closedFile, const QString& fn) {
    closedFile.setFileName(CsvStorage::wholeFn(fn));

    if (!closedFile.open(QFile::ReadOnly)) {
        throw Unexpected(
            QString{ "Open file %1 for read failed" }.
            arg(fn)
            );
    }
}

void openedFileForAppend(QFile& closedFile, const QString& fn) {
    closedFile.setFileName(CsvStorage::wholeFn(fn));

    if (!closedFile.open(QFile::Append)) {
        throw Unexpected(
            QString{ "Open file %1 for append failed" }.
            arg(fn)
            );
    }
}

int lineCount(QFile& f)
{
    int count = 0;
    QTextStream ts(&f);
    while (!f.atEnd()) {
        static_cast<void>(ts.readLine());
        ++count;
    }
    return count;
}

// -----------------------------------------------------------------------

QString currentDtUtcStr()
{
    return QDateTime::currentDateTimeUtc().
        toString(Qt::ISODate);
}

QStringList readStrs(QFile& f)
{
    const QString line{ f.readLine() };
    return line.split(CsvStorage::sep);
}

void writeLine(QFile& f, const QStringList& strs)
{
    f.write(strs.join(CsvStorage::sep).toUtf8());
    f.write("\r\n");
}

// from strs
// -----------------------------------------------------------------------

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
    : nextUserId(0)
    , nextProductId(0)
    , nextPurchaseId(0)
    , nextCostId(0)
{
    initializeFilesIfNeeded();
    initializeIdrs();
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
    const QString currentDtStr = currentDtUtcStr();

    int id = 0;
    QList<QStringList> userLines = {
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

void CsvStorage::initializeIdrs()
{
    QVector<QPair<QString, int*>> idrs{
        { fileNameForUsers, &nextUserId },
        { fileNameForProducts, &nextProductId },
        { fileNameForPurchases, &nextPurchaseId },
        { fileNameForCosts, &nextCostId },
    };

    for (int i = 0; i < idrs.size(); ++i) {
        QFile f; openedFileForRead(f, fileNameForUsers);
        *idrs[i].second = lineCount(f) + 1;
    }
}

// public interface
// -----------------------------------------------------------------------

User CsvStorage::getUserById(const int value)
{
    QFile f;
    openedFileForRead(f, fileNameForUsers);

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

User CsvStorage::getUserByLogin(const QString& value)
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

User CsvStorage::getUserByCredentials(
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

int CsvStorage::insertUser(const User& user)
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
