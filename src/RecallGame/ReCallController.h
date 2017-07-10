#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ReCallMainView.h"
#include "ReCallController.h"
#include "Elements.h"
#include <QSvgRenderer>
#include <QtMath>
#include <QApplication>
#include <QGraphicsScene>
#include <QStyleFactory>


class QGraphicsScene;
class ReCallMainView;

class ReCallController : public QApplication
{
    Q_OBJECT
    protected: 
    QGraphicsScene* m_scene;
    ReCallMainView* m_view;
    Elements elements;
    int reCallGameLevel;
    int currentLauchedItems;


    public:
    ReCallController(int &argc, char **argv, int flags = ApplicationFlags);
    /// Destructor
    ~ReCallController();
    int runGame();
    void loadPics();
    void connectControlAnimationSignals();
    void startGame();
    void setUpLevelAnimation(const int duration, const int index, const qreal endX, const qreal endY, const qreal beginX, const qreal beginY);
    private slots:
    void notify();

};

#endif // MAINWINDOW_H
