#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSvgRenderer>
#include "Graphic.h"

class QGraphicsView;
class QGraphicsScene;
class QGraphicsView;
class MainWindow : public QApplication
{
    Q_OBJECT
    protected:
    QGraphicsScene* M_scene;
    QGraphicsView* M_view;
    Graphic* M_tube;
    Graphic* M_backGround;



    public:
    MainWindow(int &argc, char **argv, int flags = ApplicationFlags);
    /// Destructor
    ~MainWindow();
    int runGame();
    void paintBackGround();
};

#endif // MAINWINDOW_H
