#include "repositories/operatorRepository.h"
class OperatorService{
public:
    OperatorService(OperatorRepository& op_repo);
    bool addOperator( Operator& op, QString &errorMessage);
    QVector<Operator> getAllOperators();
    Operator getOperatorById(int id);
    bool updateOperator( Operator& op, QString& errorMessage);
    bool removeOperator(int id, QString& errorMessage);
    bool isInnUnique(const QString& inn, int id);
private:
    OperatorRepository m_op_repo;
};
