#include "baseRepository.h"
#include "models/license.h"
#include <QSqlDatabase>
class LicenseRepository:public BaseRepository<License>{
public:
    LicenseRepository(QSqlDatabase& db);
    bool create(License& license) override;
    QVector<License> getAll() override;
    License getById(int id) override;
    bool update(const License& license) override;
    bool remove(int id) override;
private:
    QSqlDatabase m_db;
};
