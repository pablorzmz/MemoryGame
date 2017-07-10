#include "ReCallController.h"

ReCallController::ReCallController(int &argc, char **argv, int flags)
    : QApplication(argc, argv, flags)
    , m_scene(nullptr)
    , m_view(nullptr)
    ,elements()
    ,reCallGameLevel(1)
    ,m_launchAnimation(Q_NULLPTR)
    ,levelLauchSpeed(400)

{
    m_scene = new QGraphicsScene();
    m_view = new ReCallMainView(m_scene);
    m_view->initComponents(m_scene);
    this->setApplicationName("Recall game v1.0");
    this->setStyle(QStyleFactory::create("WindowsVista"));
    elements.addElements();
    this->m_view->m_tube->setControllerEvent(this);
    this->setUpAvaiblePositions();
    m_view->show();

}
#include <iostream>
void ReCallController::notify()
{
    std::cout<<"Animation finished"<<std::endl;
    this->m_view->m_tube->lauchControl=true;
    this->elements.setEnableLauchedObject(this->reCallGameLevel);
    if(this->reCallGameLevel<12)
    {
        ++this->reCallGameLevel;
    }else
    {
      this->levelLauchSpeed-=300;
      this->reCallGameLevel=1;
    }
    this->m_view->m_tube->setEnabled(true);
}

void ReCallController::startGame()
{
   this->loadPics();
}

void ReCallController::loadPics()
{
    qreal x = this->m_view->m_tube->x();
    qreal y = this->m_view->m_tube->y();
    std::cout<<x<<","<<y<<std::endl;
    static bool firstload = true;
    if(firstload)
    {
        elements.loadElements(m_view->m_svgRenderer,this->m_scene,x+3,y+1);
        firstload=false;
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
       }  
    connect((this->m_launchAnimation), SIGNAL (finished()), this, SLOT (notify()));
}

void ReCallController::setUpLevelAnimation(const int duration,const int index,const qreal endX,const qreal endY,const qreal beginX,const qreal beginY)
{
  this->elements.elementosSGV[index]->setAnimation(duration,endX,endY,beginX,beginY);
}

void ReCallController::setUpAvaiblePositions()
{
    //pos 1
    QPoint* point0 = new QPoint(30,10);
    this->avaiblePositions.push_back(point0);
    //pos 2
    QPoint* point1 = new QPoint(30,30);
    this->avaiblePositions.push_back(point1);
    //pos 3
    QPoint* point2 = new QPoint(30,50);
    this->avaiblePositions.push_back(point2);
    //pos 4
    QPoint* point3 = new QPoint(100,5);
    this->avaiblePositions.push_back(point3);
    //pos 5
    QPoint* point4 = new QPoint(100,30);
    this->avaiblePositions.push_back(point4);
    //pos 6
    QPoint* point5 = new QPoint(70,25);
    this->avaiblePositions.push_back(point5);
    //pos 7
    QPoint* point6 = new QPoint(30,25);
    this->avaiblePositions.push_back(point6);
    //pos 8
    QPoint* point7 = new QPoint(100,45);
    this->avaiblePositions.push_back(point7);
    //pos 9
    QPoint* point8 = new QPoint(85,30);
    this->avaiblePositions.push_back(point8);
    //pos 10
    QPoint* point9 = new QPoint(85,2);
    this->avaiblePositions.push_back(point9);
    //pos 11
    QPoint* point10 = new QPoint(60,5);
    this->avaiblePositions.push_back(point10);
    //pos 12
    QPoint* point11 = new QPoint(50,30);
    this->avaiblePositions.push_back(point11);
    //pos 13
    QPoint* point12 = new QPoint(30,20);
    this->avaiblePositions.push_back(point12);

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
}

