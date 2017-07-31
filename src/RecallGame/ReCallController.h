#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define SOUNDS
#include "Elements.h"
#include <chrono>
#include <QApplication>
#include <QFile>
#include <QGraphicsScene>
#include <QInputDialog>
#include <QMessageBox>
#include <QPoint>
#include <QPushButton>
#include <QQueue>
#include <QSequentialAnimationGroup>
#include <QSvgRenderer>
#include <QtMath>
#include <QTextStream>
#include <QVector>
#include <random>
#include "ReCallMainView.h"
#include "ReCallController.h"
#include "ScoreTableModel.h"
#include "ScoreTableView.h"

#ifdef SOUNDS
    #include <QMediaPlaylist>
    #include <QMediaPlayer>
#endif


class QGraphicsScene;
class ReCallMainView;

/*! class ReCallController: main controller of application */
class ReCallController : public QApplication
{

    Q_OBJECT
    protected:
    /*! class GameSettings: it is used as a structure for the game settings */
    class GameSettings
    {
    public:
        const int maxGameLevels = 16;
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
    QGraphicsScene* m_scene;/**< A pointer to a QGraphicsScene that represents the game scene */
    ReCallMainView* m_view;/**< pointer to a ReCallMainView that represents the current game view */
    QSequentialAnimationGroup* m_launchAnimation;/**< A pointer to a QSequentialAnimationGroup object that is used to control the launching animations in a sequential way */
    Elements elements;/**< An object of class Elements that stores the game svg elements */
    int reCallGameLevel;/**< An integer value that is used to store the current game level */
    QVector<QPoint*> avaiblePositions;/**< A QVector object of QPoints pointer that stores the avaible position for launching elements from tube */
    double levelLauchSpeed;/**< A double value that controls the duration of each lauching animation */
    QQueue<QString> gameOrderQueue;/**< QQueue object that stores the lanching order, when the lanching animation start */
    QMessageBox* m_messages;/**< A pointer to a QMessageBox that is used to launch message to user and to decide the next game action */
    GameSettings mySettings;/**< An object of class GameSettings */
    ScoreTableView viewScores;/**< A ScoreTableView object that is a table with the players scores history */
    ScoreTableModel* modelScores;/**< A pointer ScoreTableModel pointer that constructs the model of score table view */
    #ifdef SOUNDS
        QMediaPlayer*  m_currentSound;/**< A pointer to a QMediaPlayer object that plays the game sounds */
        QMediaPlaylist* m_backGroundMusic;/**< A pointer to a QMediaPlaylist that stores the background game music */
        QMediaPlayer*  m_backGroundSound;/**< A pointer to a QMediaPlayer object that plays the game backgroud muusic in a loop */
    #endif

    public:
        /**
            @brief Default constructor of this class
            @details
            @todo This constructs an object and initialize its members
            @return no return value for this method
        */
    ReCallController(int &argc, char **argv);
    /**
        @brief Default destructor of this class
        @details
        @todo This destructs its members in dynamic memory
        @return no return value for this method
    */
    ~ReCallController();
    /**
        @brief runGame
        @details
        @todo This method start the executions of this application
        @return no return value for this method
    */
    int runGame();
    /**
        @brief loadPics
        @details
        @todo This method load for the first time the elements and setUp the animations
        @return no return value for this method
    */
    void loadPics();
    /**
        @brief connectControlAnimationSignals
        @details
        @todo This method connect the signal of m_launchAnimation and add animations to it for executing the lanching
        @return no return value for this method
    */
    void connectControlAnimationSignals();
    /**
        @brief startGame
        @details
        @todo This method is called every time the lanching is going to be done
        @return no return value for this method
    */
    void startGame();
    /**
        @brief setUpLevelAnimation
        @details
        @todo This method setUp the amount of launching animation according to the current value of member reCallGameLevel
        @param duration Integer value for the animation duration
        @param index Integer value of the index if the element to setUp its launching animation
        @param endX qreal value for the end point x
        @param endY qreal value for the end point y
        @param beginX start value for the end point x
        @param beginY start value for the end point y
        @return no return value for this method
    */
    void setUpLevelAnimation(const int duration, const int index, const qreal endX, const qreal endY, const qreal beginX, const qreal beginY);
    /**
        @brief setUpAvaiblePositions
        @details
        @todo This method initialize the avaible QPoints for the lanching animations
        @return no return value for this method
    */
    void setUpAvaiblePositions();
    /**
        @brief suffleAvaiblePositions
        @details
        @todo This method shuffle QPoints for avoiding repeat them
        @return no return value for this method
    */
    void suffleAvaiblePositions();
    /**
        @brief resetGame
        @details
        @todo This method reset game start setting and move elements to start positions once again
        @return no return value for this method
    */
    void resetGame();
    /**
        @brief incrementScore
        @details
        @todo This method increase the current player score when the current lauching queue is correctly selected
        @return no return value for this method
    */
    inline void increaseScore(){this->mySettings.playerScore+=mySettings.scoreIncrement;}
    /**
        @brief resetFromButton
        @details
        @todo This method is called when PropObject reset button is mouseClicked. Restarts the game.
        @return no return value for this method
    */
    void resetFromButton();
    /**
        @brief showScoresTable
        @details
        @todo This method shows a view of the current player scores history
        @return no return value for this method
    */
    void showScoresTable();
    /**
        @brief askForPlayerName
        @details
        @todo This method asks for player name. The game does not start without a player name
        @return no return value for this method
    */
    void askForPlayerName();
    /**
        @brief insertCurrentUserScore
        @details
        @todo This stores the current user score, name, level and diffculty when game finishes.
        @return no return value for this method
    */
    void insertCurrentUserScore();

    private slots:
    /**
        @brief incrementNextLevel
        @details
        @todo This slot is connected to a signal that controls when the current player level will be rised up
        @return no return value for this method
    */
    void incrementNextLevel();
    /**
        @brief clickedObjectEvaluation
        @details
        @todo This slot is connected to a signal that launching queue and the player clicks over the elements. Also, controls the finished and next diffulty of game.
        @return no return value for this method
    */
    void clickedObjectEvaluation();
    /**
        @brief aceptedEvent
        @details
        @todo This slot is connected to a signal manages the ok button actions of m_messages
        @return no return value for this method
    */
    void aceptedEvent();
    /**
        @brief rejectEvent
        @details
        @todo This slot is connected to a signal manages the cancel button actions of m_messages
        @return no return value for this method
    */
    void rejectEvent();


};

#endif // MAINWINDOW_H
