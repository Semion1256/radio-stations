#pragma once
#include "baseRepository.h"
#include "models/station.h"
#include <QSqlDatabase>
class StationRepository:public BaseRepository<Station>{
public:
    StationRepository(QSqlDatabase& db);
    bool create(Station& station) override;
    QVector<Station> getAll() override;
    Station getById(int id) override;
    bool update(const Station& station) override;
    bool remove(int id) override;

    bool isFrequencyUniqueInCity(QString frequency, QString city, int execludeId =0);
    bool isStationNameUniqueInCity(QString name, QString city, int execludeId =0);
private:
    QSqlDatabase m_db;

};
