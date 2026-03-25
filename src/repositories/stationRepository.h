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
private:
    QSqlDatabase m_db;

};
