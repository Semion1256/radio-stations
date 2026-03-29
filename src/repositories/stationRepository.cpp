#include "stationRepository.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
StationRepository::StationRepository(QSqlDatabase &db):m_db(db)
{

}

bool StationRepository::create(Station &station)
{
    QSqlQuery query(m_db);
    query.prepare("INSERT INTO stations (name, city, frequency, operator_id, is_active) values(:name, :city, :frequency, :operator_id, :is_active)");
    query.bindValue(":name", station.name());
    query.bindValue(":city", station.city());
    query.bindValue(":frequency", station.frequency());
    query.bindValue(":operator_id", station.operatorId());
    query.bindValue(":is_active", station.isActive());
    if (!query.exec()){
        qDebug() << "Failed to create station:" << query.lastError().text();
        return false;
    }
    if (query.next()){
        station.setId(query.value(0).toInt());
    }
    return true;


}

QVector<Station> StationRepository::getAll()
{
    QVector<Station> stations;
    QSqlQuery query(m_db);
    query.prepare("SELECT * from stations ORDER BY name");
    if (!query.exec()) {
        qDebug() << "Failed to get all stations:" << query.lastError().text();
        return stations;
    }
    while (query.next()){
        Station station;
        station.setId(query.value("id").toInt());
        station.setName(query.value("name").toString());
        station.setCity(query.value("city").toString());
        station.setFrequency(query.value("frequency").toString());
        station.setOperatorId(query.value("operator_id").toInt());
        station.setIsActive(query.value("is_active").toBool());

        stations.append(station);
    }
    return stations;
}

Station StationRepository::getById(int id)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * from stations WHERE id = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "Failed to get stations by id:" << query.lastError().text();
        return Station();
    }
    if (query.next()){
        Station station;
        station.setId(query.value("id").toInt());
        station.setName(query.value("name").toString());
        station.setCity(query.value("city").toString());
        station.setFrequency(query.value("frequency").toString());
        station.setOperatorId(query.value("operator_id").toInt());
        station.setIsActive(query.value("is_active").toBool());
        return station;
    }
    return Station();
}

bool StationRepository::update(const Station &station)
{
    QSqlQuery query(m_db);
    query.prepare("UPDATE stations SET name = :name, city = :city, frequency = :frequency,"
                  "operator_id = :operator_id, is_active = :is_active  WHERE id = :id");
    query.bindValue(":name", station.name());
    query.bindValue(":city", station.city());
    query.bindValue(":frequency", station.frequency());
    query.bindValue(":operator_id", station.operatorId());
    query.bindValue(":is_active", station.isActive());
    query.bindValue(":id", station.id());
    if (!query.exec()) {
        qDebug() << "Failed to update operator:" << query.lastError().text();
        return false;
    }
    return true;
}

bool StationRepository::remove(int id)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM stations WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Failed to delete station:" << query.lastError().text();
        return false;
    }
    return true;
}

bool StationRepository::isFrequencyUniqueInCity(QString frequency, QString city, int execludeId)
{
    QSqlQuery query(m_db);
    if (execludeId>0){
        query.prepare("SELECT COUNT(*) FROM stations WHERE frequency =:frequency AND city =:city AND id != :id");
        query.bindValue(":id", execludeId);

    }else{
        query.prepare("SELECT COUNT(*) FROM stations WHERE frequency =:frequency AND city =:city");
    }

    query.bindValue(":frequency", frequency);
    query.bindValue(":city", city);
    if (!query.exec()){
        qDebug() << "Failed to check frequency uniqueness:" << query.lastError().text();
        return false;
    }
    if (query.next()){
        int count = query.value(0).toInt();
        return count == 0;
    }
    return false;
}

bool StationRepository::isStationNameUniqueInCity(QString name, QString city, int execludeId)
{
    QSqlQuery query(m_db);
    if (execludeId>0){
        query.prepare("SELECT COUNT(*) FROM stations WHERE name =:name AND city =:city AND id != :id");
        query.bindValue(":id", execludeId);

    }else{
        query.prepare("SELECT COUNT(*) FROM stations WHERE frequency =:frequency AND city =:city");
    }

    query.bindValue(":frequency", name);
    query.bindValue(":city", city);
    if (!query.exec()){
        qDebug() << "Failed to check name uniqueness:" << query.lastError().text();
        return false;
    }
    if (query.next()){
        int count = query.value(0).toInt();
        return count == 0;
    }
    return false;
}


