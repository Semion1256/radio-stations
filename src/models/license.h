#pragma once
#include <QString>
#include <QDateTime>
class License{
public:
    License();
    License(int id, const QString& licenseNumber, const QDate& issueDate,
            const QDate& expiryDate, int stationId, bool isValid,
            const QString& scanPath = "", const QString& notes = "");
    // Getters
    int id() const { return m_id; }
    QString licenseNumber() const { return m_licenseNumber; }
    QDate issueDate() const { return m_issueDate; }
    QDate expiryDate() const { return m_expiryDate; }
    int stationId() const { return m_stationId; }
    bool isValid() const { return m_isValid; }
    QString scanPath() const { return m_scanPath; }
    QString notes() const { return m_notes; }
    QDateTime createdAt() const { return m_createdAt; }
    QDateTime updatedAt() const { return m_updatedAt; }

    // Setters
    void setId(int id) { m_id = id; }
    void setLicenseNumber(const QString& licenseNumber) { m_licenseNumber = licenseNumber; }
    void setIssueDate(const QDate& issueDate) { m_issueDate = issueDate; }
    void setExpiryDate(const QDate& expiryDate) { m_expiryDate = expiryDate; }
    void setStationId(int stationId) { m_stationId = stationId; }
    void setIsValid(bool isValid) { m_isValid = isValid; }
    void setScanPath(const QString& scanPath) { m_scanPath = scanPath; }
    void setNotes(const QString& notes) { m_notes = notes; }


    bool isValidObj() const;
    bool isExpired() const;
    int daysUntilExpiry() const;
private:
    int m_id;
    QString m_licenseNumber;
    QDate m_issueDate;
    QDate m_expiryDate;
    int m_stationId;
    bool m_isValid;
    QString m_scanPath;
    QString m_notes;
    QDateTime m_createdAt;
    QDateTime m_updatedAt;

};
