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
    static QString wholeFn(const QString& fn);

protected:
    static void openedFileForAppend(QFile& closedFile, const QString& fn);
    static void openedFileForRead(QFile& closedFile, const QString& fn);
    static int lineCount(QFile& f);

protected:
    explicit CsvStorage(const QString& fn);

private:
    void initializeFilesIfNeeded();
    void inflateFileForUsers(QFile& f);
    void initializeIdrs();

private:
    int nextUserId;
};

#endif // CSVSTORAGE_H
