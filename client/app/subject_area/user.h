#ifndef USER_H
#define USER_H

#include <optional>

#include <QDateTime>
#include <QRegularExpression>
#include <QString>

#include "role.h"
#include "validators/uservalidator.h"

class User final
{
public:
    static User create(
        UserValidatorSp validator,
        const QString& username, const QString& password, Role role,
        const QString& fullName, const QString& passport,
        std::optional<int> id = std::nullopt,
        const QDateTime& dateTime = QDateTime::currentDateTimeUtc()
        );
    QString toJsonString() const;

public:
    void setValidator(UserValidatorSp validator);

    QString getUsername() const;
    QString getPassword() const;
    Role getRole() const;

    QDateTime getSignUpDateTime() const;
    QString getFullName() const;
    QString getPassport() const;

    std::optional<int> getId() const;
    bool hasId() const;

public:
    void setUsername(const QString& value);
    void setPassword(const QString& value);
    //...

private:
    explicit User(Role role = Role::Client);
    UserValidatorSp validator;

private:
    std::optional<int> id;
    QString username;
    QString password;
    Role role;

private:
    QDateTime signUpDateTime;
    QString fullName;
    QString passport;
};

#endif // USER_H
