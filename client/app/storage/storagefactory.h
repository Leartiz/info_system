#ifndef STORAGEFACTORY_H
#define STORAGEFACTORY_H

#include "userstorage.h"
#include "pawnstorage.h"

class StorageFactory;
using StorageFactorySp = std::shared_ptr<StorageFactory>;

class StorageFactory
{
public:
    enum Type {
        Csv,

        // Json, Xml, Sqlite
    };
    static StorageFactorySp get(Type);

public:
    virtual UserStorageSp createUserStorage() = 0;
    virtual PawnStorageSp createPawnStorage() = 0;
};

using StorageType = StorageFactory::Type;
using StorageFactorySp = std::shared_ptr<StorageFactory>;

#endif // STORAGEFACTORY_H
