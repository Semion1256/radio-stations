#include "licenseValidator.h"

LicenseValidator::ValidationResult LicenseValidator::validateForCreate(const License &license)
{
    if (!validateLicenseNumber(license)){
        return createError("Номер лицензии обязателен");
    }
    if (!validateStationId(license)){
        return createError("Станция обязательна");
    }
    if (!validateDate(license)){
        return createError("Дата истечения не должна быть раньше даты окончания");
    }
}

LicenseValidator::ValidationResult LicenseValidator::validateForUpdate(const License &license)
{
    if (license.id()<=0){
        return createError("Неверный идентификатор лицензии");
    }
    return validateForCreate(license);
}

bool LicenseValidator::validateLicenseNumber(const License& license)
{
    return !license.licenseNumber().trimmed().isEmpty();
}

bool LicenseValidator::validateStationId(const License &license)
{
    return license.id()>0;
}

bool LicenseValidator::validateDate(const License& license)
{
    if (!license.issueDate().isValid() || !license.expiryDate().isValid()){
        return false;
    }
    return license.issueDate()<=license.expiryDate();
}

LicenseValidator::ValidationResult LicenseValidator::createError(const QString& message)
{
    return {false, message};
}
