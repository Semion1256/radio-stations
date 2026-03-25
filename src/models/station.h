#pragma once
#include <QString>
#include <QDateTime>
class Station{
public:
    Station();
    Station(int id, const QString& name, const QString& city,
            const QString& frequency, int operatorId, bool isActive);

    // Getters
    int id() const { return m_id; }
    QString name() const { return m_name; }
    QString city() const { return m_city; }
    QString frequency() const { return m_frequency; }
    int operatorId() const { return m_operatorId; }
    bool isActive() const { return m_isActive; }
    QDateTime createdAt() const { return m_createdAt; }
    QDateTime updatedAt() const { return m_updatedAt; }

    // Setters
    void setId(int id) { m_id = id; }
    void setName(const QString& name) { m_name = name; }
    void setCity(const QString& city) { m_city = city; }
    void setFrequency(const QString& frequency) { m_frequency = frequency; }
    void setOperatorId(int operatorId) { m_operatorId = operatorId; }
    void setIsActive(bool isActive) { m_isActive = isActive; }

    bool isValid() const;
private:
    int m_id;
    QString m_name;
    QString m_city;
    QString m_frequency;
    int m_operatorId;
    bool m_isActive;
    QDateTime m_createdAt;
    QDateTime m_updatedAt;
};
