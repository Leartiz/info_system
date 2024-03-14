#ifndef USERSTORAGE_H
#define USERSTORAGE_H

#include <memory>

#include "subject_area/user.h"

class UserStorage;
using UserStorageSp = std::shared_ptr<UserStorage>;
using UserStorageWp = std::shared_ptr<UserStorage>;

class UserStorage
{
public:
    virtual User getUserById(const int) = 0;
    virtual User getUserByLogin(const QString&) = 0;
    virtual User getUserByCredentials(const QString& username,
                                      const QString& password) = 0;

    virtual int insertUser(const User& user) = 0;
};

#endif // USERSTORAGE_H
