#include "csvstoragefactory.h"
#include "csvuserstorage.h"
#include "csvpawnstorage.h"

CsvStorageFactorySp CsvStorageFactory::create()
{
    return std::make_shared<CsvStorageFactory>();
}

// -----------------------------------------------------------------------

UserStorageSp CsvStorageFactory::createUserStorage()
{
    return std::make_shared<CsvUserStorage>();
}

PawnStorageSp CsvStorageFactory::createPawnStorage()
{
    return std::make_shared<CsvPawnStorage>();
}
