#ifndef CSVSTORAGEFACTORY_H
#define CSVSTORAGEFACTORY_H

#include <memory>

#include "storage/storagefactory.h"

class CsvStorageFactory;
using CsvStorageFactorySp = std::shared_ptr<CsvStorageFactory>;

class CsvStorageFactory : public StorageFactory
{
public:
    static CsvStorageFactorySp create();

public:
    UserStorageSp createUserStorage() override;
    PawnStorageSp createPawnStorage() override;
};

#endif // CSVSTORAGEFACTORY_H
