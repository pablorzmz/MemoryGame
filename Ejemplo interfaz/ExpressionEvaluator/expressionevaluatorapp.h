#ifndef EXPRESSIONEVALUATORAPP_H
#define EXPRESSIONEVALUATORAPP_H

#include <QApplication>


////////hereda para que se comporte como un aplication
class ExpressionEvaluatorApp: public QApplication
{
protected:
QWidget windows;

public:
    ExpressionEvaluatorApp(int& argc, char *argv[]);

~ExpressionEvaluatorApp()
    {
     delete windows;
    }
};

#endif // EXPRESSIONEVALUATORAPP_H
