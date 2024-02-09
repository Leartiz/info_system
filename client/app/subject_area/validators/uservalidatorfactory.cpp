#include <stdexcept>

#include "uservalidatorfactory.h"
#include "regexuservalidator.h"
#include "trueuservalidator.h"

const UserValidatorSp UserValidatorFactory::regexInstance{
    get(ValidatorType::Regex)
};

const UserValidatorSp UserValidatorFactory::trueInstance{
    get(ValidatorType::True)
};

UserValidatorSp UserValidatorFactory::get(ValidatorType value)
{
    switch (value) {
    case ValidatorType::Regex: return std::make_shared<RegexUserValidator>();
    case ValidatorType::True: return std::make_shared<TrueUserValidator>();
    }

    throw std::runtime_error("Unknown validator type");
}
