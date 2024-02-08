#include <QDir>
#include <QFile>
#include <QTextStream>

#include <QList>
#include <QStringList>

#include "subject_area/validators/uservalidatorfactory.h"

#include "csvstorage.h"
#include "storageerror.h"

const QString CsvStorage::rootDir{ "csv_storage" };
const QString CsvStorage::fileNameForUsers{ "users.csv" };
const QString CsvStorage::fileNameForProducts{ "products.csv" };
const QString CsvStorage::fileNameForPurchases{ "purchases.csv" };
const QString CsvStorage::fileNameForCosts{ "costs.csv" };

QString CsvStorage::wholeFn(const QString& fn)
{
    return rootDir + "/" + fn;
}

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
    using namespace StorageError;
    auto currentDir = QDir::current();
    if (!currentDir.exists(rootDir)) {
        if (currentDir.mkdir(rootDir)) {
            throw Critical("Mkdir failed");
        }
    }

    // ***

    auto fn = wholeFn(fileNameForUsers);
    if (!QFile::exists(fn)) {
        QFile f(fn);
        if (!f.open(QFile::WriteOnly))
            throw Critical("Create file for users failed");
        inflateFileForUsers(f);
    }

    fn = wholeFn(fileNameForProducts);
    if (!QFile::exists(fn)) {
        QFile f(fn);
        if (!f.open(QFile::WriteOnly))
            throw Critical("Create file for products failed");
    }

    fn = wholeFn(fileNameForPurchases);
    if (!QFile::exists(fn)) {
        QFile f(fn);
        if (!f.open(QFile::WriteOnly))
            throw Critical("Create file for purchases failed");
    }

    fn = wholeFn(fileNameForCosts);
    if (!QFile::exists(fn)) {
        QFile f(fn);
        if (!f.open(QFile::WriteOnly))
            throw Critical("Create file for costs failed");
    }
}

void CsvStorage::inflateFileForUsers(QFile& f)
{
    const QString currentDtStr =
        QDateTime::currentDateTimeUtc().
            toString(Qt::DateFormat::ISODate);

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
    };

    for (const auto& user : users) {
        f.write(user.join(";").toUtf8());
        f.write("\r\n");
    }
}

// -----------------------------------------------------------------------

User CsvStorage::getUserByLogin(const QString& value)
{
    using namespace StorageError;
    const auto fn = wholeFn(fileNameForUsers);

    QFile f(fn);
    if (!f.open(QFile::ReadOnly))
        throw Critical("Open file for users failed");

    // ***

    const auto trueValidator = UserValidatorFactory::get(ValidatorType::True);
    const auto regexValidator = UserValidatorFactory::get(ValidatorType::Regex);

    while (!f.atEnd()) {
        const QString line{ f.readLine() };
        const auto parts = line.split(";");

        if (parts[1] == value) {
            auto user = User::create(
                parts[0].toInt(),
                parts[1], parts[2],
                strToRole(parts[3]),
                parts[4], parts[5],
                trueValidator
                );

            user.setValidator(regexValidator);
            return user;
        }
    }

    throw NotFound("User not found");
}

User CsvStorage::getUserByCredentials(
    const QString& username, const QString& password)
{

}

int CsvStorage::insertUser(const User& user)
{
    return 0;
}
