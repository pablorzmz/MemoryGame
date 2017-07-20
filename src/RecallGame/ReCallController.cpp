#include "ReCallController.h"

ReCallController::ReCallController(int &argc, char **argv)
    : QApplication(argc, argv)
    ,m_scene(Q_NULLPTR)
    ,m_view(Q_NULLPTR)
    ,m_launchAnimation(Q_NULLPTR)
    ,elements()
    ,reCallGameLevel(1)
    ,levelLauchSpeed(1000)
    ,m_messages(Q_NULLPTR)
    ,viewScores()
    ,modelScores(Q_NULLPTR)
    #ifdef SOUNDS
    ,m_currentSound(Q_NULLPTR)
    ,m_backGroundMusic(Q_NULLPTR)
    ,m_backGroundSound(Q_NULLPTR)
    #endif
{   

    QApplication::setDesktopSettingsAware(false);
    #ifdef SOUNDS
    m_currentSound = new QMediaPlayer();

    m_backGroundMusic = new QMediaPlaylist();
    m_backGroundMusic->addMedia(QUrl("qrc::/../Sounds/backGroundMusic.wav"));
    m_backGroundMusic->setCurrentIndex(0);
    m_backGroundMusic->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);

    m_backGroundSound = new QMediaPlayer();
    m_backGroundSound->setPlaylist(m_backGroundMusic);
    m_backGroundSound->setVolume(50);
    m_backGroundSound->play();
    #endif

    this->m_scene = new QGraphicsScene();
    this->m_view = new ReCallMainView(this->m_scene);
    this->m_messages = new QMessageBox;


    this->m_messages->addButton(QMessageBox::Ok);
    this->m_messages->addButton(QMessageBox::Cancel);        
    connect((this->m_messages->button(QMessageBox::Ok)), SIGNAL (pressed()), this, SLOT (aceptedEvent()));
    connect((this->m_messages->button(QMessageBox::Cancel)), SIGNAL (pressed()), this, SLOT (rejectEvent()));

    m_view->initComponents(m_scene);
    this->setApplicationName("Recall game v1.0");
    //elements.addElements();

    this->viewScores.setSize(this->m_view->width(),this->m_view->height());
    this->m_view->m_tube->setControllerEvent(this);
    this->m_view->m_reset_button->setControllerEvent(this);
    this->m_view->m_score_button->setControllerEvent(this);

    this->setUpAvaiblePositions();
    m_view->show();
    this->askForPlayerName();

}

void ReCallController::incrementNextLevel()
{
    //std::cout<<"Animation finished"<<std::endl;

    this->m_view->m_tube->lauchControl=true;
    this->elements.setEnableLauchedObject(this->reCallGameLevel);
    if(this->reCallGameLevel<mySettings.maxGameLevels)
    {
        ++this->reCallGameLevel;
    }
    this->m_view->m_tube->stopStaticAnimations();
    this->m_view->m_score_button->setEnabled(true);
    this->m_view->m_reset_button->setEnabled(true);
}

void ReCallController::startGame()
{
    #ifdef SOUNDS
    m_currentSound->setMedia(QUrl("qrc::/../Sounds/mixItems.wav"));
    m_currentSound->setVolume(50);
    m_currentSound->play();
    #endif

   this->m_view->m_title->stopStaticAnimations();
   this->m_view->m_title->setVisible(false);
   this->loadPics();
}

void ReCallController::loadPics()
{
    qreal x = this->m_view->m_tube->x();
    qreal y = this->m_view->m_tube->y();
    static bool firstload = true;
    if(firstload)
    {
        elements.addElements();
        elements.loadElements(m_view->m_svgRenderer,this->m_scene,x+3,y+5);
        firstload=false;
        for(int index= 0; index < this->elements.svgElements.size();++index)
        {
           connect((this->elements.svgElements[index]->animation()), SIGNAL (finished()), this, SLOT (clickedObjectEvaluation()));
        }
    }
    this->connectControlAnimationSignals();
    this->m_launchAnimation->start();
    this->m_view->m_score_button->setEnabled(false);
    this->m_view->m_reset_button->setEnabled(false);
}

int ReCallController::runGame()
{        
    return exec();
}


void ReCallController::connectControlAnimationSignals()
{
    this->m_launchAnimation = new QSequentialAnimationGroup;
    this->elements.shuffleElements();
    this->suffleAvaiblePositions();
    //Se conectan las animaciones
       for(int index = 0; index < this->reCallGameLevel;++index)
        {
           setUpLevelAnimation(this->levelLauchSpeed,index,this->avaiblePositions[index]->rx(),this->avaiblePositions[index]->ry(),-1,-1);
           this->m_launchAnimation->addAnimation(this->elements.getObjectAnimation(index));
           this->gameOrderQueue.push_back(this->elements.svgElements[index]->getName());
       }  
    connect((this->m_launchAnimation), SIGNAL (finished()), this, SLOT (incrementNextLevel()));
}

