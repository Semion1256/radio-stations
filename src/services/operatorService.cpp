#include "operatorService.h"
#include "validators/operatorValidator.h"
OperatorService::OperatorService(OperatorRepository &op_repo):m_op_repo(op_repo)
{

}

bool OperatorService::addOperator(Operator &op, QString& errorMessage)
{

    auto validation = OperatorValidator::validateForCreate(op);
    if (!validation.isValid){
        errorMessage = validation.errorMessage;
        return false;
    }
    if (!isInnUnique(op.inn(), op.id())){
        errorMessage = "Оператор с таким inn уже существует";
        return false;
    }
    if (!m_op_repo.create(op)){
        return false;
    }
    return true;
}

QVector<Operator> OperatorService::getAllOperators()
{
    return m_op_repo.getAll();
}

Operator OperatorService::getOperatorById(int id)
{

    return m_op_repo.getById(id);
}

bool OperatorService::updateOperator(Operator &op, QString& errorMessage)
{

    auto validation = OperatorValidator::validateForUpdate(op);
    if (!validation.isValid){
       errorMessage = validation.errorMessage;
        return false;
    }
    if (!isInnUnique(op.inn(), op.id())){
        errorMessage = "Оператор с таким inn уже существует";
        return false;
    }
    if (!m_op_repo.update(op)){
        errorMessage = "Ошибка при обновлении оператора";
        return false;
    }
    return true;
}

bool OperatorService::removeOperator(int id, QString& errorMessage)
{
    if (!m_op_repo.remove(id)){
        errorMessage = "Ошибка при удалении оператора по id ";
        return false;
    }
    return true;
}

bool OperatorService::isInnUnique(const QString &inn, int id)
{
    Operator existing = m_op_repo.findByInn(inn);
    if (existing.id()<=0){
        return true;
    }
    return existing.id()==id;
}
