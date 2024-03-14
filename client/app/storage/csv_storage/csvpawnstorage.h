#ifndef CSVPAWNSTORAGE_H
#define CSVPAWNSTORAGE_H

#include <QString>

#include "csvstorage.h"
#include "storage/pawnstorage.h"

class CsvPawnStorage : public PawnStorage
{
public:
    static const QString fileName;

public:
    CsvPawnStorage();
};

#endif // CSVPAWNSTORAGE_H
