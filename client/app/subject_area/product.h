#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

#include <optional>

class BaseProduct
{

protected:
    std::optional<int> id;
    QString name;
};

class Product : public BaseProduct
{
public:
    Product();

private:

};

#endif // PRODUCT_H
