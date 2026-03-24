#include "station.h"
Station::Station(int id, const QString& name, const QString& city,
                 const QString& frequency, int operatorId, bool isActive)
    : m_id(id)
    , m_name(name)
    , m_city(city)
    , m_frequency(frequency)
    , m_operatorId(operatorId)
    , m_isActive(isActive)
{
}

bool Station::isValid() const
{
    return !m_name.isEmpty() &&
           !m_city.isEmpty() &&
           !m_frequency.isEmpty() &&
           m_operatorId > 0;
}
