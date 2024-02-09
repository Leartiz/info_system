#ifndef STORAGE_H
#define STORAGE_H

#include "subject_area/user.h"

class Storage
{
public:
    virtual ~Storage() {}

public:
    virtual User getUserByLogin(const QString& value) = 0;
    virtual User getUserByCredentials(const QString& username,
                                      const QString& password) = 0;
    virtual int insertUser(const User& user) = 0;

public:

};

#endif // STORAGE_H