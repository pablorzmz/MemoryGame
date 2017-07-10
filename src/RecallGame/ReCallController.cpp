#include "ReCallController.h"

ReCallController::ReCallController(int &argc, char **argv, int flags)
    : QApplication(argc, argv, flags)
    , m_scene(nullptr)
    , m_view(nullptr)
    ,elements()
    ,reCallGameLevel(7)
    ,currentLauchedItems(0)

{
    m_scene = new QGraphicsScene();
    m_view = new ReCallMainView(m_scene);
    m_view->initComponents(m_scene);
    this->setApplicationName("Recall game v1.0");
    this->setStyle(QStyleFactory::create("WindowsVista"));
    elements.addElements();
    this->m_view->m_tube->setControllerEvent(this);
    m_view->show();
    //connect(m_view->startButton(), SIGNAL (released()), this, SLOT (startGame()));

}
#include <iostream>
void ReCallController::notify()
{
    static int localLevel = this->reCallGameLevel;
    std::cout<<"Animation number : "<<localLevel<<std::endl;
    if(localLevel!=-2&&localLevel!=1&&currentLauchedItems<this->reCallGameLevel)
    {
        localLevel-=1;
        this->elements.getObjectAnimation(localLevel)->start();
        this->currentLauchedItems+=1;
        std::cout<<"Vuelvo a animación incial: "<<this->currentLauchedItems<<std::endl;
    }else
    {
        localLevel=-2;
    }

    if(localLevel==-2&&this->currentLauchedItems!=-1)
    {
        --this->currentLauchedItems;
        std::cout<<"Devueltos: "<<this->currentLauchedItems<<std::endl;
    }else
    {
        if(localLevel==-2&&this->currentLauchedItems==-1)
        {
            this->m_view->m_tube->lauchControl=true;
            localLevel=this->reCallGameLevel;
            this->connectControlAnimationSignals();
            this->currentLauchedItems=0;
            std::cout<<"Cambio de nivel: lazados("<<this->currentLauchedItems<<") nivel("<<localLevel<<")"<<std::endl;
        }
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
        elements.loadElements(m_view->m_svgRenderer,this->m_scene,x+3,y+1);
        this->connectControlAnimationSignals();
        firstload=false;
    }
    this->elements.shuffleObjects();
    this->elements.startInitialAnimation();
}

int ReCallController::runGame()
{
    return exec();
}

void ReCallController::connectControlAnimationSignals()
{
    qreal yAnimation = 20;
    qreal xAnimation = 0;
    //Se conectan las animaciones
       for(int index = 0; index < this->elements.elementosSGV.size();++index)
        {
           setUpLevelAnimation(500,index,xAnimation,yAnimation,-1,-1);
           connect((this->elements.getObjectAnimation(index)), SIGNAL (finished()), this, SLOT (notify()));
           xAnimation+=10;
       }
}

void ReCallController::setUpLevelAnimation(const int duration,const int index,const qreal endX,const qreal endY,const qreal beginX,const qreal beginY)
{
  this->elements.elementosSGV[index]->setAnimation(duration,endX,endY,beginX,beginY);
}


ReCallController::~ReCallController()
{
    delete m_scene;
    delete m_view;
}

