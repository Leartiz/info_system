#ifndef TRUEUSERVALIDATOR_H
#define TRUEUSERVALIDATOR_H

#include <memory>

#include "uservalidator.h"

class TrueUserValidator : public UserValidator
{
public:
    bool isValidUsername(const QString&) const override { return true; }
    bool isValidPassword(const QString&) const override { return true; }
    bool isValidFullName(const QString&) const override { return true; }
    bool isValidPassport(const QString&) const override { return true; }
};
using TrueUserValidatorSp = std::shared_ptr<TrueUserValidator>;

#endif // TRUEUSERVALIDATOR_H
