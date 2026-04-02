#pragma once
#include "QWidget"
#include "QPushButton"

class BaseTab:public QWidget{
    Q_OBJECT
public:
    BaseTab(QWidget *parent = nullptr);
    virtual ~BaseTab() = default;
    virtual void refresh() = 0;
    virtual void search() = 0;
    virtual void onAddClicked() = 0;
    virtual void onUpdateClicked()=0;
    virtual void onRemoveClicked() = 0;


protected:
    void setupButtons();
    QPushButton* m_addBtn;
    QPushButton* m_removeBtn;
    QPushButton* m_updateBtn;


};
