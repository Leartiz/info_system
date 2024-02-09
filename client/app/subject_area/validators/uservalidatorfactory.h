#ifndef USERVALIDATORFACTORY_H
#define USERVALIDATORFACTORY_H

#include <memory>

#include "uservalidator.h"
#include "validatortype.h"

class UserValidatorFactory
{
public:
    static const UserValidatorSp regexInstance;
    static const UserValidatorSp trueInstance;

    static UserValidatorSp get(ValidatorType);
};

#endif // USERVALIDATORFACTORY_H
