#include <QFile>

#include "csvfile.h"
#include "storage/storageerror.h"

using StorageError::Initialization;

namespace
{



} // namespace

CsvFile::CsvFile(const QString& fn)
    : f(fn)
{
    if (!QFile::exists(fn)) {
        if (!f.open(QFile::WriteOnly)) { // create!
            throw Initialization{
                QString{ "Create file %1 failed" }.arg(fn)
            };
        }
    }
}
