#include "databaseManager.h"
#include "config/envLoader.h"
#include <QDebug>
DataBaseManager::DataBaseManager(const Config &conf)
{
    m_db = QSqlDatabase::addDatabase("QPSQL");
    m_db.setHostName(conf.host);
    m_db.setPort(conf.port);
    m_db.setDatabaseName(conf.name);
    m_db.setUserName(conf.user);
    m_db.setPassword(conf.password);
    if (m_db.open()){
        qDebug() << "Database connected successfully!";
    }else{
        qDebug() << "Database connected failed!";
    }
}
