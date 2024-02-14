#include <QApplication>
#include <QMessageBox>
#include <QDebug>

#include "windownavigator.h"

#include "storage/storage.h"
#include "storage/storagefactory.h"

int main(int argc, char *argv[])
{
    try {
        // prepare dependencies

        Storage& storage =
            StorageFactory::get(StorageType::Csv);

        // noexcept part...

        QApplication a(argc, argv);
        WindowNavigator _(
            storage
            );
        return a.exec();
    }
    catch(const std::runtime_error& err) {
        qCritical() << err.what();
    }
    return 0;
}
