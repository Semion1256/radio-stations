#include "operatorRepository.h"
#include <QSqlQuery>
#include <QSqlError>
OperatorRepository::OperatorRepository(QSqlDatabase &db):m_db(db)
{

}

bool OperatorRepository::create(Operator &op)
{
    QSqlQuery query(m_db);
    query.prepare(" INSERT INTO operators (name, inn, kpp, ogrn, phone, email, contact_person)"
        "VALUES (:name, :inn, :kpp, :ogrn, :phone, :email, :contact_person)");
    query.bindValue(":name", op.name());
    query.bindValue(":inn", op.inn());
    query.bindValue(":kpp", op.kpp());
    query.bindValue(":orgn", op.ogrn());
    query.bindValue(":phone", op.phone());
    query.bindValue(":email", op.email());
    query.bindValue(":contact_person", op.contactPerson());
    if (!query.exec()){
        qDebug() << "Failed to create operator:" << query.lastError().text();
        return false;
    }
    if (query.next()){
        op.setId(query.value(0).toInt());
    }
    return true;
}

QVector<Operator> OperatorRepository::getAll()
{
    QVector<Operator> operators;
    QSqlQuery query(m_db);
    query.prepare("SELECT * from operators ORDER BY name");
    if (!query.exec()) {
        qDebug() << "Failed to get all operators:" << query.lastError().text();
        return operators;
    }
    while (query.next()){
        Operator op;
        op.setId(query.value("id").toInt());
        op.setName(query.value("name").toString());
        op.setInn(query.value("inn").toString());
        op.setKpp(query.value("kpp").toString());
        op.setOgrn(query.value("ogrn").toString());
        op.setPhone(query.value("phone").toString());
        op.setEmail(query.value("email").toString());
        op.setContactPerson(query.value("contact_person").toString());
        operators.append(op);
    }
    return operators;
}

Operator OperatorRepository::getById(int id)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * from operators WHERE id = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
        qDebug() << "Failed to get operator by id:" << query.lastError().text();
        return Operator();
    }
    if (query.next()){
        Operator op;
        op.setId(query.value("id").toInt());
        op.setName(query.value("name").toString());
        op.setInn(query.value("inn").toString());
        op.setKpp(query.value("kpp").toString());
        op.setOgrn(query.value("ogrn").toString());
        op.setPhone(query.value("phone").toString());
        op.setEmail(query.value("email").toString());
        op.setContactPerson(query.value("contact_person").toString());
        return op;
    }
    return Operator();
}

bool OperatorRepository::update(const Operator &op)
{
    QSqlQuery query(m_db);
    query.prepare("UPDATE operators SET name = :name, inn = :inn,kpp = :kpp,"
            "ogrn = :ogrn, phone = :phone, email = :email, contact_person = :contact_person WHERE id = :id");
    query.bindValue(":name", op.name());
    query.bindValue(":inn", op.inn());
    query.bindValue(":kpp", op.kpp());
    query.bindValue(":ogrn", op.ogrn());
    query.bindValue(":phone", op.phone());
    query.bindValue(":email", op.email());
    query.bindValue(":contact_person", op.contactPerson());
    query.bindValue(":id", op.id());
    if (!query.exec()) {
        qDebug() << "Failed to update operator:" << query.lastError().text();
        return false;
    }
    return true;

}

bool OperatorRepository::remove(int id)
{
    QSqlQuery query(m_db);
    query.prepare("DELETE FROM operators WHERE id = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Failed to delete operator:" << query.lastError().text();
        return false;
    }
    return true;
}

Operator OperatorRepository::findByInn(const QString& inn)
{
    QSqlQuery query(m_db);
    query.prepare("SELECT * from operators WHERE inn = :inn");
    query.bindValue(":inn", inn);
    if (!query.exec()) {
        qDebug() << "Failed to get operator by id:" << query.lastError().text();
        return Operator();
    }
    if (query.next()){
        Operator op;
        op.setId(query.value("id").toInt());
        op.setName(query.value("name").toString());
        op.setInn(query.value("inn").toString());
        op.setKpp(query.value("kpp").toString());
        op.setOgrn(query.value("ogrn").toString());
        op.setPhone(query.value("phone").toString());
        op.setEmail(query.value("email").toString());
        op.setContactPerson(query.value("contact_person").toString());
        return op;
    }
    return Operator();
}
