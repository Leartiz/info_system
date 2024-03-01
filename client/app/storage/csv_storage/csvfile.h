#ifndef CSVFILE_H
#define CSVFILE_H

#include <QFile>
#include <QString>

class CsvFile
{
public:
    enum OpenMode{
        Read, Write, Rw, Append,
    };

public:
    explicit CsvFile(const QString& fn);

private:
    QFile f;
};

#endif // CSVFILE_H
