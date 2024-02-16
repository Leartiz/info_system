#include <stdexcept>

#include "csv_storage/csvstorage.h"
#include "storagefactory.h"

Storage& StorageFactory::get(Type value)
{
    switch (value) {
    case Csv: return CsvStorage::instance();
    }

    throw std::runtime_error("Unknown storage type");
}
