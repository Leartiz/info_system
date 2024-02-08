#ifndef USER_H
#define USER_H

#include <optional>

#include <QString>
#include <QDateTime>
#include <QRegularExpression>

#include "role.h"
#include "validators/uservalidator.h"

class User final
{
public:
    static User create(
        std::optional<int> id,
        const QString& username, const QString& password,
        Role role, const QString& fullName, const QString& passport,
        UserValidatorSp validator
        );

    static User createFromCsv(const QString& csvLine,
                              UserValidatorSp validator);
    QString toCsv() const;

public:
    void setValidator(UserValidatorSp validator);

    QString getUsername() const;
    QDateTime getSignUpDateTime() const;

    QString getFullName() const;
    QString getPassport() const;

    Role getRole() const;
    bool hasId() const;

private:
    User();
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
