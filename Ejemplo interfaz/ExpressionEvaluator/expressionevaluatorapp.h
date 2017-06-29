#ifndef EXPRESSIONEVALUATORAPP_H
#define EXPRESSIONEVALUATORAPP_H

#include <QApplication>

class MainWindow;

class ExpressionEvaluatorApp : public QApplication
{
  protected:
   MainWindow* window;

  public:
   ExpressionEvaluatorApp(int& argc, char* argv[]);
   ~ExpressionEvaluatorApp();
};

#endif // EXPRESSIONEVALUATORAPP_H
