#ifndef USERVALIDATORFACTORY_H
#define USERVALIDATORFACTORY_H

#include <memory>

#include "uservalidator.h"
#include "validatortype.h"

class UserValidatorFactory
{
public:
    static UserValidatorSp get(ValidatorType);
};

#endif // USERVALIDATORFACTORY_H
