#ifndef CSVSTORAGE_H
#define CSVSTORAGE_H

#include <QFile>
#include <QString>

#include "storage/storage.h"
#include "subject_area/user.h"

class CsvStorage : public Storage
{
public:
    static const QString sep;
    static const QString rootDir;

    static const QString fileNameForUsers;
    static const QString fileNameForProducts;
    static const QString fileNameForPurchases;
    static const QString fileNameForCosts;
    static QString wholeFn(const QString& fn);

    static CsvStorage& instance();

public:
    User getUserById(const int value) override;
    User getUserByLogin(const QString& value) override;
    User getUserByCredentials(const QString& username,
                              const QString& password) override;
    int insertUser(const User& user) override;

public:

private:
    CsvStorage();
    void initializeFilesIfNeeded();
    void inflateFileForUsers(QFile& f);
    void initializeIdrs();

private:
    int nextUserId;
    int nextProductId;
    int nextPurchaseId;
    int nextCostId;
};

#endif // CSVSTORAGE_H
