#ifndef USER_H
#define USER_H

#include <optional>

#include <QString>
#include <QDateTime>
#include <QRegularExpression>

#include "role.h"

class User final
{
public:
    struct Validator
    {
        static QRegularExpression username;
        static QRegularExpression password;
        static QRegularExpression fullName;
        static QRegularExpression passport;
        static bool isValid();
    };

public:
    static User createWithoutChecks(
        const QString& username, const QString& password,
        Role role, const QString& fullName, const QString& passport
        );

    static User createFromCsv(const QString& value);
    QString toCsv() const;

    bool withId() const;

private:
    User();

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
