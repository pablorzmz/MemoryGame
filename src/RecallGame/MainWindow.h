#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSvgRenderer>
#include <QPushButton>
#include <QPalette>
#include "Graphic.h"
#include "Controller.h"

class QGraphicsView;
class QGraphicsScene;
class QGraphicsView;
class QPushButton;

class MainWindow : public QApplication
{
    Q_OBJECT
    protected:
    QPushButton* M_starButton;
    QGraphicsScene* M_scene;
    QGraphicsView* M_view;
    QSvgRenderer* M_svgRenderer;
    Graphic* M_tube;
    Graphic* M_backGround;
    Controller M_mainController;


    public:
    MainWindow(int &argc, char **argv, int flags = ApplicationFlags);
    /// Destructor
    ~MainWindow();
    int runGame();
    void paintBackGround();
    void initComponents();

    private slots:
    void startGame();

};

#endif // MAINWINDOW_H
