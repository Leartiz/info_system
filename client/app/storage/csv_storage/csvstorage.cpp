#include <QMetaEnum>

#include <QDir>
#include <QFile>
#include <QTextStream>

#include <QList>
#include <QStringList>

#include "csvstorage.h"
#include "storage/storageerror.h"

using StorageError::NotFound;
using StorageError::Unexpected;
using StorageError::Initialization;

const QString CsvStorage::sep = ";";
const QString CsvStorage::rootDir{ "csv_storage" };

QString CsvStorage::makeWholeFn(const QString& fn)
{
    return rootDir + "/" + fn;
}

// -----------------------------------------------------------------------

void CsvStorage::openedFileFor(QFile& closedFile, const QString& fn,
                               const QFile::OpenMode om) {
    const auto me = QMetaEnum::fromType<QFile::OpenMode>();
    closedFile.setFileName(CsvStorage::makeWholeFn(fn));

    if (!closedFile.open(om)) {
        throw Unexpected(
            QString{ "Open file %1 for %2 failed" }.
            arg(fn, me.valueToKey(om))
        );
    }
}

int CsvStorage::lineCount(QFile& f)
{
    int count = 0;
    QTextStream ts(&f);
    while (!f.atEnd()) {
        static_cast<void>(ts.readLine());
        ++count;
    }
    return count;
}

void CsvStorage::writeLine(QFile& f, const QStringList& strs)
{
    f.write(strs.join(CsvStorage::sep).toUtf8());
    f.write("\r\n");
}

QStringList CsvStorage::readStrs(QFile& f)
{
    const QString line{ f.readLine() };
    return line.split(CsvStorage::sep);
}

// -----------------------------------------------------------------------

CsvStorage::CsvStorage(const QString& fn)
    : wholeFn{ makeWholeFn(fn) }
{
    initializeFileIfNeeded();
}
CsvStorage::~CsvStorage(){}

void CsvStorage::initializeFileIfNeeded() const
{
    const auto currentDir = QDir::current();
    if (!currentDir.exists(rootDir)) {
        if (currentDir.mkdir(rootDir)) {
            throw Initialization("Mkdir failed");
        }
    }

    // ***

    if (!QFile::exists(wholeFn)) {
        filePreviouslyExisted = false;

        QFile f(wholeFn);
        if (!f.open(QFile::WriteOnly)) {
            throw Initialization(
                QString{ "Create file %1 failed" }.arg(wholeFn));
        }
    }
}
