#pragma once
#include "repositories/licenseRepository.h"
#include "models/license.h"
class LicenseService{
public:
    LicenseService(LicenseRepository& license_repo);

    bool addLicense( License& license, QString &errorMessage);
    QVector<License> getAllLicenses();
    License getLicenseById(int id);
    bool updateLicense( License& license, QString& errorMessage);
    bool removeLicense(int id, QString& errorMessage);

private:
    LicenseRepository m_license_repo;
};
