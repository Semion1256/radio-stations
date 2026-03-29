#include "stationService.h"
#include "validators/stationValidator.h"
StationService::StationService(StationRepository &st_repo):m_st_repo(st_repo)
{

}

bool StationService::addStation(Station &station, QString &errorMessage)
{
    auto validate = StationValidator::validateForCreate(station);
    if (!validate.isValid){
        errorMessage = validate.errorMessage;
        return false;
    }
    if (!isStationNameUniqueInCity(station.name(), station.city())){
        errorMessage = "В этом городе уже есть радиостанция с таким названием";
        return false;
    }
    if (!isFrequencyUniqueInCity(station.frequency(), station.city())){
        errorMessage = "В этом городе уже есть радиостанция на такой частоте";
        return false;
    }
    if (!m_st_repo.create(station)) {
        errorMessage = "Ошибка при сохранении радиостанции";
        return false;
    }

}

QVector<Station> StationService::getAllStations()
{
    return m_st_repo.getAll();
}

Station StationService::getStationById(int id)
{
    return m_st_repo.getById(id);
}

bool StationService::updateStation(Station &station, QString &errorMessage)
{
    auto validate = StationValidator::validateForUpdate(station);
    if (!validate.isValid){
        errorMessage = validate.errorMessage;
        return false;
    }
    if (!isStationNameUniqueInCity(station.name(), station.city(), station.id())){
        errorMessage = "В этом городе уже есть радиостанция с таким названием";
        return false;
    }
    if (!isFrequencyUniqueInCity(station.frequency(), station.city(), station.id())){
        errorMessage = "В этом городе уже есть радиостанция на такой частоте";
        return false;
    }
    if (!m_st_repo.update(station)) {
        errorMessage = "Ошибка при сохранении радиостанции";
        return false;
    }

}

bool StationService::removeStation(int id, QString &errorMessage)
{
    if (!m_st_repo.remove(id)){
        errorMessage = "Ошибка при удалении оператора по id ";
    }
}

bool StationService::isFrequencyUniqueInCity(QString frequency, QString city, int execludeId)
{
    return m_st_repo.isFrequencyUniqueInCity(frequency, city, execludeId);
}

bool StationService::isStationNameUniqueInCity(QString name, QString city, int execludeId)
{
    return m_st_repo.isStationNameUniqueInCity(name, city, execludeId);
}


