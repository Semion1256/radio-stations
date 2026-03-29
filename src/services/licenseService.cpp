
#include "licenseService.h"
#include "validators/licenseValidator.h"
LicenseService::LicenseService(LicenseRepository &license_repo):m_license_repo(license_repo)
{

}

bool LicenseService::addLicense(License &license, QString &errorMessage)
{
    auto validate = LicenseValidator::validateForCreate(license);
    if (!validate.isValid){
        errorMessage = validate.errorMessage;
    }
    if (!m_license_repo.create(license)){
        return false;
    }
    return true;
}

QVector<License> LicenseService::getAllLicenses()
{
    return m_license_repo.getAll();
}

License LicenseService::getLicenseById(int id)
{
    return m_license_repo.getById(id);
}

bool LicenseService::updateLicense(License &license, QString &errorMessage)
{
    auto validate = LicenseValidator::validateForUpdate(license);
    if (!validate.isValid){
        errorMessage = validate.errorMessage;
        return false;
    }
    if (!m_license_repo.update(license)){
        return false;
    }
    return true;
}

bool LicenseService::removeLicense(int id, QString &errorMessage)
{
    if (!m_license_repo.remove(id)){
        errorMessage = "Ошибка при удалении лицензии по id ";
        return false;

    }
    return true;
}


