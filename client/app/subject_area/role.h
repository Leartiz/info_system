#ifndef ROLE_H
#define ROLE_H

#include <QString>

enum class Role : int {
    Client,
    Worker,
    Admin
};

Role makeRole(int);
QString roleToString(const Role);
Role strToRole(const QString&);

#endif // ROLE_H
