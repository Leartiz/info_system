#include <stdexcept>
#include <utility>

#include "user.h"

User User::create(
    std::optional<int> id,
    const QString& username, const QString& password,
    Role role, const QString& fullName, const QString& passport,
    std::shared_ptr<UserValidator> validator
    )
{
    if (!validator) {
        throw std::runtime_error("Validator is nullptr");
    }

    // ***

    if (!validator->isValidFullName(username)) {
        throw std::runtime_error("Username is invalid");
    }
    if (!validator->isValidPassword(password)) {
        throw std::runtime_error("Password is invalid");
    }
    if (!validator->isValidFullName(fullName)) {
        throw std::runtime_error("Full name is invalid");
    }
    if (!validator->isValidPassport(passport)) {
        throw std::runtime_error("Passport is invalid");
    }

    // ***

    User user;
    user.validator = std::move(validator);

    user.id = id; // nil?
    user.username = username;
    user.password = password;
    user.role = role;

    user.signUpDateTime = QDateTime::currentDateTimeUtc();
    user.fullName = fullName;
    user.passport = passport;
    return user;
}

User User::createFromCsv(const QString& csvLine,
                         std::shared_ptr<UserValidator> validator)
{
    // TODO:

    return User{};
}

QString User::toCsv() const
{
    return "";
}

// -----------------------------------------------------------------------

void User::setValidator(std::shared_ptr<UserValidator> validator)
{
    if (!validator) {
        throw std::runtime_error("Validator is nullptr");
    }

    this->validator = std::move(validator);
}

QString User::getUsername() const
{
    return username;
}

Role User::getRole() const
{
    return role;
}

bool User::hasId() const
{
    return id.has_value();
}
