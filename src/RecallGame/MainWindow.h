#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>

class MainWindow : public QApplication
{
    Q_OBJECT
    protected:
    QGraphicsScene* M_scene;
    QGraphicsView* M_view;

    public:
    MainWindow(int &argc, char **argv, int flags = ApplicationFlags);
    /// Destructor
    ~MainWindow();
    int runGame();
};

#endif // MAINWINDOW_H
