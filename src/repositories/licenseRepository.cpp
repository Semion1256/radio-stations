#include "licenseRepository.h"
#include <QSqlQuery>
#include <QSqlError>
bool LicenseRepository::create(License &license)
{
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO licenses (license_number, issue_date, expiry_date, station_id, is_valid, scan_path, notes) "
                  "VALUES (:license_number, :issue_date, :expiry_date, :station_id, :is_valid, :scan_path, :notes) ");
    query.bindValue(":license_number", license.licenseNumber());
    query.bindValue(":issue_date", license.issueDate());
    query.bindValue(":expiry_date", license.expiryDate());
    query.bindValue(":station_id", license.stationId());
    query.bindValue(":is_valid", license.isValid());
    query.bindValue(":scan_path", license.scanPath());
    query.bindValue(":notes", license.notes());
    if (!query.exec()){
        qDebug() << "Failed to create license:" << query.lastError().text();
        return false;
    }
    if (query.next()){
        license.setId(query.value(0).toInt());
    }
    return true;
}

QVector<License> LicenseRepository::getAll()
{
    QVector<License> licenses;
    QSqlQuery query(m_db);
    query.prepare("SELECT * from licenses ORDER BY expiry_date");
    if (!query.exec()) {
        qDebug() << "Failed to get all licenses:" << query.lastError().text();
        return licenses;
    }
    while (query.next()){
        License license;
        license.setId(query.value("id").toInt());
        license.setLicenseNumber(query.value("license_number").toString());
        license.setIssueDate(query.value("issue_date").toDate());
        license.setExpiryDate(query.value("expiry_date").toDate());
        license.setStationId(query.value("station_id").toInt());
        license.setIsValid(query.value("is_valid").toBool());
        license.setScanPath(query.value("scan_path").toString());
        license.setNotes(query.value("notes").toString());

        licenses.append(license);
    }
    return licenses;
}

License LicenseRepository::getById(int id)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * from licenses WHERE id = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "Failed to get licenses by id:" << query.lastError().text();
        return License();
    }
    if (query.next()) {
        License license;
        license.setId(query.value("id").toInt());
        license.setLicenseNumber(query.value("license_number").toString());
        license.setIssueDate(query.value("issue_date").toDate());
        license.setExpiryDate(query.value("expiry_date").toDate());
        license.setStationId(query.value("station_id").toInt());
        license.setIsValid(query.value("is_valid").toBool());
        license.setScanPath(query.value("scan_path").toString());
        license.setNotes(query.value("notes").toString());
        return license;
    }

    return License();

}

bool LicenseRepository::update(const License &license)
{
    QSqlQuery query(m_db);
    query.prepare("UPDATE licenses SET license_number = :license_number, "
                  "issue_date = :issue_date, expiry_date = :expiry_date, "
                  "station_id = :station_id, is_valid = :is_valid, "
                  "scan_path = :scan_path, notes = :notes WHERE id = :id");

    query.bindValue(":license_number", license.licenseNumber());
    query.bindValue(":issue_date", license.issueDate());
    query.bindValue(":expiry_date", license.expiryDate());
    query.bindValue(":station_id", license.stationId());
    query.bindValue(":is_valid", license.isValid() ? 1 : 0);
    query.bindValue(":scan_path", license.scanPath());
    query.bindValue(":notes", license.notes());
    query.bindValue(":id", license.id());

    if (!query.exec()) {
        qDebug() << "Failed to update license:" << query.lastError().text();
        return false;
    }

    return true;
}

bool LicenseRepository::remove(int id)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM licenses WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Failed to delete license:" << query.lastError().text();
        return false;
    }
    return true;
}
