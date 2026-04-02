#include "baseTab.h"
#include <QPushButton>
BaseTab::BaseTab(QWidget *parent):QWidget(parent)
{

}

void BaseTab::setupButtons(){
    m_addBtn = new QPushButton("Добавить",this);
    m_removeBtn = new QPushButton("Удалить", this);
    m_updateBtn = new QPushButton("обновить", this);

    connect(m_addBtn, &QPushButton::clicked, this, &BaseTab::onAddClicked);
    connect(m_removeBtn, &QPushButton::clicked, this, &BaseTab::onRemoveClicked);
    connect(m_updateBtn, &QPushButton::clicked, this, &BaseTab::onUpdateClicked);

}
