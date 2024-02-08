#ifndef ROLE_H
#define ROLE_H

#include <QString>

enum class Role : int {
    Client,
    Worker,
    Admin
};

QString roleToString(const Role);
Role strToRole(const QString&);

#endif // ROLE_H
