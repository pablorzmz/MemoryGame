#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QColor>
#include <QString>

//ES necesario hacer Foward declaration
class QTextEdit;


class MainWindow : public QWidget
{
        Q_OBJECT
protected:
  QTextEdit* m_input =  nullptr;
  QLabel* m_result  = nullptr;

public:
    explicit MainWindow(QWidget *parent = 0);

    protected slots:
    void evaluateExpression();



};

#endif // MAINWINDOW_H
