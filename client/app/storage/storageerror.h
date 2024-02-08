#ifndef STORAGEERROR_H
#define STORAGEERROR_H

#include <stdexcept>

#include <QString>

namespace StorageError
{

struct Base : public std::runtime_error
{
    explicit Base(const QString& text);
    QString text() const;
};

struct Critical : public Base
{
    using Base::Base;
};

struct NotFound : public Base
{
    using Base::Base;
};

}


#endif // STORAGEERROR_H
