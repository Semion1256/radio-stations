#include <QApplication>
#include "mainwindow.h"
#include "config/envLoader.h"
#include "database/databaseManager.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    std::optional<Config> dbConfig = EnvLoader::load(".env");
    if (dbConfig.has_value()){
        DataBaseManager databaseManager(dbConfig.value());
    }

    MainWindow window;
    window.show();
    return app.exec();
}