void ReCallController::setUpLevelAnimation(const int duration,const int index,const qreal endX,const qreal endY,const qreal beginX,const qreal beginY)
{
  this->elements.svgElements[index]->setUpAnimation(1,duration,endX,endY,beginX,beginY);
}

void ReCallController::setUpAvaiblePositions()
{
    //pos 1
    QPoint* point0 = new QPoint(30,20);
    this->avaiblePositions.push_back(point0);
    //pos 2
    QPoint* point1 = new QPoint(40,40);
    this->avaiblePositions.push_back(point1);
    //pos 3
    QPoint* point2 = new QPoint(50,27);
    this->avaiblePositions.push_back(point2);
    //pos 4
    QPoint* point3 = new QPoint(100,10);
    this->avaiblePositions.push_back(point3);
    //pos 5
    QPoint* point4 = new QPoint(100,0);
    this->avaiblePositions.push_back(point4);
    //pos 6
    QPoint* point5 = new QPoint(70,35);
    this->avaiblePositions.push_back(point5);
    //pos 7
    QPoint* point6 = new QPoint(30,35);
    this->avaiblePositions.push_back(point6);
    //pos 8
    QPoint* point7 = new QPoint(100,35);
    this->avaiblePositions.push_back(point7);
    //pos 9
    QPoint* point8 = new QPoint(85,30);
    this->avaiblePositions.push_back(point8);
    //pos 10
    QPoint* point9 = new QPoint(85,12);
    this->avaiblePositions.push_back(point9);
    //pos 11
    QPoint* point10 = new QPoint(60,15);
    this->avaiblePositions.push_back(point10);
    //pos 12
    QPoint* point11 = new QPoint(21,40);
    this->avaiblePositions.push_back(point11);
    //pos 13
    QPoint* point12 = new QPoint(10,30);
    this->avaiblePositions.push_back(point12);
    //pos 14
    QPoint* point13 = new QPoint(120,30);
    this->avaiblePositions.push_back(point13);
    //pos 15
    QPoint* point14 = new QPoint(120,0);
    this->avaiblePositions.push_back(point14);

}

void ReCallController::suffleAvaiblePositions()
{
    //tomado de cplusplus
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->avaiblePositions.begin(),this->avaiblePositions.end(),std::default_random_engine(seed));
}
#include <iostream>

ReCallController::~ReCallController()
{
    delete m_scene;
    delete m_view;
    delete m_messages;
    #ifdef SOUNDS
    delete m_currentSound;
    delete m_backGroundMusic;
    delete m_backGroundSound;
    #endif
    std::cout<<"Controlador se destruye"<<std::endl;
}


void ReCallController::clickedObjectEvaluation()
{
    #ifdef SOUNDS
        m_currentSound->setMedia(QUrl("qrc::/../Sounds/touch.wav"));
        m_currentSound->play();
    #endif

     QAbstractButton* modifyTexts = Q_NULLPTR;
     if((this->gameOrderQueue.first().toStdString())==(this->elements.currenTop->toStdString()))
     {
         this->increaseScore();

         this->elements.shuffleElements();
         this->suffleAvaiblePositions();

         this->m_view->updateScore(this->mySettings.playerScore);

         this->gameOrderQueue.pop_front();

         if(this->gameOrderQueue.empty())
         {
             this->m_view->m_tube->setEnabled(true);
             if(this->reCallGameLevel==mySettings.maxGameLevels)
             {
                 if(mySettings.gameDifficulty==3)
                 {
                     this->insertCurrentUserScore();
                     this->m_messages->setText("You passed the entire game! That is awesome! Thanks for playing");
                     this->m_messages->setWindowTitle("Game over!");
                     modifyTexts = this->m_messages->button(QMessageBox::Ok);
                     modifyTexts->setVisible(false);
                     modifyTexts = Q_NULLPTR;
                     modifyTexts =this->m_messages->button(QMessageBox::Cancel);
                     modifyTexts->setText("Exit game");
                 }else
                 {
                     this->m_messages->setText("You passed the first 15 levels. Now it will become harder!");
                     this->m_messages->setWindowTitle("Congratulations!");
                     modifyTexts = this->m_messages->button(QMessageBox::Ok);
                     modifyTexts->setText("Go ahead!");
                     modifyTexts = Q_NULLPTR;
                     modifyTexts =this->m_messages->button(QMessageBox::Cancel);
                     modifyTexts->setText("Exit game");
                 }

                 this->m_messages->exec();
             }
         }
     }else
     {
        #ifdef SOUNDS
        m_currentSound->setMedia(QUrl("qrc::/../Sounds/endGame.wav"));
        m_currentSound->setVolume(50);
        m_currentSound->play();
        #endif

         this->insertCurrentUserScore();
         this->resetGame();

         this->m_messages->setText("Wrong choise, game over");
         this->m_messages->setWindowTitle("Thanks for playing!");
         modifyTexts = this->m_messages->button(QMessageBox::Cancel);
         modifyTexts->setText("Reset game");
         modifyTexts = this->m_messages->button(QMessageBox::Ok);
         modifyTexts->setText("Exit game");

         this->m_view->updateScore(this->mySettings.playerScore);
         this->m_messages->exec();

     }
}

