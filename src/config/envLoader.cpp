#include "envLoader.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QDir>
std::optional<Config> EnvLoader::load(const QString& filePath)
{
    // TODO добавить findEnvPath
    // Заменить симлинк


    QFile file(filePath);
    if (!file.exists()){
        qDebug()<<".env not found"<<filePath;
        return std::nullopt;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open .env file";
        return std::nullopt;
    }
    Config cfg;

    QTextStream stream(&file);
    while (!stream.atEnd()) {
        QString line = stream.readLine().trimmed();

        if (line.isEmpty() || line.startsWith("#")) continue;

        int separatorPos = line.indexOf('=');
        if (separatorPos == -1) continue;

        QString key = line.left(separatorPos).trimmed();
        QString value = line.mid(separatorPos + 1).trimmed();

        if (key == "DB_HOST") cfg.host = value;
        else if (key == "DB_PORT") cfg.port = value.toInt();
        else if (key == "DB_NAME") cfg.name = value;
        else if (key == "DB_USER") cfg.user = value;
        else if (key == "DB_PASSWORD") cfg.password = value;
    }

    file.close();
    return cfg;


}


