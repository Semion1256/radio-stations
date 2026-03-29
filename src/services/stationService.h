#pragma once
#include "repositories/stationRepository.h"
#include "models/station.h"
class StationService{
public:
    StationService(StationRepository& st_repo);
    bool addStation( Station& station, QString &errorMessage);
    QVector<Station> getAllStations();
    Station getStationById(int id);
    bool updateStation( Station& station, QString& errorMessage);
    bool removeStation(int id, QString& errorMessage);


private:
    bool isFrequencyUniqueInCity(QString frequency, QString city, int execludeId = 0);
    bool isStationNameUniqueInCity(QString name, QString city, int execludeId = 0);
    StationRepository m_st_repo;
};
