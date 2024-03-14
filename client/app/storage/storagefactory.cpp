#include <stdexcept>

#include "csv_storage/csvstoragefactory.h"
#include "storagefactory.h"

StorageFactorySp StorageFactory::get(Type value)
{
    switch (value) {
    case Csv: return CsvStorageFactory::create();
    }

    throw std::runtime_error("Unknown storage type");
}
