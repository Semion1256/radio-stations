#include "license.h"
License::License(int id, const QString &licenseNumber, const QDate &issueDate, const QDate &expiryDate, int stationId, bool isValid, const QString &scanPath, const QString &notes)
    : m_id(id)
    , m_licenseNumber(licenseNumber)
    , m_issueDate(issueDate)
    , m_expiryDate(expiryDate)
    , m_stationId(stationId)
    , m_isValid(isValid)
    , m_scanPath(scanPath)
    , m_notes(notes)

{

}

bool License::isValidObj() const
{

    if (m_licenseNumber.isEmpty() || m_stationId <= 0) {
        return false;
    }


    if (!m_issueDate.isValid() || !m_expiryDate.isValid()) {
        return false;
    }


    if (m_issueDate > m_expiryDate) {
        return false;
    }

    return true;
}

bool License::isExpired() const
{
    return QDate::currentDate() > m_expiryDate;
}

int License::daysUntilExpiry() const
{
    if (isExpired()) return 0;
    return QDate::currentDate().daysTo(m_expiryDate);
}
