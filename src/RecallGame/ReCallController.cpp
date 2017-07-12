#include "ReCallController.h"

ReCallController::ReCallController(int &argc, char **argv, int flags)
    : QApplication(argc, argv, flags)
    ,m_scene(Q_NULLPTR)
    ,m_view(Q_NULLPTR)
    ,m_launchAnimation(Q_NULLPTR)
    ,elements()
    ,reCallGameLevel(1)
    ,levelLauchSpeed(1000)
    ,m_messages(Q_NULLPTR)
{   

    m_scene = new QGraphicsScene();
    m_view = new ReCallMainView(m_scene);
    m_messages = new QMessageBox;

    this->m_messages->addButton(QMessageBox::Ok);
    this->m_messages->addButton(QMessageBox::Cancel);
    connect((this->m_messages->button(QMessageBox::Ok)), SIGNAL (pressed()), this, SLOT (aceptedEvent()));
    connect((this->m_messages->button(QMessageBox::Cancel)), SIGNAL (pressed()), this, SLOT (rejectEvent()));

    m_view->initComponents(m_scene);
    this->setApplicationName("Recall game v1.0");
    //elements.addElements();

    this->m_view->m_tube->setControllerEvent(this);
    this->setUpAvaiblePositions();
    m_view->show();

}

void ReCallController::incrementNextLevel()
{
    //std::cout<<"Animation finished"<<std::endl;
    this->m_view->m_tube->lauchControl=true;
    this->elements.setEnableLauchedObject(this->reCallGameLevel);
    if(this->reCallGameLevel<mySettings.maxGameLevels)
    {
        ++this->reCallGameLevel;
        this->m_view->m_tube->staticAnimationTimer->stop();
        this->m_view->m_tube->setElementId("tube");
    }
}

void ReCallController::startGame()
{
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
        //connect each finished animation
        for(size_t index= 0; index < this->elements.elementosSGV.size();++index)
        {
           connect((this->elements.elementosSGV[index]->animation()), SIGNAL (finished()), this, SLOT (clickedObjectEvaluation()));
        }
    }
    this->connectControlAnimationSignals();
    this->m_launchAnimation->start();
}

int ReCallController::runGame()
{
    return exec();
}


void ReCallController::connectControlAnimationSignals()
{
    this->m_launchAnimation = new QSequentialAnimationGroup;
    this->elements.shuffleObjects();
    this->suffleAvaiblePositions();
    //Se conectan las animaciones
       for(int index = 0; index < this->reCallGameLevel;++index)
        {
           setUpLevelAnimation(this->levelLauchSpeed,index,this->avaiblePositions[index]->rx(),this->avaiblePositions[index]->ry(),-1,-1);
           this->m_launchAnimation->addAnimation(this->elements.getObjectAnimation(index));
           this->gameOrderQueue.push_back(this->elements.elementosSGV[index]->getName());
       }  
    connect((this->m_launchAnimation), SIGNAL (finished()), this, SLOT (incrementNextLevel()));
}

void ReCallController::setUpLevelAnimation(const int duration,const int index,const qreal endX,const qreal endY,const qreal beginX,const qreal beginY)
{
  this->elements.elementosSGV[index]->setAnimation(1,duration,endX,endY,beginX,beginY);

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
    QPoint* point4 = new QPoint(100,40);
    this->avaiblePositions.push_back(point4);
    //pos 6
    QPoint* point5 = new QPoint(70,35);
    this->avaiblePositions.push_back(point5);
    //pos 7
    QPoint* point6 = new QPoint(30,35);
    this->avaiblePositions.push_back(point6);
    //pos 8
    QPoint* point7 = new QPoint(100,55);
    this->avaiblePositions.push_back(point7);
    //pos 9
    QPoint* point8 = new QPoint(85,40);
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
    QPoint* point13 = new QPoint(120,45);
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

ReCallController::~ReCallController()
{
    delete m_scene;
    delete m_view;
    delete m_messages;
}


void ReCallController::clickedObjectEvaluation()
{
     QAbstractButton* modifyTexts;
     if((this->gameOrderQueue.first().toStdString())==(this->elements.currenTop->toStdString()))
     {
         this->incrementScore();

         this->elements.shuffleObjects();
         this->suffleAvaiblePositions();

         this->m_view->updateScore(this->mySettings.playerScore);

         this->gameOrderQueue.pop_front();

         if(this->gameOrderQueue.empty())
         {
             this->m_view->m_tube->setEnabled(true);
             if(this->reCallGameLevel==mySettings.maxGameLevels)
             {
                 this->m_messages->setText("You passed the first 15 levels. Now it will become harder!");
                 this->m_messages->setWindowTitle("Congratulations!");
                 modifyTexts =modifyTexts = this->m_messages->button(QMessageBox::Ok);
                 modifyTexts->setText("Go ahead!");
                 modifyTexts =modifyTexts = this->m_messages->button(QMessageBox::Cancel);
                 modifyTexts->setText("Exit game");
                 this->m_messages->exec();
             }
         }
     }else
     {
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
        this->exit();

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
        this->resetGame();

    buttonPointer = this->m_messages->button(QMessageBox::Cancel);
    if(buttonPointer->text().compare("Exit game")==0)
        this->exit();
}


void ReCallController::resetGame()
{
    this->reCallGameLevel=1;
    this->mySettings.playerScore=0;

    for(int index = 0; index < this->elements.elementosSGV.size();++index)
     {
        this->elements.elementosSGV[index]->setPos(this->m_view->m_tube->x()+3,this->m_view->m_tube->y()+5);
     }
    this->gameOrderQueue.clear();
    this->m_view->m_tube->setEnabled(true);
    this->m_view->m_tube->lauchControl=true;
    this->levelLauchSpeed=1000;
    this->suffleAvaiblePositions();
    this->elements.shuffleObjects();
}
