#include "stationValidator.h"
StationValidator::ValidationResult StationValidator::validateForCreate(const Station &station)
{
    if (!validateName(station.name())){
        createError("Название радиостанции обязательно");
    }
    if (!validateCity(station.name())){
        createError("Город обязателен");
    }
    if (!validateFrequency(station.name())){
        createError("Частота должна содержать цифры (например, 101.5)");
    }
    if (!validateOperatorId(station.name())){
        createError("Оператор не выбран");
    }
    return {true, ""};
}

StationValidator::ValidationResult StationValidator::validateForUpdate(const Station &station)
{
    if (station.id() <= 0) {
        return createError("Неверный идентификатор радиостанции");
    }

    return validateForCreate(station);
}

bool StationValidator::validateName(const QString &name)
{
    return !name.trimmed().isEmpty();

}

bool StationValidator::validateCity(const QString &city)
{
    return !city.trimmed().isEmpty();
}

bool StationValidator::validateFrequency(const QString &frequency)
{

    int count = 0;
    for (QChar ch : frequency) {
        if (ch.isDigit()) {
            count++;
        }
    }
    return count >= 1;
}

bool StationValidator::validateOperatorId(const QString &operatorId)
{
    return !operatorId.trimmed().isEmpty();
}

StationValidator::ValidationResult StationValidator::createError(QString message)
{
    return {false, message};
}
