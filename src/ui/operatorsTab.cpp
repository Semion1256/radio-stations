#include "operatorsTab.h"
#include <QDebug>
#include <QVBoxLayout>
#include <QLabel>
OperatorsTab::OperatorsTab( QWidget *parent):BaseTab(parent)
{
    setupUi();
}

void OperatorsTab::refresh()
{

}

void OperatorsTab::search()
{

}

void OperatorsTab::onAddClicked()
{
    qDebug()<<"add";
}

void OperatorsTab::onUpdateClicked()
{
    qDebug()<<"update";
}

void OperatorsTab::onRemoveClicked()
{
    qDebug()<<"remove";
}

void OperatorsTab::setupUi()

{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    setupButtons();
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(m_addBtn);
    buttonsLayout->addWidget(m_updateBtn);
    buttonsLayout->addWidget(m_removeBtn);
    mainLayout->addLayout(buttonsLayout);

    QHBoxLayout* searchLayout = new QHBoxLayout();
    QLabel* searchLabel = new QLabel("🔍", this);
    m_searchEdit = new QLineEdit(this);
    m_searchEdit->setPlaceholderText("Поиск по названию, ИНН, телефону...");

    searchLayout->addWidget(searchLabel);
    searchLayout->addWidget(m_searchEdit);
    searchLayout->addStretch();
    mainLayout->addLayout(searchLayout);
}