void ReCallController::aceptedEvent()
{
    QAbstractButton* buttonPointer = this->m_messages->button(QMessageBox::Ok);
    if(buttonPointer->text().compare("Exit game")==0)
    {
        this->insertCurrentUserScore();
        this->exit();
    }

    buttonPointer = this->m_messages->button(QMessageBox::Ok);
    if(buttonPointer->text().compare("Go ahead!")==0)
    {
        this->mySettings.gameDifficulty+=1;
        this->mySettings.updateGameSettings();
        this->levelLauchSpeed-=mySettings.speedDecrement;
        this->reCallGameLevel=1;
    }
}

void ReCallController::rejectEvent()
{
    QAbstractButton* buttonPointer = this->m_messages->button(QMessageBox::Cancel);
    if(buttonPointer->text().compare("Reset game")==0)
    {
     this->resetGame();
     this->askForPlayerName();
    }

    buttonPointer = this->m_messages->button(QMessageBox::Cancel);
    if(buttonPointer->text().compare("Exit game")==0)
    {
        this->insertCurrentUserScore();
        this->exit();
    }
}

#include <iostream>
void ReCallController::resetGame()
{
    this->reCallGameLevel=1;
    this->mySettings.playerScore=0;

    for(int index = 0; index < this->elements.svgElements.size();++index)
     {
        this->elements.svgElements[index]->setPos(this->m_view->m_tube->x()+3,this->m_view->m_tube->y()+5);
     }
    this->gameOrderQueue.clear();
    this->m_view->m_tube->setEnabled(true);
    this->m_view->m_tube->lauchControl=true;
    this->levelLauchSpeed=1000;
    this->suffleAvaiblePositions();
    this->elements.shuffleElements();
    this->m_view->m_title->startStaticAnimations(150);
    this->m_view->m_title->setVisible(true);
    this->mySettings.playerName.clear();
}

void ReCallController::resetFromButton()
{
    #ifdef SOUNDS
    m_currentSound->setMedia(QUrl("qrc::/../Sounds/buttonTouch.wav"));
    m_currentSound->setVolume(100);
    m_currentSound->play();
    #endif

    QAbstractButton* buttonsChanger;
    this->m_messages->setText("Want to reset game?");
    this->m_messages->setWindowTitle("Reset current game");
    buttonsChanger = this->m_messages->button(QMessageBox::Cancel);
    buttonsChanger->setText("Reset game");
    buttonsChanger = this->m_messages->button(QMessageBox::Ok);
    buttonsChanger->setText("Return to game");

    this->m_view->updateScore(this->mySettings.playerScore);
    this->m_messages->exec();
}

void ReCallController::showScoresTable()
{    
    #ifdef SOUNDS
        m_currentSound->setMedia(QUrl("qrc::/../Sounds/buttonTouch.wav"));
        m_currentSound->setVolume(100);
        m_currentSound->play();
    #endif

    this->modelScores = new ScoreTableModel(0);
    this->modelScores->loadScores();
    this->viewScores.setModel(&(*this->modelScores));
    this->viewScores.setModelPointer(this->modelScores);
    this->viewScores.show();
    //delete this->modelScores;
}



void ReCallController::askForPlayerName()
{
    this->m_messages->close();
    bool play = false;
    bool ask = true;
    QString nickname;
    while (ask)
    {
        nickname = QInputDialog::getText(0, "Welcome to recall game!", "Nickname:", QLineEdit::Normal,
                                   "", &play);
        if (play&&nickname.isEmpty()==false)
        {
            this->mySettings.playerName=nickname;
            ask = false;
        }
    }

}

void ReCallController::insertCurrentUserScore()
{

    QFile scoresFile("../build/GameScores.txt");

    if(!scoresFile.open(QIODevice::WriteOnly | QIODevice::Append))
    {
        this->m_view->m_score_button->setEnabled(true);
        std::cout<<"Could not open file :"<<scoresFile.errorString().toStdString()<<std::endl;
        std::cout<<"File will be created"<<std::endl;
        system("mkdir ../build/GameScores.txt");
        this->insertCurrentUserScore();
    }else
    {
       this->m_view->m_score_button->setEnabled(true);
        QTextStream out(&scoresFile);

        out<<this->mySettings.playerName<<" "<<this->mySettings.gameDifficulty<<"/"<<this->reCallGameLevel
          <<" "<<this->mySettings.playerScore<<"\n";
         scoresFile.close();

    }


}
