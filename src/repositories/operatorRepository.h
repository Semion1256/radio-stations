#pragma once
#include "baseRepository.h"
#include "models/operator.h"
#include <QVector>
#include <QSqlDatabase>
class OperatorRepository:public BaseRepository<Operator>{
public:
    OperatorRepository(QSqlDatabase& db);
    bool create(Operator& op) override;
    QVector<Operator> getAll() override;
    Operator getById(int id) override;
    bool update(const Operator& op) override;
    bool remove(int id) override;
private:
    QSqlDatabase m_db;
};
