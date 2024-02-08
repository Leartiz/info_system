#ifndef REGEXUSERVALIDATOR_H
#define REGEXUSERVALIDATOR_H

#include <QRegularExpression>

#include "uservalidator.h"

class RegexUserValidator : public UserValidator
{
public:
    static const QRegularExpression& usernameRegex();
    static const QRegularExpression& passwordRegex();
    static const QRegularExpression& fullNameRegex();
    static const QRegularExpression& passportRegex();

public:
    bool isValidUsername(const QString&) const override;
    bool isValidPassword(const QString&) const override;
    bool isValidFullName(const QString&) const override;
    bool isValidPassport(const QString&) const override;
};

#endif // REGEXUSERVALIDATOR_H
