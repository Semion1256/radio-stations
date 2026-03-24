#pragma once

#include <QSqlDatabase>
class Config;
class DataBaseManager{
public :
    DataBaseManager(const Config& conf);
private:


    QSqlDatabase m_db;
};
