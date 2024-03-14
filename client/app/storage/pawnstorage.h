#ifndef PAWNSTORAGE_H
#define PAWNSTORAGE_H

#include <memory>

class PawnStorage;
using PawnStorageSp = std::shared_ptr<PawnStorage>;
using PawnStorageWp = std::weak_ptr<PawnStorage>;

class PawnStorage
{
public:
    PawnStorage();
};

#endif // PAWNSTORAGE_H
