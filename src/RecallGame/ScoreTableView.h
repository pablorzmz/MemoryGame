#ifndef SCORETABLEVIEW_H
#define SCORETABLEVIEW_H

#include <QTableView>
#include <QHeaderView>

class ScoreTableView :public QTableView
{
    Q_OBJECT

public:
    ScoreTableView();
    ~ScoreTableView();
    void setSize(const qreal w,const qreal h);
};

#endif // SCORETABLEVIEW_H
