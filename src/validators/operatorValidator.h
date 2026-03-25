#include <QString>
#include "models/operator.h"
class OperatorValidator{
     // TODO: Заменить на регулярное выражение для более строгой проверки
public:
    struct ValidationResult{
        bool isValid;
        QString errorMessage;
    };

    static ValidationResult validateForCreate(const Operator& op);
    static ValidationResult validateForUpdate(const Operator& op);
private:
    static bool validateName(const QString& name);
    static bool validateInn(const QString& inn);
    static bool validateContactPerson(const QString& contactPerson);
    static bool validatePhone(const QString& phone);
    static bool validateEmail(const QString& email);
    static bool validateKpp(const QString& kpp);
    static bool validateOgrn(const QString& ogrn);
    static ValidationResult createError(QString message);


};
