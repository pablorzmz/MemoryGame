#ifndef RECALLMAINVIEW_H
#define RECALLMAINVIEW_H

#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include <QGraphicsView>
#include "Object.h"
#include "PropObject.h"
#include "ReCallMainView.h"


class Object;
class PropObject;


/*! class ReCallMainView: main view of the application */
class ReCallMainView:public QGraphicsView
{
Q_OBJECT
protected:
  PropObject* m_tube;/**< A pointer to a PropObject that is used as the launching elemnts origin */
  PropObject* m_backGround;/**< A pointer to a PropObject that is as view background */
  QSvgRenderer* m_svgRenderer;/**< A pointer to a QSvgRenderer that used to render all the svg items */
  QGraphicsTextItem* m_playerScore;/**< A pointer to a QGraphicsTextItem that is used to show the current player score text */
  PropObject* m_title;/**< A pointer to a PropObject that is used to show the main title instruction */
  QString scoreLegend;/**< A QString object that contains the player score leyend */
  PropObject* m_score_button;/**< A pointer to a PropObject that is used as reset button */
  PropObject* m_reset_button;/**< A pointer to a PropObject that is used to show the scores view table */
  friend class ReCallController;


public:
  /**
      @brief default constructor for this class and initialize its members
      @details
      @param scene A pointer to the main scene that is used to add the view elements
      @return no return value for this method
  */
    ReCallMainView(QGraphicsScene* scene);
    /**
        @brief default destructor for this class
        @details this method destructs all of its members in dynamic memory
        @param scene A pointer to the main scene that is used to add the view elements
        @return no return value for this method
    */
    ~ReCallMainView();
    /**
        @brief paintBackGround
        @details this is used to render and initialize the current view background
        @param scene A pointer to the main scene that is used to add the view elements
        @return no return value for this method
    */
    void paintBackGround(QGraphicsScene* scene);
    /**
        @brief initComponents
        @details this method is used to set up all the members of this class
        @return no return value for this method
    */
    void initComponents(QGraphicsScene* scene);
    /**
        @brief updateScore
        @details this method is used to update the leyend in the m_playerScore. It is called any time the player score change
        @param newScoreText The integer value of the new player score to be shown;
        @return no return value for this method
    */
    void updateScore(const QString playerName,const int &newScoreText);
};

#endif // RECALLMAINVIEW_H
