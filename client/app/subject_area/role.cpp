#include <stdexcept>

#include "role.h"

Role makeRole(int value)
{
    switch (static_cast<Role>(value)) {
    case Role::Client: return Role::Client;
    case Role::Worker: return Role::Worker;
    case Role::Admin: return Role::Admin;
    }

    throw std::runtime_error("Role unknown");
}

QString roleToString(const Role value)
{
    switch (value) {
    case Role::Client: return "Client";
    case Role::Worker: return "Worker";
    case Role::Admin: return "Admin";
    }

    throw std::runtime_error("Role unknown");
}

Role strToRole(const QString& value)
{
    if (!value.compare(roleToString(Role::Client))) {
        return Role::Client;
    }
    if (!value.compare(roleToString(Role::Worker))) {
        return Role::Worker;
    }
    if (!value.compare(roleToString(Role::Admin))) {
        return Role::Admin;
    }

    throw std::runtime_error("Role as string unknown");
}
