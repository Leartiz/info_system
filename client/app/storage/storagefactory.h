#ifndef STORAGEFACTORY_H
#define STORAGEFACTORY_H

#include "storage.h"

class StorageFactory
{
public:
    enum Type {
        Csv,

        // Json, Xml, Sqlite
    };

public:
    static Storage& get(Type);
};

#endif // STORAGEFACTORY_H
