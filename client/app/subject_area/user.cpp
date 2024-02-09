#include <QJsonDocument>
#include <QJsonObject>

#include <stdexcept>
#include <utility>

#include "user.h"

User::User(Role role): role(role) {}

User User::create(
    UserValidatorSp validator,
    const QString& username, const QString& password, Role role,
    const QString& fullName, const QString& passport,
    std::optional<int> id, const QDateTime& dateTime
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
    if (!dateTime.isValid()) {
        throw std::runtime_error("Date and time is invalid");
    }

    // ***

    User user(role);
    user.validator = std::move(validator);

    user.id = id; // nil?
    user.username = username;
    user.password = password;

    user.signUpDateTime = dateTime;
    user.fullName = fullName;
    user.passport = passport;
    return user;
}

QString User::toJsonString() const
{
    return QJsonDocument{
        QJsonObject{
            { "id", id.value_or(-1) },
            { "username", username },
            { "password", password },
            { "role", roleToString(role) },

            { "signUpDateTime", signUpDateTime.toString() },
            { "fullName", fullName },
            { "passport", passport }
        }
    }.toJson();
}

// -----------------------------------------------------------------------

void User::setValidator(std::shared_ptr<UserValidator> validator)
{
    if (!validator) {
        throw std::runtime_error("Validator is nullptr");
    }

    this->validator = std::move(validator);
}

// getters
// -----------------------------------------------------------------------

std::optional<int> User::getId() const { return id; }
bool User::hasId() const { return id.has_value(); }

QString User::getUsername() const { return username; }
QString User::getPassword() const { return password; }
Role User::getRole() const { return role; }

QDateTime User::getSignUpDateTime() const { return signUpDateTime; }
QString User::getFullName() const { return fullName; }
QString User::getPassport() const { return passport; }

// setters
// -----------------------------------------------------------------------

void User::setUsername(const QString& value)
{
    if (!validator->isValidUsername(value)) {
        throw std::runtime_error("Username is invalid");
    }
    username = value;
}

void User::setPassword(const QString& value)
{
    if (!validator->isValidPassword(value)) {
        throw std::runtime_error("Password is invalid");
    }
    password = value;
}
