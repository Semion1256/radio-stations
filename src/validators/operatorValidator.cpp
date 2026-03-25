#include "operatorValidator.h"
OperatorValidator::ValidationResult OperatorValidator::validateForCreate(const Operator &op)
{
    if (!validateName(op.name())){
        return createError("Название оператора обязательно");
    }
    if (!validateInn(op.inn())){
        return createError("ИНН должен содержать 10 или 12 цифр");
    }
    if (!validateContactPerson(op.contactPerson())){
        return createError("Контактное лицо обязательное");
    }
    if (!op.phone().isEmpty() && !validatePhone(op.phone())) {
        return createError("Телефон должен содержать минимум 10 цифр");
    }

    if (!op.email().isEmpty() && !validateEmail(op.email())) {
        return createError("Некорректный формат email (пример: name@domain.ru)");
    }

    if (!op.kpp().isEmpty() && !validateKpp(op.kpp())) {
        return createError("КПП должен содержать 9 цифр");
    }

    if (!op.ogrn().isEmpty() && !validateOgrn(op.ogrn())) {
        return createError("ОГРН должен содержать 13 или 15 цифр");
    }

    return {true, ""};
}
OperatorValidator::ValidationResult OperatorValidator::validateForUpdate(const Operator &op)
{
    if (op.id() <= 0) {
        return createError("Неверный идентификатор оператора");
    }

    return validateForCreate(op);
}
bool OperatorValidator::validateName(const QString &name)
{
    return !name.trimmed().isEmpty();
}

bool OperatorValidator::validateInn(const QString &inn)
{
    for (QChar ch : inn) {
        if (!ch.isDigit()) {
            return false;
        }
    }
    return inn.length() == 10 || inn.length() == 12;
}

bool OperatorValidator::validateContactPerson(const QString &contactPerson)
{
    return !contactPerson.trimmed().isEmpty();
}

bool OperatorValidator::validatePhone(const QString &phone)
{
    int count = 0;
    for (QChar ch:phone){
        if (ch.isDigit()){
            count++;
        }
    }
    if (count == 11) {

        return phone.startsWith('7') || phone.startsWith('8');
    }

    if (count == 10) {

        return true;
    }
}

bool OperatorValidator::validateEmail(const QString &email)
{

    if (!email.contains('@')) {
        return false;
    }


    int atPos = email.indexOf('@');
    if (!email.mid(atPos).contains('.')) {
        return false;
    }


    if (email.startsWith('@') || email.endsWith('@') ||
        email.startsWith('.') || email.endsWith('.')) {
        return false;
    }

    return true;
}

bool OperatorValidator::validateKpp(const QString &kpp)
{
    for (QChar ch : kpp) {
        if (!ch.isDigit()) {
            return false;
        }
    }
    return kpp.length() == 9;
}

bool OperatorValidator::validateOgrn(const QString &ogrn)
{
    for (QChar ch : ogrn) {
        if (!ch.isDigit()) {
            return false;
        }
    }
    return ogrn.length() == 13 || ogrn.length() == 15;
}

OperatorValidator::ValidationResult OperatorValidator::createError(QString message)
{
    return {false, message};
}


