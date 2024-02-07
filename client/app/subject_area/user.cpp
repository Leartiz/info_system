#include <stdexcept>

#include "user.h"

namespace
{

void validate(const QString& value)
{
    static QRegularExpression re(User::Validator::username);
    const auto result = re.match(value);
    if (result.hasMatch()) return;

    throw std::runtime_error("Username is invalid");
}
void validatePassword(const QString& value)
{

}

void validateFullName(const QString& value)
{

}

void validatePassport(const QString& value)
{

}

}

// -----------------------------------------------------------------------

QRegularExpression User::Validator::username{
    R"(^[A-Za-z0-9_]{5,25}$)"
};

QRegularExpression password{

};

QRegularExpression fullName{

};

QRegularExpression passport{

};

User User::createWithoutChecks(
    const QString& username, const QString& password,
    Role role, const QString& fullName, const QString& passport
    )
{
    validateUsername(username);
    validatePassword(password);
    validateFullName(fullName);
    validatePassport(passport);

    User user;
    user.username = username;
    user.password = password;
    user.role = role;

    user.signUpDateTime = QDateTime::currentDateTimeUtc();
    user.fullName = fullName;
    user.passport = passport;
    return user;
}

User User::createFromCsv(const QString& value)
{
    return User{};
}

QString User::toCsv() const
{
    return "";
}

bool User::withId() const
{
    return id.has_value();
}
