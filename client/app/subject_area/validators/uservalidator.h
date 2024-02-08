#ifndef USERVALIDATOR_H
#define USERVALIDATOR_H

#include <memory>

#include <QString>

class UserValidator
{
public:
    virtual bool isValidUsername(const QString&) const = 0;
    virtual bool isValidPassword(const QString&) const = 0;
    virtual bool isValidFullName(const QString&) const = 0;
    virtual bool isValidPassport(const QString&) const = 0;
    virtual ~UserValidator(){}
};

using UserValidatorSp = std::shared_ptr<UserValidator>;

#endif // USERVALIDATOR_H
