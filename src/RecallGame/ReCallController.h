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
#include <QPalette>
#include "Object.h"
#include "Controller.h"


class QGraphicsScene;
class QPushButton;
class ReCallMainView;

class ReCallController : public QApplication
{
    Q_OBJECT
    protected: 
    QGraphicsScene* m_scene;
    ReCallMainView* m_view;
    Elements elements;


    public:
    ReCallController(int &argc, char **argv, int flags = ApplicationFlags);
    /// Destructor
    ~ReCallController();
    int runGame();
    void loadPics();

    private slots:
    void startGame();

};

#endif // MAINWINDOW_H
