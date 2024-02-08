#include "regexuservalidator.h"

const QRegularExpression& RegexUserValidator::usernameRegex() {
    static const QRegularExpression re{ R"(^[A-Za-z0-9_]{5,25}$)" };
    Q_ASSERT(re.isValid());
    return re;
}

const QRegularExpression& RegexUserValidator::passwordRegex()
{
    static const QRegularExpression re{ R"(^[\S]{5,25}$)" };
    Q_ASSERT(re.isValid());
    return re;
};

const QRegularExpression& RegexUserValidator::fullNameRegex()
{
    static const QRegularExpression re{ R"(^[А-Я]{1}[а-я]{1,25}\s[А-Я]{1}[а-я]{1,25}\s[А-Я]{1}[а-я]{1,25}$)" };
    Q_ASSERT(re.isValid());
    return re;
}

const QRegularExpression& RegexUserValidator::passportRegex()
{
    static const QRegularExpression re{ R"(^\d{4}\s\d{6}$)" };
    Q_ASSERT(re.isValid());
    return re;
}

// -----------------------------------------------------------------------

bool RegexUserValidator::isValidUsername(const QString& value) const
{
    return usernameRegex().match(value).hasMatch();
}

bool RegexUserValidator::isValidPassword(const QString& value) const
{
    return passwordRegex().match(value).hasMatch();
}

bool RegexUserValidator::isValidFullName(const QString& value) const
{
    return fullNameRegex().match(value).hasMatch();
}

bool RegexUserValidator::isValidPassport(const QString& value) const
{
    return passportRegex().match(value).hasMatch();
}
