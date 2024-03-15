#ifndef STORAGE_H
#define STORAGE_H

#include <QString>

class Storage
{
public:
    static QString currentDtUtcStr();

public:
    virtual ~Storage() = 0;
};

#endif // STORAGE_H
