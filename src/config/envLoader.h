#pragma once
#include <QString>
struct Config{
    QString host;
    int port;
    QString name;
    QString user;
    QString password;
};

class EnvLoader{
public:
    static std::optional<Config> load(const QString& filePath);


};
