#ifndef USERSTORAGE_H
#define USERSTORAGE_H

#include "subject_area/user.h"

class UserStorage
{
public:
    virtual ~UserStorage() {}

public:
    virtual User getUserById(const int) = 0;
    virtual User getUserByLogin(const QString&) = 0;
    virtual User getUserByCredentials(const QString& username,
                                      const QString& password) = 0;
    virtual int insertUser(const User& user) = 0;
};

#endif // USERSTORAGE_H
