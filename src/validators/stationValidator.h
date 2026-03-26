#include <QString>
#include "models/station.h"
class StationValidator{
public:
    struct ValidationResult{
        bool isValid;
        QString errorMessage;
    };
    static ValidationResult validateForCreate(const Station& station);
    static ValidationResult validateForUpdate(const Station& station);
private:
    static bool validateName(const QString& name);
    static bool validateCity(const QString& city);
    static bool validateFrequency(const QString& frequency);
    static bool validateOperatorId(const QString& operatorId);

    static ValidationResult createError(QString message);
};
