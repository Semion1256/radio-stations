#pragma once
#include <QString>
#include <QDateTime>
class Operator{
public:
    Operator(int id, const QString& name, const QString& inn,
             const QString& kpp, const QString& ogrn,
             const QString& phone, const QString& email,
             const QString& contactPerson);
    // Getters
    int id() const { return m_id; }
    QString name() const { return m_name; }
    QString inn() const { return m_inn; }
    QString kpp() const { return m_kpp; }
    QString ogrn() const { return m_ogrn; }
    QString phone() const { return m_phone; }
    QString email() const { return m_email; }
    QString contactPerson() const { return m_contactPerson; }
    QDateTime createdAt() const { return m_createdAt; }
    QDateTime updatedAt() const { return m_updatedAt; }

    // Setters
    void setId(int id) { m_id = id; }
    void setName(const QString& name) { m_name = name; }
    void setInn(const QString& inn) { m_inn = inn; }
    void setKpp(const QString& kpp) { m_kpp = kpp; }
    void setOgrn(const QString& ogrn) { m_ogrn = ogrn; }
    void setPhone(const QString& phone) { m_phone = phone; }
    void setEmail(const QString& email) { m_email = email; }
    void setContactPerson(const QString& contactPerson) { m_contactPerson = contactPerson; }

    bool isValid() const;
private:
    int m_id;
    QString m_name;
    QString m_inn;
    QString m_kpp;
    QString m_ogrn;
    QString m_phone;
    QString m_email;
    QString m_contactPerson;
    QDateTime m_createdAt;
    QDateTime m_updatedAt;

};
