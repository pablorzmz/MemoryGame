#include "ScoreTableView.h"

ScoreTableView::ScoreTableView()
    :QTableView()
    ,pointer(Q_NULLPTR)
{
   this->setWindowTitle("Players Score");
   QHeaderView* horizontalHeader = this->horizontalHeader();
   horizontalHeader->setSectionResizeMode(QHeaderView::Stretch);
   this->setWindowFlags(Qt::Window | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);
   this->setWindowModality(Qt::ApplicationModal);

}

ScoreTableView::~ScoreTableView()
{

}


void ScoreTableView::setSize(const qreal w, const qreal h)
{
    this->setMaximumHeight(h);
    this->setMaximumWidth(w);
    this->setMinimumHeight(h);
    this->setMinimumWidth(w);
}
#include <iostream>
void ScoreTableView::closeEvent(QCloseEvent *event)
{
    delete this->pointer;
}
