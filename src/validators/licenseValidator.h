#pragma once
#include <QString>
#include "models/license.h"
class LicenseValidator{
public:
    struct ValidationResult{
        bool isValid;
        QString errorMessage;
    };
    static ValidationResult validateForCreate(const License &license);
    static ValidationResult validateForUpdate(const License &license);
private:
    static bool validateLicenseNumber(const License& license);
    static bool validateStationId(const License& license);
    static bool validateDate(const License& license);

    static ValidationResult createError(const QString& message);

};
