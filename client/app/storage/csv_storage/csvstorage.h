#ifndef CSVSTORAGE_H
#define CSVSTORAGE_H

#include <QFile>
#include <QString>

#include "storage/storage.h"

class CsvStorage : public Storage
{
public:
    static const QString sep;
    static const QString rootDir;
    static QString makeWholeFn(const QString& fn);

protected:
    static void openedFileFor(QFile& closedFile, const QString& fn,
                              const QFile::OpenMode om);
    static int lineCount(QFile& f);

    static void writeLine(QFile& f, const QStringList& strs);
    static QStringList readStrs(QFile& f);

protected:
    explicit CsvStorage(const QString& fn);
    void initializeFileIfNeeded() const;
    mutable bool filePreviouslyExisted{ true };

    QString wholeFn;
    int nextId{ 0 };

protected:
    virtual void inflateFileIfNeeded() const = 0;
    virtual void initializeNextId() const = 0;
    ~CsvStorage() override = 0;
};

#endif // CSVSTORAGE_H
