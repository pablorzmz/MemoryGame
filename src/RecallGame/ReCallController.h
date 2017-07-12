#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ReCallMainView.h"
#include "ReCallController.h"
#include "Elements.h"
#include <QSvgRenderer>
#include <QtMath>
#include <QApplication>
#include <QGraphicsScene>
#include <QSequentialAnimationGroup>
#include <QPushButton>
#include <QMessageBox>
#include <QPoint>
#include <QVector>
#include <QQueue>
#include <random>
#include <chrono>


class QGraphicsScene;
class ReCallMainView;

class ReCallController : public QApplication
{

    Q_OBJECT
    private:
    class GameSettings
    {
    public:
        const int maxGameLevels = 15;
        int scoreIncrement;
        const QString textPlayscoreLabel ="Player score: ";
        int gameDifficulty;
        int speedDecrement;
        int playerScore;
    GameSettings()
    :scoreIncrement(2)
    ,gameDifficulty(1)
    ,speedDecrement(100)
    ,playerScore(0)
        {
        }
    void updateGameSettings()
    {
       switch(gameDifficulty)
       {
           case 1:
            scoreIncrement=2;
            speedDecrement+=speedDecrement;
           break;
           case 2:
            scoreIncrement=5;
            speedDecrement+=speedDecrement;
           break;
           case 3:
            scoreIncrement=10;
            speedDecrement+=speedDecrement;
           break;
           default:
           break;
       }
    }
    };


    protected: 
    QGraphicsScene* m_scene;
    ReCallMainView* m_view;
    QSequentialAnimationGroup* m_launchAnimation;
    Elements elements;
    int reCallGameLevel;
    QVector<QPoint*> avaiblePositions;
    double levelLauchSpeed;
    QQueue<QString> gameOrderQueue;
    QMessageBox* m_messages;
    GameSettings mySettings;


    public:
    ReCallController(int &argc, char **argv, int flags = ApplicationFlags);
    /// Destructor
    ~ReCallController();
    int runGame();
    void loadPics();
    void connectControlAnimationSignals();
    void startGame();
    void setUpLevelAnimation(const int duration, const int index, const qreal endX, const qreal endY, const qreal beginX, const qreal beginY);
    void setUpAvaiblePositions();
    void suffleAvaiblePositions();
    void resetGame();
    inline void incrementScore(){this->mySettings.playerScore+=mySettings.scoreIncrement;}

    private slots:
    void incrementNextLevel();
    void clickedObjectEvaluation();
    void aceptedEvent();
    void rejectEvent();

};

#endif // MAINWINDOW_H
