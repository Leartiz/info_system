#ifndef CSVUSERSTORAGE_H
#define CSVUSERSTORAGE_H

#include "csvstorage.h"
#include "storage/userstorage.h"

class CsvUserStorage : public CsvStorage,
                       public UserStorage
{
public:
    static const QString fileName;

public:
    CsvUserStorage();
    void inflateFileIfNeeded() const override;

public:
    User getUserById(const int) override;
    User getUserByLogin(const QString&) override;
    User getUserByCredentials(const QString& user,
                              const QString& password) override;
    int insertUser(const User& user) override;
};

#endif // CSVUSERSTORAGE_H
