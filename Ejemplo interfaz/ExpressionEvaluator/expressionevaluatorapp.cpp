#include "expressionevaluatorapp.h"
#include "mainwindow.h"

#include <QApplication>
#include <QWidget>
#include <QTextEdit>
#include <QVBoxLayout>

ExpressionEvaluatorApp::ExpressionEvaluatorApp(int& argc, char* argv[])
   //construye los miembors de la clase base para que incialice los miembros para mi
    : QApplication(argc, argv)
{
    window = new MainWindow();
}

ExpressionEvaluatorApp::~ExpressionEvaluatorApp()
{
   delete window;
}



