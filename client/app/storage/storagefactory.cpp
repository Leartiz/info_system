#include <stdexcept>

#include "storagefactory.h"
#include "csvstorage.h"

Storage& StorageFactory::get(Type value)
{
    switch (value) {
    case Csv: return CsvStorage::instance();
    }

    throw std::runtime_error("Unknown storage type");
}
