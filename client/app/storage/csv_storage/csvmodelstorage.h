#ifndef CSVMODELSTORAGE_H
#define CSVMODELSTORAGE_H

#include <QString>

class CsvModelStorage
{
public:
    static const QString sep;
    static const QString rootDir;
    static QString wholeFn(const QString& fn);

public:
    CsvModelStorage();
};

#endif // CSVMODELSTORAGE_H
