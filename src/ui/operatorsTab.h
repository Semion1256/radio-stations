#pragma once
#include "baseTab.h"
#include <QTableWidget>
#include <QLineEdit>
class OperatorsTab: public BaseTab{
public:
    OperatorsTab(QWidget *parent = nullptr);
    void refresh() override;
    void search() override;
    void onAddClicked() override;
    void onUpdateClicked() override;
    void onRemoveClicked() override;

private:
    void setupUi();
    QTableWidget* m_table;
    QLineEdit* m_searchEdit;
};
