#include "ReCallController.h"

ReCallController::ReCallController(int &argc, char **argv, int flags)
    : QApplication(argc, argv, flags)
    , m_scene(nullptr)
    , m_view(nullptr)
    ,elements()

{
    m_scene = new QGraphicsScene();
    m_view = new ReCallMainView(m_scene);
    m_view->initComponents(m_scene);
    this->setApplicationName("Recall game v1.0");
    this->setStyle(QStyleFactory::create("WindowsVista"));
    elements.addElements();
    m_view->show();
    connect(m_view->startButton(), SIGNAL (released()), this, SLOT (startGame()));
}

void ReCallController::startGame()
{
 this->loadPics();
}

void ReCallController::loadPics()
{
    elements.loadElements(m_view->m_svgRenderer,this->m_scene,3,3);
    this->m_view->startButton()->setEnabled(false);
}

int ReCallController::runGame()
{
    return exec();
}


ReCallController::~ReCallController()
{
    delete m_scene;
    delete m_view;
}
