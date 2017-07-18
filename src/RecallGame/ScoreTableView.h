#ifndef SCORETABLEVIEW_H
#define SCORETABLEVIEW_H

#include <QTableView>
#include <QHeaderView>
#include "ScoreTableModel.h"

class ScoreTableView :public QTableView
{
    Q_OBJECT
private:
    ScoreTableMode* pointer;

public:
    ScoreTableView();
    ~ScoreTableView();
    void setSize(const qreal w,const qreal h);
    void closeEvent(QCloseEvent* event);
    inline void setModelPointer(ScoreTableMode* p){this->pointer = p;}
};

#endif // SCORETABLEVIEW_H
