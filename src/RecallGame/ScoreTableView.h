#ifndef SCORETABLEVIEW_H
#define SCORETABLEVIEW_H

#include <QTableView>
#include <QHeaderView>
#include "ScoreTableModel.h"

/*! class ScoreTableView that is used show the model data of score history */
class ScoreTableView :public QTableView
{
    Q_OBJECT
protected:
    ScoreTableModel* pointer;/**< A pointer to a ScoreTableModel object */

public:
    /**
        @brief default constructor for this class
        @details this method constructs and initialize the members of this class
        @return no return value for this method
    */
    ScoreTableView();
    /**
        @brief default destructor for this class
        @details this method destructs the dynamic allocated members of this class
        @return no return value for this method
    */
    ~ScoreTableView();
    /**
        @brief setSize
        @details this method resizes the view to a given dimention
        @param w qreal Width to resize
        @param h qreal Heigth to resize
        @return no return value for this method
    */
    void setSize(const qreal w,const qreal h);
    /**
        @brief virtual method closeEvent
        @details this method is used to destruct the current model when view is closed
        @param event A pointer to a QCloseEvent object
        @return no return value for this method
    */
    void closeEvent(QCloseEvent* event);
    /**
        @brief setModelPointer
        @details this method is set up the model to the view
        @param event A pointer to a ScoreTableModel object
        @return no return value for this method
    */
    inline void setModelPointer(ScoreTableModel* p){this->pointer = p;}
};

#endif // SCORETABLEVIEW_H
