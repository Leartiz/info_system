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

// -----------------------------------------------------------------------

struct Unexpected : public Base // as runtime_error
{
    using Base::Base;
};

struct Initialization : public Base
{
    using Base::Base;
};

struct NotFound : public Base
{
    using Base::Base;
};

} // namespace StorageError


#endif // STORAGEERROR_H
