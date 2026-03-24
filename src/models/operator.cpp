#include "operator.h"
Operator::Operator(int id, const QString &name, const QString &inn, const QString &kpp, const QString &ogrn, const QString &phone, const QString &email, const QString &contactPerson)
    : m_id(id)
    , m_name(name)
    , m_inn(inn)
    , m_kpp(kpp)
    , m_ogrn(ogrn)
    , m_phone(phone)
    , m_email(email)
    , m_contactPerson(contactPerson)
{

}

bool Operator::isValid() const
{
    return !m_name.isEmpty() &&
           !m_inn.isEmpty() &&
           !m_contactPerson.isEmpty();
}
