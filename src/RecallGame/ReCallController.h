#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Elements.h"
#include <chrono>
#include <QApplication>
#include <QGraphicsScene>
#include <QMessageBox>
#include <QPoint>
#include <QPushButton>
#include <QQueue>
#include <QSequentialAnimationGroup>
#include <QSvgRenderer>
#include <QtMath>
#include <QVector>
#include <random>
#include "ReCallMainView.h"
#include "ReCallController.h"
#include "ScoreTableModel.h"
#include "ScoreTableView.h"


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
        QString playerName;
        int gameDifficulty;
        int speedDecrement;
        int playerScore;
    GameSettings()
    :scoreIncrement(2)
    ,playerName("")
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
    ScoreTableView vistaScores;
    ScoreTableMode modeloScores;

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
